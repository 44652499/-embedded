#include <stdio.h>
int g_data=10;
const int c_data=20;
int main(int argc, char const *argv[])
{
	char *p="abcd";
	//printf("%X\t%X\t%X\n",&g_data,&c_data,p);
	//输出结果:&g_data=8049664 &c_data=80484E0   p=80484E4
	return 0;
}