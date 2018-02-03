#include <iostream>
using namespace std;
/*
多继承是基类方法命名冲突问题

钻石菱形问题

虚基类解决钻石菱形问题
*/
class  Base
{
public:
	void  fun()
	{
		cout<<"Base1  fun"<<endl;
	}
};
class Base1:virtual public Base
{
public:
	Base1(int _a):Base()
	{
		cout<<"Base1"<<endl;
		a=_a;
	}	
private:
	int a;
};
class Base2:virtual public Base
{
public:
	Base2(int _b):Base()
	{
		cout<<"Base2"<<endl;
		b=_b;
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
	cout<<sizeof(Base)<<endl;//空类大小为1
	cout<<sizeof(Base1)<<endl;//Base1 类多分配4字节指针,指向基类对象
	cout<<sizeof(Base2)<<endl;//Base2 类多分配4字节指针,指向基类对象
	cout<<sizeof(Child)<<endl;//Child 类继承Base1  Base2存在两个指针指向基类对象
	//c1.fun();
	return 0;
}