#include <iostream>
using namespace std;
/*
析构函数:在对象释放之前,系统自动调用,释放对象的成员指向堆空间
定义析构函数:
~类名()
析构函数定义注意点:
1.函数名是~类名
2.无返回值类型
3.无参
一个类中有且只能有一个析构函数.默认存在析构函数

如果没有对象释放,系统不会调用析构函数
*/
class A
{
public:
	A()
	{
		p=new int[3];
	}
	//定义析构函数
	// ~A()
	// {
	// 	cout<<"disconstructor"<<endl;
	// 	//释放语句
	// 	delete p;
	// 	p=NULL;
	// }
private:
	int *p;
};
int main(int argc, char const *argv[])
{
	//A a1;
	//A a2;
	A *a3=new A;
	//必须手动释放对象,否则析构函数不能调用
	delete a3;
	a3=NULL;
	return 0;
}