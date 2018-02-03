#include <stdio.h>
typedef  void (*Fun)(int a,int b);//一种类型,函数指针类型
/*
函数指针:是一个指针,指向一个函数
指针函数:函数返回值是一个指针
*/

//函数名相当于是一个指针只读
void fun1(int a,int b)
{
    printf("%d\n",a+b);
}

void fun3(int a,int b)
{
    printf("%d\n",a-b);
}

void fun4(int a,int b)
{
    printf("%d\n",a+b);
}

void fun2(int a,int b)
{
    printf("%d\n",a-b);
}


void  test_fun(int a,int b,Fun ptr_fun)
{
    ptr_fun(a,b);
}

int main(int argc,const char* argv[])
{
    //获取函数地址
    //printf("%X\n",main);
    //printf("%X\n",&main);

    //ptr_fun=fun1;
    //ptr_fun(2,3);
   //(*ptr_fun)(2,3);
   // *ptr_fun(2,3);  //错误写法
   //ptr_fun=fun2;
   //ptr_fun(5,2);
   //test_fun(2,3,fun1);
   //test_fun(2,3,fun2);

   //函数指针数组
//    void (*ptr_fun[2]) (int a,int b);
//    ptr_fun[0]=fun1;
//    ptr_fun[1]=fun2;
//    ptr_fun[0](1,2);
//    ptr_fun[1](1,2);

    // void (*ptr_fun[2][2]) (int a,int b)={fun1,fun2,fun3,fun4};
    // //ptr_fun[0][1](3,2);
    // //定义指向函数指针数组的指针
    // void (*(*p_fun)[2]) (int a,int b);
    // //void (*(*p_fun)[2][2]) (int a,int b);
    // //printf("%d\n",sizeof(p_fun));
    // p_fun=ptr_fun;
    // //printf("%X\n",*(p_fun[0]+0));
    // //printf("%X\n",fun1);
    // //((void (int,int))(*(p_fun[0]+0)))(1,2);
    // ((Fun)*(p_fun[0]+0))(2,1);

    Fun ptr_fun[2][2]={fun1,fun2,fun3,fun4};
    Fun(*p_fun)[2];
    p_fun=ptr_fun;
    (*(p_fun[0]+1))(1,2);
    return 0;
}