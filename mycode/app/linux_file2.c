#include  "define_header_file.h"
int main(int argc,const char* argv[])
{
    int fd=open("/dev/tty",FILE_RWB_MODE);
    if(fd==-1)
    {
        SYS_ERROR_INFO("open:");
        return -1;
    }
    char buf[1024];
    int ret=read(fd,buf,sizeof(buf)-1);
    printf("%d\n",ret);
    while(ret==-1 && errno==EAGAIN)
    {
        read(fd,buf,sizeof(buf)-1);
    }
    printf("buf=%s\n",buf);
    // if(ret==-1)
    // {
    //     if(errno==EAGAIN)
    //     {
    //         perror("read:");
    //     }    
    //     else
    //     {
    //         printf("no read\n");
    //     }    
    // }
    //write(fd,buf,strlen(buf));
    close(fd);

    // int fd;
    // int key_value,i=0,count;
    // struct input_event event,press_event;
    // fd = open("/dev/input/event1", O_RDWR);
    // if (fd < 0)
    // {
    //          perror("open device buttons:");
    //          return -1;
    // }
    // char buf[100];
    // while(1)
    // {
    //     if(read(fd, &event, sizeof(event)) == sizeof(event))
    //     {
    //         if (event.type == EV_KEY)
    //         {
    //             //if ( event.value == 1)
    //             {
    //                 bzero(buf,sizeof(buf));
    //                 //sprintf(buf,"%d prssed",event.code);
    //                 printf("key %d %s\n", event.code, (event.value) ? "Pressed" : "Released");
    //                 if(event.code == KEY_ESC)
    //                     break;
    //             }
    //         }
    //     }
    // }   
    close(fd);    
    return 0;
}