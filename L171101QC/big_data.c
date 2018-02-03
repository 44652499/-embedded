#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define N  400000000
/*
从4亿不重复无符号整数中,查找任意一个输入整数是否存在
思路:
1.使用位数组
2.使用数组下标志特性
*/
//分配为数组空间,把一个整数折算成一个32个元素位数组
int *  get_bit_array()
{
	int size=N/32+1;
	int * ptr_bit=(int*)malloc(size*sizeof(int));
	assert(ptr_bit!=NULL);
	bzero(ptr_bit,size);
	return ptr_bit;
}
//存数据到位数组中
void  save_bit_array(int * ptr_bit,int value)
{
	int block_index=value/32;//存储第几块
	int block_item=value%32;//存储快第几位
	int flag=0x1;
	ptr_bit[block_index]=ptr_bit[block_index]|(flag<<block_item);
}

//输入数查找是否存在
void   find_bit_array(int * ptr_bit,int value)
{
	int block_index=value/32;
	int block_item=value%32;
	int flag=0x1;
	int isfind=ptr_bit[block_index]&(flag<<block_item);
	if(isfind==0)
	{
		printf("not found\n");
	}
	else
	{
		printf("find\n");
	}

}

int main(int argc, char const *argv[])
{
	int * ptrbit=get_bit_array();
	//save_bit_array(ptrbit,0);
	save_bit_array(ptrbit,23);
	save_bit_array(ptrbit,236);
	save_bit_array(ptrbit,23378);
	save_bit_array(ptrbit,99999991);
	save_bit_array(ptrbit,9090991);
	save_bit_array(ptrbit,888778);
	save_bit_array(ptrbit,123456789);
	find_bit_array(ptrbit,0);
	return 0;
}
