#include <stdio.h>
//typedef  const char*  T;
//typedef  char* const  T;
typedef  char* T;
//typedef  const T TT;
typedef  T const TT;
int main(int argc, char const *argv[])
{
	char ch[]="abcd";
	// T t1=ch;
	// *t1='1';
	// printf("%s\n",t1);
	char ch2[]="12312321";
	TT  t1=ch;
	*t1='2';
	printf("%s\n",t1);
	t1=ch2;
	printf("%s\n",t1);
	return 0;
}