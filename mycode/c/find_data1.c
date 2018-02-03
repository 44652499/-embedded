#include <stdio.h>
/*
实现从有序数中查找目标数，要求时间复杂度为O(logn)
*/
//对待查找数据排序处理
void    sort_find_data(int* array,int len)
{
        int i,j;
        for(i=0;i<len;i++)
        {
                for(j=0;j<len-i-1;j++)
                {
                        if(array[j]>array[j+1])
                        {
                                int temp=array[j];
                                array[j]=array[j+1];
                                array[j+1]=temp;
                        }
                }
        }
}
//递归实现数据查找
int  find_dest_by_recursion(int *array,int start,int end,int dest)
{
        int i;
        if(start>end)
        {
                return -1;
        }
        i=(start+end)/2;
        if(dest==array[i])
        {
                return i;
        }
        if(dest<array[i])
        {
                return find_dest_by_recursion(array,start,i-1,dest);
        }
        if(dest>array[i])
        {
                return find_dest_by_recursion(array,i+1,end,dest);
        }
}
//非递归实现数据折半查找
int  find_dest_not_by_recursion(int * array,int start,int end,int dest)
{
        int m;
        while(start<=end)
        {
                m=(start+end)/2;
                if(dest==array[m])
                        return m;
                 if(dest<array[m])
                    end=m-1;
                else
                     start=m+1;
        }
        return -1;
}
int main(int argc,const char argv[])
{
        int array[]={23,1,45,78,90,43,52};
        int  find_dest_data;
        scanf("%d",&find_dest_data);
        sort_find_data(array,7);
        int ret=find_dest_by_recursion(array,0,6,find_dest_data);
        //int ret=find_dest_not_by_recursion(array,0,6,find_dest_data);
        if(ret>=0)
        {
                printf("find\n");
        }
        else
        {
                printf("not find\n");
        }
        return 0;
}
