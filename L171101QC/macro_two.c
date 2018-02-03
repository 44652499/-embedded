#include <stdio.h>
/*
宏替换:预编译时用宏变量的值替换宏变量
宏变量:用#define 定义变量,分为有参数和无参数宏.
无参数宏:宏变量后面就是值
宏变量优点:
1.使用宏可提高程序的通用性和易读性,减少不一致性,减少输入错误和便于修改.例如:数组大小常用宏定义
宏变量使用注意事项:
1.一般宏变量名大写,与程序定义变量
2.定义变量语句后不需要使用";"
3.变量名与值之间必须用空格
4.宏变量使用"",则不是一个变量
5.宏定义不分配内存,变量定义分配内存
6.宏定义不存在类型问题,它的参数也是无类型的
*/
#define  A 20    //无参数宏
//#define  "B"  300
#define  B  300
#define  C  nt
int main(int argc,const char* argv[])
{
    // int data=A;//int data=20
    // int data2=A;//int data2=20;
    // int array[A];
    // int data=B;

    int data=A+B;
    char *ch="B";//B是一个常字符
    i C  data4;

    return 0;
}