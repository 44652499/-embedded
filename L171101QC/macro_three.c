#include <stdio.h>
/*
有参数宏:定义宏变量的形式是 A(参数)

有参数宏注意事项:
1.一般宏变量名大写,与程序定义变量
2.参数没有类型
3."("与宏名不能有空格
4.不检测语法错误
5.不会分配内存
6.参数可以是一个表达式,容易出现是计算顺序与需求计算顺序不一致
7.参数宏在值表达式中要求把每个参数用"()"括起
8.如果参数没有用"()"括起,必修线替换完毕再计算,切记不能边计算边替换
*/
//#define  A (a,b)  a+b //(a,b)  a+b 是一个值
#define  A(a,b)  a+b
#define  B(a,b)  a*b
#define  C(a,b)  ((a)*(b))
#define  D(a)    printf(a);
int main(int argc,const char* argv[])
{
    //int c=A(1,2);
    //int  c=A(3*4,2*9);
    int c=B(1+3,2+5);//实际计算顺序与需求计算顺序不一样
    //int c=C(1+3,2+5);
   // printf("%d\n",c);
   D("%d\n,20");

    return 0;
}