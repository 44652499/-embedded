#include <iostream>
#include <string.h>
using namespace std;
class A
{
private:
	int data;
public:
	A(int _data=0)
	{
		data=_data;
	}
	int  getdata()
	{
		return data;
	}
};
int main(int argc, char const *argv[])
{
	A  a1(200);
	A  *p1=&a1;
	cout<<p1->getdata()<<endl;
	//定义一个指针,指向的是类的成员函数
	int (A::*p2)();
	p2=&A::getdata;
	(a1.*p2)();
	return 0;
}