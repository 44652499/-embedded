#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char const *argv[])
{
	uid_t  uid=getuid();
	uid_t  euid=geteuid();
	printf("uid=%d\teuid=%d\n",uid,euid);
	return 0;
}