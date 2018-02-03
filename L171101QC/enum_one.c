#include <stdio.h>
/*
枚举类型:是一种自定义类型,把属于类型值全列举出来.该类型值被限制.只能是列举之中值
可以把常用的值类型用枚举限制.如:颜色  性别等
*/
//定义枚举类型
enum color{
   // red,white,black,orange   //枚举列举值默认是从0开始,后一个值等于前一个加1
   red=23,white,black=55,orange  //指定枚举值等于一个整数值
};

int main(int argc,const char* argv)
{
    enum color  c;//定义枚举变量
    c=red;//赋值,只能赋予列举值
    //c=read;//错误,枚举中不存在read值

    printf("%d\n",sizeof(c));//枚举类型变量实质就是一个整数类型
    c=white;
    printf("%d\n",c);
    return 0;
}