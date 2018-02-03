#include <iostream>
using namespace std;
template <typename T>
class  A;

//特化进行实现
template<>
class A<int>
{

};

int main(int argc, char const *argv[])
{
	//A<char> a1;
	A<intl> a1;
	return 0;
}