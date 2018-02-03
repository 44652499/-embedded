#include <iostream>
using namespace std;
/*
函数重载(overload):在一个类中,函数名相同,参数列表不同(参数数据类型 个数)
函数重载好处:针对相同功能,减少函数名称不同

c++函数重载没有改变 c语言只能根据函数名区分 本质:
c++编译后对原有函数名作更改:
函数名_第一个参数类型_第二个参数类型_....
int add(int a,int b)  编译后成为:add_int_int
double add(double a,double b)  编译后成为: add_double_double
int add(int a,int b,int c) 编译后成为:add_int_int_int
*/
int add(int a,int b)
{
	return a+b;
}
//返回值不能作为函数重载判断
// double  add(int a,int b)
// {
// 	return a+b;
// }
double add(double a,double b)
{
	return a+b;
}

int add(int a,int b,int c)
{
	return a+b;
}
int main(int argc, char const *argv[])
{
	//调用是根据实参类型和个数匹配一个符合的函数
	cout<<add(10,20)<<endl;
	cout<<add(23.45,67.89)<<endl;
	return 0;
}