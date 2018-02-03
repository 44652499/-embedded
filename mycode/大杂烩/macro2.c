#include <stdio.h>
int main(int argc, char const *argv[])
{
	#ifdef BUG1
	  printf("BUG1\n");
	#endif

	#ifdef BUG2
	  printf("BUG2\n");
	#endif
	return 0;
}