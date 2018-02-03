#include <stdio.h>
#define  PI  3.14
int main(int argc, char const *argv[])
{
	// int a=PI;
	// printf("%d\n",PI);
	int a[]={10,20,30,40,56};
	int *p=a;
	printf("%d\n",*p);
	printf("%d\n",*++p);
	printf("%d\n",++*p);
	printf("%d\n",*p++);
	printf("%d\n",*p);
	//printf("%d\n",*++p);
	//printf("%d\n",*++p);
	return 0;
}