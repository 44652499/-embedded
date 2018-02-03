#include <iostream>
using namespace std;
/*
多继承
*/
class base1
{
private:
	int data;
public:
	base1(int _data=0)
	{
		data=_data;
		cout<<"base1 constructor"<<endl;
	}
	void  fun()
	{
		cout<<"base1 fun"<<endl;
	}
};

class base2
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
	void  fun()
	{
		cout<<"base2 fun"<<endl;
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
	c.base1::fun();
	c.base2::fun();
	c.fun2();
	return 0;
}