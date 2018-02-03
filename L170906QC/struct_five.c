#include <stdio.h>
#include <string.h>
#include  <stdlib.h>
#define  N  100
/*实现内存泄漏信息检测与输出并处理
系统给定mallo  free 函数只负责内存分配与释放,并没有记录分配信息.自定义实现增加记账的作用.
记账信息体就是一个结构体
*/
//定义记账结构体
typedef struct
{
    void * addr;//记录分配起始地址
    int size;//记录分配大小
    int is_free;//0:未释放 1:释放
}memory_blck;

//定义记录全局数组
memory_blck  g_mem_array_blck[N];

//定数组全局下标值
int  g_index=0;

//定义malloc函数
void*  define_malloc(size_t size)
{
    void* ptr=malloc(size);
    if(ptr!=NULL)
    {
        //记账
        memory_blck  mem_blck;
        mem_blck.addr=ptr;
        mem_blck.size=size;
        mem_blck.is_free=0;

        g_mem_array_blck[g_index++]=mem_blck;
    }
    return ptr;
}
//定义free函数
void define_free(void * addr)
{
    if(addr!=NULL)
    {
        free(addr);
        //修改记录中是否释放状态
        int i;
        for(i=0;i<g_index;i++)
        {
            if(g_mem_array_blck[i].addr==addr)
            {
                g_mem_array_blck[i].is_free=1;//已经释放
            }
        }
        addr=NULL;
    }
}
int main(int argc, char const *argv[])
{
    int *p1=(int*)define_malloc(10*sizeof(int));
    int *p2=(int*)define_malloc(3*sizeof(int));
    int *p3=(int*)define_malloc(5*sizeof(int));
    int *p4=(int*)define_malloc(6*sizeof(int));
    define_free(p3);
    //输出泄漏地址空间
    int i;
    for(i=0;i<g_index;i++)
    {
        if(g_mem_array_blck[i].is_free==0)
        {
            printf("%X\t%d\n",g_mem_array_blck[i].addr,g_mem_array_blck[i].size);
             //后续再释放
            define_free(g_mem_array_blck[i].addr);
        }
    }
    return 0;
}