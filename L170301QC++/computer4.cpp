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
	//定义默认值构造函数
    //减少其他形式构造函数定义
	Computer(const char* _name="aaa",int _num=4,int _hz=123,int _mem=1024)
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
	Computer  c1;
	Computer  c2("1111");
	c1.printcomputer();
	c2.printcomputer();
	return 0;
}