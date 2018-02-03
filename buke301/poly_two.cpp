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
纯虚函数:方法体为0的虚函数
如果一个类存在一个纯虚函数,该类称为抽象类.
抽象类不能实例化对象,派生类继承抽象类,
没有 实现继承的函数,派生类也成为抽象类
*/
class  base
{
private:
	int  a;
public:
	base()
	{
		a=10;
	}
	virtual void  fun()=0;
};

class  base2
{
public:
	virtual void  fun()=0;
};

class  child :public base,public  base2
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
	// cout<<sizeof(child)<<endl;//继承每个基类虚表
	// child c;
	// int *ptr=(int*)&c;
	// cout<<*ptr<<endl;//指向第一个基类虚表的指针
	// cout<<*++ptr<<endl;//指向第一个基类的数据成员
	// cout<<*++ptr<<endl;//指向第二个基类虚表

	//base *  ptr=new child();
	base2 *  ptr=new child();
	ptr->fun();
	return 0;
}