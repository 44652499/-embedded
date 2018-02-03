#include "extern.h"
void  print_array()
{
	//extern int g_array[];
	extern int* g_array;//错误
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d\t",g_array[i]);
	}
	printf("\n");
}