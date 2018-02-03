#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#define N  100
/*
记录并检测程序中是否存在内存泄漏
设计思想:自定义一个能记账分配函数
*/
//设计记录动态分配内存的信息
typedef struct 
{
	void* addr;
	size_t  size;
	int  isfree; //isfree 0:未释放  1:已释放
}mem_block;

//定义一个全局数组账本
mem_block memarray[N];

//定义一个全局数据下标值
int gindex=0;

//自定义分配函数
void*   define_malloc(size_t size)
{
	void * ptraddr=NULL;
	ptraddr=malloc(size);
	assert(ptraddr!=NULL);
	//记账
	mem_block m_block;
	bzero(&m_block,sizeof(m_block));
	m_block.addr=ptraddr;
	m_block.size=size;
	m_block.isfree=0;

	memarray[gindex++]=m_block;
	return ptraddr;
}
//
void  define_free(void*  addr)
{
	assert(addr!=NULL);
	//销帐
	int i;
	for(i=0;i<gindex;i++)
	{
		if(memarray[i].addr==addr)
		{
			
			free(addr);
            addr=NULL;
            memarray[i].isfree=1;
		}
	}    
}
//自定义查记录函数
void  printmem()
{
	int i;
	for(i=0;i<gindex;i++)
	{
		if(memarray[i].isfree==0)
		{
			printf("%p\t%d\n",memarray[i].addr,memarray[i].size);
			define_free(memarray[i].addr);
		}
	}
}

int main(int argc, char const *argv[])
{
	int * p1=(int*)define_malloc(4*sizeof(int));
	char * p2=(char*)define_malloc(40*sizeof(char));
	short * p3=(short*)define_malloc(7*sizeof(short));
	define_free(p2);

	printmem();
	return 0;
}