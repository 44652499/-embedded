#include <stdio.h>
/*
数组名表示:表示数组第一个元素首地址
&数组名表示:表述数组首地址
*/

int main(int argc,const char * argv[])
{
    //int  array[10];
    //printf("%X\n",array+1);//+1 增加4字节
    //printf("%X\n",&array+1);//+1 增加40字节
    //array[2]=4;
   //printf("%d\n",*(array+2))
    //首元素地址本质就是一个整数值,32位系统地址整数值区间值为0x00000000~0xfffffffff
    //printf("%X\n",array);
    //printf("%X\n",array+1);//数组首元素+1,增加的一个元素字节数(sizeof (int))
    //printf("%X\n",(int)array+1);//(int)array 把地址值转换成一般整数值,+1 表示数字1
    //printf("%d\n",sizeof(&array));
    //printf("%d\n",sizeof((int)&array));

    int  array[0];
    printf("%d\n",sizeof(array));
    return 0;
}