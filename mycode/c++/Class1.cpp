#include<iostream>
using namespace std;
class A
{
public:
	A();//屏蔽函数(只声明并未定义)
};
int main(int argc, char const *argv[])
{
	A a;
	return 0;
}