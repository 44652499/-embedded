#include <iostream>
using namespace std;
/*
建造者模式:将一个复杂对象的构建与它的表示分离,使得同样的构建过程可以创建不同的表示
优点
1.隔离了构建的步骤和具体的实现,为产品的具体实现提供了灵活度.
2.封装和抽象了每个步骤的实现,实现了依赖倒转原则.
3.封装了具体的步骤,减少了代码的冗余.
*/
class Product
{
public:
	Product()
	{
	}
	void  setProductA(int _partA)
	{
		partA=_partA;
	}
	void  setProductB(int _partB)
	{
		partB=_partB;
	}
	void  setProductC(int _partC)
	{
		partC=_partC;
	}
	void show()
	{
		cout<<"partA="<<partA<<"\n"<<"partB="<<partB<<"\n"<<"partC="<<partC<<endl;
	}
private:
	int  partA;
	int  partB;
	int  partC;
};


class Builder
{
public:
	virtual void   createProduct()=0;
	virtual void   builderA(int part)=0;
	virtual void   builderB(int part)=0;
	virtual void   builderC(int part)=0;
	virtual Product*  getProduct()=0;
};

class ConBuilder:public Builder
{
public:
	 ConBuilder()
	 {
	 	ptr=NULL;
	 }

	 void   createProduct()
	 {
	 	ptr=new  Product();
	 }

	 void   builderA(int _partA)
	 {
	 	ptr->setProductA(_partA);
	 }

	 void   builderB(int _partB)
	 {
	 	ptr->setProductB(_partB);
	 }

	 void   builderC(int _partC)
	 {
	 	ptr->setProductC(_partC);
	 }

	 Product*  getProduct()
	 {
	 	return ptr;
	 }
private:
	  Product *ptr;
};

class Director
{
public:
	Director(Builder * _p_build)
	{
		p_build=_p_build;
	}
	void  concreator()
	{
		p_build->createProduct();
		p_build->builderA(1);
		p_build->builderB(2);
		p_build->builderC(3);
	}
private:
	Builder * p_build;
};

int main(int argc, char const *argv[])
{
	Builder  *build=new  ConBuilder();
	Director * dire=new Director(build);
	dire->concreator();

	Product  *ptr=build->getProduct();
	ptr->show();
	return 0;
}