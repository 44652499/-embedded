#include <iostream>
using namespace std;
/*
默认值函数:函数定义时形参存在默认值

默认值函数作用:减少函数重载个数
*/
// int add(int a=3,int b=2,int c=1)
// {
// 	return a+b+c;
// }
//参数的默认值必须是从右到左,实参的值是从左到右
// int add(int a,int b,int c=3)
// {
// 	return a+b+c;
// }
//错误写法
int add(int a,int b=2,int c)
{
	return a+b+c;
}


int main(int argc, char const *argv[])
{
	//cout<<add()<<endl;//全部用默认值
	cout<<add(1,20)<<endl;//第三个参数用默认值
	//cout<<add(3,5,8)<<endl;//都不用默认值
	//如果以上调用没有默认值函数,需要定义三个重载函数

	//cout<<add(1,,20)<<endl;//错误 没有这样写法
	return 0;
}