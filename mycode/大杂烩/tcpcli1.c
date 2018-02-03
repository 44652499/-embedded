#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>

int main(int argc, char const *argv[])
{
	int sck1=socket(AF_INET,SOCK_STREAM,0);
	if(sck1==-1)
	{
		perror("socket error\n");
		return;
	}
	//初始化服务端地址结构
	struct sockaddr_in addr;
	bzero(&addr,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_port=htons(33445);
    addr.sin_addr.s_addr=INADDR_ANY;
    //addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    //addr.sin_addr.s_addr=inet_addr("192.168.169.3");

    if(connect(sck1,(struct sockaddr*)&addr,sizeof(addr))==-1)
    {
        perror("connet:\n");
    }
    
    char buf[1025];
    while(1)
    {   	
        gets(buf);
        send(sck1,buf,strlen(buf),0);   
        bzero(buf,sizeof(buf));  
        int len=recv(sck1,buf,sizeof(buf)-1,0);      
        printf("%s\n",buf);         
    }    
	return 0;
}
