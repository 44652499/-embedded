#include <iostream>
using namespace std;
/* 
观察者模式
*/
class IObserver
{
	virtual void  doSth()=0;
};
class Observer:public IObserver
{
public:
	void  doSth()
	{
		cout<<"Watch Observer Change"<<endl;
	}
};

class IObservered
{
	virtual void  change()=0;
};

class Observered:public IObservered
{
public:
	void  change()
	{
		cout<<"Observer Change"<<endl;
		Observer *obs=new Observer();
		obs->doSth();
	}
};

int main(int argc, char const *argv[])
{
	Observered * obs=new Observered();
	obs->change();
	return 0;
}
