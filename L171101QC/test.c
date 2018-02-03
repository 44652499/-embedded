#include <stdio.h>
int main(int argc, char const *argv[])
{
	int data=20;
	int *p=&data;
	*p=30;
	p=NULL;
	*p=400;
	printf("%d\n",*p);
	return 0;
}

//root@localhost L171101QC]# gcc  -g  test.c  创建可调式文件

//[root@localhost L171101QC]# gdb  ./a.out  启动调试
//gdb 常用的指令
// list:列出代码,看源码及其行数
// r:运行
// bt:查看堆栈错误信息
