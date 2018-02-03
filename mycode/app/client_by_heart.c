#include "define_all_header.h"
#define  BUFFER_SIZE 1024
typedef enum Type
{
	HEART,
	OTHER
}Type;

typedef struct PACKET_HEAD
{
	Type type;
	int length;
}PACKET_HEAD;

void  sys_error_info(const char* errormsg)
{
	perror(errormsg);
}

int  init_socket(int port)
{
	int client_fd=socket(PF_INET,SOCK_STREAM,0);
	if(client_fd==-1)
	{
		sys_error_info("socket  fail:");
		return -1;
	}
	struct sockaddr_in  server_addr;
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(port);
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	if(connect(client_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)
	{
		sys_error_info("connect  fail:");
		return -1;
	}
	return client_fd;
}

void* send_heart(void* arg)
{
	int  client_fd=*(int*)arg;
	int count=0;
	while(1) 
    {
        PACKET_HEAD head;
        head.type = HEART;
        head.length = 0;    
        int ret=send(client_fd,(void*)&head,sizeof(head),0);
        if(ret==-1)
        {
        	perror("send fail:");
        }
        sleep(3);     // 定时3秒
        ++count;      // 测试：发送15次心跳包就停止发送
        if(count > 15)
            break;
    }
}

void  do_running(int client_fd)
{
	pthread_t  pthreadid;
	int ret=pthread_create(&pthreadid,NULL,send_heart,(void*)&client_fd);
	if(ret==-1)
	{
		sys_error_info("do_running pthread_create fail:");
		return;
	}
	pthread_join(pthreadid,NULL);
}

int main(int argc, char const *argv[])
{
	int client_fd=init_socket(1234);
	do_running(client_fd);
	return 0;
}