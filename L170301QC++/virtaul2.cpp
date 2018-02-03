#include <iostream>
using namespace std;
class Base
{
public:
	virtual void  fun()=0;
};
class Child1 :public Base
{
public:
	void  fun()
	{
		cout<<"Child1 fun"<<endl;
	}
};

class Child2:public Child1
{
public:
	void  fun()
	{
		cout<<"Child2  fun"<<endl;
	}
};
void test(Base * obj)
{
	obj->fun();
}
int main(int argc, char const *argv[])
{
	Base *b;
	Child1 c1;
	Child2 c2;
	b=&c1;
	test(b);
	b=&c2;
	test(b);
	return 0;
}