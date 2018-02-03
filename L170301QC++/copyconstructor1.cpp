#include <iostream>
using namespace std;
/*
拷贝构造函数(复制构造函数):构造新对象时,用一个对象作为引用参数.复制参数对象的成员值
类存在一个默认拷贝构造函数

调用拷贝构造函数:
1.对象初始化新对象
2.对象作为函数形参,并且是值传递
3.返回值类型是对象(陈泽斌详细讲解)


类中都存在一个赋值函数
void   operator =(A  & obj)
*/
class A
{
public:
	A()
	{

	}
	A(int _a)
	{
		a=_a;
	}
	//引用类型参数
	A(const A&  obj)
	{
		cout<<"copy constructor"<<endl;
		a=obj.a;
	}
	//赋值函数
	void   operator =( A  & obj)
	{
		cout<<"operator ="<<endl;
		a=obj.a;
	}

	void  printa()
	{
		cout<<a<<endl;
	}
private:
	int a;
};

void   fun(A obj)
{
	obj.printa();
}

A  fun()
{
	static A a(4);
	return a;
}

int main(int argc, char const *argv[])
{
	A a1(3);
	a1.printa();
	//A a2(a1);//参数是另一个对象
	//A a2=a1;//初始化对象
	// A  a2;
	// a2=a1;//赋值
	// a2.printa();

	//fun(a1);

	//fun();
	//A ret=fun();
   const  A& ret2=fun();//fun() 返回时常见一个临时对象,把函数内部对象拷贝给临时对象,临时对象不可以修改
	return 0;
}