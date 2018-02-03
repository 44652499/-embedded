#include <iostream>
using namespace std;
/*
c++实现动态创建对象(分配内存)使用:
new/delete 符号 new operator
new[]/delete[]  符号  new[] operator
new:分配一块空间
new[]:分配一段连续内存空间
delete:释放一块空间
delete[]:释放一段连续内存空间

new/delete是系统基础类型与 new[]/delete[] 没有区别
如果是自定义数据类型:
new:分配内存空间,调用自定义类型的构造函数初始化
delete :调用自定义类型析构函数,释放空间
new[]:分配内存空间,多次调用自定义类型的构造函数初始化
delete[]:多次调用自定义类型析构函数,释放空间
*/
int main(int argc, char const *argv[])
{
	
	//int *p=new int;//p指向堆上4个字节空间, 初始值为0
	//cout<<*p<<endl;

	//int * p=new int(10);//p指向堆上4个字节空间, 指定初始值为10
	//一下判断错误
	// if(p==NULL)
	// {
	// 	cout<<"fail"<<endl;
	// 	return;
	// }
	//c++ 如何判断内存是否分配成功??
	// cout<<*p<<endl;
	// delete  p;//释放一块空间
	// cout<<*p<<endl;//清0 处理
	// p=NULL;
	// cout<<*p<<endl;

	int* p=new int[10];//分配一段连续内存空间sizeof(int)*10
	int i;
	for(i=0;i<10;i++)
	{
		p[i]=i+1;
		cout<<p[i]<<'\t';
	}
	cout<<endl;

	//delete[]  p;//释放一段空间
	//疑问点:释放是如何知道释放块数?
	//答疑:int* p=new int[10];  分配时多分配4个字节,存储单元数
	//p=NULL;

	//delete p;//语法可以,存在泄漏
	//p=NULL;

	int *ptr=new int;
	delete[] ptr;//正确,系统基础类型delete[]可以释放new 分配空间 
	ptr=NULL;
	return 0;
}