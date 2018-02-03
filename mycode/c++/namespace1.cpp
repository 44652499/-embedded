#include <iostream>
using namespace std;
/*
命名空间(namespace):管理工程类或函数结构,通过命名空间达到类或函数名唯一
std:系统标准命名空间
自定义命名空间
*/
namespace A
{
	void  fun()
	{
		cout<<"A fun"<<endl;
	}
}

void  fun()
{
	cout<<"fun"<<endl;
}
int main(int argc, char const *argv[])
{
	fun();
	return 0;
}