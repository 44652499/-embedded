#include <iostream>
#include <string.h>
using namespace std;
/*
拷贝构造函数:

*/

class A
{
private:
	int data;
public:
    A(int _data=0)
	{
		data=_data;
	}
	A(const A& obj)
	{
		data=obj.data;
		cout<<"copy constructor"<<endl;
	}
	void  operator =(A &obj)
	{
		data=obj.data;
		cout<<"operator ="<<endl;
	}
	int  getdata()
	{
		return data;
	}
};
//函数形参值传递,调用拷贝构造函数
void fun(A  a1)
{
	cout<<"fun"<<endl;
}

A  fun2()
{
	A a2(300);
	return a2;
}

int main(int argc, char const *argv[])
{
	A  a1(200);
	//A  a2(a1);//调用拷贝构造函数
    //A  a2=a1;//调用拷贝构造函数
    //A  a2;
    //a2=a1;//赋值函数
	//cout<<a2.getdata()<<endl;
	//fun(a1);
	A  a3=fun2();//A(const A& obj) 要求形参必须只读,
	//fun2返回后生成一个临时对象,拷贝给a3,临时对象只读
	return 0;
}