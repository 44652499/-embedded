#include <stdio.h>
#include <string.h>
#include  <stdlib.h>
/*
结构体类型内存大小计算:
1.结构体变量大小是所有子元素大小只和
2.结构体变量大小最终必须是4的倍数(地址自然对齐)
3.子元素是不同类型嵌套,每个子元素的起始地址为偶数值
4.如果是相同类型子元素合成一个集合
*/

// typedef struct 
// {
//     int a;
//     char  ch;
//     char  chs[10];//ch chs 合成整体大小为11字节,最后对齐为12字节
// }AA;
// typedef struct 
// {
//     int a;
//     char  ch;//ch 对齐占用4个字节,空闲3个字节,由于int b 占4个字节,不能使用部分空闲空间,b占用下一个4字节
//     int  b;
//     char  chs[10];
// }AA;

// typedef struct 
// {
//     int a;
//     char  ch;//ch 对齐占用4个字节,空闲3个字节,short  b占用空闲2个空间
//     short  b;
//     char  chs[10];
// }AA;

// typedef struct 
// {
//     int a;
//     char  ch;//ch 对齐占用4个字节,空闲3个字节,short  b占用空闲2个空间
//     short  b;
//     char  ch2;
//     char  chs[10];//ch2与chs合成一起占用11字节对齐12字节
// }AA;

// typedef struct 
// {
//     int a;
//     char  ch;//ch 对齐占用4个字节,空闲3个字节,short  b占用空闲2个空间
//     short  b;//b起始地址值是一个偶数,空一个空间
//     char  ch2;
// }AA;

// typedef struct 
// {
//     int a;
//     char  ch;//ch 对齐占用4个字节,空闲3个字节,short  b占用空闲2个空间
//     char  ch2;//占用ch后一个空间,与ch组成一个整体,short  b占用剩余两个空间,地址值为偶数
//     short  b;    
// }AA;

// typedef struct 
// {
//     int a;
//     double d;//分解成2个4字节对齐
//     short  b;    
// }AA;

//#pragma pack 指定内存对齐大小
//#pragma pack(1)
//#pragma pack(2)
//#pragma pack(3)//错误,对齐边界必须是2 的较小次方
// #pragma pack(8)//意义不大,超过4按照4对齐
// typedef struct 
// {
//     int a;
// }AA;


typedef struct 
{
}AA;//空结构体占用0字节
int main(int argc, char const *argv[])
{
    // AA  a1={20,'a',"123456"};
    // int *  ptr=(int*)&a1;
    // printf("%d\n",*ptr);
    // ptr=ptr+1;
    // printf("%c\n",*((char*)ptr));
    // printf("%s\n",((char*)ptr+1));


    // AA  a2={20,'a',30,"123456"};
    // int *  ptr=(int*)&a2;
    // printf("%d\n",*ptr);
    // ptr=ptr+1;
    // printf("%c\n",*((char*)ptr));
    // ptr=ptr+1;
    // printf("%d\n",*ptr);
    // ptr=ptr+1;
    // printf("%s\n",ptr);

    AA  a1;
    printf("%d\n",sizeof(a1));  
    return  0;
}