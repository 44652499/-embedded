#include <stdio.h>
/*
while   do whiel 循环:
while:先判断条件,再执行循环语句,至少执行0次
do  while:首先执行一次,再判断条件,至少执行1次
*/
int main(int argc, char const *argv[])
{
	//一下情况是死循环
	// while(1)
	// {

	// }
	//for(;;)
	//int i=2;
	//for(;;i++)
	//for(i=3;;)
	//for(i=3;;i++)
	//for(i=3;i<10;)

	int i=4,j=6;
	//for(i=5,j=7;i<10,j<10;i++,j++)
	for(i=5,j=7;j<10,i<10;i++,j++)
	{
		printf("ok\n");
	}
	return 0;
}