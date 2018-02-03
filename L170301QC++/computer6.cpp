#include <iostream>
#include <string.h>
using namespace std;
/*
构造函数(constructor):在实例对象时,系统自动调用,用来初始化对象的数据成员

哪里语句是实例化对象需要调用构造函数?

构造函数特点:
1.类第一个调用的函数
2.自动调用
3.函数名为类名
4.无返回值
5.可以是私有

*/
class  Computer
{
public:
	Computer(int _hz=123,int _mem=1024):cpu_hz(_hz),memory(_mem)
	{
		cout<<"constructor"<<endl;
	}

	void  printcomputer()
	{
		cout<<cpu_hz<<"\t"<<memory<<endl;
	}
private:
	int   cpu_hz;
	int   memory;
};
int main(int argc, char const *argv[])
{
	Computer  c1;
	Computer  &c2=c1;//c2引用
	Computer  *c3=new Computer;	//new Computer 动态创建匿名对象
	Computer  *c4=&c1;//c4是一个指针
	Computer  *c5=new Computer(1,2);//new Computer(1,2) 动态创建匿名对象
	Computer  *c6=new Computer[2];//new Computer[2]  动态创建2个匿名对象
	Computer  c7[2];//对象数组
	Computer* c8[2];//指针数组
	Computer*  (*c9)[2];//数组指针
	return 0;
}