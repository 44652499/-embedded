#include <iostream>
using namespace std;
/*
多继承是基类方法命名冲突问题

钻石菱形问题
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
class Base2
{
public:
	Base2(int _b)
	{
		cout<<"Base2"<<endl;
		b=_b;
	}
	void  fun(int a)
	{
		cout<<"Base2  fun"<<endl;
	}
private:
	int b;
};
class Child:public  Base2,public Base1
{
public:
	Child(int _a,int _b,int _c):Base2(_a),Base1(_b)
	{
		c=_c;
	}
private:
	int c;
};
int main(int argc, char const *argv[])
{
	Child  c1(1,2,3);
	//c1.fun();//错误,派生类对象分别存在Base1,Base2对象,且两个基类都有一个共同方法.派生类无法确定方法
	//c1.Base1::fun();
	//c1.Base2::fun();
	//多个基类方法名一样,就会出现歧义
	return 0;
}