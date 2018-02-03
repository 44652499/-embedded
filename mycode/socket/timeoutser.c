#include "appheader.h"
/*
*/
void  timeout_fun(int signum)
{
	printf("recv time out\n");
	exit(-1);
}

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
	struct sockaddr_in  seraddr;//struct sockaddr_in 填充与 struct sockaddr 一样大
	bzero(&seraddr,sizeof(seraddr));
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(PORT);
	//seraddr.sin_addr.s_addr=htonl(INADDR_ANY);//选择一个合适有效地址
	seraddr.sin_addr.s_addr=inet_addr("192.168.252.3");
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
	signal(SIGALRM,timeout_fun);
    struct sockaddr_in clientaddr;
    int clientaddr_len;
	int client_sck=accept(sckd,(struct sockaddr*)&clientaddr,&clientaddr_len);
	printf("clent ip=%s\tport=%d\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
	if(client_sck==-1)
	{
		perror("accept:");
		exit(-1);
	}
	//setnonblock(client_sck);
    //int  ntimeout=5000;
    //setsockopt(client_sck,SOL_SOCKET,SO_SNDTIMEO,(char*)&ntimeout,sizeof(int));
    while(1)
    {
       char  buf[100];
	   //gets(buf);
	   //send(client_sck,buf,strlen(buf),0);
	   //sendto(client_sck,buf,strlen(buf),0,NULL,NULL);
	   bzero(buf,sizeof(buf));
	   alarm(4);
	   int ret=recv(client_sck,buf,sizeof(buf)-1,0);
	   //recvfrom(client_sck,buf,sizeof(buf)-1,0,NULL,NULL);
	   // if(ret==-1)
	   // {
	   // 	if(errno==EAGAIN)
	   // 	{
	   // 		printf("recv timeout:\n");
	   // 		continue;
	   // 	}
	   // }
	   while(ret==-1)
	   {
	   	  ret=recv(client_sck,buf,sizeof(buf)-1,0);
	   }
	   alarm(0);
	   printf("rec:%s\n",buf);
    }	
    
	close(client_sck);
	return 0;
}

//[root@localhost 1103app]# netstat -ant | grep 2348
