#include <stdio.h>
//将一个一位数组a[10]中的元素值按逆序重新存放.假定数组中原来元素顺序为:1,3,5,7,9,8,6,4,2,0,按逆序重新存放后元素的值位:0,2,4,6,8,9,7,5,3,1。要求：在程序中将数组初值初始化，输出逆序重新存放后元素的值。

int main(int argc,const char* argv[])
{
    int array[10];
    //scanf("%d",array);//只给第一个元素输入值
    int i;
    for(i=0;i<10;i++)
    {
        //scanf("%d",&array[i]);
        //scanf("%d",array);//错误 只给第一个元素输入值
        scanf("%d",array+i);
    }
    for(i=0;i<10/2;i++)
    {
        int tmp=array[10-1-i];
        array[10-1-i]=array[i];
        array[i]=tmp;
    }

    for(i=0;i<10;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
    return 0;
}