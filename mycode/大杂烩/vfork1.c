#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
    // printf("end");
    // //exit(0);
    // _exit(0);

    //pid_t pid=vfork();
    pid_t pid=fork();
    if(pid==0){
        printf("child process pid=%d\n",getpid());
        printf("child process ppid=%d\n",getppid());
        //exit(0);
        return;//���������з���,�ͷ���������ջ(����ջ),vfork�Ǹ��ӽ��̹���ռ�,�ӽ��̷����ͷ�,����������ʱ�Ѿ�û��ջ
    }
    if(pid>0){
        printf("parent process pid=%d\n",getpid());
    }
    return 0 ;
}
