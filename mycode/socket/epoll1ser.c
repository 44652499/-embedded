#include "appheader.h"
/*
epoll:监控文件描述符事件(event)变化.通过事件获取变化的文件描述符值.
对大批量文件描述符监控效果较好(事件(IN|OUT)通知,与被监控的描述符数量无关)

事件类型:
typedef union epoll_data {
                void *ptr;
                int fd;  //文件描述符值
                __uint32_t u32;
                __uint64_t u64;
            } epoll_data_t;

 struct epoll_event {
                __uint32_t events;     //事件集合
                epoll_data_t data;     //用户数据
            };

创建epoll文件描述符值,告诉内核分配指定空间存放被监视文件描述值
epoll_create
int epoll_create(int size);
int size:指定被监视文件描述值的 个数
返回值:文件描述值
最后调用close epoll文件描述值

epoll_ctl
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
int epfd:epoll文件描述符(epoll_create 返回值)
int fd:存入epoll集合中的目标文件描述值
struct epoll_event *event:目标文件描述符关联事件
具体事件:
 EPOLLIN:输入事件
 EPOLLOUT:输出事件
 事件触发模式:
 EPOLLET:边缘触发,是一种高效触发模式,数据到达内核后,只会通知一次应用程序.非堵塞工作方式(要求套接字必须为非堵塞模式)
 int op:操作方式:
 EPOLL_CTL_ADD
 EPOLL_CTL_MOD
 EPOLL_CTL_DEL

 epoll_wait
 int epoll_wait(int epfd, struct epoll_event *events,
                      int maxevents, int timeout);
struct epoll_event *events:指向存放已经发生事件变化的对象
int maxevents:发生事件变化最大数,不能超过epoll_create size参数值
int timeout:超时
=0:立即返回,无事件变化
>0:堵塞指定时间
返回值:
>0:即将IO操作文件描述符个数
=0:超时
=-1:错误
*/
void  setnonblock(int sck)
{
   int flags=fcntl(sck,F_GETFL);
   flags=flags|O_NONBLOCK;
   fcntl(sck,F_SETFL,flags);
}


int main(int argc, char const *argv[])
{
	int sckd=socket(PF_INET,SOCK_STREAM,0);
	if(sckd==-1)
	{
		perror("socket:");
		exit(-1);
	}
	setnonblock(sckd);//设置监听套接字非堵塞
	struct sockaddr_in  seraddr;
	bzero(&seraddr,sizeof(seraddr));
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(PORT);
	seraddr.sin_addr.s_addr=inet_addr("192.168.252.3");
	//设置套接字选项(地址重用)
	int value=1;
	setsockopt(sckd,SOL_SOCKET,SO_REUSEADDR,&value,sizeof(sckd));
	//绑定
	if(bind(sckd,(struct sockaddr*)&seraddr,sizeof(seraddr))==-1)
	{
		perror("bind :");
		exit(-1);
	}
	//监听
	if(listen(sckd,10)==-1)
	{
		perror("listen:");
		exit(-1);
	}

    int efd=epoll_create(256);
    if(efd==-1)
    {
    	perror("epoll_create:");
    	exit(-1);
    }

    struct epoll_event ev;
    ev.events=EPOLLIN|EPOLLET;
    ev.data.fd=sckd;
    epoll_ctl(efd,EPOLL_CTL_ADD,sckd,&ev);

    struct epoll_event *events;
    int clientsck;
    while(1)
    {
    	 int neventfd=epoll_wait(efd,events,20,1000);
         if(neventfd<=0)
    	     continue;
    	 if(neventfd>0)
    	 {
    	 	  int i;
    	 	  for(i=0;i<neventfd;i++)
    	 	  {
    	 	  	  if(events[i].events&EPOLLIN)
    	 	  	  {
    	 	  	  	if(events[i].data.fd==sckd)
    	 	  	  	{    	 	  	  		
    	 	  	  		clientsck=accept(sckd,NULL,NULL);
    	 	  	  		if(clientsck>0)
    	 	  	  		{
    	 	  	  			setnonblock(clientsck);
                            ev.events=EPOLLIN|EPOLLET;
                            ev.data.fd=clientsck;
                            epoll_ctl(efd,EPOLL_CTL_ADD,clientsck,&ev);
    	 	  	  		} 
    	 	  	  	}
    	 	  	  	else if(events[i].data.fd==clientsck)
    	 	  	  	{
                          char buf[1024];
                          bzero(buf,sizeof(buf));
                          recv(clientsck,buf,sizeof(buf)-1,0);
                          printf("rec1:%s\n",buf);
                          if(buf[0]=='a')
                          {
                            char buf2[1000];
                            bzero(buf2,sizeof(buf2));
                            recv(clientsck,buf2,sizeof(buf2)-1,0);
                            printf("recv2:%s\n",buf2);
                          }
                          // ev     ents[i].events=EPOLLOUT|EPOLLET;
                          // events[i].data.fd=clientsck;
                          // epoll_ctl(efd,EPOLL_CTL_MOD,clientsck,& events[i]);
    	 	  	  	}
    	 	  	  }
    	 	  	  // else if(events[i].events&EPOLLOUT)
    	 	  	  // {
    	 	  	  // 	char buf[1024];
    	 	  	  // 	gets(buf);
    	 	  	  // 	send(events[i].data.fd,buf,strlen(buf),0);
    	 	  	  // 	events[i].events=EPOLLIN|EPOLLET;
            //         events[i].data.fd=clientsck;
            //         epoll_ctl(efd,EPOLL_CTL_MOD,clientsck,& events[i]);
    	 	  	  // }
    	 	  }
    	 }
    }   
	return 0;
}

/*
1.再创建一个epoll文件描述符,大小为1,存储监听套接字
*/