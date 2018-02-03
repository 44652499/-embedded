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
	//列表初始化数据成员
	//列表方式初始化解决只读成员变量初始化问题
	Computer(int _hz=123,int _mem=1024):cpu_hz(_hz)//,memory(_mem)
	{
		//cpu_hz=_hz;//不能再构造函数中对只读成员变量赋值
		memory=_mem;
	}

	void  printcomputer()
	{
		cout<<cpu_hz<<"\t"<<memory<<endl;
	}
private:
	//const int   cpu_hz;//只读成员变量
	int   cpu_hz;
	int   memory;
};
int main(int argc, char const *argv[])
{
	Computer  c1;
	c1.printcomputer();
	return 0;
}