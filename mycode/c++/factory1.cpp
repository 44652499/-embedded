#include <iostream>
using namespace std;
/*
常用的场景
例如部署多种数据库的情况,可能在不同的地方要使用不同的数据库,此时只需要在配置文件中设定数据库的类型,每次再根据类型生成实例,这样,不管下面的数据库类型怎么变化,在客户端看来都是只有一个AbstractProduct,使用的时候根本无需修改代码.提供的类型也可以用比较便于识别的字符串,这样不用记很长的类名,还可以保存为配置文件.
这样,每次只需要修改配置文件和添加新的产品子类即可.
所以简单工厂模式一般应用于多种同类型类的情况,将这些类隐藏起来,再提供统一的接口,便于维护和修改.
优点
1.隐藏了对象创建的细节,将产品的实例化推迟到子类中实现.
2.客户端基本不用关心使用的是哪个产品,只需要知道用哪个工厂就行了,提供的类型也可以用比较便于识别的字符串.
3.便添加新的产品子类,每次只需要修改工厂类传递的类型值就行了.
4.遵循了依赖倒转原则.
*/
class  Product
{
public:
	virtual void  operation()=0;
};
class ProductA:public Product
{
public:
	void  operation()
	{
		cout<<"ProductA operation"<<endl;
	}
};
class ProductB:public Product
{
public:
	void  operation()
	{
		cout<<"ProductB operation"<<endl;
	}
};
class ProductC:public Product
{
public:
	void  operation()
	{
		cout<<"ProductC operation"<<endl;
	}
};
class Factory
{
public:
	 Product * createProduct(string objname)
	 {
	 	if(objname=="ProductA")
	 	{
	 		return new ProductA();
	 	}
	 	if(objname=="ProductB")
	 	{
	 		return new ProductB();
	 	}
	 	if(objname=="ProductC")
	 	{
	 		return new ProductC();
	 	}
	 }
};
int main(int argc, char const *argv[])
{
	Factory *fa=new Factory();
	Product * pa=fa->createProduct("ProductA");
	pa->operation();
	pa=fa->createProduct("ProductB");
	pa->operation();
	pa=fa->createProduct("ProductC");
	pa->operation();
	return 0;
}