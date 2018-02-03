#include <iostream>
using namespace std;
/*
构造函数是否可以是虚函数?
析构函数是否可以是虚函数?

如果基类析构函数是非虚函数,通过基类指针释放派生类动态对象.只调用基类析构函数.没有调用派生类析构函数.容易造成派生类对象指针成员指向的动态资源泄漏
*/
class  Base
{
public:
	virtual Base1(){}
	virtual void  fun()=0;//纯虚函数
    //虚析构函数
	virtual ~Base()
	{
		cout<<"~Base"<<endl;
	}
};

class  Child1 :public Base
{
public:
	void  fun()
	{
		cout<<"Child1 fun"<<endl;
	}
	~Child1()
	{
		cout<<"~Child1"<<endl;
	}
};

int main(int argc, char const *argv[])
{
	Base * ptr=new Child1();
	ptr->fun();
	delete  ptr;
	ptr=NULL;
	return 0;
}