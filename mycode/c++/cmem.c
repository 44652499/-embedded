#include <stdio.h>
int  g_data=10;
int  g_data2;
static int s_data=20;
static int s_data2;
int add(int a,int b)
{
	int c;
	c=a+b;
	return c;
}

int main(int argc, char const *argv[])
{
	int l_a=20;
	int l_b=30;
	int ret=add(l_a,l_b);
	printf("ret=%d\n",ret);
	return 0;
}