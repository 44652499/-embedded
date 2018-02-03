#include <iostream>
using namespace std;
/*
设计模式:单例模式(只能构造类一个对象)
*/
class  A
{
public:
	static A *   initobj()
	{	
		if(obj==NULL)
		{
			obj=new A(10);
		}		
		return obj;
	}
	void  fun()
	{
		cout<<"fun"<<endl;
	}
private:
	A(int _a)
	{
		a=_a;
	}
	int a;
	static A* obj;
};
A * A::obj=NULL;
int main(int argc, char const *argv[])
{
	//A a1(100);

	A  *obj=A::initobj();
	obj->fun();
	A  *obj2=A::initobj();
	obj2->fun();
	return 0;
}
