#include <stdio.h> 
#include <limits.h>
/*
存储类型:
1.auto:自动 默认为此存储类型.一般是修饰局部变量
2.register:寄存器变量,直接存储在寄存器中(不存储在内存)
3.static:静态变量
4.extern
5.volatile

静态变量:所有的静态变量存储在数据段或BSS段
1.静态局部变量:static  修饰局部变量
2.静态全局变量:static  修饰全局变量
静态全局变量与一般全局变变量区别?
1.静态全局不能跨文件访问,全局可以跨文件访问
静态局部变量与一般局部变量区别?
1.静态局部存在数据端或bss段,一般局部存储栈
2.未初始化局部变量值随机,未初始化静态局部变量为0
3.静态局部变量生命周期域全局变量一样,离开作用域仍有效.一般局部局部变量离开作用域释放
4.静态局部变量只会初始化一次
静态局部变量与一般局部变量都只能在本作用域内访问.
*/
//auto int g_data;  //错误写法
//static int g_data;
int  fun(int i)
{
    //int sum=0;//每次分配释放,初始化为0
    static int sum=0;//第一次分配空间并初始化,后续都是用上一次值
    sum=sum+i;
    return sum;
}
int main(int argc,const char* argv[])
{
    int i;
    int sum1=0;
    //int a=sum;//错误,不能跨作用域访问静态局部变量
    for(i=0;i<5;i++)
    {
        sum1+=fun(i);
    }
    printf("%d\n",sum1);
    // auto int l_data;//正确
    // int l_data2;
    // printf("l_data2=%X\n",&l_data2);
    // register int l_data3=20;
    // printf("%d\n",l_data3);
    //printf("l_data3=%X\n",&l_data3);//错误.,寄存器不存在地址
   // static int l_data4;
   // printf("%d\t%d\n",g_data,l_data4);
   
    return  0;
}