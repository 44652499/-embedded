#include <iostream>
using namespace std;
/*
static:
static 对象:

static数据成员:不属于对象,共享于所有对象
                只能在类外初始化,不能再构造函数初始化
                在类外访问静态数据成员前必须要初始化
                可以通过类名或对象名访问
                可以在一般函数中访问
static函数成员:
*/
class  A
{
public:
	void print()
	{
		cout<<a<<endl;
	}
	static int a; //静态数据成员
};
//初始化静态数据成员:
int A::a=100;

int main(int argc, char const *argv[])
{
	A a1;
	//cout<<sizeof(a1)<<endl;
	// a1.a=400;
	// A a2;
	// cout<<a2.a<<endl;
	// A::a=3000;
	// cout<<a1.a<<endl;

	a1.print();
	return 0;
}