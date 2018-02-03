#include "appheader.h"

typedef struct client_info
{
	char client_id[10];
	struct sockaddr_in  client_addr;
	int client_addr_len;
}client_info;

void sys_error(char * msgtitle)
{
	perror(msgtitle);
	exit(-1);
}
//初始化tcp套接字
int   init_tcp_socket()
{
	int tcp_socket=socket(PF_INET,SOCK_STREAM,0);
	if(tcp_socket==-1)
	{
		sys_error("socket");
	}
	struct sockaddr_in  server_addr;
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	server_addr.sin_addr.s_addr=inet_addr("192.168.252.3");

	if(connect(tcp_socket,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)
	{
		sys_error("connect");
	}
	return tcp_socket;
}

//注册登记到服务端
struct sockaddr_in register_to_server(int tcp_socket,char * client_id)
{
   struct sockaddr_in  myself_addr;
   send(tcp_socket,client_id,strlen(client_id),0);
   recv(tcp_socket,&myself_addr,sizeof(myself_addr),0);
   printf("ip=%s\t%d\n",inet_ntoa(myself_addr.sin_addr),ntohs(myself_addr.sin_port));
   close(tcp_socket);
   return myself_addr;
}


//初始化uDP套接字
int init_udp_socket(struct sockaddr_in myself_addr)
{
	int udp_socket=socket(PF_INET,SOCK_DGRAM,0);
	if(udp_socket==-1)
	{
		sys_error("socket");
	}	
    if(bind(udp_socket,(struct sockaddr*)&myself_addr,sizeof(myself_addr))==-1)
    {
    	sys_error("bind:");
    }
    return udp_socket;
}
//建立文件内存映射
client_info *  init_file_map()
{
	int fd=open("client_info",O_RDWR);
	if(fd==-1)
	{
		sys_error("open:");
	}
	int file_size=20*sizeof(client_info);
	client_info *p_info=(client_info*)mmap(NULL,file_size,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
	if(p_info==NULL)
	{
		sys_error("mmap");
	}
	return p_info;
}

//获取目标客户地址结构信息
struct sockaddr_in  get_dest_client_addr(client_info * p_info,char * client_id)
{ 
   struct sockaddr_in dest_client_addr;
   bzero(&dest_client_addr,sizeof(dest_client_addr));
   int i;
   for(i=0;i<20;i++)
   {
   	if(strcmp(p_info[i].client_id,client_id)==0)
   	{
   		dest_client_addr=p_info[i].client_addr;
   		break;
   	}
   }
   return dest_client_addr;
}

//与客户通信
void  chat_to_client(int udp_socket,client_info * p_info)
{
    char chat_client_id[10];   
    struct sockaddr_in chat_addr;
    char msg[1024]; 
	while(1)
	{
        gets(chat_client_id);  
        bzero(&chat_addr,sizeof(chat_addr));
        chat_addr=get_dest_client_addr(p_info,chat_client_id); 
        printf("to ip=%s\t%d\n",inet_ntoa(chat_addr.sin_addr),ntohs(chat_addr.sin_port));
        gets(msg);
        sendto(udp_socket,msg,strlen(msg),0,(struct sockaddr*)&chat_addr,sizeof(chat_addr));
        bzero(msg,sizeof(msg)); 
        recvfrom(udp_socket,msg,sizeof(msg)-1,0,NULL,NULL);   
        printf("recv:%s\n",msg);      
	}
}

int main(int argc, char const *argv[])
{
    if(argc!=2)
    {
    	printf("parameter error\n");
    	exit(-1);
    }
	int tcp_socket=init_tcp_socket();
	struct sockaddr_in myself_addr=register_to_server(tcp_socket,(char*)argv[1]);
	int udp_socket=init_udp_socket(myself_addr);
	client_info  *p_info=init_file_map();
    chat_to_client(udp_socket,p_info);
	return 0;
}
/*
增加mysql数据库 sqlite数据库操作
*/