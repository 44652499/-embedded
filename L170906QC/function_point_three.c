#include <stdio.h>
/*int  (*(*f)(int,int))(int);*/
//1.函数指针,指向一个整数参数和返回值又是一个函数指针
//2.返回值函数指针,指向 和返回值是整数的函数
typedef  int (*ptr_ret)(int);
typedef  ptr_ret  (*ptr_fun)(int,int);


int  (*(*f)(int,int))(int);
int  fun(int a)
{
    return a;
}

ptr_ret  fun2(int a,int b)
{
    ptr_ret  p1=fun;
    return  p1;
}
int main(int argc,const char* argv[])
{
    // ptr_ret  p2=fun2(200,100);
    // //printf("%d\n",p2(3));
    // f=fun2;
    // p2=f(200,100);
    // printf("%d\n",p2(3));
    char ch[]="中国人";
    //printf("%s",ch);
    printf("%d\n",sizeof(ch));
    printf("%c",ch[0]);
    printf("%c%c%c",ch[0],ch[1],ch[2]);
    printf("%c%c%c",ch[3],ch[4],ch[5]);
    printf("%c%c%c",ch[6],ch[7],ch[8]);
    return 0;
}