#include <iostream>
using namespace std;
/*
引用:对已经存在变量另取别名,并没有分配新的空间

引用变量定义:
被引用空间数据类型  &  引用变量名=被引用空间;

const 被引用空间数据类型  &  引用变量名=被引用空间;

引用变量与指针区别:
1.引用变量不占用空间,指针占用4个字节
2.引用变量必须初始化,指针不一定
3.引用变量不能改变引用,指针可以改变指向

引用变量一般用来作为函数形参和函数返回值
c++ 函数传参:值  指针  引用
*/
//引用参数形式:直接使用实参空间
void swap(int & a,int & b)
{
	int temp=a;
	a=b;
	b=temp;
}
//const 限制引用参数不能改变实参值
void fun(const int& a)
{
	//a=300;//错误
    cout<<"fun"<<endl;
}

int &  fun2(int & a)
{
	return a;
}

//错误,不能返回局部变量的引用
// int &  fun3(int a)
// {
// 	return a;
// }

int  g_data=300;
int & fun4()
{
	return g_data;
}

int main(int argc, char const *argv[])
{
	//int a=20;
	//cout<<hex<<&a<<endl; //16进制值输出
	//int &b=a;//b是一个引用变量,引用a变量空间
	//cout<<hex<<&b<<endl; 
	//b=4000;
	//cout<<a<<endl;
	//int &c1=a;//可以用c1 修改a 空间值
	//const int &c2=a;//不可以用c2修改a 空间值
	//以上都正确,const是否使用,根据被引用空间是用const 修饰
	//const int a=30;
	//int &b=a;//错误 ,只读空间只能使用只读引用
	//const  int &b=a;

	// int a=400;
	// int &b=a;//初始化,引用变量不能改变引用
	// int c=500;
	// b=c;//赋值,没有改变引用
	// cout<<a<<endl;

	// int a=5,b=6;
	// swap(a,b);
	// cout<<a<<'\t'<<b<<endl;

	// int a=50;
	// fun(a);

	fun4()=5000;//g_data=5000;
	cout<<g_data<<endl;
	return 0;
}