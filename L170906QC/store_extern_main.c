#include <stdio.h>
#include "store_extern.h"
//定义个全局变量
//int  g_idata=20;
//static int  g_idata=20;//extern int g_idata 错误,不能跨文件引用

//double   g_idata=20;
int  g_array[3];
int main(int argc, char const *argv[])
{
	int ret=add_int(1,2);
	printf("%d\n",ret);
	//printf("%d\n",g_idata);
	printf("%d\n",g_array[0]);
	return 0;
}
/*
多个源文件如何编译?
[root@localhost L170906QC]# gcc -c  store_extern.c
[root@localhost L170906QC]# gcc  -c  store_extern_main.c 
[root@localhost L170906QC]# gcc  store_extern.o  store_extern_main.o  -o  store_extern_main
[root@localhost L170906QC]# ./store_extern_main

*/