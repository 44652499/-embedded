#include <stdio.h>
int main(int argc, char const *argv[])
{
	char *s = "char *s=%c%s%c;main(){printf(s,34,s,34);}";
    //printf(s,34,s,34);
    printf("char *s=%c%s%c;main(){printf(s,34,s,34);}",34,"char *s=%c%s%c;main(){printf(s,34,s,34);}",34)
	return 0;
}