#include <stdio.h>
/*
有参数宏定义:宏支持参数形式
#define  F (a,b)  a*b

有参数宏注意事项:
1.实参可以是表达式
2.宏名和参数的括号间不能有空格
3.宏替换只作替换,不做计算,不做表达式求解
4.函数调用在编译后程序运行时进行,并且分配内存.宏替换在编译前进行,不分配内存
5.宏的结合不存在类型,也没有类型转换
6.宏展开使源程序变长,函数调用不会变长
7.宏展开不占运行时间,只占编译时间,函数调用占运行时间(分配内存 保留现场 值传递 返回)

宏使用 特殊符号:#,##
#:表示""括起值
##:表示连接
*/
//#define  F(a,b)  a*b//F是一个无参数的宏
//#define  F(a,b)  a*b //定义不规范
//#define  F2(a,b)  ((a)*(b)) //规范定义,在参数宏中,参数必须用"()",而且整个值都用"()"
//#define  BLOCK_SIZE  (1024*1024*2)
#define  F3(a)  #a
#define  F4(a,b) a##b
//#define  F5(a,b) #(a##b)  //#其后必须接参数

#define E(a,b) a##b 
#define D(a) #a 
#define S(a) D(a) 
int main(int argc, char const *argv[])
{
	//int a=F(1+3,2+4);//先替换,替换完毕后计算  1+3*2+4
	//printf("%d\n",a);
	//int total_size;
	//int block_cnt=total_size/BLOCK_SIZE;

	//char *p=F3(123);
	//int data=F4(123,456);
	//int data=F5(123,456);

	D(E(a,b)); //"E(a,b)"
    S(E(a,b)); // "ab"
	return 0;
}