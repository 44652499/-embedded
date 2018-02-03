#include  <iostream>
using namespace std;
/*
 "()" 符号重载
*/
class  fun
{
public:
	int  operator()(int a,int b)
	{
		return a+b;
	}
};

int main(int argc, char const *argv[])
{
	fun f;
	int ret=f(1,2);//f 是类的对象 ,()符号用成员函数方式重载,1,2参数
	cout<<ret<<endl;
	return 0;
}