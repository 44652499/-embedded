#include "define_all_header.h"
#define  CLIENT_ID_LEN 10
#define  MSG_BUF_LEN   1024

typedef struct msgpack
{
	char src_client_id[CLIENT_ID_LEN];
	char msg_buf[MSG_BUF_LEN];
}msgpack;

void sys_msg_err(const char *errname)
{
	perror(errname);
	exit(-1);
}

int get_listen_fd()
{
	int listen_fd=socket(PF_INET,SOCK_STREAM,0);
	if(listen_fd==-1)
	{
		sys_msg_err("get listen_fd fail:");
	}
	return listen_fd;
}

int get_udp_fd()
{
	int udp_fd=socket(PF_INET,SOCK_DGRAM,0);
	if(udp_fd==-1)
	{
		sys_msg_err("get udp_fd fail:");
	}
	return udp_fd;
}

struct sockaddr_in addr_init(int port)
{
	struct sockaddr_in addr;
	bzero(&addr,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	//addr.sin_addr.s_addr=INADDR_ANY;
	addr.sin_addr.s_addr=inet_addr("192.168.70.3");
}

void bind_and_listen(int listen_fd,struct sockaddr_in server_addr)
{
	if(bind(listen_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)
	{
		sys_msg_err("bind server_addr fail:");
	}
	if(listen(listen_fd,10)==-1)
	{
		sys_msg_err("bind and listen fail:");
	}
}

void server_running(int listen_fd,int udp_fd)
{
	fd_set work_set;
	struct timeval timeout;
	bzero(&timeout,sizeof(timeout));
	int max_fd=listen_fd>udp_fd?listen_fd:udp_fd;
	while(1)
	{
		FD_ZERO(&work_set);
		FD_SET(listen_fd,&work_set);
		FD_SET(udp_fd,&work_set);
		timeout.tv_sec=1;
		timeout.tv_usec=0;
		int fd_nums=select(max_fd+1,&work_set,NULL,NULL,&timeout);
		printf("fd_nums=%d\n",fd_nums);
		if(fd_nums<=0)
		{
			continue;
		}
		if(fd_nums>0)
		{
			if(FD_ISSET(listen_fd,&work_set))
			{
				struct sockaddr_in client_addr;
				bzero(&client_addr,sizeof(client_addr));
				socklen_t client_addr_len=sizeof(client_addr);
				int client_fd=accept(listen_fd,(struct sockaddr*)&client_addr,&client_addr_len);
				if(client_fd==-1)
				{
					sys_msg_err("aceept client_fd fail:");
				}
				if(client_fd>0)
				{
					printf("aceept client_addr succeed\n");
					printf("client_addr:%s\n",inet_ntoa(client_addr.sin_addr));

					msgpack msg;
					bzero(&msg,sizeof(msg));

					int recv_size=recv(client_fd,(void*)&msg,sizeof(msg),0);
					if(recv_size>0)
					{
						printf("recv succeed\n");
						printf("%s is online\n",msg.src_client_id);

						int send_size=send(client_fd,(void*)&client_addr,sizeof(client_addr),0);
						if(send_size>0)
						{
							printf("send client_addr succeed\n");
						}	
						else
						{
							printf("send client_addr fail\n");
						}
					}
					else
					{
						printf("recv fail\n");
					}
				}
			}
			if(FD_ISSET(udp_fd,&work_set))
			{

			}
		}
	}
}

void qq_server()
{
	int listen_fd=get_listen_fd();
	int isreuse=1;
	setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR,(void*)&isreuse,sizeof(isreuse));
	printf("listen_fd=%d\n",listen_fd);
	struct sockaddr_in server_addr=addr_init(5566);	
	signal(SIGPIPE,SIG_IGN);
	bind_and_listen(listen_fd,server_addr);

	int udp_fd=get_udp_fd();
	printf("%d\n",udp_fd);
	if(bind(udp_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)
	{
	  sys_msg_err("bind fail:");
	}
	server_running(listen_fd,udp_fd);
}

int main(int argc, char const *argv[])
{
	qq_server();
	return 0;
}

