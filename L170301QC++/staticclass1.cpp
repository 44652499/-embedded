#include <iostream>
using namespace std;
/*
static:
static 对象:

static数据成员:

static函数成员:
*/
class  A
{
public:
	A(int _a)
	{
		a=_a;
	}
	void  print()
	{
		cout<<a<<endl;
	}
private:
	int a;
};

void   fun()
{
	int i;
	for(i=0;i<10;i++)
	{
		static A a2(200);//静态局部对象,存储在数据段.在进程结束释放
	}
}
int main(int argc, char const *argv[])
{
	A a1(100);
	a1.print();
	//static  A  a2(200); //静态对象,静态变量
	fun();
	return 0;
}