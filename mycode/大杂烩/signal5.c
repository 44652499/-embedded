#include <signal.h>
#include <stdio.h>
void printsigset(sigset_t *p)
{
   int i=0;
   for(i=1;i<32;i++)
   {
      if(sigismember(p,i))
      {
      	putchar('1');
      }
      else
      {
      	putchar('0');
      }
   }
   putchar('\n');
}
int main(int argc, char const *argv[])
{
	sigset_t  s,p;
	int i=0;
	sigemptyset(&s);
	sigaddset(&s,SIGINT);
	sigaddset(&s,SIGQUIT);
	sigaddset(&s,SIGTSTP);
	sigprocmask(SIG_BLOCK,&s,NULL);
	while(1)
	{
		sigpending(&p);
		printsigset(&p);
//		if(i==20)
//		{
         //sigdelset(&p,SIGTSTP);
  //       sigprocmask(SIG_UNBLOCK,&s,NULL);
//		}
		sleep(1);
		i++;
	}
	return 0;
}
