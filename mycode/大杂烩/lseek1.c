#include "definefile.h"
int main(int argc, char const *argv[])
{
      int fd=open("lseek.txt",O_RDONLY);
      if(fd<0)
      {
            perror("open:");
            exit(-1);
      }
      //lseek(fd,3,SEEK_END);
      lseek(fd,-3,SEEK_END);
      char buf[1024];
      int len=read(fd,buf,sizeof(buf-1));
      buf[len]='\0';
      printf("len=%d\t%s\n",len,buf);
      close(fd);
      return 0;
}
