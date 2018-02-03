// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <errno.h>
// #define MSG  "try again\n"
// #define TIMEOUT  "time out\n"
// int main(int argc, char const *argv[]) {
// char buf[10];
//  int n,i;
//   int fd=open("/dev/tty",O_RDONLY|O_NONBLOCK);
// //  int fd=open("/dev/stdin",O_RDONLY|O_NONBLOCK);
// //  int fd=open("/dev/stdin",O_RDONLY);
// //int fd=open("/dev/stdin",O_WRONLY);
//   if(fd==-1)
//   {
//       perror("main open:");
//       exit(-1);
//   }
//   // printf("fd=%d\n",fd);
//   // n=read(fd,buf,sizeof(buf)-1);
//   // buf[n]='\0';
//   // write(STDOUT_FILENO,buf,strlen(buf));
//   //tryagain:
//   for(i=0;i<5;i++)
//   {
//     n=read(fd,buf,10);
//     if(n>=0)
//       break;
//       if(errno!=EAGAIN)
//       {
//          printf("main read:%s",strerror(errno));
//          exit(-1);
//       }
//       sleep(1);
//       write(STDOUT_FILENO,MSG,strlen(MSG));
//   }
//   if(i==5)
//   {
//       write(STDOUT_FILENO,TIMEOUT,strlen(TIMEOUT));
//   }
//   else
//   {
//         write(STDOUT_FILENO,MSG,strlen(MSG));
//   }
// //  write(STDOUT_FILENO,buf,n);
//   close(fd);
//   return 0;
// }


// /dev/fb0
// #include <unistd.h>
// #include <stdio.h>
// #include <fcntl.h>
// #include <linux/fb.h>
// #include <sys/mman.h>
// #include <stdlib.h>
// #include <errno.h>
// int main ()
// {
// int fp=0;
// struct fb_var_screeninfo vinfo;
// struct fb_fix_screeninfo finfo;
// fp = open ("/dev/fb0",O_RDWR);
// if (fp < 0)
// {
// printf("Error : Can not open framebuffer device\n");
// perror("main:");
// exit(1);
// }
// if (ioctl(fp,FBIOGET_FSCREENINFO,&finfo))
// {
// printf("Error reading fixed information\n");
// exit(2);
// }
// if (ioctl(fp,FBIOGET_VSCREENINFO,&vinfo))
// {
// printf("Error reading variable information\n");
// exit(3);
// }
// printf("The mem is :%d\n",finfo.smem_len);
// printf("The line_length is :%d\n",finfo.line_length);
// printf("The xres is :%d\n",vinfo.xres);
// printf("The yres is :%d\n",vinfo.yres);
// printf("bits_per_pixel is :%d\n",vinfo.bits_per_pixel);
// close (fp);
// }

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <stdlib.h>
int main ()
{
int fp=0;
struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;
long screensize=0;
char *fbp = 0;
int x = 0, y = 0;
long location = 0;
fp = open ("/dev/fb0",O_RDWR);
if (fp < 0)
{
printf("Error : Can not open framebuffer device/n");
exit(1);
}
if (ioctl(fp,FBIOGET_FSCREENINFO,&finfo))
{
printf("Error reading fixed information/n");
exit(2);
}
if (ioctl(fp,FBIOGET_VSCREENINFO,&vinfo))
{
printf("Error reading variable information/n");
exit(3);
}
screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
fbp =(char *) mmap (0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fp,0);
if ((int) fbp == -1)
{
printf ("Error: failed to map framebuffer device to memory./n");
exit (4);
}
x = 100;
y = 100;
location = x * (vinfo.bits_per_pixel / 8) + y * finfo.line_length;
*(fbp + location) = 100;
*(fbp + location + 1) = 15;
*(fbp + location + 2) = 200;
*(fbp + location + 3) = 0;
munmap (fbp, screensize);
close (fp);
return 0;
}
