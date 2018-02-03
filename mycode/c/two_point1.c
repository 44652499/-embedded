#include <stdio.h>
typedef int (*fun)(int);
int  add1(int a)
{
	return a+10;
}

int add2(int b)
{
	return b+20;
}

int sub1(int a)
{
	return a-30;
}

int sub2(int a)
{
	return a-40;
}

int main(int argc, char const *argv[])
{
	// int (*p[2])(int);
	// p[0]=add1;
	// p[1]=add2;
	// printf("%d\n",p[0](10));
	// printf("%d\n",p[1](20));

	// int (*p[2][2])(int);
	// p[0][0]=add1;
	// p[0][1]=add2;
	// p[1][0]=sub1;
	// p[1][1]=sub2;
	// int (*(*q)[2])(int);
	// //printf("%d\n",sizeof(q));
	//  q=p;
	//  int i,j;
	//  for(i=0;i<2;i++)
	//  {
	//    for(j=0;j<2;j++)
	// 	{
	//  		printf("%d\n",((fun)*(*(q+i)+j))(10));
	//  	}
	//  }	

	// int a[][3]={1,2,3,4,5,6,7,8,9};
	// int *p1;
	// int **q=&p1;
	// int i,j;
	// for(i=0;i<9;i++)
	// {
	// 	p1=(int*)a+i;
	// 	printf("%d\t",**q);		
	// }
	// printf("\n");

	// int a[][3]={1,2,3,4,5,6,7,8,9};
	// int *p1;
	// int **q=&p1;
	// int i,j;
	// for(i=0;i<3;i++)
	// {
	// 	p1=(int*)(a+i);
	// 	for(j=0;j<3;j++)
	// 	{
 //          printf("%d\t",*(*q+j));
	// 	}	
	// 	printf("\n");	
	// }	

   char data[1000];
   int i;
   for(i=0;i<1000;i++)
   {
      data[i]=-1-i;
      printf("%d\n",data[i]);
   }
   printf("%d\n",strlen(data));
   return 0;
}
