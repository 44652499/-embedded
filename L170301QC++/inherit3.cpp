#include  <iostream>
using namespace std;
/*
实例化派生类对象,首先调用基类构造函数实例化一个匿名基类对象
如果是系统默认无参构造可以不写
*/
class   Base
{
public:
	Base(int _a)
	{
		cout<<"base  constructor"<<endl;
	}
private:
	int a;
	int c;
};

class  Child :  Base
{
public:
	//Child(int _a):Base(1)//调用基类一个参数构造函数
	Child(int _a):Base(1)
	{
		//Base(1);//写法错误
		cout<<"child constructor"<<endl;
	}
private:
	int b;
};

int main(int argc, char const *argv[])
{
	//cout<<sizeof(Base)<<endl;
	//cout<<sizeof(Child)<<endl;
	//sizeof(Child) 大小看出,派生类对象必定存在一个基类对象
	//与继承方式 基类成员访问模式无关

	Child c1(1);
	return 0;
}