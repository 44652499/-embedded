#include <iostream>
using namespace std;
/*
自定义命名空间
*/
namespace n1
{
	void   fun()
    {
	 cout<<"fun1"<<endl;
    }
}


void   fun()
{
	cout<<"fun2"<<endl;
}

using namespace n1;
/**/
int main(int argc, char const *argv[])
{
	n1::fun();
	return 0;
}