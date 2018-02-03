#include <iostream>
using namespace std;
/*
多继承:多个基类存在同名的方法.派生类继承过去出现同名方法歧义问题,
也称为菱形问题

虚基类解决菱形问题
*/
class  base
{
private:
	int b;
public:
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
   child():base1(20),base2(30)
   {
   	 a=40;
   	 cout<<"child constructor"<<endl;
   }
 private:
 	int a;
};

int main(int argc, char const *argv[])
{
	child c;
	//c.fun();//歧义,两个基类存在同名的方法
	//c.base1::fun();
	//c.base2::fun();
	//c.fun2();
	//cout<<sizeof(c)<<endl;//未使用virtual情况下,派生类大小为20,因为
	//base 在base1  base2都存在一个对象 

	cout<<sizeof(c)<<endl;
	return 0;
}