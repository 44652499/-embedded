#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#define MAXFILE  65535
volatile sig_atomic_t  running=1;
int fd;
void sig_handler(int signo)
{
   close(fd);
   running=0;
}

int main(int argc, char const *argv[])
{
  pid_t pid;
  pid=fork();//在Shell终端里造成一程序已经运行完毕的假象。之后的所有工作都在子进程中完成 从而在形式上做到了与控制终端的脱离
  if(pid<0)
  	exit(-1);
  if(pid>0)
  	exit(-1);
  // pid=setsid();
  // //让进程摆脱原会话的控制 让进程摆脱原进程组的控制 让进程摆脱原控制终端的控制
  // if(pid<0)
  // {
  // 	perror("setsid:");
  // 	exit(-1);
  // }
  chdir("/tmp");
  umask(0);
  int i;
  int  flag=1;
  char *buf="this is a daemon!";
  for(i=0;i<MAXFILE;i++)
  {
  	close(i);
  }
  signal(SIGTERM,sig_handler);
  while(running)
  {
     if(flag==1)
     {
        fd=open("daemon.log",O_CREAT|O_WRONLY|O_APPEND,0600);
        if(fd<0)
        {
        	perror("open:");
        	exit(-1);
        }
        flag=0;
     }
     write(fd,buf,strlen(buf));
     usleep(10*1000);
  }
  return 0;
}


// int writemsg()
// {
//     //int ret=creat("msg",0777);
//     //这个函数有问题,不管文件是否存不存在都是返回大于0的值,所以每次都创建了文件(删除之前创建的文件)
//     //printf("ret=%d",ret);
//     //还是按照如下写法
//     int fd=open("msg",O_CREAT|O_EXCL|O_RDWR|O_APPEND,0777);
//     if(fd==-1)
//     {
//       if(errno==EEXIST)
//       {
//         fd=open("msg",O_RDWR|O_APPEND);
//       }
//     }
//     char buf[1024];
//     gets(buf);
    
//     write(fd,buf,strlen(buf));
//     close(fd);
//     return;
// }

// int main(int argc, char const *argv[])
// {
//   // int fd=open("append.txt",O_CREAT|O_EXCL|O_RDWR|O_APPEND,0777);
//   // if(fd==-1)
//   // {
//   //   if(errno==EEXIST)
//   //   {
//   //     fd=open("append.txt",O_RDWR|O_APPEND);
//   //   }
//   // }
//   // char buf[1024];
//   // gets(buf);
//   // write(fd,buf,strlen(buf));
//   writemsg();
//   return 0;
// }