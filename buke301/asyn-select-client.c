/*
客户与客户之间的通信:
1.客户通过tcp与服务器链接
2.服务器收到客户发送id,并回发地址结构
3.服务端保存客户用队列保存id 地址结构
4.客户端使用udp套接字实现与客户通信(服务器中转).
5.select实现异步通信
*/
#include "define_all_header.h"

/*
定义消息类型
*/
typedef struct msgnode
{
	char  clientid[10];
	char  mesinfo[50];
}msgnode;
/*
定义线程参数结构类型
*/
typedef struct pthreadarg
{
	int udpsocket;
	struct sockaddr_in serveraddr;
}pthreadarg;
/*
错误信息输出函数
*/
void  sys_print_error(const char* title,const char * info)
{
	char  msg[100];
	strcpy(msg,title);
	strcat(msg,"-->");
	strcat(msg,info);
	perror(msg);
	exit(-1);
}
/*
初始化tcp监听套接字
*/
int  init_client_socket()
{
	int clientsocket=socket(PF_INET,SOCK_STREAM,0);
	if(clientsocket==-1)
	{
		sys_print_error("init_listent_socket","socket error:");
	}
	return  clientsocket;
}
/*
初始化udp套接字
*/
int  init_udp_socket()
{
	int udpsocket=socket(PF_INET,SOCK_DGRAM,0);
	if(udpsocket==-1)
	{
		sys_print_error("init_udp_socket","socket error:");
	}
	return udpsocket;
}
/*
初始化地址结构
*/
struct sockaddr_in  init_socket_addr(const char * ipaddr,int  port)
{
	struct sockaddr_in  serveraddr;
	bzero(&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(port);
	serveraddr.sin_addr.s_addr=inet_addr(ipaddr);
	return  serveraddr;
}

/*
绑定udp套接字
*/
void bind_udp_socket(int udpsocket,struct sockaddr_in myselfaddr)
{
	int ret=bind(udpsocket,(struct sockaddr*)&myselfaddr,sizeof(myselfaddr));
	if(ret==-1)
	{
		sys_print_error("bind_udp_socket","bind");
	}
}

/*
监听套接字绑定地址 并监听
*/
void  connet_tcp_socket(int clientsocket,struct sockaddr_in serveraddr)
{
	int ret=connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(ret==-1)
	{
		sys_print_error("listent_tcp_socket","bind");
	}	
}

/*
关闭套接字
*/
void  close_socket(int  clientsocket)
{
	close(clientsocket);
}
/*
客户端使用tcp套接链接服务端并发送自己id
*/
struct sockaddr_in   client_login(int clientsocket)
{
	char  clientid[10];
	struct sockaddr_in myselfaddr;
	bzero(&myselfaddr,sizeof(myselfaddr));
	gets(clientid);
	int ret=send(clientsocket,(void*)clientid,strlen(clientid),0);
	if(ret==-1)
	{
		sys_print_error("client_login","send error:");
	}
	ret=recv(clientsocket,(void*)&myselfaddr,sizeof(myselfaddr),0);
	if(ret==-1)
	{
		sys_print_error("client_login","send error:");
	}
	printf("%s\t%d\n",inet_ntoa(myselfaddr.sin_addr),ntohs(myselfaddr.sin_port));
	close_socket(clientsocket);
	return myselfaddr;
}



/*
发送线程
*/
void *  send_pthread(void* arg)
{
	pthreadarg  sendpthreadarg=*(pthreadarg*)arg;
	msgnode  msg;
	while(1)
	{
		bzero(&msg,sizeof(msg));
		gets(msg.clientid);
		gets(msg.mesinfo);
		sendto(sendpthreadarg.udpsocket,(void*)&msg,sizeof(msg),0,(struct sockaddr*)&(sendpthreadarg.serveraddr),sizeof(sendpthreadarg.serveraddr));
	}
}
/*
接收线程
*/
void*  recv_pthread(void* arg)
{
  	int udpsocket=*(int*)arg;
  	msgnode  msg;
  	while(1)
  	{
  		bzero(&msg,sizeof(msg));
  		recvfrom(udpsocket,(void*)&msg,sizeof(msg),0,NULL,NULL);
  		printf("msg:%s\n",msg.mesinfo);
  	}
}

int main(int argc, char const *argv[])
{
	int clientsocket=init_client_socket();
	int udpsocket=init_udp_socket();
	struct sockaddr_in serveraddr=init_socket_addr("127.0.0.1",3344);
	connet_tcp_socket(clientsocket,serveraddr);
    struct sockaddr_in  myselfaddr=client_login(clientsocket);
    bind_udp_socket(udpsocket,myselfaddr);
    pthread_t  pthreadids[2];
    pthreadarg  sendpthreadarg;
    sendpthreadarg.udpsocket=udpsocket;
    sendpthreadarg.serveraddr=serveraddr;
    int ret=pthread_create(&pthreadids[0],NULL,send_pthread,(void*)&sendpthreadarg);
    if(ret==-1)
    {
    	sys_print_error("main","pthread_create send error:");
    }

    ret=pthread_create(&pthreadids[1],NULL,recv_pthread,(void*)&udpsocket);
    if(ret==-1)
    {
    	sys_print_error("main","pthread_create recv error:");
    }

    pthread_join(pthreadids[0],NULL);
    pthread_join(pthreadids[1],NULL);
	return 0;
}
