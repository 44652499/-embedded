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
为什么定义变量必须有数据类型?
数据类型是限制分配内存大小单位.
c语言常用的数据类型:
char  1byte
short  2byte
int   4byte
long  4byte
float 4byte
double 8byte
long long 8byte

计算  char  表示最大值域最小值:
char :
1 0000000   取反  1 1111111  +1   1  10000000  -128
1 1111111   取反  1 0000000  +1   1  0000001   -1
0 1111111  127
signed char:min=-128  max=127
unsigned char:min=0  max=255

为什么使用变量标识符:
用来表示内存块,实际底层使用的编码值(0x00000000~0xffffffff)

*/
int g_data=20;//数据段
int g_data2;//bss段
static  int g_data3=20;
char  c_data='a';//数据段仍然增加4字节,考虑到内存地址对齐 如:(malloc_ptr + 3) & ~3;
char  c_data2='b';
int main(int argc,const char* argv[])
{
    static int  data4=40;//数据段
    static int data5;//bss段

    //char  ch='b';//char  实际就是一个整数的1/4
    //char ch=98;
    //char ch=126; //所有字符用ascii编码值表示,zhi用7位表示ascii编码值区间位0-127
   // char  ch=0;//0 表示字符 '\0'
    //char  ch='0'; //'0' ascii  48
   // char  ch='A';  //'A' ascii  65
    //printf("%d\n",ch);
    //printf("%c\n",ch);
    //char  ch=300;//溢出,长数据类型赋值给短数据类型溢出
    //char ch=(char)300;//使用强制类型转换
    //printf("%d\n",ch);//300   100101100  ch只能取低8位 00101100  
    //char ch=(char)405;
    //printf("%d\n",ch);//405 110010101   ch只能取低8位 10010101 
    //计算底层存储都是补码.如果符号位是1表示负数,补码取反+1表示原码: 1 1101011

    printf("%d\n",SCHAR_MIN);
    printf("%d\n",SCHAR_MAX);

    // long  a=1123L;
    // unsigned long b=12321UL;
    // long long c=111LL;
    // float  f=123.45f;
    // double d=34.56;
    int  d;
    int f;
    int c;
    printf("%X\n",&d);//"&"取标识符所表示空间的起始地址,结束地址根据类型计算和内存对齐
    printf("%x\n",&f);
    printf("%p\n",&c);
    return 0;
}
/*
struct float
{
    unsigned int negative:1;
	unsigned int exponent:8;
	unsigned int mantissa:23;
}

struct double
{
    unsigned int negative:1;
	unsigned int exponent:11;
	unsigned int mantissa0:20;
	unsigned int mantissa1:32;
}
以上 刘坚 详细说明:
*/