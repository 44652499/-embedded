#include <stdio.h>
/*
指针数组:是一个数组,数组元素类型是一个指针
数组指针:是一个指针 指向是一个数组
*/
int main(int argc,const char* argv[])
{
    // int a[4]={1,2,3,4};
    // int  (*ptr)[4];//ptr 数组指针,数组的元素是int类型
    // printf("%d\n",sizeof(ptr));//指针
    // printf("%d\n",sizeof(ptr[0]));//字节数
    // printf("%d\n",ptr[1]-ptr[0]);//空间数
    // printf("%d\n",(int*)ptr[1]-(int*)ptr[0]);//空间数
    // printf("%d\n",(int)ptr[1]-(int)ptr[0]);//字节数
    //ptr=a;//错误, a表示元素,sizeof(a[0])
    // ptr=&a;
    // int i ;
    // for(i=0;i<4;i++)
    // {
    //     //printf("%d\n",*(ptr[i]));
    //     //printf("%d\n",*((int*)ptr+i));
    //     printf("%d\n",*((char*)ptr+i*4));
    // }

//     int a[][3]={1,2,3,4,5,6};
//     int (*ptr)[3];
//    // ptr=&a;
//     ptr=a;
//     int i,j;
//     // for(i=0;i<2;i++)
//     // {
//     //     for(j=0;j<3;j++)
//     //     {
//     //         //printf("%d\t",ptr[i][j]);
//     //         printf("%d\t",*(*(ptr+i)+j));
//     //     }
//     //     printf("\n");
//     // }
//     for(i=0;i<6;i++)
//     {
//         printf("%d\t",*((int*)ptr+i));
//     }

    int a[]={1,2,3,4};
    int b[]={3,5};
    int c[]={10,20,30,50};
    char ch[]="abcd";
    int* array[][2]={{a,b},{c,(int*)ch}};
    int* (*ptr)[2];
    //使用ptr输出a b c ch的元素值
    ptr=array;
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            //printf("%d\n",*(*(ptr[i]+j)));
            printf("%d\n",*(*(*(ptr+i)+j)));
        }
    }
    return 0;
}