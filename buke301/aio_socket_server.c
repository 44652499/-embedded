void handle_read(union sigval sigev_value) { /* handle data or disconnection */ }
void handle_write(union sigval sigev_value) { /* free writing buffer memory */ }
void start()
{
    const int acceptorSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
memset(&addr, 0, sizeof(struct sockaddr_in));
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = INADDR_ANY;
addr.sin_port = htons(port);
    bind(acceptorSocket, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));

    listen(acceptorSocket, SOMAXCONN);

    struct sockaddr_in address;
socklen_t addressLen = sizeof(struct sockaddr_in);

    for(;;)
    {
         const int incomingSocket = accept(acceptorSocket, (struct sockaddr*)&address, &addressLen);
         if(incomingSocket == -1)
         { /* handle error ... */}
         else
         {
              //say socket to append outcoming messages at writing:
              const int currentFlags = fcntl(incomingSocket, F_GETFL, 0);
              if(currentFlags < 0) { /* handle error ... */ }
              if(fcntl(incomingSocket, F_SETFL, currentFlags | O_APPEND) == -1) { /* handle another error ... */ }

              //start reading:
              struct aiocb* readingAiocb = new struct aiocb;
              memset(readingAiocb, 0, sizeof(struct aiocb));
              readingAiocb->aio_nbytes = MY_SOME_BUFFER_SIZE;
              readingAiocb->aio_fildes = socketDesc;
              readingAiocb->aio_buf = mySomeReadBuffer;
              readingAiocb->aio_sigevent.sigev_notify = SIGEV_THREAD;
              readingAiocb->aio_sigevent.sigev_value.sival_ptr = (void*)mySomeData;
              readingAiocb->aio_sigevent.sigev_notify_function = handle_read;
              if(aio_read(readingAiocb) != 0) { /* handle error ... */ }
          }
    }
}

//called at any time from server side:
send(void* data, const size_t dataLength)
{
    //... some thread-safety precautions not needed here ...

    const int cancellingResult = aio_cancel(socketDesc, readingAiocb);
    if(cancellingResult != AIO_CANCELED)
    {
        //this one happens ~80% of the time - embracing previous call to permanent while cycle does not help:
        if(cancellingResult == AIO_NOTCANCELED)
        {
            puts(strerror(aio_return(readingAiocb))); // "Operation now in progress"
            /* don't know what to do... */
        }
    }
    //otherwise it's okay to send:
    else
    {
        aio_write(...);
    }
}



/*
int Session_INIT(...,type?REQUESTER|RESPONDER)
{
SOCKET sock,cnct;
HANDLE sink[2];

// Initialize a pipe (usually paire of handle of iostream or FILE*)
pipe(sink);

// Initialize a socket
// There are various implementations 
// Some can bind a signal() to a socket  
// Some can just wake up and unblock all pending call to accept(),select(), or recv()
// then you must check if your sockets are concerned
// Overall, it's much better than a stupid stubborn loop, polling all sockets
sock = socket(...);
fcntl(sock,...to be in BLOCKING mode...);
ioctl(sock,...to be in BLOCKING mode...);
fcntl(sock,...to be able to receive signal() or SIGIO,SIGINT,...);
ioctl(sock,...to be able to receive signal() or SIGIO,SIGINT,...);

// Although it could be a REQUESTER, it's useful to assign a preferred
// outgoing interface, especially when there are several on local host.
// Most of examples over the web, don't mention it explicitely
getaddrinfo(...local address string...);
bind(sock,...address of preferred local network interface);

if ( type == REQUESTER )
  {
  getaddrinfo(...remote address string...);
  connect(sock,...address of remote peer...);
  }
else
  listen(sock,...);

// From now we must process as soon as possible:
//   - pending connection requests from listen()
//   - pending receiving data from connect() like "Welcome" banners from server
//     They should be bufferized by the system, then don't waste time...

// Launch a new task, process or thread whatever it's called (here UNX like multitasking)
// NB: According UNX standard, each call of fork() will return two times:
//  one in parent process or thread context,
//  one in child  process or thread context,
//  In both cases, variables are duplicated from fork()
chld=fork();  // two tasks : INVOKER & (OUTGOING|LISTENER) 

if ( chld )
  {
  // INVOKER task

  // Depending on implementation of signal() and accept(),select()
  // The goal here is to be able to behave on listener or outgoing process
  // by close() according accept() or select(), or kill() according signal()
  // to break a blocking accept() or select()
  return ( sink[1] );

  }

else if ( type == REQUESTER )
  {

  // OUTGOING task
  return ( Session_JOBS(sock,sink,...) );

  }

// Herein a basic listener implementation 

while ( 1 )
  {

  // LISTENER task

  // Process or thread will sleep until an incoming call occurs
  cnct = accept(sock,...blocking mode...);


  // It will be waken up on incoming call or a signal(), SIGIO, SIGINT for example,
  // wasor something wrong
  if ( SOCK_ERROR )
    break;
  
  // From now we must process as soon as possible:
  //   - pending connection requests from listen()
  //   - pending receiving data from accept() like "Hello" banners from client
  //     They should be bufferized by the system, then don't waste time...

  // Launch a new task, process or thread whatever it's called (here UNX like multitasking)
  // NB: According UNX standard, each call of fork() will return two times:
  //  one in parent process or thread context,
  //  one in child  process or thread context,
  //  In both cases, variables are duplicated from fork()
  chld=fork();  // two tasks : LISTENER&(INCOMING)
  if ( chld ) continue;

  // INCOMING task
  return ( Session_JOBS(cnct,sink,...) );

  }

// Clear gracefully listening socket
close(sock);

return ( 0 );

}

int Session_JOBS(sock,sink,...)
{

// Whatever INCOMING or OUTGOING connection

while ( 1 )
  {

  // Process or thread will sleep until something occur on one of sockets
  select(sock,...);

  // There are many ways to implement this part but keep in your mind it should
  // be similar...
    
  if ( sock has received data )
    {

    // Retrieve received data and process it
    recv(sock,...);

    // Parse incomning data to identify protocol sink (PDU) 
    // Each PDU can be considered as an event so let's put it in the pipe
    //
    // In many implementations, calls to recv() are released if blocking or 
    // simply return no data on shutdown() from remote
    //
    write(sink[1],...parsed PDU event or END event...);

    }
  
  if ( sock is ready to send )

    {

    // Prepare to send more data
    send(sock,...);

    // Check outgoing data to identify sent Protocol Data Units (PDU)
    // Each PDU can be considered as an event so let's put it in the pipe
    // In many implementations, calls to send() are released if blocking or 
    // simply return no data on shutdown() from remote or errors are raised
    //
    write(sink[1],...parsed PDU event or END event...);

    }

  // Sometime, it appears that...
  // The task was waken for no incoming data from remote
  // The task was waken for no outgoing data from remote
  // In fact, a signal() was raised 
        //  to this socket
  //  to all sockets of this task (to the process or thread)
  //  to all sockets
  //
  // In many implementations, calls to are released if blocking or simply return 
  // no read data on shutdown() from remote
  //
  if ( no actual I/O on socket ie recv() or send() return 0 )
    {

    // Like sink[] pipe is share by INVOKER, OUTGOING and INCOMING task 
    // (thru LISTENER task), here's a funnel to a central point
    evnt = read(sink[0],...pending PDU event...);
    if ( size )
      {
      
      // HERE THE BEHAVIOR OF YOUR PROTOCOLE CAN BE HANDLE
      // INDEPENDENTLY OF AVAIBILITY OF
      //  - BLOCKING or NON-BLOCKING features
      //  - TRUE MULTITASKING or PSEUDO-MULTITASKING
      //
      // IT COULD BE NATIVE STATE-EVENT AUTOMATE PROVIDED IN
      // MANY PROTOCOL SPECIFICATIONS TO DESCRIBE ITS DYNAMICS
      // 

      // Automate changes state independently, stts < 0 is illegal
      stts = automate[stts][evnt];
      if ( stts < 0 ) break; 

      // In parallel, if transition is legal, 
      // actions could be independent of protocol
      switch (evnt)
        {
        case CHUNK_RECVD:
          // Subsequent of a recv() for example
          // Save it into a file
          // Prepare to send its acknowledgement
          break;

        case CHUNK_ACK_SENT:
          // Subsequent of a send() for example
          // Nothing special
          // or reset time-out watchdog
          break;

        case CHUNK_SENT:
          // Subsequent of a sent() for example
          // Save it into a file
          // Prepare to send its acknowledgement
          break;

        case CHUNK_ACK_RCVD:
          // Nothing special
          // or reset time-out watchdog
          break;

        case CLOSE_REQUEST:
          
          // Gracefully end the session
          shutdown(sock,FD_BOTH);
          break;

        case CLOSE_ACCEPTED:
          
          close(sock);
          break;
        }              
      
      }
    else
      { 

      // Clear gracefully connected socket
      close(sock);
      break;

      }
    }
  }

return(0);

}
Offline


*/