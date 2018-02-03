#include <stdio.h>
typedef int(*PTR)[2];
int main(int argc, char const *argv[])
{
	// int array[]={1,2,3,4,5,6};
	// printf("%X\n",&array[0]);
	// printf("%X\n",&array[2]);
	// printf("%X\n",&array[4]);
	// int (*p)[2];//指针
	// //printf("%d\t%d\n",sizeof(array),sizeof(p));
	// //p=&array;
	// //p=array;
	// p=(PTR)array;
	// //printf("%d\n",p+1-p);
	// ///printf("%d\n",(int)(p+2)-(int)p);
	// int i,j;
	// for(i=0;i<3;i++)
	// {
	// 	printf("%X\n",p);
	// 	for(j=0;j<2;j++)
	// 	{
	// 		//printf("%d\t",(int*)p[0]);
	// 		//printf("%d\t",*((int*)(p+i)+j));
	// 		printf("%d\t",((int*)(p+i))[j]);
	// 	}
	// 	printf("\n");
	// }

	int a[]={1,2,3,4,5};
	int b[]={100,200,300,500,400};
	int c[]={4,5,6,7,8};
	int d[]={12,3,4,5,6};
	int* p[2][2]={a,b,c,d};
	int* (*q)[2];
	//通过q实现输出 数组 a b c d的元素值
	q=p;
	int i,j,k;
	for(i=0;i<4;i++)
	{		
		for(k=0;k<5;k++)
		{
			printf("%d\t",*((int*)*((int**)q+i)+k));
		}
		printf("\n");		
	}
	return 0;
}