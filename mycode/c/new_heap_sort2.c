#include <stdio.h>
void swap(int array[],int i,int j)
{
	int temp;
	temp=array[i];
	array[i]=array[j];
	array[j]=temp;
}

void heapadjust(int array[],int s,int num)
{
	int i;
	int temp;
	temp=array[s];
	for(i=2*s;i<=num;i=i*2)
	{
		if(i<num && array[i]<array[i+1])
		{
			i++;
		}
		if(temp>=array[i])
		{
			break;
		}
		array[s]=array[i];
		s=i;
	}
	array[s]=temp;
}
void heapsort(int* array,int num)
{
	int i;
	for(i=num/2;i>0;i--)
	{
		heapadjust(array,i,num);
	}
	for(i=num;i>1;i--)
	{
		swap(array,1,i);
		heapadjust(array,1,i-1);
	}
}

int main(int argc, char const *argv[])
{
	
	int i;
	heapsort(a,9);
	printf("排序后的结果:");
	for(i=1;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}