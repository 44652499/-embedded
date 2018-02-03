#include <iostream>
using namespace std;
/*
类如果存在虚函数,类的对象分配一个指针,指向存放类虚函数地址集合(虚表)
派生类继承基类,继承基类虚表.派生类对对象也存在一个指针

虚表:是一个函数指针数组,记录类虚函数地址值
*/
class  Base
{
public:
	virtual void  fun()=0;//纯虚函数
	virtual void  fun1()=0;
};

class  Child1 :public Base
{
public:
	void  fun()
	{
		cout<<"Child1 fun"<<endl;
	}
};

int main(int argc, char const *argv[])
{
	cout<<sizeof(Base)<<endl;
	cout<<sizeof(Child1)<<endl;
	return 0;
}