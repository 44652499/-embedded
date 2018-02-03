#include  <iostream>
#include  <stdio.h>
#include  "add.h"
// extern "C"
// {
// 	#include  "add.h"
// }
using namespace std;
/*
#define  _cplusplus
extern "C"

c++  调用c  库函数

为什么c++ 调用c  add(1,2) 出错?
c编译之后函数名不变  :add
c++编译之后函数名变成:函数名_参数类型 :add_int_int
c++链接器链接是无法找到add_int_int 函数

extern "C":连接时按照c 链接器找函数
*/
int main(int argc, char const *argv[])
{
	printf("hello\n");
	int ret=add(1,2);
	cout<<ret<<endl;
	return 0;
}