#include <iostream>
using namespace std;
/*
内联函数(inline):
a.函数声明 定义一起完成
b.定义时使用inline修饰

一般函数调用:
1.寻址函数跳转
2.保存当前函数堆栈
3.被调用函数分配堆栈
4.返回到原来函数执行地址,回复堆栈数据

内联特点:
1.调用函数时,用函数语句替换调用函数语句.实际上交就不存在函数调用.类似于宏替换
内联函数优点:减少函数调用,避免函数调用寻址堆栈分配等开销,提高执行效率

内联函数语句要求:
1.语句越短越好
2.不能出现循环
3.不能出现递归
4.不能出现开关语句
*/
//内联函数
void  fun1()
{
	cout<<"fun1"<<endl;
}
void fun2();
//不是内联函数
inline void fun3();
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
//内联函数
inline void  fun2()
{
	cout<<"fun1"<<endl;

}

void  fun3()
{
	cout<<"fun1"<<endl;
}