#include <stdio.h>
/*
快排:把第一个数作为目标数,首先拿高位与目标比较,如果大,移动右边下标值.
如果小则把高位数填入目标数位置然后移动左边下标值.当左边和右边的下标值相同
再填入目标数
比目标数小大全在左边,大的全在右边.继续对两边子数组按照上述步骤处理
时间复杂度是:O(n*logn)
*/

//划分数组为子数组,左边的比目标数小,右边大
// int  quick_half_array(int *array,int left,int right)
// {
// 	int tmp=0;
// 	tmp=array[left];
// 	while(left<right)
// 	{
// 		while(array[right]>tmp&&left<right)
// 		{
// 			right--;
// 		}
// 		if(left<right)
// 		{
// 			array[left++]=array[right];
// 		}
// 		while(array[left]<tmp&&left<right)
// 		{
// 			left++;
// 		}
// 		if(left<right)
// 		{
// 			array[right--]=array[left];
// 		}
// 	}
// 	array[left]=tmp;
// 	return left;
// }

int  quick_half_array(int *array,int left,int right)
{
	int tmp=0;
	tmp=array[left];
	while(left<right)
	{
		if(array[right]>=tmp&&left<right)
		{
			right--;
		}
		if(left<right)
		{
			array[left]=array[right];
		}
		if(array[left]<=tmp&&left<right)
		{
			left++;
		}
		if(left<right)
		{
			array[right]=array[left];
		}
	}
	array[left]=tmp;
	return left;
}
//递归快排
void  quick_sort(int *array,int left,int right)
{
	if(left<right)
	{
		int mid=quick_half_array(array,left,right);
		quick_sort(array,left,mid-1);
		quick_sort(array,mid+1,right);
	}
}
int main(int argc, char const *argv[])
{
	int array[]={6,73,56,13,15,90,9,32};
	quick_sort(array,0,7);
	int i;
	for(i=0;i<8;i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
	return 0;
}