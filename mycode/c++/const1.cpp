#include <iostream>
using namespace std;
const int a=10;
int main(int argc, char const *argv[])
{
	//const int a=10;
	int *p=(int*)&a;
	cout<<*p<<" "<<a<<endl;
	cout<<p<<" "<<&a<<endl;
	*p=20;
	cout<<*p<<" "<<a<<endl;
	cout<<p<<" "<<&a<<" "<<&p<<endl;
	cout<<*p<<" "<<a<<endl;
	return 0;
}