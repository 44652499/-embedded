#include "appheader.h"
int main(int argc, char const *argv[])
{
    int frame_sck;
    frame_sck=socket(PF_INET,SOCK_PACKET,htons(0x0003));
    //frame_sck=socket(PF_PACKET,SOCK_RAW,htons(ETH_P_802_2));
    if(frame_sck==-1)
    {
        perror("socket:");
        exit(-1);
    }   
    char *dev="eth4";
    struct ifreq ifr;
    strcpy(ifr.ifr_name,dev);
    int i=ioctl(frame_sck,SIOCGIFFLAGS,&ifr);
    if(i<0)
    {
        close(frame_sck);
        perror("ioctl get:");
        exit(-1);
    }
    ifr.ifr_flags|=IFF_PROMISC;
    i=ioctl(frame_sck,SIOCSIFFLAGS,&ifr);
    if(i<0)
    {
        close(frame_sck);
        perror("ioctl set:");
        exit(-1);
    }
    char ep_buf[ETH_FRAME_LEN];
    struct ethhdr *eh;
    int fl=0;
    eh=(struct ethhdr*)ep_buf;
    while(1)
    {
        bzero(ep_buf,sizeof(ep_buf));
        //fl=read(frame_sck,ep_buf,sizeof(ep_buf));
        fl=recvfrom(frame_sck,ep_buf,sizeof(ep_buf),0,NULL,NULL);

        if(fl>46)
        {
           printf("dest MAC:");
           for(i=0;i<5;i++)
           {
                printf("%.2x-",eh->h_dest[i]);
           }
           printf("%.2x\n",eh->h_dest[5]);

           printf("source MAC:");
           for(i=0;i<5;i++)
           {
                printf("%02x-",eh->h_source[i]);
           }
           printf("%02x\n",eh->h_source[5]);
           printf("protocol:0x%04x\n",ntohs(eh->h_proto));
           if(ntohs(eh->h_proto)==0x0800)
           {
                struct iphdr* iph;
                //iph=(struct iphdr*)((unsigned long)ep_buf+ETH_HLEN);
                iph=(struct iphdr*)(ep_buf+sizeof(struct ethhdr));
                struct sockaddr_in srcaddr;
                struct sockaddr_in desaddr;
                bzero(&srcaddr,sizeof(srcaddr));
                bzero(&desaddr,sizeof(desaddr));
                  //printf("src ip%s\n",inet_ntoa((struct in_addr)(iph->saddr)));
                  //printf("dest ip%s\n",inet_ntoa((struct in_addr)(iph->daddr)));
                printf("protocol:%d\n",iph->protocol);
                if(iph->protocol==6)
                {
                    struct tcphdr* tcph;
                    //tcph=(struct tcphdr*)(iph+iph->ihl*4);
                    tcph=(struct tcphdr*)(iph+sizeof(struct iphdr));
                    printf("src port:%d\n",ntohs(tcph->source));
                    printf("dst port:%d\n",ntohs(tcph->dest));
                }
           }
           sleep(3);
        }
        else
        {
            printf("fl=%d\n",fl);
        }
    }     
	return 0;
}