#include <iostream>
using namespace std;
// class A
// {
// public:
// 	static new_handler set_new_handler(new_handler p);
// 	static  void *  operator new (size_t size);
// private:
// 	static new_handler currentHandler;
// };
// new_handler A::currentHandler=0;

// new_handler A::set_new_handler(new_handler p)
// {
// 	new_handler oldHandler=currentHandler;
// 	currentHandler=p;
// 	return currentHandler;
// }

// void  A::operator new(size_t size)
// {
// 	new_handler globalHandler=std::set_new_handler(currentHandler);

// 	void * memory;

// 	try
// 	{
// 		memory=::operator new(size);
// 	}
// 	catch(std::bad_alloc & ex)
// 	{
// 		std::set_new_handler(globalHandler);
// 		throw;
// 	}
// 	std::set_new_handler(globalHandler);
// 	return memory;
// }

class A
{
public:
	A(int& _data,int _num):data(_data),num(_num){}
	void fun()
	{
		cout<<data<<"\t"<<num<<endl;
	}
private:
	int data;
	int num;
};
int main(int argc, char const *argv[])
{
	A a1(12,34);
	a1.fun();
	return 0;
}