#include <iostream>
using namespace std;
/*
多态:派生类继承基类,派生类重写(覆盖)基类的虚方法.实现派生类个性.
基类提供统一接口虚函数,派生类都有不同的实现.

实现多态必同时满足如下三个条件:
1.必须是公有继承
2.基类的方法必须是虚方法
3.必须是通过基类指针或引用调用基类方法

虚函数:存储在虚表(vtable),派生类继承虚表覆盖虚表的基类虚函数

覆盖(override):派生类重写基类的虚函数,函数形式完全一样(函数名 参数列表都相同)

重载  覆盖 隐藏区别?
重载:同一个类中函数名相同 参数列表不同
隐藏:
a.派生类中重新定义与基类完全一样非虚方法
b.派生类中重新定义与基类同名函数,参数列表不同方法
覆盖:派生类重写基类的虚函数,函数形式完全一样(函数名 参数列表都相同)
*/
class  Base
{
public:
	virtual void  fun()//定义虚函数
	{
		cout<<"Base fun"<<endl;
	}
};

class  Child :public Base
{
public:
	void  fun()
	{
		cout<<"Child fun"<<endl;
	}
};
int main(int argc, char const *argv[])
{
	Base  *ptr=new Child();//实现多态,调用派生类自身方法
	ptr->fun();
	return 0;
}