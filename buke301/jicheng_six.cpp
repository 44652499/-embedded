#include <iostream>
using namespace std;
/*
多继承:多个基类存在同名的方法.派生类继承过去出现同名方法歧义问题,
也称为菱形问题

虚基类解决菱形问题:
base 类指在child中产生唯一一个对象,在base1  base2中指产生一个指向base
类的指针
*/
class  base
{
private:
	int b;
public:
	base()
	{
		b=100;
	}
	void  fun()
	{
		cout<<"base fun"<<endl;
	}
};
class base1: virtual base
{
private:
	int data;
public:
	base1(int _data=0)
	{
		data=_data;
		cout<<"base1 constructor"<<endl;
	}	
};

class base2:virtual base
{
private:
	int data;
public:
	base2(int _data=0)
	{
		data=_data;
		cout<<"base2 constructor"<<endl;
	}
	void  fun2()
	{
		cout<<"base2 fun2"<<endl;
	}
};

class child :public  base1,public  base2
{
public:
   child():base1(200),base2(300)
   {
   	 a=400;
   	 cout<<"child constructor"<<endl;
   }
 private:
 	int a;
};

int main(int argc, char const *argv[])
{
	child c;
	//cout<<sizeof(c)<<endl;
	int *ptr=(int*)&c;
	//cout<<*ptr<<endl;//base1 指向基类的指针
	((base*)ptr)->fun();
	cout<<*++ptr<<endl;//base1 数据成员
	cout<<*++ptr<<endl;//base2 指向基类的指针
	cout<<*++ptr<<endl;//base2数据成员
	cout<<*++ptr<<endl;//child 数据成元
	cout<<*++ptr<<endl;//base 数据成员
	return 0;
}