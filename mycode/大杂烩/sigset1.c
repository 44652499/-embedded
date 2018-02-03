#include <signal.h>
#include <stdio.h>
void  printsigset(sigset_t * set)
{
    int i;
    for(i=1;i<32;i++)
    {
        if(sigismember(set,i)==1)
        {
            putchar('1');
        }
        else
        {
            putchar('0');
        }
    }
    puts("");
}
int main(int argc, char const *argv[]) {
    sigset_t s,p;
    int i=0;
    sigemptyset(&s);
    sigaddset(&s,SIGINT);
    sigaddset(&s,SIGQUIT);
    sigprocmask(SIG_BLOCK,&s,NULL);
    while(1)
    {
        sigpending(&p);
        printsigset(&p);
        if(i==10)
        {
            sigdelset(&s,SIGQUIT);
            sigprocmask(SIG_UNBLOCK,&s,NULL);//mask=mask & ~value
        }
        sleep(1);
        i++;
    }
    return 0;
}
