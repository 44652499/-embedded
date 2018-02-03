#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <linux/input.h>   //内核输入设备定义信息文件
#include <pwd.h>
#include <grp.h>q
#include <time.h>
#include <sys/file.h>
#include <dirent.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <assert.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <signal.h> 
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#define  N  2
#define  ADD  EPOLL_CTL_ADD
#define  MOD  EPOLL_CTL_MOD
#define  DEL  EPOLL_CTL_DEL
#define  EPOLLSIZE 10
#define  QUEUESIZE 200
typedef  void* (*pfcallback)(void* arg);
/*
队列节点定义
*/
typedef struct  tasknode
{
	int  work_socket;
	pfcallback  pfrecv;
	pfcallback  pfsend;
	struct  tasknode *  next;
}tasknode;
/*
队列定义
*/
typedef struct taskqueue
{
	int       queuesize;
	tasknode *  task_head;
	tasknode *  task_tail;
}taskqueue;
/*
定义线程参数类型
*/
typedef struct pthreadarg
{
	int *  ptrlistensocketds;
	int    epollfd;
	taskqueue *  ptrtaskqueue;	
}pthreadarg;
/*
初始化队列
*/
void  init_task_queue(taskqueue * ptrqueue)
{
	ptrqueue->task_head=NULL;
	ptrqueue->task_tail=NULL;
	ptrqueue->queuesize=0;
}
/*
判断队列是否为空
*/
int  is_queue_null(taskqueue * ptrqueue)
{
	if(ptrqueue->task_head==NULL &&  ptrqueue->task_tail==NULL)
		return 1;
	return 0;
}
/*
判断队列是否满
*/
int  is_queue_full(taskqueue *  ptrqueue)
{
	if(ptrqueue->queuesize==QUEUESIZE)
		return 1;
	return 0;
}
/*进队操作*/
void  push_task_queue(taskqueue*  ptrqueue,tasknode* ptrnode)
{
	if(!is_queue_full(ptrqueue))
	{
		if(ptrqueue->task_head==NULL)
		{
			ptrqueue->task_head=ptrnode;			
		}
		else
		{
			ptrqueue->task_tail->next=ptrnode;
		}
		ptrqueue->task_tail=ptrnode;
		ptrqueue->queuesize++;
		ptrnode=NULL;
	}
}
/*出队操作*/
tasknode*  pop_task_queue(taskqueue* ptrqueue)
{
	tasknode *  returntasknode=NULL;
	if(!is_queue_null(ptrqueue))
	{
		returntasknode=ptrqueue->task_head;
		ptrqueue->task_head=ptrqueue->task_head->next;
		returntasknode->next=NULL;
		ptrqueue->queuesize--;
	}
	return returntasknode;
}
/*
获取队列的首元素节点
*/
tasknode *  get_task_queue_head(taskqueue *  ptrqueue)
{
	if(!is_queue_null(ptrqueue))
	{
		return ptrqueue->task_head;
	}
	return NULL;
}
/*
获取队列的尾元素节点
*/
tasknode*  get_task_queue_tail(taskqueue *  ptrqueue)
{
	if(!is_queue_null(ptrqueue))
	{
		return  ptrqueue->task_tail;
	}
	return NULL;
}

/*
系统错误信息输出函数
*/
void  sysetem_error_output(const char*  functionname,const char*  errorinfo)
{
	char errormessage[100];
	bzero(errormessage,sizeof(errormessage));
	strcpy(errormessage,functionname);
	strcat(errormessage,"-->");
	strcat(errormessage,errorinfo);
	perror(errormessage);
	exit(-1);
}
/*
设置文件描述符为非堵塞模式
*/
void   set_nonblock_fd(int  fd)
{
	int flags=fcntl(fd,F_GETFL);
	flags=flags|O_NONBLOCK;
	fcntl(fd,F_SETFL,flags);
} 

/*
设置套接字地址可以重用,取消2MSL时间
*/
void  set_socket_reuseaddr(int reusesocket,int value)
{
	setsockopt(reusesocket,SOL_SOCKET,SO_REUSEADDR,(void*)&value,sizeof(reusesocket));
}

/*
初始化监听套接字
返回值:返回监听套接字
*/
int  init_listen_socket()
{
	int listensocket=socket(PF_INET,SOCK_STREAM,0);
	if(listensocket==-1)
	{
		sysetem_error_output("init_listen_socket","socket error:");
	}
	set_nonblock_fd(listensocket);
	set_socket_reuseaddr(listensocket,1);
	signal(SIGPIPE,SIG_IGN);

}

/*
初始化监听套接字地址,并启动 绑定 监听
参数:监听端口数组(多个监听套接字)
*/
void listen_socket_work(int listensocket,const char* ipaddr,int port)
{
	struct sockaddr_in listen_addr;
	bzero(listen_addr,sizeof(listen_addr));
	listen_addr.sa_family=AF_INET;
	listen_addr.sa_port=htons(port);
	listen_add.sa_addr.s_addr=inet_addr(ipaddr);
	int ret=bind(listensocket,(struct sockaddr*)&listen_addr,sizeof(listen_addr);
	if(ret==-1)
	{
		sysetem_error_output("listen_socket_work","bind error:");
	}
	ret=listen(listensocket,5);
	if(ret==-1)
	{
		sysetem_error_output("listen_socket_work","listen error:");
	}	
}

/*
初始化epoll 文件描述符
参数:限制epoll文件描述的个数
*/
int init_epoll_socket(int  socketsize)
{
	int  epollfd;
	epollfd=epoll_create(socketsize);
	if(epollfd==-1)
	{
		sysetem_error_output("init_epoll_socket","epoll_create error:");
	}
	return epollfd;
}

/*
把监听套接字绑定事件并放入到epoll文件系统中
*/
void  input_socket_epoll(int epollfd,int inputsocket)
{
	struct epoll_event socketevent;
	socketevent.events=EPOLLIN|EPOLLET;
	socketevent.data.fd=inputsocket;
	epoll_ctl(epollfd,ADD,inputsocket,&socketevent);
}

/*
epoll  监听套接字接收客户请求线程
*/
void *  listent_socket_accpet(void * arg)
{
	pthreadarg *  ptrpthreadarg=(pthreadarg *)arg;
	struct epoll_event  acceptepollevent[N];
	int ret,i;
	while(1)
	{
		bzero(acceptepollevent,sizeof(acceptepollevent));
		ret=epoll_wait(ptrpthreadarg->epollfd,acceptepollevent,N,1000);
		if(ret<=0)
		{
			continue;
		}
		if(ret>0)
		{
			for(i=0;i<N;i++)
			{
				if(acceptepollevent[i].data.fd>0)
				{
					int accpetclientsocket=accept(acceptepollevent[i].data.fd,NULL,NULL);
					if(accpetclientsocket>0)
					{
						tasknode  *ptrtasknode=(tasknode*)malloc(sizeof(tasknode)*1);
						ptrtasknode->work_socket=accpetclientsocket;
						ptrtasknode->pfrecv=NULL;
						ptrtasknode->pfsend=NULL;
						ptrtasknode->next=NULL;
						push_task_queue(ptrpthreadarg->ptrtaskqueue,ptrtasknode);
					}
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int listensocketds[N];
	unsigned short listenportds[N]={1122,3344};
	int i;
	int epollfd=init_epoll_socket(EPOLLSIZE);
	for(i=0;i<2;i++)
	{
		listensocketds[i]=init_listen_socket();
		listen_socket_work(listensocketds[i],"127.0.0.1",listenportds[i]);
		input_socket_epoll(epollfd,listensocketds[i]);
	}
	taskqueue  ptrtaskqueue;
	init_task_queue(&ptrtaskqueue);
	pthread_t  accpetpthreadid;
	pthreadarg *ptrpthreadarg=(pthreadarg*)malloc(1*sizeof(pthreadarg));
	if(ptrpthreadarg==NULL)
	{
		sysetem_error_output("main","pthreadarg malloc error:");
	}
	ptrpthreadarg->ptrlistensocketds=listensocketds;
	ptrpthreadarg->epollfd=epollfd;
	ptrpthreadarg->ptrtaskqueue=&ptrtaskqueue;
	int ret=pthread_create(&accpetpthreadid,NULL,listent_socket_accpet,(void*)ptrpthreadarg);
	if(ret=-1)
	{
		sysetem_error_output("main","pthread_create error:");
	}
	//


	pthread_join(accpetpthreadid,NULL);
	return 0;
}