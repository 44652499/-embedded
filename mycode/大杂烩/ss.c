#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>  //extern int errno;
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/mman.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <sys/epoll.h>
#define  PAGESIZE 1024
#define PORT1 4567
#define PORT2 7788



 void printsignals(sigset_t* _s1)
  {
  	int i;
  	for(i=1;i<32;i++)
  	{
  		if(sigismember(_s1,i)==1)
  		{
  			putchar('1');
  		}
  		else
  		{
  			putchar('0');
  		}
  	}
  	printf("\n");
  }
 int main(int argc, char const *argv[])
 {

  	sigset_t s1,s2;
  	sigemptyset(&s2);
  	sigaddset(&s2,SIGINT);//ctrl+c
    sigaddset(&s2,SIGTSTP);//ctrl+z
    sigaddset(&s2,SIGQUIT);//ctrl+/
  	sigprocmask(SIG_BLOCK,&s2,NULL);//设置堵塞信号
  	//mask=mask | value
  	int c=0;
  	while(1)
  	{
  		sigpending(&s1);
  		printsignals(&s1);
  		c++;
  		if(c==6)
  		{
  			//sigdelset(&s2,SIGQUIT);
  			//sigprocmask(SIG_UNBLOCK,&s2,NULL);//设置堵塞信号
  		    //mask=mask & ~value
  		}
  		sleep(1);
  	}
  	return 0;
 }