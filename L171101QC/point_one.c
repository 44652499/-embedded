#include <stdio.h>
/*
地址:是一个无符号整数值,表示特殊含义,内存空间编码值(内存按照字节编码),如 存在物理芯片4G,物理地址编码值为:0x00000000-0xffffffff,一般用16进制表示地址编码值.
物理地址:物理存储地址编码值
虚拟地址:一般是多任务系统中使用虚拟芯片,每个任务都会映射到物理内存.每个任务都被虚拟出一个独立内存空间.在程序中访问都是虚拟地址
指针:是一个变量,记录以上地址编码值.
定义指针变量:
数据类型 *  指针变量名;
注意:
1.数据类型:指针指向的空间存储值类型,非指针变量自身空间存储类型
2.指针变量名:记录指针变量空间(指针也是一个变量,占用内存)
*/

int *  fun()
{
    int *p;
    int data=200;
    p=&data;
    return p;//函数返回之后,释放栈
    //函数不能返回局部变量地址
}
//函数传参:地址传递(实际就是值传递)
void  fun2(int *a ,int *b)
{
    int *c=*a;
    *a=*b;
    *b=*c;
}

int main(int argc,const char * argv[])
{
   // int *  ptr;
    //printf("%X\t%X\n",ptr,&ptr);
    //输出两个地址值:1.ptr变量存储值(指向空间的值)
    //2.ptr变量自身的地址值

    //char *  ptr_ch;
    //printf("%d\t%d\n",sizeof(ptr),sizeof(ptr_ch));
    //所有指针变量占用空间为4byte(32位) 8byte(64位)

    // int * ptr;
    // int a=30;
    // ptr=&a;//赋值给指针变量
    // printf("%d\t%d\n",a,*ptr);//*指针变量获取的指针指向空间值
    // printf("%X\t%X\n",&a,ptr);//
    // printf("%d\t",sizeof(*ptr));

    //指针变量获取的指向空间起始地址,如何结束?
    //根据定义指针变量时的类型 计算出结束地址.数据类型就是内存划分单元.

    //int data=0x123456;
    //char * ptr=&data;//ptr 结束地址为:data起始地址+sizeof(char)
    //char * ptr=&data;
    //printf("%x\n",*(int*)ptr);//(int*)强制转换,确定结束地址为:
    //data起始地址+sizeof(int)
    
    //指针加减n计算  指针+/- n*sizeof(指针类型).n表示的空间数,计算时应该按照字节数计算
    // char *ptr=&data;
    // printf("%X\n",&data);
    // printf("%X\n",ptr);
    // printf("%X\n",ptr+1);//ptr+1=ptr+1*sizeof(char)
    // printf("%X\n",(int*)ptr+1);//ptr+1=ptr+1*sizeof(int)
    // printf("%X\n",(int)ptr+1);//ptr+1=ptr+1
    //(int)ptr 把特殊地址编码值转换成整数值,1表示数字1

    // int  data=0x12345678;
    // char * ptr=&data;
    // int i;
    // for(i=0;i<4;i++)
    // {
    //     printf("%X\n",*(ptr+i));
    // }

    // int *p=20;//不符合当前操作系统虚拟地址值.不能直接对指针变量赋值地址编码值
    // printf("%d\n",*p);//非法访问(无效地址)

    //野指针:1.指针变量未初始化或赋值 2.使用一个已经释放的空间
    // int  *p;
    // *p=20;//使用一个野指针 错误
    // printf("%d\n",*p);

    //一般使用NULL化解野指针
    //int  *p=NULL;//NULL 宏变量值为0
    // int  *p=0; //指针很可怕 使用需初始化(NULL 拴住野指针)
    // if(p!=NULL)
    // {
    //     *p=20;//使用一个野指针 错误
    //     printf("%d\n",*p);
    // }

    // int *ptr=fun();
    // printf("%d\n",*ptr);//ptr是一个野指针,继续访问一个已经释放空间

    int a=20,b=30;
    fun2(&a,&b);
    printf("%d\t%d\n",a,b);
   
    return 0;
}