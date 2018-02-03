#include <iostream>
using namespace std;

// int add(int a,int b)
// {
// 	return a+b;
// }
// double add(double a,double b)
// {
// 	return a+b;
// }

// char  add(char a,char b)
// {
// 	return a+b;
// }

//以上三个函数可以用下面一个函数代替(参数类型存在大小包含关系)
 // double add(double a=0,double b=0)
 // {
	// return a+b;
 // }

//以上函数只有数据类型不同.c++ 模板实现与类型无关
//函数模板:函数定义存在未知类型
//模板函数:函数调用,实参确定类型

//函数模板
template<class T>
T  add(T a,T b)
{
	return a+b;
}

template<class T1,class T2,class T3>
T2 fun(T1 a,T2 b ,T3 c)
{
	return a+b+c;
}

template<class T,int N=200>
T  add2(T a,T b)
{
	return a+b+N;
}

int main(int argc, char const *argv[])
{
	// cout<<add(1,2)<<endl;
	// cout<<add(34.56,67.89)<<endl;
	// cout<<add('a','b')<<endl;

	//模板函数
	// cout<<add(1,2)<<endl;
	// cout<<add<double>(34.56,78.9)<<endl;
	// cout<<add('0','1')<<endl;
       //cout<<add<int>(12.34,56.78)<<endl;//存在问题,实参 //double-->形参int.注意参数类型兼容性

	//cout<<fun<int,double,char>(12,45.67,'a')<<endl;
	//cout<<fun(12,45.67,'a')<<endl;

	  cout<<add2(2,3)<<endl;
	  return 0;
}