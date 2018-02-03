#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	key_t key=ftok("sem2.c",0x12345);
	if(key==-1)
	{
		perror("ftok:");
		exit(0);
	}
	int semid=semget(key,1,IPC_CREAT|IPC_EXCL|0777);//1个信号集
	if(semid==-1)
	{
		perror("semget:");
		exit(0);
	}
	semctl(semid,0,SETVAL,0);//下标标号为0的信号量值为n(n>0)
	struct sembuf sem;
	pid_t pid=fork();
	if(pid<0)
	{
		printf("fork fail\n");
		exit(0);
	}
	if(pid==0)
	{
	   while(1)
	   {
	   	 sem.sem_num=0;//下标标号为0的信号量
         sem.sem_op=-1;//p操作
         sem.sem_flg=0;//IPC_NOWAIT IPC_UNDO
         semop(semid,&sem,1);//1个信号集做P操作
         printf("child process done p\n");
         sleep(1);
	   }
       
	}
	if(pid>0)
	{
       sleep(5);
       while(1)
       {
       	sem.sem_num=0;
       	sem.sem_op=1;
       	sem.sem_flg=0;
       	semop(semid,&sem,1);
       	printf("parent process done V \n");
       	sleep(3);
       }
	}
	return 0;
}
