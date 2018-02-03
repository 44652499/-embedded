#include <iostream>
using namespace std;
class Base
{
public:
	Base()
	{
		fun();
	}
	virtual void   fun()
	{
		cout<<"fun"<<endl;
	}
};
class Child :public Base
{
public:
	Child():Base()
	{
		cout<<"Child"<<endl;
	}
	virtual void   fun()
	{
		cout<<"Child fun"<<endl;
	}
};
int main(int argc, char const *argv[])
{
	//Base b1;
	Child c1;
	return 0;
}