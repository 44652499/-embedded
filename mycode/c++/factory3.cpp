#include <iostream>
using namespace std;
/*
常用的场景
例如Linux和windows两种操作系统下,有2个挂件A和B,他们在Linux和Windows下面的实现方式不同,Factory1负责产生能在Linux下运行的挂件A和B,Factory2负责产生能在Windows下运行的挂件A和B,这样如果系统环境发生变化了,我们只需要修改工厂就行了.
优点
1.封装了产品的创建,使得不需要知道具体是哪种产品,只需要知道是哪个工厂就行了.
2.可以支持不同类型的产品,使得模式灵活性更强.
3.可以非常方便的使用一族中间的不同类型的产品.
*/
class  AbstractProductA
{
public:
	virtual void  operation()=0;
};

class  AbstractProductB
{
public:
	virtual void  operation()=0;
};

class  ProductA1:public  AbstractProductA
{
public:
	void  operation()
	{
		cout<<"ProductA1 operation"<<endl;
	}
};

class ProductA2:public AbstractProductA
{
public:
	void  operation()
	{
		cout<<"ProductA2 operation"<<endl;
	}
};

class ProductB1:public AbstractProductB
{
public:
	void  operation()
	{
		cout<<"ProductB1 operation"<<endl;
	}
};
class ProductB2:public AbstractProductB
{
public:
	void  operation()
	{
		cout<<"ProductB2 operation"<<endl;
	}
};

class AbstractFactory
{
public:
	virtual AbstractProductA * createProductA()=0;
	virtual AbstractProductB * createProductB()=0;
};

class  ConFactory1:public AbstractFactory
{
	AbstractProductA * createProductA()
	{
		return new ProductA1();
	}
	AbstractProductB * createProductB()
	{
		return new ProductB1();
	}
};

class  ConFactory2:public AbstractFactory
{
	AbstractProductA * createProductA()
	{
		return new ProductA2();
	}
	AbstractProductB * createProductB()
	{
		return new ProductB2();
	}
};
int main(int argc, char const *argv[])
{
	AbstractFactory *fa1=new ConFactory1();
	fa1->createProductA()->operation();
	fa1->createProductB()->operation();
	AbstractFactory *fa2=new ConFactory2();
	fa2->createProductA()->operation();
	fa2->createProductB()->operation();
	return 0;
}