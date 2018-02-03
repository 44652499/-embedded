#include <stdio.h>
/*
有一个unsigned long型整数,先要分别将其前2个字节和后2个字节用为两个unsigned int型整数输出(设一个int型数据占2个字节),试编写一函数partition实现上述要求.要求在主函数输入该long型整数,在函数partition中输出结果
*/
typedef union A
{ 
	unsigned short part[2]; 
	unsigned long w; 
}A;

void partition(unsigned long num) 
{  
	A *p;
	A  n;
    p=&n;
    n.w=num; 
    printf("long integer=%lx\n",num); 
    printf("short1=%x,shrot2=%x\n",p->part[0],p->part[1]); 
} 
int main(int argc, char const *argv[])
{ 
	unsigned long x; 
    printf("Input a long number:"); 
    scanf("%lx",&x); 
    partition(x); 
    return 0;
} 