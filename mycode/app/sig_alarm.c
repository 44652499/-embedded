#include "define_header_file.h"
int main(int argc, char const *argv[])
{
	// printf("running\n");
    // alarm(2);
	// alarm(5);//非堵塞函数,发送SIGALRM 信号默认动作是结束进程
	// //alarm(2);//覆盖alarm(5)
	// while(1)
	// {
	// 	printf("go on runninig\n");
	// 	sleep(1);
	// 	//alarm(0);//取消
	// }

	//实现输入超时
	char  buf[20];
	alarm(5);
	gets(buf);
	if(strlen(buf)>0)
	{
		alarm(0);
	}
	while(1)
	{

	}
	return 0;
}