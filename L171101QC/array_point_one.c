#include <stdio.h>
#include <string.h>
typedef  int B[4]; //B表示数据类型(4个整数)

typedef  int C[2]; //c表示数据类型(2个整数)

typedef  int D[2][2];
/*
数组指针:是一个指针(占用4字节),指向的是一个数组(指针+1增加指向数组的大小)

指针数组:是一个数组,元素类型是指针
*/
int main(int argc, char const *argv[])
{
	
	// int *  ptrarray[10];//数组,数组存放10个指针元素
	// int  (*ptr)[10];//指针,指向的是一个由10个整数组成数组空间
	// printf("%d\n",sizeof(ptrarray));
	// printf("%d\n",sizeof(ptr));
	// printf("%d\n",ptr+1-ptr);//相差空间数
 //    printf("%d\n",(int)(ptr+1)-(int)ptr);//相差字节数

	// int a=3,b=5,c=7;
	// int *  array[3]={&a,&b,&c};
	// int  i;
	// for(i=0;i<3;i++)
	// {
	// 	//printf("%d\n",*(array[i]));
	// 	printf("%d\n",*(*(array+i)));
	// }

	// int  a[]={1,2,3,4};
	// int  b[]={10,20,30,40};
	// int  c[]={100,200,300,400};
	// int* array[]={a,b,c};
	// int i,j;
	// for(i=0;i<3;i++)
	// {
	// 	for(j=0;j<4;j++)
	// 	{
	// 		//printf("%d\t",*(array[i]+j));
	// 		printf("%d\t",*(*(array+i)+j));
	// 	}
	// 	printf("\n");
	// }
	//int * array[]={&a,&b,&c};//&a &b  &c表示 空间存储的是4个整数
	// B* array[]={&a,&b,&c};
	// int i,j;
	// for(i=0;i<3;i++)
	// {
	// 	for(j=0;j<4;j++)
	// 	{
	// 		printf("%d\t",*((int*)array[i]+j));
	// 	}
	// 	printf("\n");
	// }


	// int  a[][2]={1,2,3,4};
	// int  b[][2]={10,20,30,40};
	// int  c[][2]={100,200,300,400};
	// C* array[]={a,b,c};
	// int i,j,k;
	// for(i=0;i<3;i++)
	// {
	// 	for(j=0;j<2;j++)
	// 	{
	// 		for(k=0;k<2;k++)
	// 		{
	// 			//printf("%d\t",array[i][j][k]);
	// 			printf("%d\t",*(*(array[i]+j)+k));
	// 		}
	// 		printf("\n");
	// 	}
	// }

	// int  a[][2]={1,2,3,4};
	// int  b[][2]={10,20,30,40};
	// int  c[][2]={100,200,300,400};
	// D* array[]={&a,&b,&c};
	// int i,j,k;
	// for(i=0;i<3;i++)
	// {
	// 	for(j=0;j<2;j++)
	// 	{
	// 		for(k=0;k<2;k++)
	// 		{
				
	// 			printf("%d\t",*(*((C*)array[i]+j)+k));
	// 		}
	// 		printf("\n");
	// 	}
	// }

	//数组指针
	// int a[][2]={1,2,3,4};
	// int (*ptr)[2]=a;
	// //int (*ptr)[2]=&a;
	// int i,j;
	// for(i=0;i<2;i++)
	// {
	// 	for(j=0;j<2;j++)
	// 	{
	// 		//printf("%d\t",*(*(ptr+i)+j));
	// 		printf("%d\t",ptr[i][j]);
	// 	}
	// 	printf("\n");
	// }

	// int  a[][3]={1,2,3,4,5,6,7,8,9};
	// int  (*ptr)[2]=(int(*)[2])a;//注意强制转换
	// int i,j;
	// for(i=0;i<4;i++)
	// {
	// 	for(j=0;j<2;j++)
	// 	{
	// 		printf("%d\t",*(*(ptr+i)+j));
	// 	}
	// 	printf("\n");
	// }

	int a[]={1,2,3,4};
	int b[]={10,20,30,40};
	int c[]={100,200,300,400};
	char ch[]="abcdef";
	int *  array[][2]={a,b,c,(int*)ch};
	int * (*ptr)[2]=array;
    int  i,j,k;
    for(i=0;i<2;i++)
    {
    	for(j=0;j<2;j++)
    	{
    		if(i==1 && j==1)
    		{
    			printf("%s\t",(char*)*(*(ptr+i)+j));
    		}
    		else
    		{
    			for(k=0;k<4;k++)
    			{
    				printf("%d\t",*(*(*(ptr+i)+j)+k));
    			}
    			printf("\n");
    			
    		}
    	}
    }
	return 0;
}