#include  <stdio.h>
/*
const
只读指针:不能通过指针修改指向的空间,指针值可以修改
指针只读:指针不能改变指向,可以改变指定空间值
*/
int main(int argc,const char* argv[])
{
    // int *  ptr;
    // int a=300;
    // ptr=&a;
    // printf("%d\n",a);
    // printf("%d\n",*ptr);
    // *ptr=400;
    // a=500;
    // printf("%d\n",a);
    // printf("%d\n",*ptr);

    //const  int  *   ptr;//ptr指向空间只读(不能通过ptr修改指向空间值)
   // int  const *   ptr;
//     int  a=300;
//     ptr=&a;
//     a=400;
//    // *ptr=500;//错误
//     printf("%d\n",a);
//     printf("%d\n",*ptr);
//     int b=500;
//     ptr=&b;
//     printf("%d\n",*ptr);
//     int a=30;
//    // int  *  const  ptr;//指针变量值只读,可以通过指针修改指向的空间值
//    int  *  const  ptr=&a;    
//    // ptr=&a;
//     int b=40;
//     //ptr=&b;
//     *ptr=4000;
//     printf("%d\n",*ptr);

    // const int a=400;
    // //int *ptr=&a;//错误,只读空间一般使用只读指针指向
    // const int *ptr=&a;
    // //*ptr=5000;
    // printf("%d\n",*ptr);

    //const int * const  ptr;//指针空间不能修改,不能通过指针修改指向空间
     int const * const  ptr;
    return 0;
}