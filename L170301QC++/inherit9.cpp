#include <iostream>
using namespace std;
/*
隐藏:派生类重新定义基类的方法
1.函数名  参数完全与基类一样
2.函数名 相同 参数不同
隐藏于重载区别:
1.重载在统一类作用域,隐藏在不同类作用域
2.重载 函数名相同 参数列表不同,隐藏只要是函数名一样

隐藏结果:
1.基类指针指向派生类对象或引用派生类对象,通过指针调用方法.隐藏派生类的方法.调用基类方法
2.派生类指针或引用派生类对象,调用方法,隐藏基类的方法.调用派生类方法
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
	//派生类中重新定义一个基类一样的方法
	void  fun()
	{
		cout<<"child  fun"<<endl;
	}
	void  fun(int a)
	{
		cout<<"child fun int"<<endl;
	}
private:
	int c;
};
int main(int argc, char const *argv[])
{
	Base1 b1(1);
	Child c1(1,2);
	Base1 * ptr1=new Base1(1);
	Base1 * ptr2=new Child(1,2);
	Base1  &b2=c1;
	ptr1->fun();//基类方法,隐藏派生类方法
	ptr2->fun();
	b2.fun();
	c1.fun();//派生类方法,隐藏就类方法
	ptr2->fun(20);//隐藏派生类的方法,调用基类方法,但基类没有此方法
	return 0;
}