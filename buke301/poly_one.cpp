#include <iostream>
using namespace std;
/*
多态:相同的方法在不同类中从存在不同实现.主要使用基类与派生类之间
派生类可以重写基类的方法(替换虚表中的基类虚函数)
多态三个必要条件:
1.公有继承
2.基类的指针或引用派生类对象
3.基类的函数必须是虚函数

虚函数:virtual 修饰的函数.存在虚表中的函数.可以被派生类重写

*/
class  base
{
public:
	virtual void  fun()
	{
		cout<<"base fun"<<endl;
	}
};
class  child :public base
{
public:
	virtual  void  fun()
	{
		cout<<"child fun"<<endl;
	}
};

class  child2 :public base
{
public:
	virtual  void  fun()
	{
		cout<<"child2 fun"<<endl;
	}
};
int main(int argc, char const *argv[])
{
	base *ptr=new child;
	ptr->fun();
	ptr=new child2();
	ptr->fun();	

	// cout<<sizeof(base)<<endl;
	// cout<<sizeof(child)<<endl;
	// cout<<sizeof(child2)<<endl;
	// return 0;
}