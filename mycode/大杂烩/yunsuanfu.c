#include <stdio.h>
int main(int argc, char *argv[])
{
	//int a = 1;
	//int result = a+++3<<2; 
	//int a = 2;
	//int result=(a++ > 2)?(++a):(a+=3);

	//int a = 1234567;
	//int b = 0x06;
	//int result = a&b;
	char result = (char) 0xffeffefe;
	//int result =((0xfe2baf&0xf)|0xff) >> 2/(4<<1); 
	printf("%d\n",result);
	return 0;
}
