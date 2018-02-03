#include "appheader.h"
/*
获取主机IP地址:
*/
//gethostbyname gethostbyaddr 只能获取回环IP地址
/*int main(int argc, char const *argv[])
{
    char hostname[128];
    gethostname(hostname,sizeof(hostname));
    struct hostent * ent=NULL;
    //ent=gethostbyname(hostname);
    ent=gethostbyname("192.168.252.3");
    if(ent!=NULL)
    {
    	printf("host name=%s\n",ent->h_name);
    	int i;
    	for(i=0;ent->h_addr_list[i]!=NULL;i++)
    	{
    		printf("%s\n",inet_ntoa(*(struct in_addr*)(ent->h_addr_list[i])));
    	}
    }
	return 0;
}*/
//通过网卡名称获取IP地址
/*int main(int argc, char const *argv[])
{
	int socket_get_ip;
	char charip[50];
	struct sockaddr_in *sin;
	struct ifreq  ifr_ip;

	socket_get_ip=socket(PF_INET,SOCK_STREAM,0);
	if(socket_get_ip==-1)
	{
		perror("socket:");
		exit(-1);
	}

	bzero(&ifr_ip,sizeof(ifr_ip));
    strncpy(ifr_ip.ifr_name,"eth4",sizeof(ifr_ip.ifr_name)-1);
    //#define SIOCGIFADDR	0x8915 // get PA addresa
    if(ioctl(socket_get_ip,SIOCGIFADDR,&ifr_ip)<0)
    {
    	perror("ioctl-SIOCGIFADDR:");
    	exit(1);
    }

    sin=(struct sockaddr_in*)&ifr_ip.ifr_addr;
    strcpy(charip,inet_ntoa(sin->sin_addr));
    printf("ip:%s\n",charip);
    close(socket_get_ip);
	return 0;
}*/
//设置指定网卡的网络地址
/*int main(int argc, char const *argv[])
{
	int sock_get_ip;
	struct sockaddr_in sock_setip;
	struct ifreq ifr_set_ip;
	bzero(&ifr_set_ip,sizeof(ifr_set_ip));
	char ipaddr[]="192.168.252.5";
	if(ipaddr[0]=='\0')
		exit(-1);
	sock_get_ip=socket(PF_INET,SOCK_STREAM,0);
	if(sock_get_ip==-1)
	{
		perror("socket:");
		exit(-1);
	}

	bzero(&sock_setip,sizeof(sock_setip));
	strncpy(ifr_set_ip.ifr_name,"eth4",sizeof(ifr_set_ip.ifr_name)-1);
    sock_setip.sin_family=AF_INET;
    sock_setip.sin_addr.s_addr=inet_addr(ipaddr);
    memcpy(&ifr_set_ip.ifr_addr,&sock_setip,sizeof(sock_setip));
    //#define SIOCSIFADDR	0x8916	//set PA address
    if(ioctl(sock_get_ip,SIOCSIFADDR,&ifr_set_ip)<0)
    {
    	perror("ioctl-SIOCSIFADDR");
    	exit(-1);
    }
    //#define	IFF_UP		0x1		// interface is up
    //#define	IFF_RUNNING	0x40 // interface RFC2863 OPER_UP
    ifr_set_ip.ifr_flags|=IFF_UP |IFF_RUNNING;
    //#define SIOCSIFFLAGS	0x8914	// set flags
    if(ioctl(sock_get_ip,SIOCSIFFLAGS,&ifr_set_ip)<0)
    {
    	perror("ioctl-SIOCSIFFLAGS");
    	exit(-1);
    }
    close(sock_get_ip);
	return 0;
}*/
//获取网卡物理地址
/*int main(int argc, char const *argv[])
{
	int sock_mac;
	struct ifreq  ifreq_mac;
	char mac_addr[30];
	sock_mac=socket(PF_INET,SOCK_STREAM,0);
	if(sock_mac==-1)
	{
		perror("socket:");
		exit(-1);
	}

    bzero(&ifreq_mac,sizeof(ifreq_mac));
	strncpy(ifreq_mac.ifr_name,"eth4",sizeof(ifreq_mac.ifr_name)-1);
	//#define SIOCGIFHWADDR	0x8927	//Get hardware address
	if(ioctl(sock_mac,SIOCGIFHWADDR,&ifreq_mac)<0)
	{
		perror("ioctl-SIOCGIFHWADDR:");
		exit(-1);
	}

	sprintf(mac_addr,"%02x:%02x:%02x:%02x:%02x:%02x",
		(unsigned char)ifreq_mac.ifr_hwaddr.sa_data[0],
		(unsigned char)ifreq_mac.ifr_hwaddr.sa_data[1],
		(unsigned char)ifreq_mac.ifr_hwaddr.sa_data[2],
		(unsigned char)ifreq_mac.ifr_hwaddr.sa_data[3],
		(unsigned char)ifreq_mac.ifr_hwaddr.sa_data[4],
		(unsigned char)ifreq_mac.ifr_hwaddr.sa_data[5]);
	printf("%s\n",mac_addr);
	return 0;
}*/
//获取掩码地址
int main(int argc, char const *argv[])
{
	int sock_mask;
	struct sockaddr_in *sock_addr;
	struct ifreq  ifreq_mask;
	char netmask[50];

	bzero(&ifreq_mask,sizeof(ifreq_mask));
	sock_mask=socket(PF_INET,SOCK_STREAM,0);
	if(sock_mask==-1)
	{
		perror("socket:");
		exit(-1);
	}

	strncpy(ifreq_mask.ifr_name,"eth4",sizeof(ifreq_mask.ifr_name)-1);
    //#define SIOCGIFNETMASK	0x891b	// get network PA mask
	if(ioctl(sock_mask,SIOCGIFNETMASK,&ifreq_mask)<0)
	{
		perror("ioctl-SIOCGIFNETMASK");
		exit(-1);
	}

	sock_addr=(struct sockaddr_in*)(&ifreq_mask.ifr_netmask);
	strcpy(netmask,inet_ntoa(sock_addr->sin_addr));
	printf("%s\n",netmask);
	close(sock_mask);
	return 0;
}
