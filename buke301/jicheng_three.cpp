#include <iostream>
using namespace std;
/*
重载  覆盖(隐藏)
重载:同类中方名相同 参数列表不同
覆盖(隐藏):在基类 派生类之间.派生类中定义与基类同名方法.用派生类对象调用
派生类的方法.覆盖基类方法
*/
class base
{
private:
	int data;
	int data2;
public:
	base(int _data=0,int _data2=0)
	{
		data=_data;
		data2=_data2;
		cout<<"base constructor"<<endl;
	}
	void  fun()
	{
		cout<<"base fun"<<endl;
	}
};

class child :public  base
{
public:
   child():base(20,30)
   {
   	a=40;
   	 cout<<"child constructor"<<endl;
   }
   void  fun()
	{
		cout<<"child fun"<<endl;
	}

   void  fun(int  a)
	{
		cout<<"child fun a"<<endl;
	}
 private:
 	int a;
};

int main(int argc, char const *argv[])
{
	// child c;
	// c.fun();
	// c.fun(10);
	// base  b;
	// b.fun();
	//b.fun(30);基类调用基类的方法,基类不存在这方法
    child c; 
    base &b=c;//赋值兼容
    b.fun();//基类的方法
    //b.fun(20); 
	return 0;
}