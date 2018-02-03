#include  <iostream>
#include  <stdlib.h>
#include  <string.h>
using namespace std;
/*
自定义异常类:
*/
class exception_0
{
public:
	exception_0(const char* msg)
	{
		strcpy(this->msg,msg);
	}
	const  char *  what()
	{
		cout<<"0"<<endl;
	}
private:
	char msg[20];
};
class exception_1
{
public:
	exception_1(const char* msg)
	{
		strcpy(this->msg,msg);
	}
	const  char *  what()
	{
		cout<<"1"<<endl;
	}
private:
	char msg[20];
};
class exception_2
{
public:
	exception_2(const char* msg)
	{
		strcpy(this->msg,msg);
	}
	const  char *  what()
	{
		cout<<"2"<<endl;
	}
private:
	char msg[20];
};
int  define_div(int x,int y)
{
	if(y==0)
		throw exception_0("div  is zero");//抛出自定义异常类的实例
	if(y==1)
		throw exception_1("div  is one");
	if(y==2)
		throw exception_2("div  is two");
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
