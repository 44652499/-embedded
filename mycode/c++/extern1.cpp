#include <iostream>
#include "add.h"
using namespace std;
/*
c++ 调用 c库函数
c++中不能直接调用c自定义函数(常规定义)??
c++ 使用编译器g++,g++ 编译之后函数名改变了 原来函数名_参数类型 形成新的函数名.
int add(int ,int )  g++编译之后的函数名是add_int_int
c   使用编译器gcc .gcc 编译前与后函数名不变,
int add(int ,int )  gcc编译之后的函数名是add
在c++ 调用add(3,4)时,在c库函数找不此函数
*/
int main(int argc, char const *argv[])
{
	cout<<add(3,4)<<endl;
	return 0;
}