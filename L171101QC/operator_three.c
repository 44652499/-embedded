#include <stdio.h> 
#include <limits.h> 
/*
比较符号: >  <  >=  <= !=
比较的结果只有:
真
假
c如何表示真假:
0:表示假
非0:表示真
真一般取1,假一般取0
*/
int main(int argc,const char* argv[])
{
    //int a;
    // static int a;
    // if(a)
    // {
    //     printf("yes\n");
    // }
    // else
    // {
    //     printf("no\n");
    // }

    // int a=9;
    // printf("%d\n",1<a);
    // if(1<a<20)
    // {
    //     printf("yes\n");
    // }
    // else
    // {
    //     printf("no\n");
    // }
    //双精度如何比较
    // double  d1=12345.123124;
    // double  d2=12345.123123;
    // //比较双精度不能直接使用= != > <
    // if(abs(d1-d2)<0.000001)
    // {
    //     printf("d1==d2");
    // }
    // else
    // {
    //     printf("d1!=d2");
    // }
    //计算1/2017 精确到小数位后100位
    //printf("%f\n",(double)1/2017);
    int a=10;
    int b=2017;
    int i;
    for(i=0;i<100;i++)
    {
        printf("%d",a/b);
        a=a%b*10;
    }
    return 0;
}