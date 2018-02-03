#include <iostream>
using namespace std;
/*
工厂设计模式提供了一个共同的接口来指向新创建的对象,避免用new创建对象
优点: 
1、一个调用者想创建一个对象,只要知道其名称就可以了.
2、扩展性高,如果想增加一个产品,只要扩展一个工厂类就可以.
3、屏蔽产品的具体实现,调用者只关心产品的接口
*/
/*
简单工厂模式:主要特点是需要在共产类中做判断,从而创建相应的产品.当增加新产品时,需要修改工厂类
缺点:需要增加新的类型时,需要修改工厂类.违反了开放封闭原则:软件实体(类、模块、函数)可以扩展,但是不可修改
*/
enum  FRUIT_TYPE{
	APPLE,
	ORANGE
};
class  Fruit
{
public:
	virtual void eat()=0;
};
class Apple :public Fruit
{
public:
	void eat()
	{
		cout<<"eat apple"<<endl;
	}
};

class Orange:public Fruit
{
public:
	void eat()
	{
		cout<<"eat orange"<<endl;
	}
};
//工厂类
// class Factory
// {
// public:
// 	Fruit*  getInstance(FRUIT_TYPE fruit)
// 	{
// 		if(fruit==APPLE)
// 		{
// 			return new Apple();
// 		}
// 		if(fruit==ORANGE)
// 		{
// 			return new Orange();
// 		}
// 		return NULL;
// 	}
// };

//简单工厂抽象类
//工厂方法模式:指定义一个用于创建对象的接口,让子类决定实例化哪一个类
//缺点:当增加一种新产品,就需要创建一个对象的工厂.当新产品很多时,就会有很多的类定义
class  Factory
{
public:
	virtual  Fruit * getInstance()=0;
};
class  FactoryApple:public Factory
{
public:
	Fruit*  getInstance()
	{
		return new Apple();
	}
};
class FactoryOrange:public Factory
{
public:
	Fruit* getInstance()
	{
		return new Orange();
	}
};

//抽象工厂模式:提供一个创建一系列相关或相互依赖对象的接口,而无需指定它们具体的类
//待完成
int main(int argc, char const *argv[])
{
	// Factory  factory_obj;
	// Fruit * f=factory_obj.getInstance(APPLE);
	// f->eat();
	// f=factory_obj.getInstance(ORANGE);
	// f->eat();

	Factory  *factory_obj=new FactoryApple();
	Fruit * f=factory_obj->getInstance();
	f->eat();

	factory_obj=new FactoryOrange();
	f=factory_obj->getInstance();
	f->eat();
	return 0;
}