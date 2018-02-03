#include "appheader.h"

int connect_host[NUM];
int connect_num=0;

void* handler_request()
{
   fd_set read_fd_set;
   int maxfd=0;
   struct timeval tv;
   int ret;
   int i;
   while(1)
    {
      FD_ZERO(&read_fd_set);
      for(i=0;i<NUM;i++)
       {
          if(connect_host[i]>-1)
          {
            FD_SET(connect_host[i],&read_fd_set);
            if(maxfd<connect_host[i])
            {
              maxfd=connect_host[i];
            }
          }
       }
      tv.tv_sec=1;
      tv.tv_usec=0;
      ret=select(maxfd+1,&read_fd_set,NULL,NULL,&tv);
      if(ret<=0||connect_num==0)
      {
        continue;
      }  
      if(ret>0)
      {
        for(i=0;i<NUM;i++)
        {
          if(connect_host[i]>-1)
          {
            if(FD_ISSET(connect_host[i],&read_fd_set))
            {
              char buf[1024];
              bzero(buf,sizeof(buf));
              ret=recv(connect_host[i],buf,sizeof(buf)-1,0);
              if(ret==0)
              {
                connect_host[i]=-1;
                connect_num--;
              }
              if(ret>0)
              {
                printf("recv:%s\n",buf);
                send(connect_host[i],buf,strlen(buf),0);
              }
            }
          }         
        }
      }
    }
  return NULL;
}

void* handler_connect(void * argv)
{   
    int listensck=*(int*)argv;
    int clientfd;
    struct sockaddr_in client_addr;
    int sockaddr_len;
    int i;
    while(1)
    {
      clientfd=accept(listensck,(struct sockaddr*)&client_addr,&sockaddr_len);
      if(clientfd>0)
      {
         for(i=0;i<NUM;i++)
         {
          if(connect_host[i]==-1)
          {
            connect_host[i]=clientfd;
            connect_num++;
            break;
          }
         }
      }
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
	int sckd=socket(PF_INET,SOCK_STREAM,0);
	if(sckd==-1)
	{
		perror("socket:");
		exit(-1);
	}
	struct sockaddr_in  seraddr;
	bzero(&seraddr,sizeof(seraddr));
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(PORT);
	seraddr.sin_addr.s_addr=inet_addr("192.168.252.3");
	//设置套接字选项(地址重用)
	int value=1;
	setsockopt(sckd,SOL_SOCKET,SO_REUSEADDR,&value,sizeof(sckd));
	//绑定
	if(bind(sckd,(struct sockaddr*)&seraddr,sizeof(seraddr))==-1)
	{
		perror("bind :");
		exit(-1);
	}
	//监听
	if(listen(sckd,10)==-1)
	{
		perror("listen:");
		exit(-1);
	}

  int i;
  for(i=0;i<NUM;i++)
  {
    connect_host[i]=-1;
  }

  pthread_t pthreads[2];
  int ret=pthread_create(&pthreads[0],NULL,handler_connect,(void*)&sckd);
  while(ret==-1)
  {
    ret=pthread_create(&pthreads[0],NULL,handler_connect,(void*)&sckd);
  }
  ret=pthread_create(&pthreads[1],NULL,handler_request,NULL);
  while(ret==-1)
  {
    ret=pthread_create(&pthreads[1],NULL,handler_request,NULL);
  }
  for(i=0;i<2;i++)
  {
    pthread_join(pthreads[i],NULL);
  }
	return 0;
}