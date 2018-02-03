#include <stdio.h>
#define N  5
/*
数组:是一段连续内存空间,被分割成同样大小的单元(元素)
数组定义:
数据类型 数组名[数组元素个数]
数组名:表示数组的起始地址值
数据类型:表示数组元素类型,规定元素的空间大小,均匀分配内存.
数组空间大小=元素个数*元素数据类型大小

*/
int main(int argc, char const *argv[])
{
	//静态数组:数组定义完毕,其大小不可改变,起始地址不能变
	//int array_a[5]={1,2,3,4,5};
	// int array_b[N];
	// int c=5;
	// int array_c[c];
	// //数组内存空间大小:
	// printf("%d\n",sizeof(array_a));
	// printf("%d\n",sizeof(array_b));
	// printf("%d\n",sizeof(array_c));
	//数组名是一个变量,表示集合
	//输出数组每个元素地址值
	// printf("%X\n",&array_a[0]);
	// printf("%X\n",&array_a[1]);
	// printf("%X\n",&array_a[2]);
	// printf("%X\n",&array_a[3]);
	// printf("%X\n",&array_a[4]);
	//数组名表示是什么地址?
	//数组名表示的数组第一个元素地址
	// printf("%X\n",array_a);
	// //&array_a  表示数组一段空间
	// printf("%X\n",&array_a);
	// //array+1: "1"表示单位,根据array_a 确定单位大小
	// printf("%X\n",array_a+1);
	// //数组起始地址就是整数编码值  (int)(array_a) 弱化成整数 "1"表示数字1
	// printf("%X\n",(int)(array_a)+1);
	// //"1"表示整个数组空间大小
	// printf("%X\n",&array_a+1);

	// int i;
	// for(i=0;i<5;i++)
	// {
	// 	//printf("%d\n",array_a[i]);//array[i]表示数组元素值
	// 	printf("%d\n",*(array_a+i));//array+i表示元素地址值
	// }

	// int array_a[5];
	// int array_b[5]={1,2,3,4,5};
	// //array_a=array_b;//错误,数组名是一个只读变量,不能被赋值
	// //array[0]=array_b[0];//数组元素赋值
	// //array_a+1=array_b+1;//错误.数组元素地址固定
	// *(array_a+1)=*(array_b+1);
	// *(array_a)=*(array_b)+1;

    //数组初始化
    // int array_1[]={1,2,3,45};
    // int array_2[5]={1,2,3,45};
    // //int array_3[3]={1,2,3,45};//错误,越界
    // int array_4[9]={0};//数组元素值都为0

    // int array_a[]={1,2,3,4,5};
    // int *ptr=(int*)(&array_a+1);
    // printf("%d\n",*(ptr-1));

    int array_a[0];
    printf("%d\n",sizeof(array_a));
	return 0;
}
//1.定义一个数组,里面有10个元素,输出数组最大和最小元素值
//2.13个人围成一圈,从第一个人开始报数1,如果报数是3的倍数出圈,请问最后剩下的人编号是多少?
//3.定义个数组,有序输出数组元素值
//4.将一个一位数组a[10]中的元素值按逆序重新存放.假定数组中原来元素顺序为:1,3,5,7,9,8,6,4,2,0,按逆序重新存放后元素的值位:0,2,4,6,8,9,7,5,3,1。要求：
//在程序中将数组初值初始化，输出逆序重新存放后元素的值。