#include "appheader.h"
#define BUFFER_MAX 2048
typedef struct ethhdr  MAC_FRM_HDR;
typedef struct iphdr   IP_HDR;
typedef struct udphdr  UDP_HDR;
int main(int argc, char const *argv[])
{

    int socket_raw;
    char buf[BUFFER_MAX];
    int n_rd;
    socket_raw=socket(PF_PACKET,SOCK_RAW,htons(ETH_P_IP));	
    if(socket_raw==-1)
    {
    	perror("socket:");
    	exit(-1);
    }
    while(1)
    {
    	n_rd=recvfrom(socket_raw,buf,BUFFER_MAX,0,NULL,NULL);
    	if(n_rd<46)
    	{
    		perror("recvfrom:");
    		printf("incomplete packet(errno is %d)\n",errno);
    		close(socket_raw);
    		exit(-1);
    	}
        MAC_FRM_HDR *mac_hdr; 
        IP_HDR *ip_hdr; 
        UDP_HDR * udp_hdr;    
        char *tmp1, *tmp2;
        int AND_LOGIC = 0xFF;

        mac_hdr =(MAC_FRM_HDR*) buf;
        ip_hdr =(IP_HDR*)(buf + sizeof(MAC_FRM_HDR));
        udp_hdr =(UDP_HDR*)(ip_hdr+sizeof(IP_HDR));
        tmp1 = mac_hdr->h_source;
        tmp2 = mac_hdr->h_dest;

        printf("MAC: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X==> %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n",
            tmp1[0]&AND_LOGIC, tmp1[1]&AND_LOGIC, tmp1[2]&AND_LOGIC,
            tmp1[3]&AND_LOGIC, tmp1[4]&AND_LOGIC, tmp1[5]&AND_LOGIC,
            tmp2[0]&AND_LOGIC, tmp2[1]&AND_LOGIC, tmp2[2]&AND_LOGIC,
            tmp2[3]&AND_LOGIC, tmp2[4]&AND_LOGIC, tmp2[5]&AND_LOGIC);

        tmp1 = (char*)&ip_hdr->saddr;
        tmp2 = (char*)&ip_hdr->daddr;

        printf("IP: %d.%d.%d.%d => %d.%d.%d.%d\n",
            tmp1[0]&AND_LOGIC, tmp1[1]&AND_LOGIC, tmp1[2]&AND_LOGIC,
            tmp1[3]&AND_LOGIC, tmp2[0]&AND_LOGIC, tmp2[1]&AND_LOGIC,
            tmp2[2]&AND_LOGIC,tmp2[3]&AND_LOGIC);

        switch(ip_hdr->protocol) 
        {
            case IPPROTO_ICMP: printf("ICMP"); break;
            case IPPROTO_IGMP: printf("IGMP"); break;
            case IPPROTO_IPIP: printf("IPIP"); break;
            case IPPROTO_TCP:
            case IPPROTO_UDP:
                            printf("Protocol: %s\n", ip_hdr->protocol == IPPROTO_TCP ? "TCP" : "UDP");
                            printf("Source port: %u, destination port: %u\n", udp_hdr->source, udp_hdr->dest);
                            break;
            case IPPROTO_RAW: printf("RAW\n"); break;
            default: printf("Unknown, please query in inclued/linux/in.h\n"); break;
        }
    }
    close(socket_raw);
	return 0;
}