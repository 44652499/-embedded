#include  <iostream>
using namespace std;
template<typename T>//T表示一种类型,还可以使用非类型
void  fun(T a,T b)
{
	T c=a+b;
	cout<<c<<endl;
}
// template<class  T,int N>//int N 表示一个整数
// T  fun2(T a,T b)
// {
// 	//N=300;  错误,100=300 相当于一个只读变量
// 	return a+b+N;
// }
// template<class  T,int N=100>//int N 默认值
// T  fun2(T a,T b)
// {
// 	return a+b+N;
// }
// template<class  T=int,int N=100>//int N 默认值
// T  fun2(T a,T b)
// {
// 	return a+b+N;
// }
template<class  T,double N>//错误,函数模板非类型参数只能是正数和指向对象的指针
T  fun2(T a,T b)
{
	return a+b+N;
}
int main(int argc, char const *argv[])
{
	//fun(1,2);
	//fun('0','1');
	//cout<<fun2<int,100>(1,2)<<endl;
   // int a=100;  错误, template<class  T,int N>  N  相当于是一个只读变量
	//const int a=100;
	//cout<<fun2<int,a>(1,2)<<endl;
	//cout<<fun2(1,2)<<endl;//[root@localhost L170301Q]# g++  -std=c++11 functiontemplate2.cpp  使用默认值
	//cout<<fun2<int>(1,2)<<endl;
	//cout<<fun2<int,200>(1,2)<<endl;
    //错误
	//cout<<fun2<int,34.56>(1,2)<<endl;
	//cout<<fun2<double,34.56>(1,2)<<endl;
	return 0;
}