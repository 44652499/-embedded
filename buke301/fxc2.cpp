#include <iostream>
#include <string.h>
using namespace std;
/*
类中存在多个默认函数:
1.构造函数:实例化对象时,系统自动调用,初始化对象的数据成员
   构造函数定义:
      类名([参数列表])
2.析构
3.赋值
4.拷贝构造

函数重载(overload):同一个类中,函数名相同参数列表不同(参数个数 或参数类型 不同)

inline内联函数:用函数定义语句替换函数调用语句,避免函数调用寻址调转和局部栈开销
内联函数优点:
1.减少函数调用寻址
2.减少函数调用开销
内联函数缺点:
1.增加函数编译代码长度
2.用空间换时间
内联函数定义:
1.函数定义声明一起完成
2.inline 修饰函数定义
*/
//描述学生群体类
class  student
{
private:
	//属性:描述事物静态数据
	int sid;
	char sname[10];
public:
	//默认无参构造函数
	student()
	{
		cout<<"constructor"<<endl;
	}
	student(int  _sid)
	{
       sid=_sid;
	}
	student(const char* _name)
	{
		strcpy(sname,_name);
	}
	student(int _sid,const  char* _name);//声明
	// student(int _sid,const  char* _name)//定义
	// {
 //        sid=_sid;
 //        strcpy(sname,_name);
	// }
	//拷贝构造函数
	student(student&  stu)
	{

	}
	//方法:提供公共的方法操作私有数据成
	int getsid()
	{
       return sid;
	}

	char*  getsname()
	{
		return sname;
	}
};
 //类名::限制类成员方法
inline student::student(int _sid,const  char* _name)
 {
        sid=_sid;
        strcpy(sname,_name);
 }


int main(int argc, char const *argv[])
{
	student s1;	//自动调用默认构造函数
	student s2(11,"sdfsdf");
	cout<<s2.getsid()<<'\t'<<s2.getsname()<<endl;
	return 0;
}