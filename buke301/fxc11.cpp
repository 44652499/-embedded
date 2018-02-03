#include <iostream>
using namespace std;
/*
实现单例模式类:
const:
1.只读对象:只读对象数据成员不能修改.只读对象只能调用只读函数成员
2.只读数据成员:
3.只读函数成员:只读函数成员内不能修改数据成员

static:
1.静态对象:一般静态变量,符合静态存储特性
2.静态数据成员:静态数据成员不属于对象,共享与对象.不能用this访问
3.静态函数成员:静态函数成员只能访问静态数据成员
*/
// class A
// {
// private:
// 	const int data;
// public:
// 	A(int _data=0):data(_data)
// 	{
// 		//data=_data;
// 	}
// 	//只读函数成员
// 	int  getdata() const
// 	{
// 		return data;
// 	}
// 	void  fun()
// 	{
// 		cout<<data<<endl;
// 	}
// };

// class A
// {
// //private:
// public:
// 	static int data;//
// 	int a;
// public:
// 	A(int _data=0)
// 	{
// 		//this->data=300;//错误 1.不能用this访问 2.不能在构造函数初始化
// 	}
// 	int  getdata() 
// 	{
// 		return data;
// 	}

// 	static void  fun()
// 	{
//       a=30;
// 	}
	
// };
// int  A::data=20; //初始化静态成员变量,共享于所有对象

class  A
{
private:
	static A * ptr;
	A()
	{

	}
public:
	static A *  createobj()
	{
		//return new A;
		if(ptr==NULL)
		{
			ptr=new A;
		}		
		return ptr;
	}
	void fun()
	{
		cout<<"fun"<<endl;
	}
};

A* A::ptr=NULL;
int main(int argc, char const *argv[])
{
	// const A a1(200);
	// a1.getdata();

	// A a2;
	// //cout<<sizeof(a2)<<endl;
	// //cout<<a2.getdata()<<endl;
	// cout<<a2.data<<endl;
	// cout<<A::data<<endl;

	A* a1=A::createobj();
	a1->fun();
	return 0;
}