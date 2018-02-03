#include <iostream>
#include <string.h>
using namespace std;
/*
自定义学生类:添加get/set 方法

*/
class   Student
{
public:	
	void setsid(int _sid)
	{
		sid=_sid;
	}
	int getsid()
	{
		return sid;
	}
	void setname(const char *  _name)
	{
		strcpy(name,_name);
	}
	char*  getname()
	{
		return name;
	}
private:
	int sid;
	char name[10];
};
int main(int argc, char const *argv[])
{
	Student s1;
	s1.setsid(111);
	s1.setname("s111");
	Student s2;
	s2.setsid(222);
	s2.setname("s222");
	cout<<s1.getsid()<<"\t"<<s1.getname()<<endl;
	cout<<s2.getsid()<<"\t"<<s2.getname()<<endl;
	return 0;
}