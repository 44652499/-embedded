#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <error.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#define PORT 8787

void setnonblock(int fd)
{
	int flags=fcntl(fd,F_GETFL);
    flags=flags|O_NONBLOCK;
	fcntl(fd,F_SETFL,flags);
}

int main(int argc, char const *argv[])
{
	int fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd==-1)
	{
		perror("fail to socket");
		return 0;
	}
	setnonblock(fd);
	struct sockaddr_in addrs;
	addrs.sin_family=AF_INET;
	addrs.sin_port=htons(PORT);
	addrs.sin_addr.s_addr=inet_addr("127.0.0.1");

	int bind_1=bind(fd,(struct sockaddr*)&addrs,sizeof(struct sockaddr));
	if(bind_1==-1)
	{
		perror("fail to bind");
		return 0;
	}

	int listen_1=listen(fd,10);
	if(listen_1==-1)
	{
		perror("fail to listen");
		return 0;
	}

	struct epoll_event ev,event[1024];
	
	int efd=epoll_create(1024);
	if(efd==-1)
	{
		perror("fail to epoll");
		return 0;
	}
	ev.data.fd=fd;
	ev.events=EPOLLIN|EPOLLET;
	epoll_ctl(efd,EPOLL_CTL_ADD,fd,&ev);
	while(1)
	{
		int ret=epoll_wait(efd,event,100,1000);
		//printf("%d\n",ret);
		if(ret<=0)
		{
			//printf("等待超时\n");
			continue;
		}
		/*else if(ret==-1)
		{
			perror("fail to epoll_wait");
			return 0;
		}*/
		else if(ret>0)
		{	
			printf("ccc\n");
			int i;
			for(i=0;i<ret;i++)
			{	
				printf("bbb\n");
				if(event[i].data.fd==fd)//错误在这里???????
				{
					struct sockaddr_in addrc;
					int clientlen=sizeof(struct sockaddr);
					int newfd=accept(fd,(struct sockaddr*)&addrc,&clientlen);
					printf("aaa\n");
					if(newfd==-1)
					{
						perror("fail to sockaddr");
						return 0;
					}
					if(newfd>0)
					{
						printf("ddd\n");
						setnonblock(newfd);
						ev.data.fd=newfd;
						ev.events=EPOLLIN|EPOLLET;
						epoll_ctl(efd,EPOLL_CTL_ADD,newfd,&ev);
					}
				}
				else if(event[i].events&EPOLLIN)
				{	
					printf("fff\n");
					int tmp=event[i].data.fd;
					char buf[1024];
					bzero(buf,sizeof(buf));
					recv(tmp,buf,sizeof(buf)-1,0);
					printf("%s\n",buf);
					ev.data.fd=tmp;
					ev.events=EPOLLOUT|EPOLLET;
					epoll_ctl(efd,EPOLL_CTL_MOD,tmp,&ev);
					printf("hhh\n");
				}
				else if(event[i].events&EPOLLOUT)
				{	
					printf("eee\n");
					int tmp=event[i].data.fd;
					char buf1[1024];
					bzero(buf1,sizeof(buf1));
					gets(buf1);
					send(tmp,buf1,strlen(buf1),0);
					ev.data.fd=tmp;
					ev.events=EPOLLIN|EPOLLET;
					epoll_ctl(efd,EPOLL_CTL_MOD,tmp,&ev);
				}
			}
		}
	}
	return 0;
}
