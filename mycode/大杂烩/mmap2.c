#include "definefile.h"
int main(int argc, char const *argv[])
 {
     int fd, nread, i;
     struct stat sb;
     char *mapped;

/* ���ļ� */
     if ((fd = open(argv[1], O_RDWR)) < 0)
     {
         perror("open");
      }

/* ��ȡ�ļ������� */
     if ((fstat(fd, &sb)) == -1)
     {
         perror("fstat");
      }

/* ˽���ļ�ӳ�佫�޷��޸��ļ� */
if ((mapped = (char *)mmap(NULL, sb.st_size, PROT_READ |
                PROT_WRITE, MAP_SHARED, fd, 0)) == (void *)-1) {
    perror("mmap");
}

/* ӳ�����, �ر��ļ�Ҳ���Բ����ڴ� */
close(fd);

/* �޸�һ���ַ� */
    mapped[20] = '9';
    return 0;
}
