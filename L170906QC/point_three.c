#include <stdio.h>
/*
指针变量赋值:把一个指针变量值赋给另一个指针变量
注意:两变指针指向空间大小一样

特殊指针void*:万能指针(无法确定空间存储类型)
实现代码通用性:功能与数据类型无关,一般使用void* 实现通用性
*/
int main(int argc,const char* argv[])
{
    //int a=30;
    //int  *ptr_a1=&a;
    //int *ptr_a2=ptr_a1;
   //printf("%d\n",*ptr_a2);
    //char*  ptr_a2=ptr_a1;//错误.char*ptr_a2 指向一个字节,ptr_a1指向4个字节.赋值两边指针所指向的空间大小不一样.
   // char*  ptr_a2=(char*)ptr_a1;//指定指向空间的字节数
    //printf("%d\n",*ptr_a2);
    void*  ptr;
    //printf("%d\n",sizeof(ptr));
    //printf("%d\n",sizeof(*ptr));//默认为char类型
    int  a=300;
    ptr=&a;
    //int *ptr_a=(int*)ptr;//强制转换
    int *ptr_a=&a;
    ptr=ptr_a;//不需要强制转换
    return 0;
}