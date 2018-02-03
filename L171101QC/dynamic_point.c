#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
动态指针:动态分配内存,返回地址给指针存储(指向动态空间指针)
动态分配内存在程序执行语句时动态分配合适大小空间.
动态分配内存一般是指进程堆空间内存
进程堆(heap)空间特性:
1.堆空间内存单元是匿名,必须通过地址访问
2.堆空间分配时是根据内部brk (program break)指针划分
3.调用系统函数分配释放(系统不会自动分配释放)
虚拟地址与物理地址:
操作系统中所有进程使用的虚拟地址,其大小为2^n(机器位数).给每个进程一个虚拟内存,让每个进程都存在一个独立内存访问.避免多个进程堆同意物理内存访问冲突
进程实际上最终访问的是物理内存.虚拟内存通过使用MMU 电路实现与物理内存映射转换

 虚拟内存单元管理:
 1.内存页管理,内核中默认pagesize=4096byte
 2.内存页通过两个链表管理:
    空闲链表:每个节点按照页大小分配,分配内存时,从链表中提取一个节点移动到使用链表中.
    使用链表:链表每个节点是处于正在使用状态,每个节点允许出现碎片.如果释放一个节点把此节点移动空闲链表.分配内存时优先使用内存碎片
 3.分配空间不能跨站两个不完整内存页,否则占用一个新页
 4.动态内存使用最容易出现溢出和越界

分配内存系统函数:malloc calloc realloc
释放内存系统函数:free

malloc:动态分配内存库函数,底层是通过调用brk函数,增加brk指针.brk从未初始化数据段最后地址开始.一般分配内存小于128字节系统调用brk,大于128字节 调用mmap匿名映射函数
 void *malloc(size_t size);

 malloc 函数调用特点:
 1.初始化动态内存空间值为0
 2.分配内存必须是连续空间.但是多次malloc分配空间非连续,没绝对地址大小关系(后分配使用前面内存碎片)
 3.多次调用malloc容易产生碎片,搜索碎片效率低
 4.动态内存地址值必须是能被4整除(32位) malloc_ptr = (malloc_ptr + 3) & ~3

 释放函数free
 void free(void *ptr);
 free完成什么功能:
 1.通过改变内部计数变量值,当值为0时,把空间清0,状态改为可释放状态



*/
int main(int argc, char const *argv[])
{
	
	// int  *ptr=(int*) malloc(10*sizeof(int));
	// //(int*) malloc(10*sizeof(int));  对匿名空间
	// //int  *ptr  局部栈

	// //一般发生缺页错误,分配失败
	// //assert(ptr==NULL);//ptr==NULL 为假 终止进程
	// assert(ptr!=NULL);
	// // if(ptr==NULL)
	// // {
	// // 	printf("malloc fail\n");
	// // }
	// //printf("%d\n",*ptr);
	// int i=0;
	// for(i=0;i<20;i++)
	// {
	// 	*(ptr+i)=i+1;
	// 	printf("%d\t",*(ptr+i));//访问页其它空间,但是容易出现数据篡改 问题
 //    }
 //    printf("\n");

	// char * ch=(char*)malloc(10*sizeof(char));
	// gets(ch);
	// puts(ch);

	// int * ptr=malloc(1*sizeof(int));
	// *ptr=20;
	// printf("%d\n",*ptr);
	// int* p2=ptr;
	// free(ptr);//如果只是使用free ,ptr成为野指针
	// ptr=NULL;//ptr 成为空指针
	// //printf("%d\n",*ptr);
	// *p2=200;
	// //free(p2);//发生二次释放,错误
	// p2=NULL;
	// //printf("%d\n",*p2);

	int *ptr=(int*)malloc(1*sizeof(int));//(int*)malloc(1*sizeof(int)) 发生内存泄漏
	ptr=(int*)malloc(2*sizeof(int));
	free(ptr);
	ptr=NULL;
	return 0;
}

/*
刘坚:什么是内存泄漏?哪些情况引起发生内存泄漏?如何设计一个程序防止检测内存泄漏
*/