#include <iostream>
using namespace std;
class A
{
public:
	A(int _a,int _b)
	{
		a=_a;
		b=_b;
	}
	void  getA()
	{
		cout<<a<<endl;
	}
	void getB()
	{
		cout<<b<<endl;
	}
private:
	int a;
	int b;
};

class HandlerA
{
private:
	A*  ptr_a;
public:
	HandlerA(int _a,int _b)
	{
		ptr_a=new A(_a,_b);
	}
	void  getA()
	{
		ptr_a->getA();
	}
	void getB()
	{
		ptr_a->getB();
	}
	~HandlerA()
	{
		if(ptr_a!=NULL)
		{
			delete ptr_a;
			ptr_a=NULL;
		}
	}
};
int main(int argc, char const *argv[])
{
	HandlerA  ha(10,23);
	ha.getA();
	ha.getB();
	return 0;
}