#include <stdio.h>
#define MAXSIZE 10
//实现归并,并把结果保存在list1
void  merging(int *list1,int list1_size,int *list2,int list2_size)
{
	int i,j,k,n;
	int temp[MAXSIZE];
	i=j=k=0;
	while(i<list1_size && j<list2_size)
	{
		if(list1[i]<list2[j])
		{
			temp[k++]=list1[i++];
		}
		else
		{
			temp[k++]=list2[j++];
		}
	}
	while(i<list1_size)
	{
		temp[k++]=list1[i++];
	}
	while(j<list2_size)
	{
		temp[k++]=list2[j++];
	}
    for(n=0;n<(list1_size+list2_size);n++)
    {
    	list1[n]=temp[n];
    }
}
//拆分数组成多个子数组(每个元素算成一个数组)
void   mergsort(int array[],int len)
{
	if(len>1)
	{
		int *list1=array;
		int list1_size=len/2;
		int *list2=array+len/2;
		int list2_size=len-list1_size;
		mergsort(list1,list1_size);
		mergsort(list2,list2_size);
		merging(list1,list1_size,list2,list2_size);
	}
}
int main(int argc, char const *argv[])
{	
	int a[10]={5,2,6,0,3,9,1,7,4,8};
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	mergsort(a,10);
	printf("排序后的结果:");
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}