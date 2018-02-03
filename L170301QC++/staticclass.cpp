#include <iostream>
using namespace std;
/*
类的构造函数可以是私有.
1.调用public构造函数
2.构造函数为private.在类外使用指针获取类内的对象的地址
*/
class  A
{
public:
	static A *   initobj()
	{
		A* obj=new A(10);
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
};
int main(int argc, char const *argv[])
{
	//A a1(100);

	A  *obj=A::initobj();
	obj->fun();
	A  *obj2=A::initobj();
	obj2->fun();
	return 0;
}
