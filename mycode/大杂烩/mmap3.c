#include "definefile.h"
//mmap��������
// int main(int argc, char const *argv[])
//  {
//     char    *p_map;
//     /* ����ӳ��,����һ���ڴ湩���ӽ���ͨ�� */
//     p_map = (char *)mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE,
//             MAP_SHARED | MAP_ANONYMOUS, -1, 0);
//     if(fork() == 0)
//      {
//         sleep(1);
//         printf("child got a message: %s\n", p_map);
//         sprintf(p_map, "%s", "hi, dad, this is son");
//         munmap(p_map, BUF_SIZE); //ʵ���ϣ�������ֹʱ�����Զ����ӳ�䡣
//         exit(0);
//     }
//     sprintf(p_map, "%s", "hi, this is father");
//     sleep(2);
//     printf("parent got a message: %s\n", p_map);
//     return 0;
// }


//mmapӳ����ڴ������������ҳ���С
int main(int argc, char const *argv[])
 {
     int fd,i;
     int pagesize,offset;
     char *p_map;
     struct stat sb;

    /* ȡ��page size */
    pagesize = sysconf(_SC_PAGESIZE);
    printf("pagesize is %d\n",pagesize);

    /* ���ļ� */
    fd = open(argv[1], O_RDWR, 00777);
    fstat(fd, &sb);
    printf("file size is %zd\n", (size_t)sb.st_size);

    // offset = 0;
    // p_map = (char *)mmap(NULL, pagesize , PROT_READ|PROT_WRITE,MAP_SHARED, fd, offset);
    // close(fd);
    // p_map[sb.st_size] = '9';  //������ͬһ��ҳ�������,���ܳ�������ҳ����,��Ϊ����ҳ���ж������±�Ϊsb.st_sizeֵ
    // p_map[pagesize-1] = '9';

    // p_map = (char *)mmap(NULL, sb.st_size, PROT_READ|PROT_WRITE,MAP_SHARED, fd, offset);
    //close(fd);
    // p_map[sb.st_size] = '5';
    // printf("%s\n",p_map);


   offset = 0;
   p_map = (char *)mmap(NULL, 2*pagesize , PROT_READ|PROT_WRITE,MAP_SHARED, fd, offset);
   close(fd);
   p_map[sb.st_size] = '9';//���ߴ���
   p_map[pagesize-1] = '9';//�δ���
    munmap(p_map, pagesize * 2);

    return 0;
}
