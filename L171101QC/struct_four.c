#include <stdio.h>
//#pragma pack(1)  //语句指定内存对齐大小
//#pragma pack(0)  //自然对齐
//#pragma pack(2)  
//#pragma pack(3)  //按照4对齐
//#pragma pack(8)   //按照4对齐
/*
结构变量内存分配:
1.由每个成员按照定义顺序组合
2.总大小为所有成员大小之和
3.内存对齐
内存对齐:前一个空间多分配字节数,让下一个空间起始地址为偶数
内存对齐分为自然对齐和语句对齐
自然对齐:32位系统中按照4字节对齐,分配空间大小必定是4的最小倍数
*/
// typedef struct A
// {
// 	int  a;
// 	int  b;
// };

// typedef struct 
// {
// 	int  a;
// 	char  b;
// }A; //内存对齐

// typedef struct 
// {
// 	int  a;
// 	char  b;
// 	char  c;
// 	char  b1;
// 	char  c2;  //c   b1 b2继续使用剩余3字节
// }A;

// typedef struct 
// {
// 	int  a;
// 	char  b;
// 	short c;//c 继续占用b剩余最后两字节
// }A;

// typedef struct 
// {
// 	int  a;
// 	char  b;
// 	short c; //c占用b剩余最后两个空间(b起始地址值必须是sizeof(short)倍数)
// 	char d; //d另外分配4字节
// }A;

// typedef struct 
// {
// 	short a;  //最大成员大小不足4,按照最大成员大小对齐
// 	char  b[3];//集合 按照集合成员大小计算
// 	short c;
// }A;

// typedef struct 
// {
// 	double a;  //最大成员大小超过4,按4对齐
// 	short c;
// }A;

typedef struct 
{
	//char  c;
	int  a;
	char  b; //结构大小与成员定义顺序有关
	char  c;
}A;
int main(int argc, char const *argv[])
{
	printf("%d\n",sizeof(A));
	return 0;
}