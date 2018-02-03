#include <stdio.h>
//输出两个数的最大值与最小值
#define  MAX(a,b)  ((a)>=(b)?(a):(b))
#define  MIN(a,b)  ((a)>=(b)?(b):(a))
//不建议 定义长语句宏.尽量用"\"
#define  MAX_NEW(a,b) if((a)>(b)) \
                        printf("%d\n",(a)) ; \
                      else  \
                      	printf("%d\n",(b));
 //把小写字母转换成大写
 #define TOUPPER(a)  ((a)>='a' && (a)<='z')?(a)-32:(a)
 //判断是否是十进制数字字符
 #define  ISDIGIT(a) ((a)>='0' && (a)<='9')?1:0
 //判断是否是16进制字符
 #define ISHEX(a)  (((a)>='0' && (a)<='9')||(((a)>='a' && (a)<='f')  || ((a)>='A' && (A)<'F'))) ?1:0   
//输出数组的元素的个数
#define  ARRAYELEMENTS(a)  sizeof(a)/sizeof(a[0])     
//计算一年的秒数
#define  SECONDS   (365*24*60*60L)
int main(int argc, char const *argv[])
{

	int a=3,b=5;
	//MAX_NEW(a,b);
	printf("%c\n",TOUPPER('b'));
	unsigned long  a=12l;
	return 0;
}