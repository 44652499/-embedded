#include <iostream>
#include <string.h>
using namespace std;
/*
深拷贝/浅拷贝

*/

class A
{
private:
	int data;
	int *  ptr;
public:
    A(int _data=0)
	{
		data=_data;
		ptr=new int[4];
	}
	//浅拷贝
	// A(const A& obj)
	// {
	// 	data=obj.data;
	// 	ptr=obj.ptr;
	// 	cout<<"copy constructor"<<endl;
	// }

	A(const A& obj)
	{
		data=obj.data;
		//ptr=obj.ptr;
		ptr=new int[4];
		cout<<"copy constructor"<<endl;
	}
	void  operator =(A &obj)
	{
		data=obj.data;
		cout<<"operator ="<<endl;
	}
	int  getdata()
	{
		return data;
	}
	~A()
	{
		if(ptr!=NULL)
		{
			delete ptr;
			ptr=NULL;
		}
	}
};


int main(int argc, char const *argv[])
{
	A  a1(200);
	A  a2(a1);	
	return 0;
}