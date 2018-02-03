#include "definefile.h"
int main(int argc, char const *argv[])
 {
     int fd, nread, i;
     struct stat sb;
     char *mapped;

/* 打开文件 */
     if ((fd = open(argv[1], O_RDWR)) < 0)
     {
         perror("open");
      }

/* 获取文件的属性 */
     if ((fstat(fd, &sb)) == -1)
     {
         perror("fstat");
      }

/* 私有文件映射将无法修改文件 */
if ((mapped = (char *)mmap(NULL, sb.st_size, PROT_READ |
                PROT_WRITE, MAP_SHARED, fd, 0)) == (void *)-1) {
    perror("mmap");
}

/* 映射完后, 关闭文件也可以操纵内存 */
close(fd);

/* 修改一个字符 */
    mapped[20] = '9';
    return 0;
}
