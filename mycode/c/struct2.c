#include <stdio.h>
struct A
{
	char b;
	char c;
	short a;	
	double e;
	char f[0];
}a1={20,30},a3;

int main(int argc, char const *argv[])
{
	struct A  a2;
	//printf("%d\t%d\n",a1.a,a1.b);
	printf("%d\n",sizeof(a2));
	return 0;
}