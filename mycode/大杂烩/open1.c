#include "definefile.h"
int main(int argc, char const *argv[])
{
   //int fd=open("open1.txt",O_CREAT|O_EXCL|O_WRONLY,0777);
   int fd=open("open1.txt",O_WRONLY,0744);
   close(fd);
   unlink("open1.txt");
    return 0;
}
