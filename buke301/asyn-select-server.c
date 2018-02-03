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
定义节点类型
*/
typedef struct clientaddrnode
{
	char clientid[10];
	struct sockaddr_in  clientaddr;
	int  clientaddrlen;
	struct clientaddrnode  *next;
}clientaddrnode;

/*
定义消息类型
*/
typedef struct msgnode
{
	char  clientid[10];
	char  mesinfo[50];
}msgnode;

/*
链表结构
*/
typedef struct list
{
	clientaddrnode *  listhead;
	clientaddrnode *  listtail;
}list;
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
int  init_listent_socket()
{
	int listentsocket=socket(PF_INET,SOCK_STREAM,0);
	if(listentsocket==-1)
	{
		sys_print_error("init_listent_socket","socket error:");
	}
	int  value=1;
	setsockopt(listentsocket,SOL_SOCKET,SO_REUSEADDR,&value,sizeof(listentsocket));
	return  listentsocket;
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
	struct sockaddr_in  listentaddr;
	bzero(&listentaddr,sizeof(listentaddr));
	listentaddr.sin_family=AF_INET;
	listentaddr.sin_port=htons(port);
	listentaddr.sin_addr.s_addr=inet_addr(ipaddr);
	return  listentaddr;
}

/*
监听套接字绑定地址 并监听
*/
void  listent_tcp_socket(int listentsocket,struct sockaddr_in listentaddr)
{
	int ret=bind(listentsocket,(struct sockaddr*)&listentaddr,sizeof(listentaddr));
	if(ret==-1)
	{
		sys_print_error("listent_tcp_socket","bind");
	}
	ret=listen(listentsocket,10);
	if(ret==-1)
	{
		sys_print_error("listent_tcp_socket","bind");
	}
}
/*
绑定udp套接字
*/
void bind_udp_socket(int udpsocket,struct sockaddr_in listentaddr)
{
	int ret=bind(udpsocket,(struct sockaddr*)&listentaddr,sizeof(listentaddr));
	if(ret==-1)
	{
		sys_print_error("listent_tcp_socket","bind");
	}
}

/*
客户地址信息链表插入操作
*/
void list_add_client_addr(list*  ptrlist,const char * clientid,struct sockaddr_in  clientaddr)
{
   clientaddrnode *  ptrnewnode=(clientaddrnode*)malloc(1*sizeof(clientaddrnode));
   strcpy(ptrnewnode->clientid,clientid);
   ptrnewnode->clientaddr=clientaddr;
   ptrnewnode->clientaddrlen=sizeof(clientaddr);
   ptrnewnode->next=NULL;
   printf("%s\n",clientid);
   if(ptrlist->listhead==NULL)
   {
   	ptrlist->listhead=ptrnewnode;   	
   }
   else
   {
   	ptrlist->listtail->next=ptrnewnode;
   }
   ptrlist->listtail=ptrnewnode;
   ptrnewnode=NULL;
}
/*
根据clientid 从链表中查找节点
*/
clientaddrnode*  list_query_client_addr(list * ptrlist,const char* clientid)
{
	clientaddrnode* returnnode=NULL;
	if(ptrlist->listhead!=NULL)
	{
		clientaddrnode* movennode=ptrlist->listhead;
		while(movennode!=NULL)
		{
			if(strcmp(movennode->clientid,clientid)==0)
			{
				returnnode=movennode;
				break;
			}
			movennode=movennode->next;
		}
	}
	return returnnode;
}
/*
select 实现异步操作:
内核监控多个文件描述符,根据文件描述的状态(写  读 异常),使用位(fd_set)标记发生状态文件描述符值,并复制到应用程序.
select 是一个堵塞性函数,根据时间参数设置是否堵塞:
0:非堵塞
NULL:一致堵塞
>0:堵塞指定时间
select  一般内核默认是监控1024个文件描述符(128byte*8=1024bit)
返回值:
0:无文件描述符返回
-1:错误
>0:返回文件描述符的个数
*/

void  asyn_select_work(int listentsocket,int udpsocket)
{
	fd_set readset;
	int maxfd=-1;
	struct timeval tm;
	struct sockaddr_in clientaddr;
	char clientid[10];
	int msglen=-1;
	int  clientaddrlen=sizeof(clientaddr);
	msgnode msg;
	list  listobj;
	listobj.listhead=NULL;
	listobj.listtail=NULL;
	while(1)
	{
		FD_ZERO(&readset);
		FD_SET(listentsocket,&readset);
		FD_SET(udpsocket,&readset);
		if(listentsocket>udpsocket)
		{
			maxfd=listentsocket;
		}
		else
		{
			maxfd=udpsocket;
		}
		tm.tv_sec=1;
		tm.tv_usec=0;
		int  ret=select(maxfd+1,&readset,NULL,NULL,&tm);
		if(ret<0)
		{
			sys_print_error("asyn_select_work","select");
		}
		if(ret==0)
		{
			continue;
		}
		if(ret>0)
		{
			if(FD_ISSET(listentsocket,&readset))
			{
				bzero(&clientaddr,sizeof(clientaddr));
				msglen=-1;
				bzero(clientid,sizeof(clientid));
				int acceptsocket=accept(listentsocket,(struct sockaddr*)&clientaddr,&clientaddrlen);
				if(acceptsocket==-1)
				{
					sys_print_error("asyn_select_work","accpet error:");
				}
				printf("%s\t%d\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
				msglen=recv(acceptsocket,clientid,sizeof(clientid),0);
				if(msglen>0)
				{
					send(acceptsocket,(void*)&clientaddr,sizeof(clientaddr),0);
					close(acceptsocket);
				}
				list_add_client_addr(&listobj,clientid,clientaddr);
			}
			if(FD_ISSET(udpsocket,&readset))
			{
				bzero(&msg,sizeof(msg));
				recvfrom(udpsocket,(void*)&msg,sizeof(msg),0,NULL,NULL);
                printf("clientid=%s\t%s\n",msg.clientid,msg.mesinfo);
				clientaddrnode* returnnode=list_query_client_addr(&listobj,msg.clientid);
				if(returnnode!=NULL)
				{
					sendto(udpsocket,(void*)&msg,sizeof(msg),0,(struct sockaddr*)&(returnnode->clientaddr),returnnode->clientaddrlen);
				}
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int listentsocket=init_listent_socket();
	int udpsocket=init_udp_socket();
	struct sockaddr_in listentaddr=init_socket_addr("127.0.0.1",3344);
	listent_tcp_socket(listentsocket,listentaddr);
	bind_udp_socket(udpsocket,listentaddr);
	asyn_select_work(listentsocket,udpsocket);
	return 0;
}
