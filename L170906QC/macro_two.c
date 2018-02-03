//#include  <stdio.h>
//#define  A  20
//#define  A  20  30
//#define  A20  //A20为宏变量名称
///#define N 20
//#define NAME  "abcd"
/*
宏变量:在预编译时用值替换变量.
定义宏变量:
#define  宏变量名  值
宏变量定义优点其注意项:
1.宏名一般用大写
2.使用宏可提高程序的通用性和易读性,减少不一致性,减少输入错误和便于修改.例如:数组大小常用宏定义
3.宏定义末尾不加分号;
4.字符串"" 中永远不包含宏
5.宏定义不分配内存,变量定义分配内存.
6.宏定义不存在类型问题,它的参数也是无类型的

头文件如下语句作用:
ifndef _AA_
#define _AA_
#endif
防止头文件被多次重复加载
 */
#include "macro_one_test.h"
#include "macro_two_test.h"
int main(int argc, char const *argv[])
{
	//int i_a=A;
	//int i_a=20;
	//int array[N];
	//int i_b="A";
	//char *p=NAME;
	return 0;
}