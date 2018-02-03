#include "definefile.h"
//mmap匿名操作
// int main(int argc, char const *argv[])
//  {
//     char    *p_map;
//     /* 匿名映射,创建一块内存供父子进程通信 */
//     p_map = (char *)mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE,
//             MAP_SHARED | MAP_ANONYMOUS, -1, 0);
//     if(fork() == 0)
//      {
//         sleep(1);
//         printf("child got a message: %s\n", p_map);
//         sprintf(p_map, "%s", "hi, dad, this is son");
//         munmap(p_map, BUF_SIZE); //实际上，进程终止时，会自动解除映射。
//         exit(0);
//     }
//     sprintf(p_map, "%s", "hi, this is father");
//     sleep(2);
//     printf("parent got a message: %s\n", p_map);
//     return 0;
// }


//mmap映射的内存必须是整数倍页面大小
int main(int argc, char const *argv[])
 {
     int fd,i;
     int pagesize,offset;
     char *p_map;
     struct stat sb;

    /* 取得page size */
    pagesize = sysconf(_SC_PAGESIZE);
    printf("pagesize is %d\n",pagesize);

    /* 打开文件 */
    fd = open(argv[1], O_RDWR, 00777);
    fstat(fd, &sb);
    printf("file size is %zd\n", (size_t)sb.st_size);

    // offset = 0;
    // p_map = (char *)mmap(NULL, pagesize , PROT_READ|PROT_WRITE,MAP_SHARED, fd, offset);
    // close(fd);
    // p_map[sb.st_size] = '9';  //必须在同一个页面中完成,不能出现两个页面中,因为两个页面中都存在下标为sb.st_size值
    // p_map[pagesize-1] = '9';

    // p_map = (char *)mmap(NULL, sb.st_size, PROT_READ|PROT_WRITE,MAP_SHARED, fd, offset);
    //close(fd);
    // p_map[sb.st_size] = '5';
    // printf("%s\n",p_map);


   offset = 0;
   p_map = (char *)mmap(NULL, 2*pagesize , PROT_READ|PROT_WRITE,MAP_SHARED, fd, offset);
   close(fd);
   p_map[sb.st_size] = '9';//总线错误
   p_map[pagesize-1] = '9';//段错误
    munmap(p_map, pagesize * 2);

    return 0;
}
