#include  <iostream>
using namespace std;
/*
异常:是在程序在执行时发生错误.run time error
异常从发生到处理实现:
1.抛出异常
2.捕捉异常
3.处理异常
抛出异常:throw
c++ 异常实质就是一种数据类型(表示异常错误类型).有系统定义好的异常类型,也有自定义异常类型.
系统定义类型:exception(异常基类)  logic_error逻辑异常  bad_alloc(内存分配异常)等
抛出异常 throw 异常类型;
捕捉异常:
try
{
	//抛出异常的语句
}
处理异常(执行发生异常之后的语句)
catch(异常类型)
{
	//异常执行语句
}
档捕捉的到异常发生后,停止往下执行,立即跳转到执行catch中的语句
*/

// int  div(int x,int y)//可以抛出任意异常
// {
// 	return x/y;
// }

// int  div(int x,int y) throw(int,double)//可以出抛出正数类型异常
// {
// 	if(y==0)
// 		throw 4;//抛出异常
//     if(y==2)
//     	throw 2.3;
//     cout<<"div"<<endl;
// 	return x/y;
// }

int  div(int x,int y) throw()//不抛出任何异常
{
	// if(y==0)
	// 	throw 4;//在div 中不能 抛出异常,否则程序终止
 //    if(y==2)
 //    	throw 2.3;
    cout<<"div"<<endl;
	return x/y;
}

int main(int argc, char const *argv[])
{
	try
	{
		cout<<div(2,0)<<endl;
		cout<<"main div"<<endl;
	}
	catch(int obj)//捕捉异常
	{
		cout<<obj<<endl;
		cout<<"div  zero  error"<<endl;
	}	
	catch(double obj)//捕捉异常
	{
		cout<<obj<<endl;
		cout<<"div  zero  error"<<endl;
	}
	cout<<"main go on"<<endl;	
	return 0;
}