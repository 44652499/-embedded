#include  <iostream>
#include  <stdlib.h>
using namespace std;
/*
自定义异常类:
*/
class exception_0
{
public:
	const  char *  what()
	{
		cout<<"0"<<endl;
	}
};
class exception_1
{
public:
	const  char *  what()
	{
		cout<<"1"<<endl;
	}
};
class exception_2
{
public:
	const  char *  what()
	{
		cout<<"2"<<endl;
	}
};
int  define_div(int x,int y)
{
	if(y==0)
		throw exception_0();//抛出自定义异常类的实例
	if(y==1)
		throw exception_1();
	if(y==2)
		throw exception_2();
	return x/y;
}

int main(int argc, char const *argv[])
{
	int x,y;
	cin>>x>>y;
	try
	{
		define_div(x,y);
	}
	catch(exception_0  h1)
	{
		//cout<<"0"<<endl;
		h1.what();
	}
	catch(exception_1  h1)
	{
		//cout<<"1"<<endl;
		h1.what();
	}
	catch(exception_2  h1)
	{
		//cout<<"2"<<endl;
		h1.what();
	}
	return 0;
}
