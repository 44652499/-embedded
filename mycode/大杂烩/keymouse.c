#include "definefile.h"
void mouse_op(int fd,int rel_x,int rel_y)
{
      struct input_event event;
      gettimeofday(&event.time,0);
      event.type=EV_REL;
      event.value=rel_x;
      event.code=REL_X;
      write(fd,&event,sizeof(event));
      event.type=EV_REL;
      event.value=rel_y;
      event.code=REL_Y;
      write(fd,&event,sizeof(event));

      event.type=EV_SYN;
      event.value=0;
      event.code=SYN_REPORT;
      write(fd,&event,sizeof(event));
}
int main(int argc, char const *argv[]) {
      int fd_mouse=-1;
      int i=0;
      fd_mouse=open("/dev/input/event0",O_RDWR);
      if(fd_mouse<=0)
      {
            perror("open event2:");
            exit(-1);
      }
      for(i=0;i<50;i++)
      {
            mouse_op(fd_mouse,10,10);
            sleep(1);
      }
      close(fd_mouse);
      return 0;
}
