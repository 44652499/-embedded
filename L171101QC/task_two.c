#include <stdio.h> 
#include <limits.h>
/*
程序:是一个静态存储文件,占用存储磁盘.不占用内存
进程:是程序文件动态执行过程,占用虚拟内存.
进程是操作系统资源分配最小单位.
进程逻辑结构struct task_struct  包含100多个成员
32位机器每个进程都是独立空间,占用4G虚拟内存(struct mm_struct) 4G表示进程虚拟内存地址区间值:0x00000000~0xffffffff(虚拟地址值).当进程执行时把虚拟内存映射物理内存.所有进程共享同一个物理内存.

进程结构:
1.1-3G:用户进程空间(编码中代码 变量 数据 等)
2.3-4G:内核空间(编码中系统函数调用,一般用户程序不能直接访问)

用户进程空间结构:
1.text 代码段
2.data 已初始化数据段
3.bss  未初始化数据端
4.堆   程序执行是通过调用系统函数动态分配内存
5.文件内存映射区(map)
6.栈   程序定义局部变量 或函数调用的参数及其返回值

[root@localhost L171001QC]# size a.out
   text	   data	    bss	    dec	    hex	filename
   1053	    272	      4	   1329	    531	a.out
数据段:已经初始化全局 或 静态变量
变量定义:必须为变量分配内存
变量声明:变量已经存在,重新引用声明,不再分配空间
bss:未初始化全局 或 静态变量,系统用0填充
栈:局部变量

全局变量:在文件中定义不属于"{}"

局部变量:在"{}"定义变量

全局变量生命周期:
1.在编译时分配空间
2.进程结束释放
局部变量生命周期
1.在进入定义"{}"分配空间
2.离开定义"{}"释放空间

存储类型:
1.auto
2.register
3.static
4.extern
*/
int g_data=20;//数据段
int g_data2;//bss段
int g_data3=20;
int main(int argc,const char* argv[])
{
    static int  data4=40;//数据段
    static int data5;//bss段
    printf("%d\t%d\n",g_data2,data5);
    int  l_data1;//栈
    int  l_data2;//栈空间地址值从高到低递增,现定义变量地址高于后定义的变量
    printf("%X\t%X\n",&g_data,&g_data3);
    //printf("%X\t%X\n",&g_data2,&g_data3);
    printf("%X\t%X\n",&l_data1,&l_data2);
    int  l_a=30;
    {
        int  l_a=40;
        printf("%d\n",l_a);//优先访问同作用域变量
    }   
    printf("%d\t%d\n",l_data1,l_data2);//栈为初始化值,将是一个随机值.
}
//1.画出进程结构图
//2.计算 int 最大值与最小值