#include <iostream>
using namespace std;
typedef void (*PTR_FUN)();
class Base
{
public:
	virtual void fun1()
	{
		cout<<"Base fun1"<<endl;
	}
private:
	int data;
};
class Child:public Base
{
public:
    virtual void fun2()
	{
		cout<<"Child fun2"<<endl;
	}
};
int main(int argc, char const *argv[])
{
	Child obj_b1;
	int *ptr_vtable=(int *)(*(int *)&obj_b1);
	int *ptr_fun=(int *)(*ptr_vtable);
	((PTR_FUN)ptr_fun)();

	ptr_fun=(int *)(*((int *)ptr_vtable+1));
	((PTR_FUN)ptr_fun)();
	return 0;
}