#include <stdio.h>
struct s
{
	int a;
	char b;
	double c;
}t1={1,'a',45.67};
int main(int argc, char const *argv[])
{
	struct  s t2={(100,300),'b',88.99};
	printf("%d\n",t2.a);
	printf("%c\n",t1.b);
	printf("%f\n",t2.c);
	return 0;
}