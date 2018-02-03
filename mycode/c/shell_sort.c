#include <stdio.h>
/*
基本思想是:取一个间隔(gap)，将序列分成若干的子序列，对每个子序列进行直插排序;然后逐渐缩小间隔，重复以上过程，直到间隔为1。不需要大量的辅助空间，和归并排序一样容易实现。希尔排序是基于插入排序的一种算法，在此算法基础之上增加了一个新的特性，提高了效率。希尔排序的时间复杂度为 O(N*(logN)2)
*/
void shell_sort(int * arr,int n)
{
	int h,j,k,t;
	for(h=n/2;h>0;h=h/2)
	{
		for(j=h;j<n;j++)
		{
			t=arr[j];
			for(k=j-h;k>=0&&t<arr[k];k=k-h)
			{
				arr[k+h]=arr[k];
			}
			arr[k+h]=t;
		}
	}
}
int main(int argc, char const *argv[])
{
	int arr[]={2,6,7,4,8,1,9,10,3,4};
	int n=10,k;   
	shell_sort(arr,n);
	for(k=0;k<n;k++)
		printf("%d\t",arr[k]);
	printf("\n");
	return 0;
}