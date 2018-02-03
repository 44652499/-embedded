#include <iostream>
#include <string.h>
using namespace std;
/*
构造函数(constructor):在实例对象时,系统自动调用,用来初始化对象的数据成员
构造函数声明语法:
 类名(参数列表);
 构造函数注意点:
 1.函数名必须是类名
 2.无返回值类型
 3.不同参数列表
 一个类可以存在多个不同形式的构造函数(构造函数可以重载)
*/
class  Computer
{
public:
	//定义无参构造函数
	Computer()
	{
		cout<<"constructor"<<endl;
	}
	//定义一个有四个参数构造函数
	Computer(const char* _name,int _num,int _hz,int _mem)
	{
		strcpy(computer_kind_name,_name);
		cpu_num=_num;
		cpu_hz=_hz;
		memory=_mem;
	}

	void  printcomputer()
	{
		cout<<computer_kind_name<<"\t"<<cpu_num<<'\t'<<cpu_hz<<"\t"<<memory<<endl;
	}
private:
	char  computer_kind_name[20];
	int   cpu_num;//c11标志支持定义成员变量时赋值,但是一般不这样赋值
	int   cpu_hz;
	int   memory;
};
int main(int argc, char const *argv[])
{
	Computer  c1;//构造一个对象,调用的是无参构造函数
	//一般类中存在一个无参构造函数,只要定义构造函数,默认构造函数不存在
	//Computer  c1("aa",4,111,1024);//构造一个对象,调用的是四个参数构造函数
	c1.printcomputer();

	// Computer  c2;
	// c2.initcomputer("bb",8,222,2048);
	// c2.printcomputer();
	return 0;
}