#include  <stdio.h>
/*
回顾:
1.指针+n:
  p+n 含义:p地址值增加的空间数(n表示空间数),增加字节数:n*sizeof(*p)
  (int)p+n 含义:p表示的地址值已经转换成整数,n是一个整数
  (T*)p+n: 含义:p地址值增加的空间数(n表示空间数),增加字节数:n*sizeof(T)
2.野指针:1.使用未赋值的局部指针变量,一般使用NULL避免野指针
      int *p=NULL ;
         2.使用已经释放地址空间
*/
int main(int argc,const char* argv[])
{

    // int  a=20;
    // int *p=&a;
    // int  b=30;
    // p=&b;

    // int  array[]={1,2,3,4};
    // arra=&a;//错误,数组名表示只读地址

    //只读指针:不能通过指针修改指向的空间值
    // int  a=20;
    // const  int*  ptr=&a;
    // //*ptr=400;//
    // a=400;
    // printf("%d\n",*ptr);

    // const  int  a=40;
    // //int *ptr=&a;
    // //*ptr=400;//错误, 不符合修改主次关系(a为空间)
    // //const int *ptr=&a;//都不能修改存储空间 a
    // int  const*  ptr=&a;
    // printf("%d\n",a);

    //指针只读:不能改变指针指向（指针变量自身不修改）

    int  a=30;
    int * const ptr=&a;
    *ptr=400;
    printf("%d\n",a);
    int  b=50;
    ptr=&b;//错误,ptr 是一个指针只读
    return  0;
}