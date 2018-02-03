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
        return;//从主函数中返回,释放主函数的栈(进程栈),vfork是父子进程共享空间,子进程返回释放,父进程运行时已经没有栈
    }
    if(pid>0){
        printf("parent process pid=%d\n",getpid());
    }
    return 0 ;
}
