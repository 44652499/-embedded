#include <stdio.h>
/*
递归:在调用函数时,存在f(x+1),f(x)存在一定关联.f(x)中调用f(x+1),f(x)称为函数递归调用.
函数自己调用自己
实现函数递归:
1.必须存在一定关系 f(x)  f(x+1) 存在一定规律
2.必须存在一个结束点.否则死循环
递归实现原理过程:
1.从f(x)  到 f(x+n)  递推
2.递推到结束点.停止往下递推
3.从结束点开回退,一一返回递归函数结果
1+2+3+...+100  分析:
1.f(x+n)=f(x)+n  f(100)=f(99)+99  f(99)=f(98)+n  f(2)=f(1)+2  f(1)=1;

递归更多是考虑过程,不要考虑细节
递归实际就是函数嵌套调用,每调用一次函数分配一个独立栈,递归是一种效率低的算法操作.
注意:
1.递归函数递归参数不能是全局变量
2.递归函数不一定都要有返回值 和参数
*/
int   sum(int n)
{
    if(n==1)
       return 1;
    else
       return sum(n-1)+n;
}
void e(int n)
{
  if(n>0)
  {
    e(--n);
    printf("%d" , n);
    e(--n);
  }
}
//上台阶:一次只能跨一个或跨两个,假设现有n台阶楼梯n=7计算出有多上种上法
int   fun(int n)
{
    if(n==1)
       return 1;
    if(n==2)
       return 2;
    return fun(n-1)+fun(n-2);
}
//不使用任何变量编写strlen 函数
int   fun2(char * ch)
{
    if(*ch=='\0')
       return 0;
    else
    {
        return fun2(++ch)+1;
        //fun2(ch++)+1; //错误,每次调用函数是,首地址都没变
    }
}
//.有5个人坐在一起,问第5个人多少岁?他说比第4个人大两岁问第4个人岁数,他说比第3个人大两岁问第3个人,又说比第2个人大两岁问第2个人,说比第1个人大两岁最后问第1个人,他说是10岁请问第5个人多大

int  fun3(int n)
{
    if(n==1)
       return 10;
    return  fun3(n-1)+2;
}
//用递归方法求n!
int  fun4(int n)
{
    if(n==1)
       return 1;
    return  fun4(n-1)*n;
}
//6.求数列:y=f(x)=f(x-1)+f(x-2) 的指定的第x项对应的y值是多少? 条件:f(1)=f(2)=1; x必须是非0的正整数
int  fun6(int n)
{
    if(n==1 || n==2)
       return 1;
    return fun6(n-1)+fun6(n-2);
}
//采用递归方法将任一整数转换为二进制形式
void  fun7(int n)
{
    if(n/2==0)
    {
        printf("%d",n);
    }   
    else
    {       
        fun7(n/2); 
        printf("%d",n%2);
    }
}
//用递归法将一个整数n转换成字符串（例如输入4679，应输出字符串“4679”），n为不确定数，可以是位数不超过5，且数值在-32768~32767之间和任意整数
void   fun8(int  n)
{
    if(n/10==0)
    {
        printf("%c",n%10+48);
    }
    else
    {
        fun8(n/10);
        printf("%c",n%10+48);
    }
}
//9.利用递归函数调用方式，将所输入的一行字符，以相反顺序打印出来.
void  fun9()
{
    char ch;
    ch=getchar();
    if(ch=='\n' ||  ch==' ')
       return ;
    fun9();
    putchar(ch);
}
//10.汉诺塔是根据一个传说形成的一个问题。汉诺塔（又称河内塔）问题是源于印度一个古老传说的益智玩具。大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘
//输出移动步骤函数 (刘嘉麟讲)
int main(int argc, char const *argv[])
{
    //int result=sum(5);
    //printf("%d\n",result);
    // int a;
    // a=3;
    // e(a);
   // printf("%d\n",fun(7));
     //printf("%d\n",fun2("abcd"));
    // printf("%d\n",fun3(5));
    //printf("%d\n",fun4(6));
    //printf("%d\n",fun6(3));
    //fun7(14);
    //fun8(1234);
    fun9();
    return 0;
}