#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
/*
常用的排序算法:
1.冒泡
2.交换
3.选择
5.插入
6.快排(折半)
7.计数
8.基数(木桶法)
9.希尔
10.归并
11.堆
12.位排
*/
//冒泡:前一个与后一个比较,大的交换,继续与后一个比较.每比较一轮最大的数在最后
//平均:O(n^2)
void   sort1(int * array,int length)
{
    int i,j;
    for(i=0;i<length;i++)//控制排序轮数
    {
      for(j=0;j<length-i-1;j++)//控制每轮比较次数
      {
        if(array[j]>array[j+1])
        {
            int tmp=array[j];
            array[j]=array[j+1];
            array[j+1]=tmp;
        }
      }
    }
}

//交换:第一个数与后面数一一比较,有大小交换,继续用第一个数与后面数比较.一轮之后第一个数最小
//平均:O(n^2)
void   sort2(int *array,int length)
{
    int i,j;
    for(i=0;i<length;i++)
    {
        for(j=i+1;j<length;j++)
        {
            if(array[i]>array[j])
            {
                int tmp=array[i];
                array[i]=array[j];
                array[j]=tmp;
            }
        }
    }
}

//选择:每一轮从数中选择一个最小的值与待排序数组中的第一个数换
void   sort3(int *array,int length)
{
    int i,j;
    int min_pos;
    for(i=0;i<length;i++)
    {
        int min=array[i];
        min_pos=i;
        for(j=i+1;j<length;j++)
        {
            if(array[j]<min)
            {
                min=array[j];
                min_pos=j;
            }
        }
        if(min_pos!=i)
        {
            array[min_pos]=array[i];
            array[i]=min;
        }
    }
}
//插入:每一轮将一个数插入到前面有序数中
void   sort4(int *array,int length)
{
    int i,j;
    for(i=1;i<length;i++)
    {
       int tmp=array[i];
       j=i-1;
       while(j>=0 &&  tmp<array[j])
       {
           array[j+1]=array[j];
           j--;
       }
       array[++j]=tmp;
    }
}
//计数一:动态创建一个数组,待排序数组最大值+1 为数组元素个数.把动态数组的下标值看成待排序元素值.数组下标值不能位负数且不重复.
//时间复杂度O(n)
void  sort5(int * array,int length)
{
    int i;
    int max=array[0];
    for(i=0;i<length;i++)
    {
        if(max<array[i])
        {
            max=array[i];
        }
    }

    int *ptr=(int*) malloc((max+1)*sizeof(int));
    bzero(ptr,sizeof(ptr));
    for(i=0;i<length;i++)
    {
        ptr[array[i]]++;
    }

    //输出
    for(i=0;i<max+1;i++)
    {
        if(ptr[i]>0)
        {
            printf("%d\t",i);
        }
    }
    printf("\n");
    free(ptr);
    ptr=NULL;
}

//计数二:动态创建一个数组,待排序数组最大值+1 为数组元素个数.把动态数组的下标值看成待排序元素值.数组下标值不能位负数且不重复.计数排序可以实现重复元素值
//时间复杂度O(n^2)
void  sort6(int * array,int length)
{
    int i;
    int max=array[0];
    for(i=0;i<length;i++)
    {
        if(max<array[i])
        {
            max=array[i];
        }
    }

    int *ptr=(int*) malloc((max+1)*sizeof(int));
    bzero(ptr,sizeof(ptr));
    for(i=0;i<length;i++)
    {
        ptr[array[i]]++;//记录对应下标值重复出现的次数
    }

    //输出
    for(i=0;i<max+1;i++)
    {
        while(ptr[i]-->0)//重复次数
        {
            printf("%d\t",i);
        }
    }
    printf("\n");
    free(ptr);
    ptr=NULL;
}


//位排序:在计数 排序基础上,把字节数组折算成位数组,依然用用数组下标作为待排序数处理.根据位操作将位数组元素值1.减少计数排序空间浪费
void  sort7(int *array,int length)
{
    int i;
    int max=array[0];
    for(i=0;i<length;i++)
    {
        if(max<array[i])
        {
            max=array[i];
        }
    }
    int n=max/32+1;
    int *ptr=(int*) malloc(n*sizeof(int));
    bzero(ptr,sizeof(ptr));
    for(i=0;i<length;i++)
    {
        int n_blck=array[i]/32;//存储ptr数组的第几个元素
        int n_index=array[i]%32;//存储ptr数组的第几个元素第几位
        unsigned int base=0x1;
        base=base<<n_index;
        ptr[n_blck]=ptr[n_blck]|base;
    }
    int j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<32;j++)
        {
            unsigned int base=0x1;
            base=base<<j;
            if((ptr[i]&base)!=0)
            {
                printf("%d\t",i*32+j);
            }
        }
    }
    printf("\n");
    free(ptr);
    ptr=NULL;
}


//实现一个大数据查找1亿不重复正数数据,随便输一个数如何判断该数是否存在
int *   malloc_addr()
{
    int n=100000000/32+1;
    int *ptr=(int*) malloc(n*sizeof(int));
    bzero(ptr,sizeof(ptr));
    return  ptr;
}

void  set_big_data(int * ptr,int dest_data)
{
    int n_blck=dest_data/32;
    int n_index=dest_data%32;
    unsigned int base=0x1;
    base=base<<n_index;
    ptr[n_blck]=ptr[n_blck]|base;
}

void   find_big_data(int *  ptr,int  dest_data)
{         
    int n_blck=dest_data/32;
    int n_index=dest_data%32;
    unsigned int base=0x1;
    base=base<<n_index;
    if((ptr[n_blck]&base)!=0)
    {
        printf("find ok\n");
    }
    else
    {
        printf("not find \n");
    }   
}

void  free_addr(int * ptr)
{
    free(ptr);
    ptr=NULL;
}
//如果以上数据是允许重复正数 如何存储域查找??(胡盼)
int main(int argc, char const *argv[])
{
    int array[]={19,23,10,15,8,1,2,34};
    //sort1(array,8);
    //sort2(array,8);
    //sort3(array,8);
    //sort4(array,8);
    // int i;
    // for(i=0;i<8;i++)
    // {
    //     printf("%d\t",array[i]);
    // }
    // printf("\n");

    //sort5(array,8);
    //sort6(array,8);
    //sort7(array,8);
    int  * ptr=malloc_addr();
    set_big_data(ptr,12);
    set_big_data(ptr,1200);
    set_big_data(ptr,100);
    set_big_data(ptr,1111);
    set_big_data(ptr,99999);
    set_big_data(ptr,2314344);
    set_big_data(ptr,76890);
    find_big_data(ptr,2314344);
    free_addr(ptr);
    return  0;
}