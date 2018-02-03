/*
进程池：主线程创建多个进程，有人时唤醒进程执行任务，当任务执行完之后堵塞进程。等待下一批任务再唤醒
实现进程池步骤：
1.主线程创建进程
2.堵塞子进程
3.主线程建任务队列
4.主线程分发任务给每一个子进程（进程通信）
5.子进程唤醒执行任务，执行完之后继续获取任务，没有则堵塞
6.子进程主动与主线程通信
*/

#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define  N  10
pid_t  childprocess[N];
//定义消息内容
typedef struct  msg_content
{
	void *  addr;
	int   pos;
	char  islive;
}msg_content;
//定义消息节点类型
typedef struct  msg_node
{
	int  msg_type;
	msg_content  msg_c;
}msg_node;
//子进程执行任务
void  child_do_task(int msgid)
{
	msg_node msg;
	while(1)
	{
		bzero(&msg,sizeof(msg)); 
	    msgrcv(msgid,&msg,sizeof(msg_node)-sizeof(int),getpid(),0);
	    if(msg.msg_c.islive=='y')
	    {
	    	 printf("%d  do  task  pos=%d\n",getpid(),msg.msg_c.pos);
	    }
	    else
	    {
	    	//发送结束确认消息给父进程
	    	msg.msg_type=getppid();
	    	msg.msg_c.pos=getpid();
	    	msg.msg_c.islive='y';
	    	msgsnd(msgid,&msg,sizeof(msg)-sizeof(int),0);
	    	exit(-1);
	    }
	   
	}	
}
//创建子进程
void  create_child_process(int msgid,int  num)
{
	int i=0;
	int index=0;
	for(i=0;i<num;i++)
	{
		pid_t pid=fork();
		if(pid==0)
		{
			child_do_task(msgid);
		}
		if(pid>0)
		{
			childprocess[index++]=pid;
		}
	}
	
}
//主进程执行任务
void   main_process_task(int msgid)
{
	int i;
	for(i=0;i<20;i++)
	{
		msg_node * ptr_node=(msg_node*)malloc(1*sizeof(msg_node));
		ptr_node->msg_type=childprocess[i%N];
		ptr_node->msg_c.addr=NULL;
		ptr_node->msg_c.pos=i+1;
		ptr_node->msg_c.islive='y';

		msgsnd(msgid,ptr_node,sizeof(msg_node)-sizeof(int),0);
		sleep(1);
	}
	//发送子进程消息，让其中5个子进程结束
	for(i=0;i<5;i++)
	{
		msg_node * ptr_node=(msg_node*)malloc(1*sizeof(msg_node));
		ptr_node->msg_type=childprocess[i%N];
		ptr_node->msg_c.islive='n';

		msgsnd(msgid,ptr_node,sizeof(msg_node)-sizeof(int),0);
	}
	//收到子进程结束信息
	i=0;
	msg_node msg;
	while(i<5)
	{
		bzero(&msg,sizeof(msg)); 
	    int  ret=msgrcv(msgid,&msg,sizeof(msg_node)-sizeof(int),getpid(),0);
	    if(ret>0)
	    {
	    	int pos=msg.msg_c.pos;
	    	int j;
	    	for(j=0;j<N;j++)
	    	{
	    		if(childprocess[j]==pos)
	    		{
	    			childprocess[j]=-1;
	    		}
	    	}
	    	i++;
	    }
	}
	//发送任务给剩余进程执行
	for(i=0;i<20;i++)
	{
		msg_node * ptr_node=(msg_node*)malloc(1*sizeof(msg_node));
		int j=i%N;
		while(childprocess[j]==-1)
		{
			j++;
			if(j==N)
			{
				j=0;
			}
		}
		ptr_node->msg_type=childprocess[j];
		ptr_node->msg_c.addr=NULL;
		ptr_node->msg_c.pos=i+1;
		ptr_node->msg_c.islive='y';

		msgsnd(msgid,ptr_node,sizeof(msg_node)-sizeof(int),0);
		sleep(1);
	}
	//发送子进程消息，结束所有子进程
	//收到子进程结束信息
}
int main(int argc, char const *argv[])
{
	int msgid=msgget((key_t)0x12345,0666|IPC_CREAT);
	if(msgid==-1)
	{
		perror("msgget fail:");
		return;
	}

 	create_child_process(msgid,N);
 	main_process_task(msgid);
 	
 	return 0;
 }