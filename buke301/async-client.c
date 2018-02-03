/********************************************************
*文件名: ssync-client.c
*功能: 网络异步通讯客户端程序
*运行方式：./ssync-client 127.0.0.1 7838
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
	int sockfd;
	int len;
	struct sockaddr_in dest;
	char buf[MAXBUF + 1];
	fd_set rdfs;
	struct timeval tv;
	int retval, maxfd = -1;

	
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Socket:");
		exit(1);
	}

	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_port = htons(2233);
	dest.sin_addr.s_addr = INADDR_ANY; 
	// if(inet_aton(argv[1], (struct in_addr *)&dest.sin_addr.s_addr) == 0)
	// {
	// 	perror(argv[1]);
	// 	exit(1);
	// }

	if(connect(sockfd, (struct sockaddr *)&dest, sizeof(dest)) != 0)
	{
		perror("Connection:");
		exit(1);	
	}

	printf("\n准备就绪，可以开始聊天了......直接输入消息回车即可发送\n");
	while(1)
	{
		FD_ZERO(&rdfs);
		FD_SET(0, &rdfs);
		maxfd = 0;
		FD_SET(sockfd, &rdfs);
		if(maxfd < sockfd)
			maxfd = sockfd;
		tv.tv_sec = 1;
		tv.tv_usec = 0;

		retval = select(maxfd + 1, &rdfs, NULL, NULL, &tv);
		if(retval == -1)
		{
			printf("select出错，将退出...\n");
			break;
		}
		else
		{
			if(retval == 0)
			{
				//printf("没有任何的消息，继续等待......\n");
				continue;
			}
			else
			{
				if(FD_ISSET(sockfd, &rdfs))
				{
					//接收对方发给来的消息
					bzero(buf, MAXBUF + 1);
					len = recv(sockfd, buf, MAXBUF, 0);
					if(len > 0)
					{
						printf("recv sucess %s, total: %d\n", buf, len);
					}
					else
					{
						if(len < 0)
						{
							printf("Recv error\n");
							break;
						}
						else
						{
							printf("Quit\n");
							break;
						}
					}
				}
				if(FD_ISSET(0, &rdfs))
				{
					bzero(buf, MAXBUF + 1);
					//fgets(buf, MAXBUF, stdin);
					read(0,buf,MAXBUF);
					if(!strncasecmp(buf, "quit", 4))
					{
						printf("Quit\n");
						break;
					}
					len = send(sockfd, buf, strlen(buf) - 1, 0);
					if(len < 0)
					{
						perror("Send:");
						break;
					}
					else
					{
						printf("Send sucess!\n");
					}
				}
			}
		}		
	}
	close(sockfd);
	return 0;
}
