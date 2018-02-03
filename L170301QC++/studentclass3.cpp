#include <iostream>
#include <string.h>
using namespace std;
/*
类的大小简单计算:
1.只计算数据成员大小,考虑内存对齐
2.空类大小算1个字节
*/
class   Student
{
public:	
	void setsid(int _sid)
	{
		//sid=_sid;
	}
private:
	//int sid;
	//char name[10];
};
int main(int argc, char const *argv[])
{
	Student s1;
	cout<<sizeof(s1)<<endl;
	return 0;
}
//设计一个电脑类