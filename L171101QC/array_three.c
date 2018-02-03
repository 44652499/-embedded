#include <stdio.h>
int main(int argc,const char * argv[])
{
    // int array[]={1,2,3};
    // int array2[]={11,22,33};
    // array2=array;//错误,数组名不能出现左边被赋值

    //二维数组:是一个一维数组,数组每个元素又是一个一维数组
    //二维数组在内存从第一个元素起始地址到最后一个元素结束
    int  array[2] [3]={1,2,3,4,5,6};
    // int i=0;
    // int j=0;
    // for(i=0;i<2;i++)
    // {
    //     for(j=0;j<3;j++)
    //     {
    //         printf("%X\n",&array[i][j]);
    //     }
    // }
    //通过从数组首元素地址开放访问整个数组值
    // int *p=&array[0][0];
    // int i;
    // for(i=0;i<6;i++)
    // {
    //     printf("%d\n",*(p+i));
    // }

    //二维数组名表示什么含义?
    //不管数组是几维的,数组名都是首元素地址..此时明白首元素是一个值还是一个小数组?
    printf("%X\n",array);
    printf("%X\n",array+1);//+1 增加 sizeof(array[0]) 表示12个字节
    //以上输出值相差12字节?
    //第一个元素是一个一维数组 int b[3]

    printf("%X\n",array[0]);//array[0]相当于是b值
    printf("%X\n",array[0]+1);//+1 增加4字节
    //二维数组名表示行地址,数组名+1 指定下一行地址
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
           // printf("%d\t",array[i][j]);
           printf("%d\t",*(*(array+i)+j));
           //array+i 取出外围一维数组元素地址,此地址存放的元素类型为 int b[3]
           //*(array+i) 取出内围每个一维数组地址,此地址存放的元素类型为int
        }
        printf("\n");
    }
    //定义二维数组并初始化时,可以不指定行数,但必须制定列数 为什么?
    //指定列数,才能计算出外围一维数组元素大小,否则 不定.
    int  array2[2][]={1,2,3,4,5,6};
    int  array3[][3]={1,2,3,4,5,6};
    return 0;
}