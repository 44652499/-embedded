#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAX 400000000   //4亿个数
/*
给4亿个不重复的unsigned int的整数,没排过序的,然后再给一个数,如何快速判断这个数是否在那4亿个数当中
*/
//获取位数组的最大大小
unsigned int   init_bit_block_size()
{
       unsigned int block_size=MAX%32?MAX/32+1:MAX/32;
        return block_size;
}
//错误信息提示输出
void   print_error_msg(char* msg_title,char* msg_info)
{
        printf("%s:%s\n",msg_title,msg_info);
        return;
}
//获取位数组的集合
unsigned int *  init_bit_array(int block_size)
{
        unsigned int * ptr=(unsigned int*)malloc(block_size*sizeof(int));
        if(ptr==NULL)
        {
                print_error_msg("init_bit_array","malloc fail");
        }
        bzero(ptr,block_size*sizeof(int));
        return ptr;
}
//根据目标数设置位数组值
void  set_bit_array(int * ptr,int value)
{
       unsigned int  n_block=value/32;
       unsigned int  n_remain=value%32;
       unsigned int bit_value=0x1;
       ptr[n_block]=ptr[n_block]|(bit_value<<n_remain);
}
//根据目标数判断在位数组中是否存在
int  is_exists_bit_array(int *ptr,int value)
{
        unsigned int  n_block=value/32;
        unsigned int  n_remain=value%32;
        unsigned int bit_value=0x1;
        if(ptr[n_block]&(bit_value<<n_remain))
        {
                return 1;//存在
        }
        return 0;//不存在
}

//释放动态分配空间
void  free_bit_array(int *ptr)
{
        if(ptr!=NULL)
        {
                free(ptr);
                ptr=NULL;
        }
}

int  main(int argc,const char* argv[])
{
        unsigned int block_size=init_bit_block_size();
        unsigned int *ptr=init_bit_array(block_size);
        if(ptr==NULL)
        {
                print_error_msg("main:","bit array init fail");
        }
        set_bit_array(ptr,1234567);
        int ret=is_exists_bit_array(ptr,1234568);
        if(ret)
        {
                printf("is exists\n");
        }
        else
        {
                printf("not exists\n");
        }
        free_bit_array(ptr);
        return 0;
}
