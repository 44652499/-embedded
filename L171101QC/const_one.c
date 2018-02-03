#include <stdio.h> 
/*
const;
常量:只常字符,存储在代码段的常量符号表中.代码段中常字符只读且唯一
变量:

const 修饰变量为只读变量
*/
int  g_data=20;
const int g_data2=30;//const 修饰全局变量存储在代码的常量符号表中
int g_data4;
const int g_data3;//const 修饰全局变量存储BSS段
int main(int argc,const char* argv[])
{
    char *ch1="abcd";//ch1局部变量存储栈, "abcd"常字符存储在代码段.把"abcd" 地址赋值给ch1变量
    ///char *ch2="abcd";//ch2局部变量存储栈, "abcd"常字符存储在代码段.把"abcd" 地址赋值给ch2变量
    //"abcd" 在代码段只会出现一次.
    //char ch3[]="abcd";//ch3局部变量存储栈,"abcd"存储在数组中的字符
    //char ch4[]="abcd";
    // if(ch1==ch2)//比较ch1值是否等于ch2值(都是"abcd"地址)
    // {
    //     printf("yes\n");
    // }
    // else
    // {
    //     printf("no\n");
    // }
    // if(ch3==ch4)//比较数组首地址是否相等
    // {
    //     printf("yes\n");
    // }
    // else
    // {
    //     printf("no\n");
    // }
    // //*ch1='1';//错误.ch1指向代码段
    // *ch3='1';
    // printf("%c\t%c\n",*ch1,*ch3);

    //printf("g_data=%X\n",&g_data);
    printf("ch1=%X\n",ch1);//输出常字符'a'地址
    printf("main=%X\n",main);//输出主函数起始地址

    int  l_data;
    const int l_data2;
    //l_data2=20;//错误
    printf("l_data=%X\n",&l_data);
    printf("l_data2=%X\n",&l_data2);//const 修饰局部变量存储栈
    printf("g_data=%X\n",&g_data);
    printf("g_data=%X\n",&g_data2);

    printf("g_data=%X\n",&g_data4);
    printf("g_data=%X\n",&g_data3);
    return 0;
}
