#include <stdio.h>
#include <signal.h>
// int is_over=1;
// void   signal_fun(int sig_num)
// {
// 	is_over=0;
// }
// int main(int argc, char const *argv[])
// {
// 	srand(time(NULL));
// 	signal(SIGINT,signal_fun);
// 	int data;
// 	while(is_over)
// 	{
// 		data=rand()%100;
// 	    printf("当前抽奖编号:%d\n",data);
// 	    usleep(500);
// 	}
// 	system("echo  -e '\033c'");
// 	printf("本次中奖号码为:%d\n",data);	
// 	return 0;
// }

int main(int argc, char const *argv[])
{
	int a;
	a=1;
	//scanf("%d",a);
	printf("%d\n",a);
	return 0;
}
