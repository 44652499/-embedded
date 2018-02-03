#include "define_all_header.h"
#define  BUFFER_SIZE 1024
#define  CLIENT_NUMS 100
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

typedef struct client_heart_info
{
	char ip_addr[20];
	int count;
}client_heart_info;

typedef struct list_node
{
	int client_key;
	client_heart_info client_heart;
	struct list_node  * next;
}list_node;

typedef  struct list
{
	list_node *  list_head;
	list_node *  list_curr;
}list;

typedef struct pthread_arg_value
{
	int  * max_fd;
	fd_set * master_set;
	list*  define_list;
}pthread_arg_value;

int  client_set[CLIENT_NUMS];
int  client_index=0;

void* heart_handler(void* arg);

void  sys_error_info(const char* errormsg)
{
	perror(errormsg);
}

void  init_client_set()
{
	int i;
	for(i=0;i<CLIENT_NUMS;i++)
	{
		client_set[i]=-1;
	}
}

list* init_list()
{
	list *  define_list=(list*)malloc(1*sizeof(list));
	if(define_list==NULL)
	{
		sys_error_info("init_list fail:");
		exit(-1);
	}
	define_list->list_head=NULL;
	define_list->list_curr=NULL;
	return define_list;
}

void  list_insert(list_node* new_node,list *define_list)
{
	if(new_node!=NULL && define_list!=NULL)
	{
		printf("%d\t%s\t%d\n",new_node->client_key,new_node->client_heart.ip_addr,new_node->client_heart.count );
		if(define_list->list_head==NULL)
		{
			define_list->list_head=new_node;
			define_list->list_curr=new_node;
		}
		else
		{
			define_list->list_curr->next=new_node;
			define_list->list_curr=new_node;
		}
	}
}

list_node*  list_find(int fd,list *define_list)
{
	if(define_list!=NULL)
	{
		list_node*  tmp_node=define_list->list_head;
		while(tmp_node!=NULL)
		{
			if(tmp_node->client_key==fd)
			{
				return tmp_node;
			}
			tmp_node=tmp_node->next;
		}
		return tmp_node;
	}	
}

void  list_delete(int fd,list *define_list)
{
	if(define_list!=NULL)
	{
		list_node*  delete_node=define_list->list_head;
		list_node*  tmp_node=NULL;
		while(delete_node!=NULL)
		{
			if(delete_node->client_key==fd)
			{
				tmp_node->next=delete_node->next;
				delete_node->next=NULL;
				free(delete_node);
				delete_node=NULL;
			}
			else
			{
				tmp_node=delete_node;
			}
			tmp_node=tmp_node->next;
		}
	}	
}



int  init_socket(int port)
{
	init_client_set();
	int listen_fd=socket(PF_INET,SOCK_STREAM,0);
	if(listen_fd==-1)
	{
		sys_error_info("socket  fail:");
		return -1;
	}
	struct sockaddr_in  listen_addr;
	bzero(&listen_addr,sizeof(listen_addr));
	listen_addr.sin_family=AF_INET;
	listen_addr.sin_port=htons(port);
	listen_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	int opt=1;
	setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(listen_fd));
	if(bind(listen_fd,(struct sockaddr*)&listen_addr,sizeof(listen_addr))==-1)
	{
		sys_error_info("bind  fail:");
		return -1;
	}
	if(listen(listen_fd,10)==-1)
	{
		sys_error_info("listen  fail:");
		return -1;
	}
	return listen_fd;
}

void  do_accepting(int listen_fd,fd_set  *master_set,int * max_fd,list *define_list)
{
	struct sockaddr_in client_addr;
	socklen_t client_addr_len=sizeof(client_addr);
	int client_fd=accept(listen_fd,(struct sockaddr*)&client_addr,&client_addr_len);
	if(client_fd<0)
	{
		sys_error_info("accept fail:");
		exit(-1);
	}
	printf("new connection was accepted.\n");
	//将客户端套接字与ip地址存储在链表中
	list_node * new_node=(list_node*)malloc(1*sizeof(list_node));
	if(new_node==NULL)
	{
		sys_error_info("malloc new node fail:");
		exit(-1);
	}

	new_node->client_key=client_fd;
	bzero(new_node->client_heart.ip_addr,sizeof(new_node->client_heart.ip_addr));
	strcpy(new_node->client_heart.ip_addr,inet_ntoa(client_addr.sin_addr));
	new_node->client_heart.count=0;
	list_insert(new_node,define_list);

	client_set[client_index++]=client_fd;

	FD_SET(client_fd,master_set);	
	if(client_fd>*max_fd)
	{
		*max_fd=client_fd;
	}

	pthread_t id;
	pthread_arg_value  arg_value;
	arg_value.max_fd=max_fd;
	arg_value.master_set=master_set;
	arg_value.define_list=define_list;

	int ret=pthread_create(&id,NULL,heart_handler,(void*)&arg_value);
	if(ret!=0)
	{
		sys_error_info("pthread_create  fail:");
		return;
	}	
}

void do_recving(int nums,int max_fd,fd_set* master_set,list *define_list)
{
	int work_fd;
	for(work_fd=0;work_fd<=max_fd;work_fd++)
	{
		if(FD_ISSET(work_fd,master_set))
		{
			printf("work_fd=%d\n",work_fd);
			PACKET_HEAD head;
			int ret=recv(work_fd,&head,sizeof(head),0);
			printf("ret=%d\n",ret);
			if(ret>0)
			{
				if(head.type==HEART)
				{
					printf("Received heart-beat from client.\n");
					//收到心跳包,count 赋值 0
					list_node  *curr_node=list_find(work_fd,define_list);
					if(curr_node!=NULL)
					{
						curr_node->client_heart.count=0;
					}
				}
			}
			if(ret==0)			
			{
				close(work_fd);
				FD_CLR(work_fd,master_set);
				int i;
				for(i=0;i<client_index;i++)
				{
					if(client_set[i]==work_fd)
					{
						client_set[i]=-1;
					}
					if(client_set[i]>max_fd)
					{
						max_fd=client_set[i];
					}
				}
			}
		}
	}
}



void   do_running(int listen_fd,list *define_list)
{
	int max_fd=listen_fd;
	fd_set master_set;
	struct timeval timeout;
	int i;
	while(1)
	{
		FD_ZERO(&master_set);
		FD_SET(listen_fd,&master_set);

		for(i=0;i<client_index;i++)
		{
			if(client_set[i]!=-1)
			{
				FD_SET(client_set[i],&master_set);
			}			
		}

		timeout.tv_sec=3;
		timeout.tv_usec=0;
		int nums=select(max_fd+1,&master_set,NULL,NULL,&timeout);
		if(nums<=0)
		{
			//perror("select fail:");
			//exit(-1);
			continue;
		}
		if(nums>0)
		{
			if(FD_ISSET(listen_fd,&master_set))
			{
				do_accepting(listen_fd,&master_set,&max_fd,define_list);
			}
			else
			{
				do_recving(nums,max_fd,&master_set,define_list);
			}
		}
	}
}

void*  heart_handler(void* arg)
{
	printf("The heartbeat checking thread started.\n");
	pthread_arg_value*  arg_value=(pthread_arg_value*)arg;
	list *define_list=arg_value->define_list;
	int *max_fd=arg_value->max_fd;
	while(1)
	{
		list_node * curr_node=NULL;
		for(curr_node=define_list->list_head;curr_node!=NULL;curr_node=curr_node->next)
		{
			if(curr_node->client_heart.count==5)//3s*5没有收到心跳包，判定客户端掉线
			{
				 int free_fd=curr_node->client_key;
				 close(free_fd); // 关闭该连接
				 FD_CLR(free_fd,arg_value->master_set);
				 int i;
				 for(i=0;i<client_index;i++)
				 {
					if(client_set[i]==free_fd)
					{
						client_set[i]=-1;
					}
					if(client_set[i]>*max_fd)
					{
						*max_fd=client_set[i];
					}
				 }
				list_delete(free_fd,arg_value->define_list);
				 // 从链表中移除该记录
				break;
            }
			else if(curr_node->client_heart.count<5 && curr_node->client_heart.count>=0)
			{
				curr_node->client_heart.count++;
			}
		}
		sleep(3);
	}
}


int main(int argc, char const *argv[])
{
	int listen=init_socket(1234);
	list  * define_list=init_list();
	do_running(listen,define_list);	
	return 0;
}
