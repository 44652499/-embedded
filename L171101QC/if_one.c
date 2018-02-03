#include <stdio.h> 
int  main (int argc,const char* argv[])
{
    //int a=1,b=3,c=5,d=4;
    // if(a<b)
    //    if(c<d) 
    //       x=1;
    //    else 
    //       if(a<c)
    //         if(b<d)
    //            x=2;
    //         else x=3;
    //       else x=6;
    // else 
    //     x=7;
    //尽量少用if else嵌套
    // int x;
    // if(a>=b)
    // {
    //     x=7;
    //     printf("%d\n",x);
    //     return;//结束当前的函数执行,由于现在是用在主函数,结束主函数结束程序执行.
    // }
    // if(c<d)
    // {
    //     x=1;
    //     printf("%d\n",x);
    //     return;
    // }
    // if(a>=c)
    // {
    //     x=6;
    //     printf("%d\n",x);
    //     return;
    // }
    // if(b<d)
    // {
    //     x=2;
    //     printf("%d\n",x);
    //     return;
    // }
    // x=3;
    // printf("%d\n",x);
    //一个变量与一个常数比较
    // int a=4;
    // //if(a=3)//正确,
    // //if(a=0)//if(0)
    // if(scanf("%d",&a))//输入语句正确,相当于if(1)
    // //if(3=a)//错误
    // //if(3==a)//建议写法
    // {
    //     printf("yes\n");
    // }
    // else
    // {
    //     printf("no\n");
    // }
    //char c='D';
    //printf("%d\n",c);
   
    
    char ch;
    ch=getchar();
    putchar(ch);
    return 0;
}