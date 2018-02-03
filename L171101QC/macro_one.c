//#include <stdio.h>
#include "define_head.h"
#include "define_head2.h"
/*
预编译:编译前一个步骤,主要是完成头文件加载, 宏变量,执行预编译指令生成一个新的编译

[root@localhost L171101QC]# gcc  zy_one.c 把源文件编译成可执行二进制文件
把源文件编译成二进制可执行文件经过步骤:
1.预编译
2.编译
3.汇编
4.链接
[root@localhost L171101QC]# gcc -E macro_one.c 只完成预编译,生成新的文件
预编译不会检测语法,不考虑数据类型,不会分配内存

加载头文件:
1.#include <stdio.h>:从系统目录找到头文件(linux 系统目录是:/usr/include)
2.#include "stdio.h":首先从当前目录找到头文件,再到系统目录找文件.一般工程的自定义头文件存放在工程当前目录下.
如果头文件保存在/home 目录下,如何加载头文件?
头文件在当前工程目录下:
[root@localhost L171101QC]# gcc  -c  define_head.c
[root@localhost L171101QC]# gcc  -c  macro_one.c 
[root@localhost L171101QC]# gcc define_head.o  macro_one.o -o 
macro

[root@localhost L171101QC]# mv  define_head.h /home
[root@localhost L171101QC]# gcc  -c -I/home  macro_one.c //指定头文件所在的目录  -I 头文件绝对路径值

2.为什么自定义头文件用上
#ifndef _A_   //_A_自定一唯一标识符
#define _A_
#endif
作用:防止头文件重复加载
*/
int main(int argc,const char* argv[])
{
    printf("hello world\n");
    printf("%d\n",add(3,4));
    return 0;
}