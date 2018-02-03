#include <stdio.h>
#include <signal.h>
#include <stdio.h>
void  sig_fun(int signum)
{
  printf("end\n");
}

void mysleep(unsigned int nsec)
{
	struct sigaction  newact,oldact;
	unsigned int unsleep;
	newact.sa_handler=sig_fun;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags=0;
	sigaction(SIGALRM,&newact,&oldact);

	sigset_t newset,oldset,suspset;
	sigemptyset(&newset);
	sigaddset(&newset,SIGALRM);
	sigprocmask(SIG_BLOCK,&newset,&oldset);

	alarm(nsec);

	suspset=oldset;

	sigdelset(&suspset,SIGALRM);
	sigsuspend(&suspset);

	alarm(0);

	sigaction(SIGALRM,&oldact,NULL);

	sigprocmask(SIG_SETMASK,&oldset,NULL);
}

int main(int argc, char const *argv[])
{
	while(1)
	{
		mysleep(2);
		printf("tow seconds passwd\n");
	}
	return 0;
}