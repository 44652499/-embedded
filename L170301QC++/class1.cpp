#include <iostream>
using namespace std;
/*面向对象(OOP):用抽象语言描述实物(属性+动作)
类(class):是一种自定义数据类型,类似于c struct,实现抽项目描述
定义类:
class  类名
{
	private:成员
	public:成员
	protected:成员
};
class  成员默认访问方式是private
类里面一般定义:
属性成员(变量成员)
函数成员
一般是要求数据成员私有,函数成员公有.在类外通过调用函数成员操作或获取数据成员
封装=class+priavte 数据成员+public 函数成员
私有成员变量给类公有函数使用
private:只能在本类中访问
public:都可以访问
protected:只能在具有继承关系类中访问

c++ 类与c 结构体区别?
1.c++类成员可以是数据和函数,c结构体只能是数据成员
2.c++类成员必定存在访问模式,c结构成员没有

c++类与c++结结构体区别?
1.c++ 类默认访问模式是private,c++结结构体类默认访问模式是public

对象(object):类的一个实例化(变量)
对象与类是一种抽象与具体关系.
类是对象的抽象描述,对象是类的具体化
*/
//class  student
struct  student
{
public:
	void  fun()
	{
		cout<<"fun"<<endl;
	}
//private:
	int id;
	char name[20];	
};
int main(int argc, char const *argv[])
{
	student s1;//对象
	s1.id=20;
	cout<<s1.id<<endl;
	s1.fun();
	return 0;
}