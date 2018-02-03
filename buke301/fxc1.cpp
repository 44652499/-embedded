#include <iostream>
#include <string.h>
using namespace std;
/*
c++面向对象编程思想:用抽象思想描述一类事物的属性和行为
c++面向对象编程三大特性:
1.封装:用抽象思想用类描述事物的相同属性和行为
       类(class):自定义数据类型.抽象描述属性和行为
       类组成:数据成员+函数成员
       数据成员私有,函数成员公有
       对象(object):类类型变量.对象是类具体实例化
       对象与类是一种抽象与具体关系
2.继承
3.多态
*/
//描述学生群体类
class  student
{
private:
	//属性:描述事物静态数据
	int sid;
	char sname[10];
public:
	//方法:提供公共的方法操作私有数据成员
	void setsid(int _sid)
	{
		sid=_sid;
	}
	int getsid()
	{
       return sid;
	}

	void  setsname(const char*  _sname)
	{
		strcpy(sname,_sname);
	}

	char*  getsname()
	{
		return sname;
	}
};
int main(int argc, char const *argv[])
{
	student s1;//对象
	cout<<sizeof s1<<endl;
	//s1是一个变量占用内存,占用内存与类的非静态数据成员有关
	//类的成员函数共享与所有对象.
	s1.setsid(200);
    s1.setsname("aaaa");
	cout<<s1.getsid()<<'\t'<<s1.getsname()<<endl;
	return 0;
}