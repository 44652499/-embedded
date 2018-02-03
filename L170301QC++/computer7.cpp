#include <iostream>
#include <string.h>
using namespace std;
/*

*/
class  Computer
{
public:
	//函数声明
	Computer(int _hz,int _mem);
	void  printcomputer();
private:
	int   cpu_hz;
	int   memory;
};
//类的成员函数定义
Computer::Computer(int _hz=123,int _mem=1024):cpu_hz(_hz),memory(_mem)
{
	cout<<"constructor"<<endl;
}
//类的成员函数定义
void  Computer::printcomputer()
{
	cout<<cpu_hz<<"\t"<<memory<<endl;
}
//文件方法
void  printcomputer()
{
	cout<<"printcomputer"<<endl;
}
int main(int argc, char const *argv[])
{
	Computer c1;
	c1.printcomputer();
	printcomputer();
	return 0;
}