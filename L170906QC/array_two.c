#include  <stdio.h>
/*
计算地址一定是一个线性结构,从低地址到高地址
二维数组:是一个一维数组,其每个元素又将是一个一维数组
二维数组定义:
数据类型  数组名[外围一维数组元素个数][外围数组元素所包含一维数元素个数];
int  array[4][5]:
array 是存在4个元素一维数组;
array 每个元素有是一个存在5个元素一维数组
arrray :表示一段连续内存,其空间大小为20*4=80个字节
*/
int main(int argc,const char* argv[])
{
    //int array[3][2];
    //分解 二位数组外围一维数组元素地址
    // printf("%X\n",array);
    // printf("%X\n",array[0]);//array[0] 相当于是元素一维数组名(第一个元素地址)
    // printf("%X\n",array[0]+1);//array[0][1]的地址
    // printf("%X\n",&array[0]+1);
    // printf("%X\n",array[1]);
    // printf("%X\n",array[2]);
    //外围一维数组的元素有是一个地址值(记录元素数组起始地址)
    //二位数组元素地址存储结构
    // int i,j;
    // for(i=0;i<3;i++)
    // {
    //     for(j=0;j<2;j++)
    //     {
    //         printf("%X\t",&array[i][j]);
    //     }
    //     printf("\n");
    // }
    //二维数组名表示什么地址??
    // printf("%X\n",array);
    // printf("%X\n",&array);
    // printf("%X\n",array[0]);
    // printf("%X\n",&array[0][0]);

    // printf("%X\n",array+1);//1表示外围一维数组元素(2*sizeof(int))
    // printf("%X\n",&array+1);
    // printf("%X\n",array[0]+1);//1表示是里面一维数组元素(sizeof(int))
    // printf("%X\n",&array[0][0]+1);
    //二位数组名表示数组第一个元素地址,此时第一个元素仍然是一个数组集合
    //二维数组名+1 表示的是第二个元素地址(第二行地址)

    // int array[3][2]={{1,2},{3,4},{5,6}};
    // //array[0]={1,2}  array[1]={3,4} array[2]={5,6}
    // // printf("%d\n",*(*(array+1)+0));
    // // //*(array+1)表示存储值为int
    // // //array+1 表示存储值为{3,4}
    // // printf("%d\n",*((int*)(array+1)));//(int*)(array+1)
    // // printf("%d\n",array[1][0]);

    // printf("%d\n",*(*(array+1)+1));
    // //*(array+1)表示存储值为int
    // //array+1 表示存储值为{3,4}
    // printf("%d\n",*((int*)(array+1)+1));//(int*)(array+1) 强制转换,确定+1 是加sizeof(int)字节数
    // printf("%d\n",array[1][1]);

    //*(*(array+i)+j)==array[i][j]
     //使用一个简单指针输出二维数组元素
    //  int array[3][2]={{1,2},{3,4},{5,6}};
    //  int *p=(int*)array;//两边地址+1 的单位大小不等
    //  int i;
    //  for(i=0;i<3*2;i++)
    //  {
    //      printf("%d\n",*(p+i));
    //  }

    //二维数组定于初始化
    int  array_one[2][3]={1,2,3,4,5,6};
    //int  array_two[2][]={1,2,3,4,5,6,7};//错误,无法确定行之间间隔字节数
    //int array_two[2][];  //错误
    int  array_two[][3]={1,2,3,4,5,6,7};
    printf("%d\n",array_two[2][1]);
    return 0;
}