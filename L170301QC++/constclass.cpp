#include  <iostream>
using namespace std;
/*
只读(const):
只读对象:只读变量,表示对象的数据成员不能被类的成员函数修改,
只读数据成员:
只读函数成员:在函数中不能修改对象的数据成员
*/
class   A
{
public:
	A(int _a,int _b)
	{
		a=_a;
		b=_b;
	}
	//定义类的只读成员函数
	// void  print() const
	// {
	// 	cout<<a<<'\t'<<b<<endl;
	// }
	void  print() const;

	void  fun()
	{
		cout<<"fun"<<endl;
	}
private:
	int a;
	int  b;
	//const int b;//只读数据成员
};

void  A::print() const
{
	//a=400;//错误,只读成员函数中不能修改成员变量
	//fun();//错误.
	cout<<a<<'\t'<<b<<endl;
}
int main(int argc, char const *argv[])
{
	A  a1(1,2);
	const A  a2(3,4);//只读对象(只读变量),对象数据成员成为只读
	//a2.print();//错误,print 是一个非只读函数.
	//a2.print();
	a1.print();
	return 0;
}