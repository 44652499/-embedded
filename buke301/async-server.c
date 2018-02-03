/********************************************************************
*文件名: async-server.c
*功能:   网络异步通讯服务器端程序
*运行方式：./async-server 7838 1
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <wait.h>
#include <sys/time.h>
#include <unistd.h>

#define MAXBUF 1024

int main(int argc, char *argv[])
{
	int sockfd, new_fd; //对于服务器程序都需要两个socke描述符，一个是服务器监听的，一个是和特定的客户端通信的
	socklen_t len;
	struct sockaddr_in my_addr, their_addr;//服务器的地址结构和客户端的地址结构
	unsigned int myport, lisnum; //端口号和监听数
	char buf[MAXBUF + 1];  //读写信息
	fd_set rdfs;   //文件描述符的集合
	struct timeval tv;  //延时超时，包括一个表示秒数和一个表示毫秒数的成员
	int retval, maxfd = -1;  //maxfd为最大的文件描述符	

    //创建套接字
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Socket:");
		exit(1);
	}
	
	//填充服务器的地址结构
	bzero(&my_addr, sizeof(struct sockaddr_in));
	my_addr.sin_family = AF_INET;  //定义协议族为IPV4
	my_addr.sin_port = htons(2233);  //端口号
	my_addr.sin_addr.s_addr = INADDR_ANY; 

    //绑定
	if(bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("Bind:");
		exit(1);
	}
	
	//监听
	if(listen(sockfd, lisnum) == -1)
	{
		perror("Listen:");
		exit(1);
	}

	while(1)
	{
		printf("\n等待一个新的连接到来，开始新的聊天......\n");
		len = sizeof(struct sockaddr);

        //接收特定的用户的通信
		if((new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &len)) == -1)
		{
			perror("Accept:");
			exit(1);
		}
		else
		{
			printf("服务器：连接自%s, 端口: %d, 套接字: %d\n", inet_ntoa(their_addr.sin_addr), ntohs(their_addr.sin_port), new_fd);
		}
		
		//多路IO的处理方式	
		//开始处理每个连接上的数据收发
		printf("\n准备就绪，可以开始聊天了......直接输入消息，回车即可发送\n");
		while(1)
		{
			//清空集合
			FD_ZERO(&rdfs);
			//将标准输入的句柄加入到只读文件描述符集合中
			FD_SET(0, &rdfs);
			maxfd = 0;
			
			//将当前的连接句柄new_fd添加到集合中
			FD_SET(new_fd, &rdfs);
			if(new_fd > maxfd)
			{
				maxfd = new_fd;
			}

			//设置最大等待时间
			tv.tv_sec = 1;  //超时秒数
			tv.tv_usec = 0; //超时毫秒数
            
			//通过系统调用select对所有在集合中的文件描述符进行监视，当在tv设定的时间之内没有所监视的文件描述符发生状态改变的时候，tv时间到，select退出；如果在tv设定的时间内所监视的文件描述符集合中的某个文件描述符发生状态改变，select立即响应；
			//通过select的返回值来确定是什么情况发生：
			//select的返回值为0表示延时时间到
			//select的返回值为-1表示select出错
			//否则表示select退出是由于某个文件描述符发生了状态改变
			retval = select(maxfd+1, &rdfs, NULL, NULL, &tv);
			
			if(retval == -1)
			{
				printf("Select发生异常，将退出!");
				exit(1);
			}
			else
			{
				if(retval == 0)
				{
					//printf("没有任何的消息到来，用户也没有按键，继续等待......\n");
					continue;
				}
				else  //处理具体的文件描述的操作
				{
					if(FD_ISSET(0, &rdfs))  //用户有输入，将输入的数据发送到指定的客户端
					{
						bzero(buf, MAXBUF + 1);
						//fgets(buf, MAXBUF, stdin);
						read(0,buf,MAXBUF);
						if(!strncasecmp(buf,"quit", 4))
						{
							printf("用户要求终止聊天\n");
							break;
						}
						len = send(new_fd, buf, strlen(buf)-1, 0);//去掉回车键，将输入的消息发送到客户端
						if(len > 0)
						{
							printf("消息:%s  发送成功，共发送了%d个字节\n", buf, len);
						}
						else
						{
							printf("消息:%s  发送失败， 错误代码:%d\n 错误消息:%s\n", buf, errno, strerror(errno));
							break;
						}
					}
					//当前连接上有消息到来，接收对方发过来的消息
					if(FD_ISSET(new_fd, &rdfs))
					{
						bzero(buf, MAXBUF + 1);

						//接收客户端的消息
						len = recv(new_fd, buf, MAXBUF, 0);
						if(len > 0)
						{
							printf("接收消息成功:%s, 共有%d个字节.\n", buf, len);
						}
						else
						{
							if(len < 0)
							{
								printf("消息接收失败，错误代码%d,错误消息：%s\n", errno, strerror(errno));
							}
							else
							{
								printf("对方退出了，终止聊天\n");
							}
							break;
						}
					}
				}
			}
			
		}
		close(new_fd);
		//处理每一个连接上的数据收发结束
		printf("还要和其他的用户聊天吗？（no->退出）\n");
		fflush(stdout);
		bzero(buf, MAXBUF + 1);
		fgets(buf, MAXBUF, stdin);
		if(!strncasecmp(buf, "no", 2))
		{
			printf("终止聊天!\n");
			break;
		}
		
		
	}
	close(sockfd);

	return 0;
}
