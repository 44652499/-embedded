#include <iostream>
using namespace std;
/*
继承赋值兼容问题:
1.派生类对象可以赋值给基类对象
2.基类指针可以指向派生类对象
3.基类引用可以引用派生类对象
*/
class Base1
{
public:
	Base1(int _a)
	{
		cout<<"Base1"<<endl;
		a=_a;
	}
	void  fun()
	{
		cout<<"Base1  fun"<<endl;
	}
private:
	int a;
};
class Child:public Base1
{
public:
	Child(int _a,int _c):Base1(_a)
	{
		c=_c;
	}
private:
	int c;
};
int main(int argc, char const *argv[])
{
	Base1 b1(1);
	Child c1(1,2);
	b1=c1;
	Base1 * ptr1=new Base1(1);
	Base1 * ptr2=new Child(1,2);
	//Child * ptr3=new Base1(1);//错误
	Base1  &b2=c1;
	// Child  &c2=b1;//错误
	b1.fun();
	c1.fun();
	ptr1->fun();
	ptr2->fun();
	b2.fun();
	return 0;
}