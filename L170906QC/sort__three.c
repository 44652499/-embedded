#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
/*
基数:把待排序数按照个十百千...排序
 65 89 1234 12 34
 第一趟: 12  1234 34 65 89
 第二趟: 12  1234 34 65 89
 第三趟: 12  34  65  89  1234

 基数也称为木桶排序:
*/
//初始化木桶数据为0
void init_array(int  src_array[][10])
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            src_array[i][j]=0;
        }
    }
}

//获取最大值返回位数
int   get_max_value(int* array,int length)
{
    int  max=array[0];
    int i;
    for(i=0;i<length;i++)
    {
        if(max<array[i])
        {
            max=array[i];
        }
    }
    int cnt=0;
    while(max!=0)
    {
        cnt++;
        max=max/10;
    }
    return cnt;
}

void   sort8(int* array,int length)
{
    //构建木桶
    int  src_array[10][10];
    init_array(src_array);
    int cnt=get_max_value(array,length);
    //printf("cnt=%d\n",cnt);
    //目标数存放
    int t;
    int i,j;
    int base;
    for(j=1;j<=cnt;j++)
    {
        t=1;
        base=1;//初始化
        while(t<j)
        {
            base=base*10;
            t++;
        }
        int n;
        for(i=0;i<length;i++)
        {
            n=array[i]/base%10;
            t=0;
            while(src_array[n][t]!=0)
            {
                t++;
            }
            src_array[n][t]=array[i];
        }
        int k=0;
        for(i=0;i<10;i++)
        {
            t=0;//初始化
            while(src_array[i][t]!=0)
            {
                array[k++]=src_array[i][t++];
            }            
        }   
        printf("\n");
        init_array(src_array);    
    }   
}

//归并:把集合拆分成n个有序子集,再合并n有序子集
//稳定排序,,时间复杂度:(n*log2 n)
void   merger_sort(int * ptr_array1,int length1,int * ptr_array2,int length2)
{
    int  ptr_array[length1+length2];
    int i,j,k;
    i=j=k=0;
    while(i<length1 && j<length2)
    {
        if(ptr_array1[i]<ptr_array2[j])
        {
            ptr_array[k++]=ptr_array1[i++];
        }
        else
        {
            ptr_array[k++]=ptr_array2[j++];
        }
    }
    while(i<length1)
    {
        ptr_array[k++]=ptr_array1[i++];
    }
    while(j<length2)
    {
        ptr_array[k++]=ptr_array2[j++];
    }
    for(i=0;i<length1+length2;i++)
    {
        ptr_array1[i]=ptr_array[i];
    }
}
    

void  sort9(int * array,int length)
{
    if(length>1)
    {
        int * ptr_array1=array;
        int   length1=length/2;
        int * ptr_array2=ptr_array1+length1;
        int   length2=length-length1;
        sort9(ptr_array1,length1);
        sort9(ptr_array2,length2);
        merger_sort(ptr_array1,length1,ptr_array2,length2);
    }
}

//希尔排序:是一种特殊插入排序,根据等长度比较对应的元素值
//时间复杂: O(nlog2 n) <O(m)< O(n^2)
void   sort10(int * array,int length)
{
    int i;
    int j;
    int k;
    for(i=length/2;i>0;i=i/2)
    {
        for(j=i;j<length;j++)
        {
            int tmp=array[j];
            for(k=j-i;tmp<array[k]&&k>=0;k=k-i)
            {
                array[k+i]=array[k];
            }
            array[k+i]=tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int array[]={109,2773,120,15,88,1,221,34};
    //sort8(array,8);
    //sort9(array,8);
    sort10(array,8);
    int i;
    for(i=0;i<8;i++)
    {
       printf("%d\t",array[i]);
    }
    printf("\n");
    return  0;
}