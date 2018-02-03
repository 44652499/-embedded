#include <iostream>
using namespace std;
class A
{
public:
	explicit A(int _a)
	{
		a=_a;
	}
	void  printa()
	{
		cout<<a<<endl;
	}
private:
	int a;
};
int main(int argc, char const *argv[])
{
	A a1(2);
	a1.printa();

	A  a2=40;//初始化,正数初始化a2对象a成员
	//调用一个参数的构造函数,可以这样初始化对象一个成员

	
	//但是存在歧义,初始化是两边类型不一致,防止歧义产生,explicit限制构造函数
	a2.printa();
	return 0;
}