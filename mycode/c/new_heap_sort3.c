#include <stdio.h>
void swap(int array[],int i,int j)
{
	int temp;
	temp=array[i];
	array[i]=array[j];
	array[j]=temp;
}

void heap_adjust(int *array,int index,int num)
{
	int i;
	int temp;
	temp=array[index];
	for(i=2*index;i<=num;i=i*2)
	{
		if(i<num && array[i]<array[i+1])
		{
			i++;
		}
		if(temp>=array[i])
		{
			break;
		}
		array[index]=array[i];
		index=i;
	}
	array[index]=temp;
}

void  heap_sort(int *array,int num)
{
	int i;
	for(i=num/2;i>0;i--)
	{
		heap_adjust(array,i,num);
	}
	for(i=num;i>1;i--)
	{
		swap(array,1,i);
		heap_adjust(array,1,i-1);
	}
}

int main(int argc, char const *argv[])
{
	int a[10]={-1,5,2,6,0,3,9,1,7,4};
	int i;
	heap_sort(a,9);
	printf("排序后的结果:");
	for(i=1;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}