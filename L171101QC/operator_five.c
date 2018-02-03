#include <stdio.h> 
#include <limits.h> 
/*
"?:" 唯一三元符号
a?b:c: if(a){b}else{c}
*/
int main(int argc,const char* argv[])
{
    // int a=9;
    // int b=3;
    // printf("%d\n",a/b?4:5);
    // printf("%d\n",a>b?4:5);
    // printf("%d\n",a%b?4:5);
   // printf("%d\n",a%b?a-b?:1:a/b?2:5);
    //printf("%d\n",a/b?a-b?0:1:a/b?2:5);
    //a%b?a-b?:1:a/b?2:5   a%b  ?  a-b?:1  :  a/b?2:5

    // int a=7;
    // unsigned int b=20;
    // //printf("%d\n",a-b);// a-b 是一个无符号数,但是输出是%d,完成了一个转换
    // printf("%u\n",a-b);
    // printf("%c\n",a-b>0?'y':'n');
    // //如果表达式中右有符号数和无符号数,其结果必定是无符号数
    // //a-b其结果必定是一个无符号数

    //如何不使用比较符号(== != > <  >= <=) ,实现比较 a ,b大小
    // int a=5;
    // int b=-3;
    // printf("%d\n",abs(a-b)-(a-b)?b:a);

    //逗号 ,
    //int a=(1,2,3,45);//","取最后一个值
    //printf("%d\n",a);

    // int a=4;
    // int b=5;
    // int c=(a++,++b,a+++b);//取最后一个表式值,单前面表达式运行
    // printf("%d\n",c);

    // int a[3]={(1,2,3,4)};
    // printf("%d\n",a[0]);
    // printf("%d\n",a[1]);
    // printf("%d\n",a[2]);

    //赋值
    int a=3;
    //a+=3*5+2;//a=3+(3*5+2)=20
    a*=3+5+2; //a=a*(3+5+2)=3*(3+5+2)  赋值右边表达式算一个整体
    printf("%d\n",a);
    return 0;
}