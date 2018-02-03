#include <stdio.h>
/*
表达式:
表达式=操作数  and  符号
操作数是一个类型的变量
*/
int main(int argc, char const *argv[])
{
	// int a=20;//整数类型
	// double  b=20;//double=int,可以把类型短赋值给类型长,自动转换
	// //int c=23.45;//int =double ,存在溢出.不建议这样写
	// int  c=(int)23.45;//一般用强制转换
	// printf("%d\n",c);
	// //float  f=34.56;//float=double,
	// float  f=34.56f;//定义浮点数并赋值浮点数
	// long  l=1232345l;//定义长整数
    /*表示中存在多个不同类型操作数,其结果是最长类型*/
	printf("%d\n",4/3);
	printf("%d\n",4/3.0);//4/3.0 结果是double,输出要求是int ,没有强制类型转换
	printf("%d\n",(int)4/3.0);//4/3.0 结果是double,输出要求是int ,没有强制类型转换
	printf("%d\n",(int)(4/3.0));//4/3.0 结果是double,输出要求是int ,用强制类型转换
	printf("%f\n",4/3.0);//double  类型输出
	return 0;
}