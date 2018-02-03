#include <iostream>
using namespace std;
int max_T(int a,int b)
{
	cout<<"max_int_int"<<endl;
	return a>b?a:b;
}

template<class T>
T max_T(T a,T b)
{
	cout<<"max_T_T"<<endl;
	return a>b?a:b;
}

template <class T>
T max_T(T a,T b,T c)
{
	cout<<"max_T_T_T"<<endl;
	return max_T(a,b)>c?max_T(a,b):c;
}
int main(int argc, char const *argv[])
{
	cout<<max_T(3,4)<<endl;
	cout<<max_T(4,5,6)<<endl;
	cout<<max_T<>(6,7)<<endl;
	cout<<max_T<int>(8,9)<<endl;
	return 0;
}