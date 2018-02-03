#include <iostream>
#include <string.h>
using namespace std;
/*
数据类型强制转换
*/
class A
{
public:
	A(int _data,const char* _ch)
	{
		data=_data;
		strcpy(ch,_ch);
	}
	//特殊写法,适用于类型强制转换
	operator int()
	{
		return data;
	}
	operator char*()
	{
		return ch;
	}
private:
	int data;
	char ch[10];
};
int main(int argc, char const *argv[])
{
	A a1(100,"abcd");
	int d=a1;
    char* ch=a1;
	cout<<d<<endl;
	cout<<ch<<endl;
	return 0;
}

//介绍c++ 智能指针?作用是什么?