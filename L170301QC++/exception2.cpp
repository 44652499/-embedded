#include  <iostream>
#include  <stdlib.h>
using namespace std;
/*
bad_alloc:异常
*/


//new 失败执行函数
void  new_fail()
{
	cout<<"new_fail"<<endl;
	int *p=new int[100];
	abort();//手动结束函数
}

int main(int argc, char const *argv[])
{
	//int *p=new int[1000000];
	//在c++ 判断new 分配内存是否成功,不能用下面语句判断
	// if(p==NULL)
	// {
	// 	cout<<"alloc  fail"<<endl;
	// }

	//使用捕捉异常bad_alloc 判断
	// try
	// {
	// 	int *p=new int[1000000000000];
	// 	//int *p=new(nothrow) int[1000000000000];//不抛出异常
	// }catch(bad_alloc e)
	// {
	// 	cout<<"alloc fail"<<endl;
	// }

	//注册执行函数.new  分配失败.调用执行注册函数
	set_new_handler(new_fail);
	int *p=new int[1000000000000];//new 失败之后 默认死循环执行注册函数
	return 0;
}