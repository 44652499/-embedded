#include <stdio.h>
#include <limits.h>
/*
无符号数 /有符号
signed:最高位是符号位 0:表示正数  1:表示负数
unsigned:不存在符号位,都是数字位
系统类型(基础类型) 32位
  char      1byte
  short     2byte
  int       4byte
  float     4byte
  long      4byte
  double    8byte
  long long  8byte
  char  ch  minvalue=10000000  -128   maxvalue=011111111 127
  计算底层存储是补码
*/
int main(int argc, char const *argv[])
{
	//signed char a;// char a
	//unsigned char b;
	//char  ch=12345;
	printf("%d\t%d\n",SCHAR_MIN,SCHAR_MAX);
	printf("%d\t%d\n",INT_MIN,INT_MAX);
	printf("%d\n",sizeof(long long));//计算空间内存大小
	int  a;
	printf("%d\n",sizeof(int));
	printf("%d\n",sizeof(a));
	printf("%d\n",sizeof a);
	//printf("%d\n",sizeof int);

	printf("%d\n",a);//访问未初始化局部变量值,没有意义.随机值
	return 0;
}
///*IEE754 表示如何定义单精度(float)和双精度(double)*/
