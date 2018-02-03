#include <iostream>
using namespace std;
class A
{
public:
	~A()
	{
		cout<<"A"<<endl;
	}
};
char  fun()
{
	A a1;
	throw  'T';
	return '0';
}
int main(int argc, char const *argv[])
{
	try
	{
		cout<<fun()<<endl;
	}
	catch(char c)
	{
		cout<<c<<endl;
	}
	return 0;
}