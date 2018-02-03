#include <stdio.h>
/*
快排(折半排序):从左右两边交叉获取待排序数据,与一个数比较,大放在该数左边,小的放在该数右边.重复按照上述方法进行.
时间复杂度:O(n*log2 n)
*/
int  quick_sort_index(int * array,int left,int right)
{
    int tmp=array[left];
    while(left<right)
    {
        while(array[right]>tmp && left<right)
        {
            right--;
        }
        if(left<right)
        {
            array[left]=array[right];
            left++;
        }
        while(array[left]<tmp && left<right)
        {
            left++;
        }
        if(left<right)
        {
            array[right]=array[left];
            right--;
        }
    }
    array[left]=tmp;
    return left;
}

void  quick_sort(int *array,int left,int right)
{
    if(left<right)
    {
        int mid=quick_sort_index(array,left,right);
        quick_sort(array,left,mid-1);
        quick_sort(array,mid+1,right);
    }
}

int main(int argc, char const *argv[])
{
    int array[]={10,27,12,15,88,1,21,34};
    quick_sort(array,0,7);
    int i;
    for(i=0;i<8;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
    return 0;
}

//实现非递归的快排O(nlog2 n)
//了解 动态规划(DP)(背包 最小币值和)