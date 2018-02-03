#include <iostream>
#include <string.h>
using namespace std;
/*
定义电脑类
定义个一个函数初始化类的所有数据成员
*/
class  Computer
{
public:
	void  initcomputer(const char* _name,int _num,int _hz,int _mem)
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
	c1.initcomputer("aa",4,123,1024);
	c1.printcomputer();

	Computer  c2;
	c2.initcomputer("bb",8,222,2048);
	c2.printcomputer();
	return 0;
}