#include <stdio.h>
int  g_data;
int  g_data2;
static int s_data;
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
    printf("ret=%p\n",&ret);
	printf("l_a=%p\n",&l_a);
	printf("l_b=%p\n",&l_b);
	printf("g_data=%p\n",&g_data);
	printf("g_data2=%p\n",&g_data2);
	printf("s_data=%p\n",&s_data);
	printf("s_data2=%p\n",&s_data2);
	printf("main=%p\n",&main);
	printf("add=%p\n",add);
	while(1)
	{

	}
	return 0;
}