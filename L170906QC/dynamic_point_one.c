#include <stdio.h>
#include <stdlib.h>
/*
动态指针:指针指向的空间是动态分配(进程执行语句时分配)
进程占用虚拟内存, 其中有一部分称为heap(堆)
堆空间特点:
1.匿名,不能标识符标记.只能用指针变量指向
2.堆空间调用系统函数分配,调用系统函数释放
3.使用堆空间最容易出现内存泄漏
虚拟内存:通过虚拟技术让每一个进程都拥有一个独立物理内存
虚拟内存通过段与物理内存建立一种映射关系
虚拟内存通过内存页面管理,正常情况先按照页交替加载.
虚拟内存页面一般为4096=4k
申请内存时,底层是以页为单位分配.但是实际使用时内存需求可能是不定大小,容易造成内存碎片
申请内存时:
1.首先使用符合大小的内存碎片,但不能跨两个不完整页面
2.当碎片大小不满只,重新分配一个新页面(有可能产生碎片)

内存管理:
1.空间链表
2.使用链表
分配时:从空闲链表中取一个节点到使用链表中
释放时:从使用链表中取一个节点到空闲链表中

针对小内存处理slab 分配器:
把一页内存根据2^n 次幂分配,满足小内存需求

brk改变数据段大小,相当于是一个指针指向页面,通过移动指针实现内存的分配和释放
在用户空间一般调用malloc  calloc realloc 实现内存动态分配,系统函数中已经实现分页 内存对齐  小内存管理
#include  <stdlib.h>
分配函数:
 void *malloc(size_t size);
 void *calloc(siz_t nmemb, size_t size);
 void *realloc(void *ptr, size_t size);
 释放函数
 void free(void *ptr);

 malloc分配过程:
 1.从使用链表中查找合适大小碎片
 2.如果第一步失败,从空间链表中分配
 3.分配的内存不能跨站两个不完整页面
 4.内存对齐(4字节对齐)

 void *p;
	if (size < 0)
		return NULL;
	if (!malloc_ptr)
		malloc_ptr = free_mem_ptr;
    malloc_ptr = (malloc_ptr + 3) & ~3;   //4对齐
    	p = (void *)malloc_ptr;
	malloc_ptr += size;
	if (free_mem_end_ptr && malloc_ptr >= free_mem_end_ptr)
		return NULL;
    malloc_count++;    
    
经常连续调用malloc 缺陷:
1.容易产生更多碎片
2.搜索判断更多碎片是否符合需求大小
3.效率
用内存池思想尽量减少mallo缺陷

free  释放原理:
1.对内存使用计数-1处理,只有当计数为0时,内存为空间状态,放入到空闲链表中
2.对内存中的值清0
*/
int main(int argc,const char* argv[])
{
    //int*p=malloc(4);
   // int*p=malloc(1*sizeof(int));
    // int*p=malloc(10*sizeof(int));
    // if(p==NULL)
    // {
    //     printf("malloc error\n");
    //     return;
    // }
    //*p=20;
    //printf("%d\n",*p);

    // int i=0;
    // //可以超出分配大小使用,但是不建议这样使用,容易覆盖其它数据
    // for(i=0;i<15;i++)
    // {
    //     p[i]=i+1;
    // }
    // for(i=0;i<15;i++)
    // {
    //     printf("%d\t",p[i]);
    // }

    // int  *  p=malloc(1*sizeof(int));
    // *p=30;
    // printf("%d\n",*p);
    // // int size=*((int*)p-1);
    // // printf("%d\n",size);
    // //释放
    // free(p);
    // //printf("%d\n",*p);
    // //p=NULL;//有可能出现野指针(悬浮指针)
    // //*p=20;    
    // //printf("%d\n",*p);

    //int *p=malloc(5*sizeof(int));
    //int *p=calloc(5,sizeof(int));
    // int *p=realloc(NULL,5*sizeof(int));
    // int i;
    // for(i=0;i<5;i++)
    // {
    //     printf("%d\n",p[i]);
    // }
    // free(p);
    // p=NULL;   
    
    return 0;
}