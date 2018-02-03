#include <stdio.h>
//int main(int argc, char const *argv[])
main(int argc, char const *argv[])
{
	// int a=10;
	// //if(a==10)
	// //if(a=0)//赋值处理
	// //常数与变量比较
	// if(1==a)//防止出现  a=0   写法错误
	// //if(1=a)
	// {
	// 	printf("ok\n");
	// }
	// else
	// {
	// 	printf("error\n");
	// }
    /*避免出现过多if else 配对 嵌套*/
	int a=20;
	// if(a>5)
 //    {
 //    	printf("a>5\n");
 //    }
 //    else if(a>10)
 //    {
 //    	printf("a>10\n");
 //    }
 //    else if(a>15)
 //    {
 //    	printf("a>15\n");
 //    }
 //    else
 //    {
 //    	printf("a>20\n");
 //    }
	//简化成如下的写法
	if(a>5)
	{
		printf("a>5\n");
		return;
	}
	if(a>10)
	{
		printf("a>10\n");
		return;
	}
	if(a>15)
	{
		printf("a>15\n");
		return;//退出当前的函数执行,由于当前的函数为main,退出main函数相当于结束进程
	}
	printf("a>20\n");
	return 0;
}