#include <iostream>
using namespace std;
/*
纯虚函数:方法体为0 虚函数,一般定义在基类中.让派生类覆盖

抽象类:至少存在一个纯虚函数的类称为抽象类
抽象类不能实例化对象
派生类没有重写抽闲基类的纯虚函数,派生类也是一个抽象类
抽象类一般是当作基类,指向或引用派生类对象.
*/
class  Base
{
public:
	virtual void  fun()=0;//纯虚函数
};

class  Child1 :public Base
{
public:
	void  fun()
	{
		cout<<"Child1 fun"<<endl;
	}
};

class  Child2 :public Base
{
public:
	void  fun()
	{
		cout<<"Child2 fun"<<endl;
	}
};

//void test1(Child1  c1)
//void test1(Base  c1)//隐藏
// void test1(Base*  c1)//覆盖
// {
// 	c1->fun();
// }

//void test2(Child2  c2)
//void test2(Base  c2)//隐藏
// void test2(Base*  c2)//覆盖
// {
// 	c2->fun();
// }

//void test(Base*  b)
void test(Base&  b)
{
	b.fun();
}

int main(int argc, char const *argv[])
{
	Child1 c1;
	Child2 c2;
	//Base  b1;//错误,抽象类不能实例化对象
	test(c1);
	test(c2);
	return 0;
}