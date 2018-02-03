#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define  N  10  //定义木桶大小
/*
基数排序:把待排序数分解成个十百...之后一一排序.也称为木桶排序
使用一个二维数组记录每次排序结果.二维数组行表示分解的每个数字[0,9].
列记录重复
*/

//获取最大值并返回其位数
int  get_digit_bit(int *array,int len)
{
	int maxvalue=array[0];
	int i;	
	for(i=0;i<len;i++)
	{
		if(array[i]>maxvalue)
		{
			maxvalue=array[i];
		}
	}
	int cnt=0;
	while(maxvalue!=0)
	{
	  cnt++;
	  maxvalue=maxvalue/10;
	}
	return cnt;
}
//创建木桶
int** create_array()
{
	int ** ptr=NULL;
	ptr=(int**)malloc(N*sizeof(int*));
	assert(ptr!=NULL);
	int i;
	for(i=0;i<N;i++)
	{
		*(ptr+i)=(int*)malloc(N*sizeof(int));
		assert(*(ptr+i));
	}
	return ptr;
}
//清空木桶函数
void  clear_array(int ** ptr)
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			ptr[i][j]=0;
		}
	}
}
//使用木桶排序
void  sort_array(int *array,int len,int **ptr)
{
	int i;
	int col=0;
	int max_bit=get_digit_bit(array,len);
	int k=1;
	while(k<=max_bit)
	{
		int t=1;
		int tmp=1;
		while(t<k)
		{
			tmp=tmp*10;
			t++;
		}
		//把待排序数放入木桶
		for(i=0;i<len;i++)
		{
			col=0;
			
			while(ptr[array[i]/tmp%10][col]!=0)
			{
				col++;
			}
			ptr[array[i]/tmp%10][col]=array[i];
		}

		//从木桶中取出数放入到待排序数组中
		int index=0;
		for(i=0;i<N;i++)
		{
			for(col=0;col<N;col++)
			{
				if(ptr[i][col]!=0)
				{
					array[index++]=ptr[i][col];
				}
				else
				{
					break;
				}
			}
		}
		k++;
		clear_array(ptr);
	}	
}

//释放木桶
void free_array(int ** ptr)
{
	int i,j;
	for(i=0;i<N;i++)
	{
		free(*(ptr+i));
		*(ptr+i)=NULL;
	}
	free(ptr);
	ptr=NULL;
}

int main(int argc, char const *argv[])
{
	int array[]={6,73,56,13,15,90,9,32};
	int **ptr=create_array();
	sort_array(array,8,ptr);
	free(ptr);
	int i;
	for(i=0;i<8;i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
	return 0;
}