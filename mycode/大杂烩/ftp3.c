#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#define PORT 8787
int main(int argc, char const *argv[])
{
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1)
	{
		perror("fail to socket");
		return 0;
	}
	struct sockaddr_in addrs;
	bzero(&addrs,sizeof(struct sockaddr));
	addrs.sin_family=AF_INET;
	addrs.sin_port=htons(PORT);
	addrs.sin_addr.s_addr=inet_addr("127.0.0.1");

	int ret=connect(sfd,(struct sockaddr*)&addrs,sizeof(struct sockaddr));
	if(ret==-1)
	{
		perror("fail to connect");
		return 0;
	}
	char buf[1024];
	while(1)
	{
		bzero(buf,sizeof(buf));
		gets(buf);
		send(sfd,buf,strlen(buf),0);
		bzero(buf,sizeof(buf));
		recv(sfd,buf,sizeof(buf)-1,0);
		printf("%s\n",buf);
	}
	return 0;
}
