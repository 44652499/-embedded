#include <stdio.h>

int main(int argc, char *argv[])
{
	int offset = 0x2E;
	short * p = (short *)0x22000000;
	printf("%X\n",p+offset);
	offset++;
	printf("%X\n",offset);
	
	return 0;
}
