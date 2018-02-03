#include <stdio.h>
/*
指针数组:是一个数组,数组元素类型是一个指针
数组指针:
*/
int main(int argc,const char* argv[])
{
//     int a1=3,a2=4,a3=6,a4=8;
//     char *str="abcd";
//     int* array[10];//"[]" 与array结合表示数组, int* 结合表示数组元素类型是指针,int 表示指针指向的是整数空间
//     array[0]=&a1;
//     array[1]=&a2;
//     array[2]=&a3;
//     array[3]=&a4;
//     //array[4]=(int*)&str;
//     array[4]=(int*)str;
//     //输出元素;
//     int i;
//     for(i=0;i<4;i++)
//     {
//         //printf("%d\n",*array[i]);
//         printf("%d\n",*(*(array+i)));
//     }
//     //单独取出"abcd"
//    // printf("%s\n",*(array[4]));

//    printf("%s\n",array[4]);

    int a[]={1,2,3};
    int b[]={3,4,5};
    int c[]={5,6,7};
   // int * array[]={a,b,c};
    //int * array[]={(int*)&a,(int*)&b,(int*)&c};
   // int ** array[]={(int**)&a,(int**)&b,(int**)&c};//画图分析为什结果也正确
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",*(array[i]+j));
        }
        printf("\n");
    }
    return 0;
}