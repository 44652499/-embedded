#include <stdio.h>
#include "macro_one_test.h"
/*
[root@localhost L170906QC]# gcc switch_one.c 
以上编译语句完成4个步骤:
1.预编译
2.编译
3.汇编
4.链接
预编译(预处理):加载头文件  宏替换  预编译条件语句执行.不会检测语法 没有数据检测  没有内存分配
[root@localhost L170906QC]# gcc -E  macro_one.c 

加载头文件:
#include <stdio.h>:一般表示系统头文件,从系统默认目录(/usr/include)找头文件
#include "stdio.h":一般表示自定义头文件,首先从工程当前目搜索,在到系统默认目录搜索.
[root@localhost L170906QC]# mv   macro_one_test.h  /usr/include 
[root@localhost L170906QC]# gcc -E  macro_one.c 
如果自定义头文件 存放在其它目录,如何读取?
[root@localhost L170906QC]# mv  /usr/include/macro_one_test.h  .
[root@localhost L170906QC]# mv  macro_one_test.h   /home

[root@localhost L170906QC]# gcc   -I /home -E  macro_one.c  //-I指定读取头文件目录值

const修饰只读变量:
*/
const int g_data=20; //代码段常量值
const int g_data2;//BSS段
int g_data3=30;//数据段
int g_data4;//BSS段
int main(int argc, char const *argv[])
{
	//printf("Hello\n");
	int l_data; //栈
	const int l_data2;//栈
	char* p="abcd";//"abcd"为常量值
    printf("%X\n",&main);
	printf("%X\t%X\t%X\n",&g_data,p,&g_data3);
	printf("%X\t%X\n",&g_data2,&g_data4);
	printf("%X\t%X\n",&l_data,&l_data2);
	return 0;
}