#include "definefile.h"
int main(void)
{
    int fd, save_fd;
    char msg[] = "This is a test\n";

    fd = open("duptestfile", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    if(fd<0)
    {
       perror("open");
       exit(1);
    }
    save_fd = dup(STDOUT_FILENO);
   dup2(fd, STDOUT_FILENO);
   close(fd);
   write(STDOUT_FILENO, msg, strlen(msg));//写文件
   dup2(save_fd, STDOUT_FILENO);
   write(STDOUT_FILENO, msg, strlen(msg));//输出到屏幕上
   close(save_fd);
   return 0;
}
