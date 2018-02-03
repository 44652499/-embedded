#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
/*
内核的符号导入与引用符号
cat/proc/kallsyms | grep test    kallsyms内核符号表
*/

int add_test(int a,int b)
{
	return (a+b);
}

int sub_test(int a,int b)
{
	return a-b;
}

EXPORT_SYMBOL(add_test);
EXPORT_SYMBOL(sub_test);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("LZL");
