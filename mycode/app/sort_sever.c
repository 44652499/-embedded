#include "define_all_header.h"
typedef struct pthread_arg
{	
	struct sockaddr_in udp_addr;
}pthread_arg;
//发送的数据
typedef struct send_data
{
	int data[10000]; 
}send_data;
//文件操作函数
int open_file(const char* filename)
{
	int fd=open(filename,OPEN_CWD_FLAGS,0777);
	if(fd==-1)
	{
		if(errno==EEXIST)
		{
			fd=open(filename,O_RDWR);
		}
		else
		{
			perror("open error:");
			exit(-1);
		}
	}
	else
	{
		fd=open(filename,O_RDWR);
	}
	return fd;
}
//初始化服务端地址结构
struct sockaddr_in init_server_addr(int  port)
{
   struct sockaddr_in  server_addr;
   bzero(&server_addr,sizeof(server_addr));
   server_addr.sin_family=AF_INET;
   server_addr.sin_port=htons(port);
   server_addr.sin_addr.s_addr=INADDR_ANY;
   return server_addr;
}
//初始化tcp套接字
int  init_tcp_socket(struct sockaddr_in  server_addr)
{
	int  listen_fd=socket(AF_INET,SOCK_STREAM,0);
	if(listen_fd==-1)
	{
		perror("socket error:");
	}
	if(bind(listen_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)
	{
		perror("bind error:");
	}
	if(listen(listen_fd,10)==-1)
	{
		perror("listen error:");
	}
	int isreuse=1;
	setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR,(void*)&isreuse,sizeof(listen_fd));
	return listen_fd;
}
//初始化udp套接字
int  init_udp_socket(struct sockaddr_in  udp_addr)
{
	int udp_fd=socket(PF_INET,SOCK_DGRAM,0);
	if(udp_fd==-1)
	{
		perror("socket error:");
		exit(-1);
	}
	if(bind(udp_fd,(struct sockaddr*)&udp_addr,sizeof(udp_addr))==-1)
	{
		perror("bind error:");
		exit(-1);
	}
	return udp_fd;
}
//服务端实现排序及转发
void sever_sort_send(struct sockaddr_in server_addr,int listen_fd,int udp_fd)
{
	int max=0;
	fd_set read_set;
	struct timeval timeout;
	int num;
	max=listen_fd>udp_fd?listen_fd:udp_fd;
	timeout.tv_sec=0;
	timeout.tv_usec=100;
	while(1)
	{
		FD_ZERO(&read_set);
		FD_SET(listen_fd,&read_set);
		FD_SET(udp_fd,&read_set);
		num=select(max+1,&read_set,NULL,NULL,&timeout);
		if(num<=0)
		{
			continue;
		}
		if(num>0)
		{
			if(FD_ISSET(listen_fd,&read_set))
			{
				int client_fd;
				struct sockaddr_in client_addr;
				int client_addr_len=sizeof(client_addr);
				client_fd=accept(listen_fd,(struct sockaddr*)&client_addr,&client_addr_len);
				if(client_fd==-1)
				{
					perror("accept error:");
				}
				if(client_fd>0)
				{
					
					send_data s_data;
					int ret=recv(client_fd,(void*)&s_data,sizeof(s_data),0);
					if(ret>0)
					{
						send(client_fd,(void*)&client_addr,sizeof(client_addr),0);
					}
					printf("%d\n",udp_fd);
				}
				if(FD_ISSET(udp_fd,&read_set))
				{
					send_data s_data;
					bzero(&s_data,sizeof(s_data));
					
					int recv_len=recvfrom(udp_fd,(void*)&s_data,sizeof(s_data),0,NULL,NULL);
					if(recv_len>0)
					{
						int i,j;
						for(i=0;i<10000;i++)
						{
							for(j=0;j<9999;j++)
							{
								if(s_data.data[j]>s_data.data[j+1])
								{
									int temp=s_data.data[j+1];
									s_data.data[j+1]=s_data.data[j];
									s_data.data[j]=temp;
								}
							}
						}
						for(i=0;i<10000;i++)
						{
							printf("%d\n",s_data.data[i]);
						}
					}
					sendto(udp_fd,(void*)&s_data,sizeof(s_data),0,(struct sockaddr*)&client_addr,sizeof(client_addr));
				}
			}			
		}
	}
}
int main(int argc, char const *argv[])
{
	struct sockaddr_in server_addr=init_server_addr(2345);
	int listen_fd=init_tcp_socket(server_addr);
	int udp_fd=init_udp_socket(server_addr);
	sever_sort_send(server_addr,listen_fd,udp_fd);
	return 0;
}