#include <stdio.h>
/*
void* 指针:一般万能指针,底层函数的参数类型一般设计成void*,可以接收上层任意类型数据存储地址
*/
int main(int argc, char const *argv[])
{
	int a=20;
	char  ch='a';
	void *ptr=&a;
	//void * 获取指向空间数据时,必须先转换成一个具体数据类型名,否则无法计算结束地址
	printf("%d\n",*(int*)ptr);
	ptr=&ch;
	printf("%c\n",*(char*)ptr);	
	return 0;
}