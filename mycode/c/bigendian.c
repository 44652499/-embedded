#include <stdio.h>
#define BIG_LITTLE(a) (((a&0xff) <<24 )| ((a &0xff00) <<8) | ((a&0xff0000)>>8 )| ((a&0xff000000)>>24))  
int main(int argc, char const *argv[])
{
	int a=0x12345678;
	printf("a=%x\n",a);
    //BIG_LITTLE(a);
    printf("a=%x\n",BIG_LITTLE(a));
	return 0;
}