#include <stdio.h>
typedef  int (*p_fun1)(int,int);//p_fun1表示一种类型
/*

*/

int add1(int a,int b)
{
	return (a+b);
}

int add2(int a,int b)
{
	return (a+b);
}

int sub1(int a,int b)
{
	return (a-b);
}

int sub2(int a,int b)
{
	return (a-b);
}
int main(int argc, char const *argv[])
{
	//定义函数指针数组指针
	// int (*(*p_fun)[2])(int,int);
	// printf("%d\n",sizeof(p_fun));//指针变量

	//int (*p_fun2[2])(int,int);
	//printf("%d\n",sizeof(p_fun2));//数组

	// int(*p_fun2[2][2])(int,int);
	//printf("%d\n",sizeof(p_fun2));

	p_fun1 (*p_fun)[2];
	p_fun1 p_fun2[2][2];
	p_fun2[0][0]=add1;
	p_fun2[0][1]=add2;
	p_fun2[1][0]=sub1;
	p_fun2[1][1]=sub2;

	int i,j;
	//p_fun=p_fun2;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			p_fun=p_fun2+i;
			printf("%d\n",(*(*(p_fun)+j))(1,3));//有问题?
		}
	}
	return 0;
}