#include <stdio.h>
//#define  A   int*
typedef  int*  A;  
typedef  int  B;
typedef  int  C[10];//C表示一种类型,含有10 个整数类型
/*
typedef :是对已经存在的类型另取别名
typedef :不是一个预处理指令,不是简单的替换.是编译时识别


*/
int main(int argc,const char * argv[])
{
    //int *p1,p2;//p2 非指针变量,是整数
    //int *p1,*p2;
    //A  p1,p2;//#define  A   int* p2 非指针变量,是整数
    //A  p1,p2;//A 就是一个类型int *
    //int data=20;
    //B  data=20;
    //p1=&data;
   // p2=&data;
   // printf("%d\t%d\n",*p1,*p2);

    //C  c1;
    //C  c1[3];//c1是一个数组,数组元素为C类型,C类型表示10个整数数组,c1是一个二维数组
    //printf("%d\n",sizeof(c1));


    // const char* str="\x56\x78\x12\x34";//\x56\x78\x12\x34 占用4个字节
    // printf("0x%x",*(int*)str);//*(int*)str  指向的是一个存放整数空间,整数最左边是高位,上面字符数组最左边时低位

    char  *p1="12345";//"12345"常字符串,存储在代码段
    char  *p2="12345";//"12345"常字符串,存储在代码段
    char  ch1[]="12345";//"12345"字符,存储在栈
    char  ch2[]="12345";//"12345"字符,存储在栈
    printf("%d\n",p1==p2?1:0);//常字符串只会在代码段保存一份,地址肯定相等
    printf("%d\n",ch1==ch2?1:0);//字符存储不同栈,首地址不等
    //*p1='a';//*p1 修改代码段字符错误,代码段只读不能修改
    *ch1='1';//修改栈中值,正确
    printf("%s\n",p1); printf("%s\n",p1);
    return 0;
}
//typedef  与define 区别?tyepedef 作用与优点?