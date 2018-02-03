#include "define_all_header.h"
#define CLIENT_ID_LEN 10
#define MSG_BUF_LEN 1024

typedef struct msgpack
{
	char src_client_id[CLIENT_ID_LEN];
	char msg_buf[MSG_BUF_LEN];
}msgpack;

char g_client_id[CLIENT_ID_LEN];

void* sys_msg_err(const char *errname)
{
	perror(errname);
	exit(-1);
}

int get_client_fd()
{
	int client_fd=socket(PF_INET,SOCK_STREAM,0);
	if(client_fd==-1)
	{
		sys_msg_err("client_fd get fail:");
	}
	return client_fd;
}

struct sockaddr_in addr_init(int port)
{
	struct sockaddr_in addr;
	bzero(&addr,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	//addr.sin_addr.s_addr=INADDR_ANY;
	addr.sin_addr.s_addr=inet_addr("192.168.70.3");
	return addr;
}

struct sockaddr_in tcp_send_recv(int client_fd)
{
	msgpack msg;
	bzero(&msg,sizeof(msg));
	strcpy(msg.src_client_id,g_client_id);
	int send_size=send(client_fd,(void*)&msg,sizeof(msg),0);
	if(send_size<0)
	{
		printf("send fail\n");
	}
	else
	{
		printf("send succeed\n");
		struct sockaddr_in client_addr;
		bzero(&client_addr,sizeof(client_addr));
		int recv_size=recv(client_fd,(void*)&client_addr,sizeof(client_addr),0);
		if(recv_size>0)
		{
			printf("recv client_addr\n");
			printf("client_addr:%s\n",inet_ntoa(client_addr.sin_addr));
		}
		else
		{
			printf("recv client_addr fail\n");
			exit(-1);
		}
		return client_addr;
	}	
}

void qq_client()
{
	int client_fd=get_client_fd();
	struct sockaddr_in server_addr=addr_init(5566);
	if(connect(client_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)
	{
		sys_msg_err("connect fail:");
	}

	printf("connect succeed\n");
	printf("server_addr:%s\n",inet_ntoa(server_addr.sin_addr));
	printf("input client_id\n");
	scanf("%s",g_client_id);

	struct sockaddr_in client_addr=tcp_send_recv(client_fd);
}

int main(int argc, char const *argv[])
{
	qq_client();	
	return 0;
}
