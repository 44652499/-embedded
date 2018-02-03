#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <linux/tcp.h>

int main(int argc, char const *argv[])
{

	//struct tcphdr 
	//struct ip
	printf("%d\n",sizeof(struct tcphdr));
	printf("%d\n",sizeof(struct ip));
	printf("%d\n",sizeof(struct icmp));
	return 0;
}