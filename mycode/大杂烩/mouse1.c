#include "definefile.h"
int main(int argc, char const *argv[])
{
      int fd,retval;
      char buf[6];
      fd_set readfds;
      struct timeval tv;
      fd=open("/dev/input/event2",O_RDONLY);
      if(!fd)
      {
            perror("open:");
            exit(-1);
      }
      while(1)
      {
            FD_ZERO(&readfds);
            FD_SET(fd,&readfds);
            tv.tv_sec=5;
            tv.tv_usec=0;
            if((retval=select(fd+1,&readfds,NULL,NULL,&tv))==1)
            {
                  if(read(fd,buf,6)<=0)
                  {
                        continue;
                  }
                  printf("Button type=%d,X=%d,y=%d\n",(buf[0]&0x07,buf[1],buf[2]));
            }
      }
      close(fd);
      return 0;
}
