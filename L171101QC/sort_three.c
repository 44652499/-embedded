#include <stdio.h>
/*
归并排序:
1.拆分:把数组拆分成n个子数组,每个数组元素只有一个
2.合并:把n个子数组合并成n/2个子数组,子数组中元素有序
事件复杂度为:(nlog2 n)
*/
//合并
void   merge_array(int *array_1,int len_1,int *array_2,int len_2)
{
	int array_tmp[8];
	int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<len_1 && j<len_2)
	{
		if(array_1[i]<array_2[j])
		{
			array_tmp[k++]=array_1[i++];
		}
		if(array_1[i]>=array_2[j])
		{
			array_tmp[k++]=array_2[j++];
		}
	}
	while(i<len_1)
	{
		array_tmp[k++]=array_1[i++];
	}
	while(j<len_2)
	{
		array_tmp[k++]=array_2[j++];
	}
    //把临时数组值赋值给array
    for(i=0;i<len_1+len_2;i++)
    {
    	array_1[i]=array_tmp[i];
    }
}
//递归拆分
void   div_array(int *array,int len)
{
	if(len>1)
	{
		int len_1=len/2;
		int len_2=len-len_1;
		int *array_1=array;
		int *array_2=array_1+len_1;
		div_array(array_1,len_1);
		div_array(array_2,len_2);
		merge_array(array_1,len_1,array_2,len_2);
	}
	
}
int main(int argc, char const *argv[])
{
	int array[]={6,32,9,13,15,90,56,73};
	div_array(array,8);
	int i;
	for(i=0;i<8;i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
	return 0;
}