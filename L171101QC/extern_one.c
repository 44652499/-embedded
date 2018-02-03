#include <stdio.h> 
#include <limits.h>
#include "add.h"
/*
extern:外部引用,在一个文件访问另一个全局变量
extern 引用变量注意点:
1.引用全局变量
2.没有分配空间
3.与定义的形式一样

volatile:易变化.每次都是访问变量最新值(有时可能是访问缓存值)
volatile  int  data; 取消编译器优化
*/
int g_data=200;//全局变量
//static int g_data=200;// extern int g_data;  错误
int g_array[]={100,200,300};
int main(int argc,const char* argv[])
{
    printf("%X\n",&g_array);
    printf("%d\n",add(1,2));
    printf("%d\n",g_data);
    return 0;
}
/*
多个源码文件编译:
[root@localhost L171001QC]# gcc  -c  add.c  //-c  只完成预编译 编译 汇编 未完成链接(link).创建目标文件
[root@localhost L171001QC]# gcc  -c extern_one.c 
[root@localhost L171001QC]# gcc  add.o  extern_one.o  -o extern_one  //link 把多个目标文件链接成一个可执行文件
*/