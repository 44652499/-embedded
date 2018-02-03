#include "define_all_header.h"
//发送线程所需参数
typedef struct pthread_arg
{	
	int udp_fd;
	int src_fd;
	struct sockaddr_in server_addr;
}pthread_arg;
//发送的数据
typedef struct send_data
{
	int data[10000]; 
}send_data;
int dest_fd;
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
	int  client_fd=socket(AF_INET,SOCK_STREAM,0);
	if(client_fd==-1)
	{
		perror("socket error:");
		exit(-1);
	}
	if(connect(client_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)
	{
		perror("connect error:");
		exit(-1);
	}
	return client_fd;
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
//得到发送数组
void get_send_array(int* array,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		array[i]=rand();
	}
}
//将数据写入文件
void write_to_file(int fd)
{
	send_data s_data;
	int i;
	for(i=0;i<10000;i++)
	{
		s_data.data[i]=rand();
	}
	write(fd,s_data.data,sizeof(s_data.data));
}
//发送线程
void* send_pthread(void* arg)
{
	pthread_arg msg=*(pthread_arg*)arg;
	printf("%d\n",msg.udp_fd);
	send_data s_data;
	int i;
	while(1)
	{
		read(msg.src_fd,s_data.data,sizeof(s_data.data));
		sendto(msg.udp_fd,(void*)&s_data,sizeof(s_data),0,(struct sockaddr*)&msg.server_addr,sizeof(msg.server_addr));
	}
}
//接收线程
void* recv_pthread(void* arg)
{
	int udp_fd=*(int*)arg;
	send_data recv_data;
	int i;
	int recv_len=recvfrom(udp_fd,(void*)&recv_data,sizeof(recv_data),0,NULL,NULL);
	if(recv_len>0)
	{
		write(dest_fd,recv_data.data,sizeof(recv_data.data));
		for(i=0;i<10000;i++)
		{
			printf("%d\n",recv_data.data[i]);
		}		
	}
}
//发送数据到客户端
void send_data_to_server(struct sockaddr_in server_addr,int client_fd,int* array,int file_fd)
{
	int udp_fd;
	int i=0;
	pthread_arg arg;
	bzero(&arg,sizeof(arg));
	arg.server_addr=server_addr;	
	arg.src_fd=file_fd;	
	struct sockaddr_in udp_addr;
	bzero(&udp_addr,sizeof(udp_addr));
	send(client_fd,(void*)&arg,sizeof(arg),0);
	int ret=recv(client_fd,(void*)&udp_addr,sizeof(udp_addr),0);
	if(ret>0)
	{

		udp_fd=init_udp_socket(udp_addr);
		arg.udp_fd=udp_fd;
		
		pthread_t pthreadid[2];
		send_data s_data;
		for(i=0;i<10000;i++)
		{
			s_data.data[i]=array[i];
		}		
		int ret=pthread_create(&pthreadid[0],NULL,send_pthread,(void*)&arg);
		while(ret==-1)
		{
			ret=pthread_create(&pthreadid[0],NULL,send_pthread,(void*)&arg);
		}
		ret=pthread_create(&pthreadid[1],NULL,recv_pthread,(void*)&udp_fd);
		{
			ret=pthread_create(&pthreadid[1],NULL,recv_pthread,(void*)&udp_fd);
		}
		pthread_join(pthreadid[0],NULL);
		pthread_join(pthreadid[1],NULL);
	}
}
int main(int argc, char const *argv[])
{
	int array[10000];
	get_send_array(array,10000);
	int src_fd=open_file("passwd");
	dest_fd=open_file("passwd1");
	write_to_file(src_fd);
	struct sockaddr_in server_addr=init_server_addr(2345);
	int client_fd=init_tcp_socket(server_addr);
	send_data_to_server(server_addr,client_fd,array,src_fd);
	return 0;
}