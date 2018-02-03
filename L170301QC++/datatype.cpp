#include <iostream>
using namespace std;
/*
bool 布尔类型,表示真假,值只能是true false
#ifndef __cplusplus
typedef enum {false, true} bool;
#endif
false=0
true=1

bool 就是一个整数类型
#ifndef __cplusplus
#define true 1
#define false 0
#endif /* __cplusplus 
*/
int main(int argc, char const *argv[])
{
	bool isok;//为初始化局部变量,值随机
	// if(isok)
	// {
	// 	cout<<"ok"<<endl;
	// }
	// else
	// {
	// 	cout<<"not ok"<<endl;
	// }
	//isok=0;
	//cout<<isok<<endl;
	isok=true;
	if(isok==true)
	{
		cout<<"true"<<endl;
	}
	return 0;
}