#include "definefile.h"
int main(int argc, char const *argv[]) {
    if(argc<3)
    {
        printf("parameter error\n");
        exit(-1);
    }
    int ret=kill((pid_t)atoi(argv[2]),atoi(argv[1]));
    if(ret==-1)
    {
        perror("kill:");
        exit(-1);
    }
    return 0;
}

//[lizhanglin@localhost mycode]$ ./while1 &
//[lizhanglin@localhost mycode]$ ./mykill 11 29674
//[lizhanglin@localhost mycode]$ ./mykill 9 29674


//[lizhanglin@localhost mycode]$ ./while1
//����ctrl+z
//[1]+  Stopped                 ./while1

//[lizhanglin@localhost mycode]$ ./while1
//����ctrl+c

//[lizhanglin@localhost mycode]$ ./while1
//����ctrl+\

//[root@localhost mycode]$ ./mykill 9 -1(���н���)�ػ�
//[lizhanglin@localhost mycode]$sudo  ./mykill 9 -1(���н���)�ػ�
