#include <netdb.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	struct hostent *host1,*host2;
	host1=gethostbyname(argv[1]);
	if(host1==NULL)
	{
		//perror("gethostbyname:");
		printf("Error:%s\n",hstrerror(h_errno));
		exit(-1);
	}
	printf("host name:%s\n",host1->h_name);
	printf("host alias:%s\n",*host1->h_aliases);
	printf("iptype==%d\n",host1->h_addrtype);
	printf("length=%d\n",host1->h_length);
	printf("list=%s\n",inet_ntoa(*(struct in_addr*)host1->h_addr_list));
	return 0;
}
