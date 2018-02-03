#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	void * addr=sbrk(0);
	printf("addr=%d\n",addr);
	int *ptr=(int*)malloc(10*sizeof(int));
	printf("ptr=%d\n",ptr);
	addr=sbrk(0);
	printf("addr=%d\n",addr);
	free(ptr);
	ptr=NULL;
	return 0;
}