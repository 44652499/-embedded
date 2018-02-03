#include <stdio.h>
/*
预编译指令:预编译时执行指令,可以存在一定选择逻辑
常见的预编译指令:
#if
#ifndef
#ifdef
#define
#endif
#else
#undef 取消宏定义
#error:显示错误信息
#line:显示行号
#pragma: 一般与pack 一起用指定内存对齐字节大小
*/
//#define  OS   win  //指定OS 值
//#define  A
//#define  A
#ifdef   A
#error   hello world
#endif
int main(int argc,const char* argv[])
{
    // #if OS==win
    //   printf("win\n");
    // #else
    //   printf("linux\n");
    // #endif

   // #undef A
   //[root@localhost L171101QC]# gcc -D  A  macro_five.c 
   //编译语句中使用-D选项 定义宏
    #ifdef A
      printf("win\n");
    #else
      printf("linux\n");
    #endif
    return 0;
}