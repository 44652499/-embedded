#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//获取待排序数的最大数
int  get_max_data(int* array,int len)
{
    int max_data=array[0];
    int i;
    for(i=0;i<len;i++)
    {
        if(max_data<array[i])
        {
            max_data=array[i];
        }
    }
    return max_data+1;
}
//分配计数数组
int *  init_counter_array(int max_data)
{
    int * ptr=(int*)malloc(max_data*sizeof(int));
    memset(ptr,-1,sizeof(int)*max_data);
    return ptr;
}
//计数排序:把带排序数据作为排序数据的下标值,如果存在在在计数排序数组中将对应的元素赋值为1
void    counter_sort(int * array,int len)
{
    int i;
    int j=0;
    int max_data=get_max_data(array,len);
    int* ptr=init_counter_array(max_data);    
    if(ptr==NULL)
    {
        printf("malloc fail\n");
        return;
    }
    for(i=0;i<len;i++)
    {
        ptr[array[i]]=ptr[array[i]]+1;
    }
    for(i=0;i<max_data;i++)
    {
        while(ptr[i]>=0)
        {
            array[j]=i;
            ptr[i]--;
            j++;
        }
    }
    free(ptr);
    ptr=NULL;
}
int main(int argc,const char* argv[])
{
    int array[11]={13,5,2,6,0,3,4,1,2,4};
    counter_sort(array,10);
    int i;
    for(i=0;i<10;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
    return 0;
}
