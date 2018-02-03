#include <stdio.h>
/*
回顾:
1.指针:是一个存储类型为地址值的变量
2.地址值类型:实际就是一个整数值,表示内存存储单元地址编码值(0--2^32-1)
3.野指针:使用未指向的指针
4.NULL 是一个宏定义 ,其值为0,表示是空地址.避免产生野指针

typedef关键字:对已经存在类型另取别称.
一般用来另取特定类型称呼(size_t,off_t,time_t)
简化类型的描述

typedef  不等同于#define 替换
*/
#define  B    int
typedef  int  A;
typedef  int * AA;//*AA右结合,表示 AA是一个指针类型,并指针指向空间存储类型为int
//typedef  unsigned  char   B;
typedef  int ARRAY[10];//ARRAY 是一个数组类型

int main(int argc,const char* argv[])
{
    //int *ptr=NULL;//指针未指向
    //*ptr=NULL;//*ptr=0;

//     int * ptr_a,ptr_b;//ptr_b不是一个指针变量
//     //* 右结合,与ptr_a结合表示指针变量.
//     int a=200;
//     ptr_a=&a;
//     ptr_b=ptr_a;
//     printf("%d\n",ptr_b);
//    // printf("%d\n",*ptr_b);//错误
     // A  a1=200;
      //printf("%d\n",a1);
    //   B  b1=1;
    //   B  b2=3;
    //   B  b3=b1-b2;
    //   printf("%d",b3);

    // A  a1,b1;//编辑时,看成一种数据类型
    // a1=20;
    // b1=30;
    // return 0;

    // B a2,b2;//宏替换,预编译完成
    // a2=40;
    // b2=50;
//    AA  ptr_a,ptr_b;
//    A  a=200;
//    ptr_a=&a;
//    ptr_b=ptr_a;
//    printf("%d\n",*ptr_b); 

    //   ARRAY    a1,a2; //一维数组
    //   //printf("%d\t%d\n",sizeof(a1),sizeof(a2));
    //   int i;
    //   for(i=0;i<10;i++)
    //   {
    //       a1[i]=i+1;
    //       printf("%d\n",a1[i]);
    //   }

    ARRAY    a1[5],a2[5];//二维数组
    printf("%d\t%d\n",sizeof(a1),sizeof(a2));
    int  i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<10;j++)
        {
            a1[i][j]=i+j;
            printf("%d\t",a1[i][j]);
        }
        printf("\n");
    }
   return 0;
}