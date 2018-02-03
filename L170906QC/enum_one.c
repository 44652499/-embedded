#include <stdio.h>
#include <string.h>
/*
枚举:自定义数据类型,在定义时列出其可能出现的值.使用变量时只能从列举只中选一个.
红色表示0   1表示蓝色

枚举类型本质就是一个整数类型.用名称表示更具有意义
*/
enum  color
{
    red,
    blue=5,
    green,
    yellow=9,
    orange
};
int main(int argc, char const *argv[])
{
    enum color  c1;
    c1=red;
    //c1=blue;
    //c1=pink;//错误,enum  color 定义不存在此值
    //printf("%d\n",sizeof(c1));

    printf("%d\n",c1);//枚举类型的第一个值从整数0开始

    c1=green;
    printf("%d\n",c1);//前一个值加1
    return 0;
}