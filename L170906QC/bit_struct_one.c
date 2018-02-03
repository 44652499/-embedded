#include <stdio.h>
/*
位结构体:属于结构体,成员按照位访问存储,不在是以字节处理.
一个字节可以分解成多个不同成员.成员通常称为位域

定义位结构体,位域数据类型一般是:unsigned char | char  short  int
位域占用位数不能超过8

大小端模式:根据处理器约定值的存储起始地址不同
小端模式:低位数据存储在低地址,高位数据存储在高地址
大端模式:地位数据存储在高地址,高位数据存储低地址
0x12345678
小端模式存储:0x12345678
大端模式存储:0x78563412

模式只与处理器有关.
*/
//位结构体
struct  A
{
    char a:3;//位域  3域数(位数)
    //int b:2;
    //int :0; //匿名位域,预留出字节剩下的位数
    int  :2 ; //匿名位域,预留出制定的位数,下一个域从第6个位使用
    char c:4; //位域不能分开存储在两个字节中
};

//验证是否是大大小端模式
int   is_litter_endian(int data)
{
    char *ptr=(char*)&data;
    if(*ptr==1)
       return 1;
    return 0; 
}
int main(int argc, char const *argv[])
{
    //printf("%d\n",sizeof(struct  A));
    // int result=is_litter_endian(1);
    // if(result)
    // {
    //     printf("litter endian\n");
    // }
    // else
    // {    
    //     printf("big endian\n");
    // }

    // int a[5]={1,2,3,4,5};
    // int *ptr1=(int*)(&a+1);
    // int *ptr2=(int*)((int)a+1);
    // printf("%x,%x\n",ptr1[-1],*ptr2);

    //小端模式存储值0x12345678 转化成大端模式:0x78563412
    int  data=0x12345678;
    data=((data&0xff)<<24)|((data&0xff00)<<8)|((data&0xff0000)>>8)| ((data&0xff000000)>>24);
    printf("%X\n",data);
    return 0;
}