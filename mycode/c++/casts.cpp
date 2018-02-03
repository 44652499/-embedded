#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	// double  b=20.32434;
	// int a=static_cast<int>(b);
	// cout<<a<<endl;

	// double d1=2323.4;
	// double* p_d2=&d1;
	// //int * p_i=static_cast<int*>(p_d2);
	// //int * p_i=dynamic_cast<int*>(p_d2);
	// //int* p_i=reinterpret_cast<int*>(p_d2);
	// int* p_i=const_cast<int*>(p_d2);
	// cout<<*p_i<<endl;
	// cout<<p_i<<endl;

	// char* p_ch="abcd";
	// const char *p_ch2=const_cast<const char*>(p_ch);
	// cout<<p_ch2<<endl;

	char ch[]="abcd";
	const char*  p_ch=const_cast<const char*>(ch);
	cout<<p_ch<<endl;
	return 0;
}