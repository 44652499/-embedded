#include <iostream>
using namespace std;
/*
多继承:一个派生类继承多个基类
*/
class Base1
{
public:
	Base1(int _a)
	{
		cout<<"Base1"<<endl;
		a=_a;
	}
private:
	int a;
};
class Base2
{
public:
	Base2(int _b)
	{
		cout<<"Base2"<<endl;
		b=_b;
	}
private:
	int b;
};
//根据继承输出构造基类对象
class Child:public  Base2,public Base1
{
public:
	Child(int _a,int _b,int _c):Base2(_a),Base1(_b)
	{
		c=_c;
	}
private:
	int c;
};
int main(int argc, char const *argv[])
{
	//cout<<sizeof(Child)<<endl;
	Child  c1(1,2,3);
	return 0;
}