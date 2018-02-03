#include <iostream>
using namespace std;
/*
在c++ 如何判断new 分配内存是否成功或失败?
1.捕捉异常(bad_alloc)
2.set_new_hanlder 设置失败处理函数,在函数中使用exit
*/
int main(int argc, char const *argv[])
{
	try
	{
		int * p=new int[1000000000];
	}catch(bad_alloc)
	{
		cout<<"new fail"<<endl;
	}
	return 0;
}