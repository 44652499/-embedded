 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
int main(int argc, char const *argv[])
{
	struct in_addr addr;
	int ret;
	char *c=NULL;
	ret=inet_aton(argv[1],&addr);
	if(ret>0)
	{
		printf("addr=%x\n",addr.s_addr);
		c=(char*)&addr;
		printf("ip1=%x.%x.%x.%x\n",*c&0xff,*(c+1)&0xff,*(c+2),*(c+3));
		printf("ip2=%u.%u.%u.%u\n",*c&0xff,*(c+1)&0xff,*(c+2),*(c+3));
	}
	return 0;
}
