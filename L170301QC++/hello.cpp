/*
c++=  __cplusplus
#ifdef __cplusplus
#endif
c是一种面向过程编程语言
c++是一种高级面向对象编程语言
面向对象(OOP):用一种抽象思想描述任何实物.从实物存在属性(变量)和行为动作(函数)
面向对象4大特点:
a.封装
b.继承
c.多态
d.唯一性

c++程序=c++头文件(.h)+c++ 源文件(.cpp  .cxx)
标准c++ 使用编译器:g++
*/
#include  <iostream>
#include  <stdio.h>
using namespace std;//使用系统的命名空间
//命名空间管理工程类名 函数名 变量重复问题
int main(int argc, char const *argv[])
{
	// cout<<"hello world"<<endl;
	// cout<<23<<endl;
	// cout<<34.56<<endl;
	//cout:标准输出流的对象(变量)
	//"<<"输出符号
	//endl:换行"\n"
    //"::"域限制符号
	// std::cout<<"hello world"<<std::endl;
	// std::cout<<23<<std::endl;
	// std::cout<<34.56<<std::endl;

	// int a;
	// float b;
	// double c;
	// char ch[20];
	// cin>>a>>b>>c>>ch;
	// //cin>标准输入流的对象
	// //">>"输入符号
	// cout<<a<<'\t'<<b<<'\t'<<c<<'\t'<<ch<<endl;

	unsigned int a=6;
	int b=20;
	printf("%d\n",a-b);
	cout<<a-b<<endl;//真正底层计算结果
	return 0;
}