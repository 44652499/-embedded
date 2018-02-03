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
	Base()
	{
		t=10;
	}
	void  fun()
	{
		cout<<"Base1  fun"<<endl;
	}
private:
	int t;
};
class Base1:virtual  public Base
{
public:
	Base1(int _a):Base()
	{
		cout<<"Base1"<<endl;
		a=20;
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
		b=30;
	}
private:
	int b;
};
class Child:public  Base2,public Base1
{
public:
	Child(int _a,int _b,int _c):Base2(_a),Base1(_b)
	{
		c=40;
	}
private:
	int c;
};
int main(int argc, char const *argv[])
{
	Child  c1(1,2,3);
	// cout<<sizeof(Base)<<endl;
	// cout<<sizeof(Base1)<<endl;
	// cout<<sizeof(Base2)<<endl;
	// cout<<sizeof(Child)<<endl; 
	//c1.fun();

	// int * ptr=(int*)&c1;//Child对象 构造一个Base对象,让Base1  Base2指针指向该对象
	// cout<<*ptr<<endl;
	// cout<<*(ptr+1)<<endl;
	// cout<<*(ptr+2)<<endl;
	// cout<<*(ptr+3)<<endl;
	// cout<<*(ptr+4)<<endl;
	// cout<<*(ptr+5)<<endl;

	Base1  b1(1);//b1结构是:指针 自身数据成员大小  基类成员大小
	int * ptr=(int*)&b1;
	cout<<*ptr<<endl;
	cout<<*(ptr+1)<<endl;
	cout<<*(ptr+2)<<endl;
	return 0;
}