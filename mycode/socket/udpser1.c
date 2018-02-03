#include "appheader.h"
/*
udp
编程步骤:
1.创建UDP套接字
2.初始自己地址结构
3.绑定
4.获取接收方地址结构
5.发送
*/
int main(int argc, char const *argv[])
{
    int  udp_sck=socket(PF_INET,SOCK_DGRAM,0);
    if(udp_sck==-1)
    {
    	perror("socket:");
    	exit(-1);
    }
    struct sockaddr_in myself_addr;
    bzero(&myself_addr,sizeof(myself_addr));
    myself_addr.sin_family=AF_INET;
    myself_addr.sin_port=htons(1234);
    myself_addr.sin_addr.s_addr=inet_addr("192.168.252.3");

    if(bind(udp_sck,(struct sockaddr*)&myself_addr,sizeof(myself_addr))==-1)
    {
    	perror("bind:");
    	exit(-1);
    }


    //初始化接收方地址结构
    struct sockaddr_in recv_addr;
    bzero(&recv_addr,sizeof(recv_addr));
    recv_addr.sin_family=AF_INET;
    recv_addr.sin_port=htons(6789);
    recv_addr.sin_addr.s_addr=inet_addr("192.168.252.3");

    char buf[1024];
    while(1)
    {
       gets(buf);
       int ret=sendto(udp_sck,buf,strlen(buf),0,(struct sockaddr*)&recv_addr,sizeof(recv_addr));
       bzero(buf,sizeof(buf));
       recvfrom(udp_sck,buf,sizeof(buf)-1,0,NULL,NULL);
       printf("%s\n",buf);
    }
	return 0;
}