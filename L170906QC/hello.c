#include <stdio.h>
/*
编码的是源代码
源代码经过编译器生成可执行文件
执行可执行文件是进程
linux进程内存结构:
32位系统进程大小为4G(进程寻址虚拟地址空间值).虚拟地址大小从0x00000000~0xfffffff
可执行文件 与进程存在 1对多
1-3G:属于用户
3-4G:属于内核

[root@localhost L170906QC]# size a.out  查看执行文件与进程映射位置大小
进程内存结构:
1.代码段(text):处理器执行指令(源码二进制镜像文件)
2.数据段(data):在源码中定义已经初始化全局或静态变量
3.BSS段(未初始化数据段):在源码定义未初始化全局变量或静态变量.bss段空间系统自动赋值为0


全局变量:定义变量不属于"{}",属于文件

静态变量:

初始化:在定义变量并赋值

定义:分配内存动作发生

声明:对已经存在空间说明使用

数据类型:数据类型规范内存分配单位

c语言数据类型:
a.系统类型(基础类型) 32位
  char      1byte
  short     2byte
  int       4byte
  float     4byte
  long      4byte
  double    8byte
  long long  8byte
b.自定义复合类型

编译时为源码中全局变量或静态变量分配内存
进程结束时释放,伴随进程运行

进程内存结构:
4.heap 堆空间:执行时调用系统函数(malloc  calloc realloc)分配内存空间
5.内存映射区:a.文件内存映射. b.映射动态库文件(.so)
6.stack 栈:执行时为定义局部变量 函数参数 函数返回值分配空间
局部变量:定义在"{}"之间
栈特点:先进后出(FILO),地址增长方向从高到低(先定义变量分配在高地址)
局部变量进入语句块分配空间,离开语句块释放

heap堆特点:空间都是匿名,只能通过其它空间记录地址值
heap空间调用函数分配释放

"&"获取地址空间起始地址

标识符作用:在程序记录区分内存空间.方便程序员识别

*/

int  g_data=10000;//定义全局变量并初始化
char g_a='a';
int  s_data;//为初始化全局变量
char s_b;
int main(int argc, char const *argv[])
{
	// g_data=300;//赋值
	// //printf("hello world\n");
	// printf("%d\n",s_data);
	// //printf("%d\n",s_b);
	// printf("%c\n",s_b);//0 值 表示 字符'\0' ascii编码值

	int l_a;
	{
		int l_b;
	}
	// printf("%X\n",&main);//输出代码段起始地址
	// printf("%X\n",&g_data);//输出数据段g_data起始地址
	// printf("%X\n",&g_a);//输出数据段g_data起始地址
	// printf("%x\n",&s_data);//输出BSS段s_data起始地址
	//printf("%p\n",&l_a);////输出栈l_a起始地址
	//printf("%p\n",&l_b);

	int *ptr=(int*)malloc(1*sizeof(int));
	//右边存储在堆空间,左边存储在栈
	printf("%X\n",ptr);//堆空间地址值
	printf("%X\n",&ptr);//ptr局部变量地址值
	return 0;
}

/*
终端:
[root@localhost L170906QC]# gcc hello.c  //创建一个可执行文件 a.out
[root@localhost L170906QC]# ./a.out
*/