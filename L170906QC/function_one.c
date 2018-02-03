#include <stdio.h>
/*
函数:实现软件模块华基本单位.队具有一定功能语句块取个有意义名称.方便重复使用.可以实现不同数据类型值处理
函数三要素:
1.函数名:同一个工程中函数名唯一.
2.参数列表:函数扩展行和通用性
3.返回值:把函数内部数据值返回给函数调用语句;
void  表示无返回值.
函数内部一般通过return返回,一个函数一次只能返回一次
函数分为:声明  定义  调用
函数不会自动执行,必须通过函数名调用执行

函数声明:只有函数原型说明,没有具体实现
函数定义:具体实现
函数一般是先声明再调用

形参:函数参数列表中的变量
实参:函数调用是传递的参数
实参传递给形参
函数被调用时,才会为函数分配栈,分别为形参 局部变量分配空间
函数参数传递方式:
1.值传递:实参值传递个形参,函数内只能访问形参
2.地址传递:实参传递个形参的是某个空间地址值.在函数内可以使用形参指针修改实参值.为了防止修改实参值一般用const修饰形参指针

地址传递就是一种特殊值传递,值为存储空间的地址值
*/
//无返回值,无参数的函数
//void  fun();
//int add(int a,int b);
void swap(int a,int b)
{
    int c=a;
    a=b;
    b=c;
    //交换的只是函数形参a b
    printf("a=%d\tb=%d\n",a,b);
}
//数组作为函数形参,将被退化成指针
//void fun(int a[10])
//void fun(int a[])
// void   fun(int *ptr)
// {
//    // printf("%d\n",sizeof(a));
// }

// void  fun(int *ptr,int len)
// {
//   int i;
//   for(i=0;i<len;i++)
//   {
//       printf("%d\t",*(ptr+i));
//   }
//   printf("\n");
// }

//void swap_two(int* a,int* b)
// void swap_two(const  int* a,const int* b)//
// {
//     int c=*a;
//     *a=*b;
//     *b=c;
//     //交换的只是函数形参a b
//     printf("a=%d\tb=%d\n",*a,*b);
// }

int  * fun(int  *ptr)
{
    return  ptr;
}
int * fun2()
{
    int *  ptr=NULL;
    int a=400;
    ptr=&a;
    return  ptr;//错误,函数不能返回局部变量地址.函数返回后释放所有的局部空间
}
int main(int argc,const char * argv[])
{
    // int a=1;
    // int b=2;
    // int c=add(a,b);//函数调用,a b 实参
    // printf("%d\n",c);

    // int a=5;
    // int b=7;
    // swap(a,b);
    // printf("a=%d\tb=%d\n",a,b);//访问主函数a b 空间

    // int a[6]={1,2,3,4,5,6};
    // fun(a,6);//数组作为函数实参,只需要传递数组首元素地址
    // printf("%d\n",sizeof(a));//计算的数组大小

    //  int a=5;
    //  int b=7;
    //  swap_two(&a,&b);
    //  printf("a=%d\tb=%d\n",a,b);//访问主函数a b 空间

    int a=300;
    fun(&a);
    int* ptr_ret=fun2();
    *ptr_ret=300;//错误用法.ptr_ret 访问一个不存在地址.ptr_ret 变成野指针
    return 0;
}
// void  fun()
// {

// }
// int add(int a,int b)//a b形参
// {
//     int ret=30;
//     return a+b;
// }