#include <stdio.h>
/*
数组:是一段连续内存空间,存储同类型的元素.
数组变量:表示一段连续内存起始地址
如何定义数组
数据类型   数组变量名[数组元素个数];
1.数据类型指数组元素类型
2.数组元素个数:明确制定数组集合中元素数量.定义必须明确此值,否则数组将没有结束地址
*/
int main(int argc,const char * argv[])
{
    int array[5]={1,2,3,4,5};
    //printf("%d\n",sizeof(array));//计算数组所有空间大小
    //printf("%d\n",sizeof(array[0]));//计算数组元素大小
    //输出数组每个元素起始地址,每个元素占用4个字节
    //printf("%X\n",array);
    //printf("%X\n",&array[0]);
    // printf("%X\n",&array[1]);
    // printf("%X\n",&array[2]);
    // printf("%X\n",&array[3]);
    // printf("%X\n",&array[4]);
    //访问空间值,实际是根据空间地址访问,并非完全靠名称
    //数组可以通过下标访问每一个元素值[0,length-1]
    //数组名:表示数组首元素地址(元素占4个字节),
    //&数组名:表述数组整个空间起始地址,空间字节数算数组大小
   /// printf("%X\n",array);
   // printf("%X\n",array+1);//+1 表示元素占用字节数
    //printf("%X\n",&array[0]+1);
    
   // printf("%X\n",&array+1);//+1 表示的是数组整个空间大小
    //printf("%X\n",&array[0]+1);
    int i;
    for(i=0;i<5;i++)
    {
       // printf("%d\t",array[i]);
       printf("%d\t",*(array+i));
    }
    printf("\n");
    return 0;
}