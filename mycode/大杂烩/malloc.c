#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int*p=(int*)malloc(0);
	if(p==NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("not null\n");
	}
	*p=21;
	printf("%d\n",*p);
	
	return 0;
}
