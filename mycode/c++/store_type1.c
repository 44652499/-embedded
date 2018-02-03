#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a;
	auto  int b;
	register  int c;
	printf("a=%p\tb=%p\tc=%p\n",&a,&b,&c);
	return 0;
}