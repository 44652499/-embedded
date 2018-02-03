#include <stdio.h>
/*
因此其最坏情况下时间复杂度为nlogn。堆排序为不稳定排序，不适合记录较少的排序。
*/
void HeapAdjust(int *a,int i,int size)
{
	int lchild=2*i;
	int rchild=2*i+1;
	int max=i;
	if(i<=size/2)
	{
		if(lchild<=size && a[lchild]>a[max])
		{
			max=lchild;
		}
		if(rchild<=size && a[rchild]>a[max])
		{
			max=rchild;
		}
		if(max!=i)
		{
			int tmp=a[i];
			a[i]=a[max];
			a[max]=tmp;
			HeapAdjust(a,max,size);
		}
	}
}

void   BuildHeap(int *a,int size)
{
	int i;
	for(i=size/2;i>=1;i--)
	{
		HeapAdjust(a,i,size);
	}
}

void HeapSort(int *a,int size)
{
	int i;
	BuildHeap(a,size);
	for(i=size;i>=1;i--)
	{
		int tmp=a[1];
		a[1]=a[i];
		a[i]=tmp;
		HeapAdjust(a,1,i-1);
	}
}

int main(int argc, char const *argv[])
{
	int a[9]={0,8,5,9,1,6,3,10,2};

	// while(scanf("%d",&size)==1 && size>0)
	// {
	// 	int i;
	// 	for (i = 1; i <=size; ++i)
	// 	{
	// 		scanf("%d",&a[i]);
	// 	}
	// 	HeapSort(a,size);
	// 	for (i = 1; i <=size; ++i)
	// 	{
	// 		printf("%d\t",a[i]);
	// 	}
	// 	printf("\n");
	// }
		int i;
		HeapSort(a,8);
		for (i = 1; i <=8; ++i)
		{
			printf("%d\t",a[i]);
		}
		printf("\n");
	return 0;
}