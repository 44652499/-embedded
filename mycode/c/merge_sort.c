#include <stdio.h>
#include <stdlib.h>
typedef int  RecType;
void  merge(RecType * R,int low,int m,int high)
{
	int i=low,j=m+1,p=0;
	RecType *R1;
	R1=(RecType*)malloc((high-low+1)*sizeof(RecType));
	if(!R1)
	{
		return;
	}
	while(i<=m&&j<=high)
	{
		R1[p++]=(R[i]<R[j])?R[i++]:R[j++];
	}
	while(i<=m)
	{
		R1[p++]=R[i++];
	}
	while(j<=high)
	{
		R1[p++]=R[j++];
	}
	for(p=0,i=low;i<=high;p++,i++)
	{
		R[i]=R1[p];
	}
}

void mergesort(RecType R[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(R,low,mid);
		mergesort(R,mid+1,high);
		merge(R,low,mid,high);
	}
}

int main(int argc, char const *argv[])
{
	int a[]={49,38,65,97,76,13,27};
	//int a[8] = {50, 10, 20, 30, 70, 40, 80, 60};
	int low=0,high=6;
	int i;
	for(i=low;i<=high;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	mergesort(a,low,high);
	for(i=low;i<=high;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}