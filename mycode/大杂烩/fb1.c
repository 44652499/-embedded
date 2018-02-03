#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
// //获取终端显示屏幕的分辨率
// int main(int argc, char const *argv[]) {
//       int fd=open("/dev/fb0",O_RDONLY);
//       if(fd==-1)
//       {
//             perror("open /dev/fb0:");
//             exit(-1);
//       }
//
//       struct fb_var_screeninfo fbscreen;
//       ioctl(fd,FBIOGET_VSCREENINFO,&fbscreen);
//       printf("R=%d\tC=%d\n",fbscreen.xres,fbscreen.yres );
//       return 0;
// }

int main(int argc, char const *argv[])
{
      struct winsize s;
      if(isatty(STDIN_FILENO)==0)
      {
            perror("isatty:");
            exit(-1);
      }
      if(ioctl(STDIN_FILENO,TIOCGWINSZ,&s)<0)
      {
            perror("ioctl:");
            exit(-1);
      }
      printf("r=%d\tc=%d\n",s.ws_row,s.ws_col);
      return 0;
}
