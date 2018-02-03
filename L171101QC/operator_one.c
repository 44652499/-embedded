#include <stdio.h> 
#include <limits.h> 
/*
程序=逻辑+表达式
表达式=操作数+操作符号
C语言常用操作符号:
1.运算符号
2.逻辑符号
3.比较符号
4.位运算符号
5.赋值符号
6.逗号
7.问号(?:)
8.其它符号

运算符号:+ - * / %
*/
int main(int argc,const char* argv[])
{
    //int a=6;
    // int a=2147483647;
    // //int b=3;
    // int b=2147483647;
    // printf("%d\n",a+b);//越界 (x>x+1),如何实现a+b a*b??
    // printf("%d\n",a-b);
    // printf("%d\n",a*b);
    // printf("%d\n",a/b);
    // printf("%d\n",a%b);

    int a=5;
    int b=8;
    // int c=a;
    // a=b;
    // b=c;
   //使用ab交换ab值
    //  a=a+b;//依然存在越界BUG
    //  b=a-b;
    //  a=a-b;
    // 最有交换ab 值  ^异或符号
    a=a^b;
    b=a^b;
    a=a^b;
    printf("%d\t%d\n",a,b);
    return 0;
}