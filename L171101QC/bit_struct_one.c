#include <stdio.h>
/*
位结构体:为了减少存储空间一种特殊结构体.结构体中成员按照位存储,不再是简单按照字节存储.
位结构体组成=位域+位段
struct  A
{
	int a:4;  //a 称为位域    4 称为位段
	char  b:2;
	//char c:0;
	char  :2;
};
位结构体位域数据类型只能是:(signed|unsigned)char int short
位结构体位段注意点:
1.位段值不能超过位域数据类型大小
2.位域位段不能跨越两个不完整字节
3.位段为0表示流出剩余位数
4.只有位段预留指定位数

位结构体大小计算:
1.所有位域大小相加
2.以最大成员内存对齐

大小端存储模式:
大端存储模式:高字节存储在低地址,低字节存储在高地址
小端存储模式:低字节存储在低地址,高字节存储在高地址
一般大小端模式与处理器有关
0x12345678
小端存储:
低地址                高地址
0x78  0x56  0x34 0x12
大端存储
低地址         高地址
0x12   0x34  0x56  0x78
*/

typedef struct A
{
	int a:4;
	char b:2;
	char c:4;
	char d:3;
	char e:4;
	char f:4;
} A;


typedef struct 	B
{
	int a:4;
	char b:2;
	char c;
} B;

//测试是否大小端模式?
void   is_bigorlitter()
{
	int a=1;
	char *ptr=(char*)&a;
	if(*ptr==1)
	{
		printf("小端存储模式\n");
	}
	else
	{
		printf("大端存储模式\n");
	}

}

int main(int argc, char const *argv[])
{
	// printf("%d\n",sizeof(A));
	// printf("%d\n",sizeof(B));
	// is_bigorlitter();


	// union
 // 	{
 // 		struct student
 // 		{
 //   			unsigned char s1:1;
 //   			unsigned char s2:3;
 // 		}x;
 // 		unsigned char c;
 // 	}v;
 // 	v.c=0;
 // 	v.x.s1=0;
 // 	v.x.s2=4;
	// printf("%d\n",v.c);
	// printf("%d\n",sizeof(v));

	// union
 // 	{
 // 		struct student
 // 		{
 //   			unsigned char s1:1;
 //   			unsigned char s2:2;
 //   			unsigned char s3:2;
 // 		}x;
 // 		unsigned char c;
 // 	}v;
 // 	v.c=0;
 // 	v.x.s1=0;
 // 	v.x.s3=2;
	// printf("%d\n",v.c);
	// printf("%d\n",sizeof(v)); 

	typedef struct bit 
	{   
    	int a:3;
    	int b:2; 
    	int c:3; 
	}bit;  
	bit s; 
    char *c=(char*)&s; 
    printf("%d\n",sizeof(bit));
    *c=0x99;
    printf("s.a=%d\ts.b=%d\ts.c=%d\n",s.a,s.b,s.c);
    int a=-1;
    printf("%x\n",a);
	return 0;
}