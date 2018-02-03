#include <iostream>
#include <string.h>
using namespace std;
/*
定义电脑类
*/
class  Computer
{
public:
	void setcomputer_kind_name(const char* name)
	{
		strcpy(computer_kind_name,name);
	}
	char*  getcomputer_kind_name()
	{
		return computer_kind_name;
	}
	void setcpu_num(int num)
	{
		cpu_num=num;
	}
	int getcpu_num()
	{
		return cpu_num;
	}
	void setcpuhz(int hz)
	{
		cpu_hz=hz;
	}
	int getcpuhz()
	{
		return cpu_hz;
	}
	void  setmemory(int mem)
	{
		memory=mem;
	}
	int getmemory()
	{
		return memory;
	}
private:
	char  computer_kind_name[20];
	int   cpu_num;//c11标志支持定义成员变量时赋值,但是一般不这样赋值
	int   cpu_hz;
	int   memory;
};
int main(int argc, char const *argv[])
{
	
	return 0;
}