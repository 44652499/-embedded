#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a=9;
	int b=9;
	//char ch=(char)(a+b);
	char ch=(a+b)+'0';
	printf("%d\n",ch-'0');
	return 0;
}