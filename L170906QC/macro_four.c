#include <stdio.h>
/*
条件编译指令:
#if
#ifndef
#ifdef
#define
#endif
#else
#undef
#error
#line
#pragma
*/
#define OS   WINDOW
//#define  A
#define B

#ifdef B
#error("error")
#endif
int main(int argc, char const *argv[])
{
	// #if OS==WINDOW
	//    printf("WINDOW");
	// #else
	//    printf("linux");
	// #endif
   // #undef A //取消宏定义

	#ifdef A 
	  printf("WINDOW");
	#else
	  printf("linux");
    #endif
	//编译时指定宏:[root@localhost L170906QC]# gcc -D A  macro_four.c  -o a.out

	return 0;
}