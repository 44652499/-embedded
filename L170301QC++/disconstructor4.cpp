#include <iostream>
using namespace std;
/*
对象构造与析构顺序:
先构造的最后析构
*/
class A
{
public:
	A()
	{
		cout<<"constructor"<<endl;
		p=new int[3];
	}
	//定义析构函数
	~A()
	{
		cout<<"disconstructor"<<endl;
		//释放语句
		delete p;
		p=NULL;
	}
private:
	int *p;
};

void   fun()
{
	int i;
	for(i=0;i<10;i++)
	{
		static A  a1;//静态局部变量只初始化一次
	}
}
int main(int argc, char const *argv[])
{
	// A a1;
	// A a2;
	// fun();

	//A *a2=new A();
	//A *a3=new A;
	A  a4();//歧义
	A  a5;
	return 0;
}