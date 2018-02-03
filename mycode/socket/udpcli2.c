#include "appheader.h"
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
    myself_addr.sin_port=htons(6789);
    myself_addr.sin_addr.s_addr=inet_addr("192.168.252.3");

    if(bind(udp_sck,(struct sockaddr*)&myself_addr,sizeof(myself_addr))==-1)
    {
    	perror("bind:");
    	exit(-1);
    }

    char buf[1024];
    struct sockaddr_in send_addr;
    int  send_addr_len=sizeof(send_addr);
    while(1)
    {
       bzero(buf,sizeof(buf));
       recvfrom(udp_sck,buf,sizeof(buf)-1,0,(struct sockaddr*)&send_addr,&send_addr_len);
       printf("addr=%s\tprot=%d\n",inet_ntoa(send_addr.sin_addr),ntohs(send_addr.sin_port));
       printf("recv:%s\n",buf);
       gets(buf);
       sendto(udp_sck,buf,strlen(buf),0,(struct sockaddr*)&send_addr,sizeof(send_addr));
    }
	return 0;
}