#include <iostream>
using namespace std;
/*
内部类:
*/

class  Outer
{
public:
	class Inner
	{
	public:
		void fun()
		{
			Outer o;
			cout<<o.a<<endl;//内部类通过外部类对象访问私有数据成员
		}
	private:
		int b;
	};

	void  fun2()
	{
		Inner obj;
		cout<<obj.b<<endl;//外部类不能访问内部类的私有成员
	}
private:
	int  a;
};
int main(int argc, char const *argv[])
{
	Outer::Inner  b; //外面如何访问内部类
	b.fun();
	return 0;
}