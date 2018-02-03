#include <iostream>
using namespace std;
/*
c++设计模式:设计模式表现的是软件设计思想(软件设计精髓),实现软件高内聚 低耦合 扩展性
设计模式更多是针对大型工程软件
c++23种设计模式,常用的:
1.单例模式
2.工厂模式(抽象工厂模式)
3.构建模式
4.桥接模式
5.观察者模式
6.适配器模式
7.原型模式
8.组合模式

单例模式:只能构造一个对象,通过该对象调用类的成员方法.减少对象创建,降低内存分配.多线程操作非安全性
*/
class  single
{
public:
	static single *  createSingleObj()
	{
		single *  ptr_single=NULL;
		if(sptr_single==NULL)
		{
         	ptr_single=new single();
		}
		return ptr_single;
	}
private:
	single()
	{

	}
	static  single * sptr_single;
};
single * single::sptr_single=NULL;
int main(int argc, char const *argv[])
{
	single*  sobj1=single::createSingleObj();
	single*  sobj2=single::createSingleObj();
	single*  sobj3=single::createSingleObj();
	return 0;
}