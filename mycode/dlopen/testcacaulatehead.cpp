#include <iostream>
extern "C"
{
	//#include "cacaulate.h"
	extern int add(int a,int b);
}

using namespace std;
int main(int argc, char const *argv[])
{
	int a=3,b=5;
	cout<<add(a,b)<<endl;
	//cout<<sub(a,b)<<endl;
	//cout<<mul(a,b)<<endl;
	return 0;
}