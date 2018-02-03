#include <iostream>
using namespace std;
/*
常用的场景
基本与简单工厂模式一致,只不过是改进了简单工厂模式中的开放-封闭原则的缺陷,使得模式更具有弹性.将实例化的过程推迟到子类中,由子类来决定实例化哪个.
优点
基本与简单工厂模式一致,多的一点优点就是遵循了开放-封闭原则,使得模式的灵活性更强.
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
	 virtual Product * createProduct(string objname)=0;
};
class  Confactory:public Factory
{
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
	Factory *fa=new Confactory();
	Product * pa=fa->createProduct("ProductA");
	pa->operation();
	pa=fa->createProduct("ProductB");
	pa->operation();
	pa=fa->createProduct("ProductC");
	pa->operation();
	return 0;
}