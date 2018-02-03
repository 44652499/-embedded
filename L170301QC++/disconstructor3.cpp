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
int main(int argc, char const *argv[])
{
	A a1;
	A a2;
	return 0;
}