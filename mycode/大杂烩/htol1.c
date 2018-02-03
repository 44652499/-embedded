#include <arpa/inet.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	long x=0x11223344;
	char *c;
	c=(char*)&x;
	printf("H=%x\t%x\t%x\t%x\n",*c,*(c+1),*(c+2),*(c+3));//小端模式
	long y=htonl(x);
	c=(char*)&y;
	printf("H=%x\t%x\t%x\t%x\n",*c,*(c+1),*(c+2),*(c+3));//大端模式
	return 0;
}