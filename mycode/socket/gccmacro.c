#include <stdio.h>
#ifdef A
void fun()
{
	printf("A linux\n");
}
#endif

#ifdef B
void fun()
{
	printf("B window\n");
}
#endif
int main(int argc, char const *argv[])
{
	fun();
	return 0;
}