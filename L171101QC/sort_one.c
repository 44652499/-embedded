#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
排序:
算法:能解决一定问题高效率代码.
如何评估算法是否好:
1.保证算法结果正确
2.保证算法的时间复杂度最小
3.保证算法空间复杂度最小
决定算法的好坏主要是看:时间复杂度 和空间复杂度
空间复杂度:算法执行过程对内存的消耗
时间复杂度:描述算法随着输入数规模递增,所运行消耗时间构成一个数量级函数关系
注意:算法的时间复杂度不是一个具体运行时间
构成 O(n) 称为是复杂度函数
O(n)实际反映的是算法语句执行的次数关系.一般那单条语句执行一次消耗时间可以
忽略不计,重点与循环多次执行的语句有关
常用的时间复杂度函数:
O(1):常数  
O(n):存在一层循环
O(n^2):存在两层嵌套循环
O(log2 n):存在一层循环,但循环次数以对数递减
O(nlog2 n):存在两层嵌套循环,但是一层循环是n递增,另一层是以对数递减
O(2^n)  ), O(!n)
在代码中分析时间复杂度函数可能出现这种:
o(n)=n^2+n+1  取最大数量级  O(n^2)
O(n)=a*n+b;   与系数无关,取数量级 O(n)

常见的时间复杂度函数从小到大排序:
O(1)<O(log2 n)<O(n)<O(nlog2 n)<O(n^2)<O(2^n)<O(!n)
常用排序方法:
1.冒泡
2.交换
3.选择
4.插入
5.计数(hash查找排序)
6.基数(木桶排序)
7.位排
8.快排(二分排序)
9.希尔排序
10.归并
11.堆排
*/
//冒泡:每轮前后两个元素比较,存在大小交换,一轮结束后最大值在最后
//时间复杂度:O(n^2)
void  sort_1(int array[],int len)
{
	int i,j;
	//控制排序数组元素比较论数
	for(i=0;i<len;i++)
	{
     for(j=0;j<len-1-i;j++)//每轮前后的元素
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
//交换:第一个元素与后面元素比较,存在大小交换.第一个元素一定是最小的
//时间复杂度:O(n^2)
void  sort_2(int array[],int len)
{
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=i+1;j<len;j++)
		{
           if(array[i]>array[j])
           {
           		int tmp=array[i];
     			array[i]=array[j];
     			array[j]=tmp;
           }
		}
	}
}
//3.选择:从数组中每次选一个最小的数放在前面
//时间复杂度O(n^2)
void   sort_3(int array[],int len)
{
	int i,j;
	int pos;
	for(i=0;i<len;i++)
	{
		int tmp=array[i];
		pos=i;
		for(j=i+1;j<len;j++)
		{
			if(tmp>array[j])
			{
				tmp=array[j];
				pos=j;
			}
		}
		if(pos!=i)
		{
			array[pos]=array[i];
			array[i]=tmp;
		}
	}
}
//4.插入:从数组中取出元素,插入到前面有序序列中的合适位置
//O(n^2)
void  sort_4(int array[],int len)
{
	int i,j;
	int tmp;
	for(i=0;i<len;i++)
	{
		tmp=array[i];
		j=i-1;
		while(tmp<array[j]&&j>=0)
		{
           array[j+1]=array[j];
           j=j-1;
		}
		array[j+1]=tmp;
	}
}
//hash查找排序:把待排序的目标数当作一个数组的下标值.
//但是排序目标不能重复,不能是负数
//计算出目标数最大值,分配数据空间
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
	ptrret=(int*)malloc((maxvalue+1)*sizeof(int));
	assert(ptrret!=NULL);
	return ptrret;
}
//时间复杂度为O(1)
void  sort_5(int array[],int len)
{
	int * ptrret=malloc_array_max_value(array,len);
	int i;
	for(i=0;i<len;i++)
	{
		ptrret[array[i]]=array[i];
	}

	for(i=0;i<91;i++)
	{
		if(ptrret[i]>0)
		{
			printf("%d\t",ptrret[i]);
		}		
	}
	printf("\n");
}

//计数排序:解决hash查找排序 目标数重复的问题
void  sort_6(int array[],int len)
{
	int * ptrret=malloc_array_max_value(array,len);
	int i;
	for(i=0;i<len;i++)
	{
		ptrret[array[i]]++; //计数
	}

	//输出
	for(i=0;i<91;i++)
	{
		while(ptrret[i]-->0)
		{
			printf("%d\t",i);
		}
	}
	printf("\n");
}

//

int main(int argc, char const *argv[])
{
	int array[]={6,32,9,13,9,90,32,73};
	//sort_1(array,8);
	//sort_2(array,8);
	//sort_3(array,8);
	//sort_4(array,8);
	//sort_5(array,8);
	sort_6(array,8);
	int i;
	// for(i=0;i<8;i++)
	// {
	// 	printf("%d\t",array[i]);
	// }
	// printf("\n");
	return 0;
}