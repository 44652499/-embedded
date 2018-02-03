#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
+0  -0 存储：
计算底层存储都是补码，正数补码与原码一样，负数补码=对应正数原码取反+1
+0 原码 补码 0   ....  000
-0  0 ... 0000  取反  1 ... 1111  +1    0 ... 0000
*/

//二分查找：折半查找，待查找数据必须有序，目标数与中间数比较
//如果大,目标在左半部分
//如果小,目标在右半部分
//继续折半
int  find_half(int * array,int begin,int end,int dest)
{
	int mid;
	while(begin<=end)
	{
		mid=(begin+end)/2;
	    if(dest<array[mid])
		{
			end=mid-1;
		}
		if(dest>array[mid])
		{
			begin=mid+1;
		}
		if(dest==array[mid])
			return 1;
	}
	return 0;
}

void sort_data(int *array,int len)
{
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				int tmp=array[j];
				array[j]=array[j+1];
				array[j+1]=tmp;
			}
		}
	}
}
//位排序:用位数组的下表表示排序目标数.维数组可以节省空间.比如一个整数可以表示32个元素位数组
int *  malloc_array_max_value(int array[],int len)
{
	int* ptrret=NULL;
	int i;
	int maxvalue=array[0];
	for(i=1;i<len;i++)
	{
    	if(maxvalue<array[i])
    	{
    		maxvalue=array[i];
    	}
	}
	int  int_block_num=maxvalue/32+1;//空间分配
	ptrret=(int*)malloc(int_block_num*sizeof(int));
	assert(ptrret!=NULL);
	return ptrret;
}
//把待排序目标数放入到位数组中
void  set_array_bit(int * array,int len,int * ptrret)
{
	int i;
	int tmp;
	int val=0x1;
	for(i=0;i<len;i++)
	{
		tmp=array[i];
		int block_i=tmp/32; //计算应该放在整形数组第几个元素
		int block_index=tmp%32;
		//把正数对应那位赋值1
		ptrret[block_i]=ptrret[block_i]|(val<<block_index);
	}
}
//从位数组中取出位元素值为1的下标值
void   get_array_bit(int * ptrret,int ptrret_len)
{
	int i;
	int tmp;
	int j;
	int val=0x01;
	for(i=0;i<ptrret_len;i++)
	{
		tmp=ptrret[i];
		for(j=0;j<32;j++)
		{
			if(tmp&(val<<j))
			{
				printf("%d\t",i*32+j);
			}
		}
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	int array[]={6,32,9,13,15,90,56,73};
	//排序
	// sort_data(array,8);
	// int ret=find_half(array,0,7,60);
	// if(ret)
	// {
	// 	printf("find ok\n");
	// }
	// else
	// {
	// 	printf("not found\n");
	// }
	int *ptrret=malloc_array_max_value(array,8);
	set_array_bit(array,8,ptrret);
	get_array_bit(ptrret,3);
	return 0;
}
//假如存在4万亿个不重复无符号整数,输入一个整数如何查找该数是否存在