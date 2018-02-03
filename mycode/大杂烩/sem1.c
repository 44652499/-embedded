#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	key_t key=ftok("sem1.c",113);
	if(key==-1)
	{
		return;
    }

	int semid=semget(key,1,IPC_CREAT);
	if(semid==-1)
	{
		return;
	}

	semctl(semid,0,SETVAL,1);
	//semctl(semid,0,SETVAL,0);
	int pid=fork();
	if(pid==-1)
		return;
	if(pid==0)
	{
      sleep(2);
	  printf("child process is running\n");

	  struct sembuf b;
	  b.sem_num=0;
	  b.sem_op=-1;
	  b.sem_flg=0;
	  semop(semid,&b,1);
	  printf("child process p  is over\n");
	}
	if(pid>0)
	{
      printf("parent process is runing\n");
	  struct sembuf  b;
	  b.sem_num=0;
	  b.sem_op=-1;
	  b.sem_flg=0;
      semop(semid,&b,1);

	  printf("parent is done\n");
	  int i;
	  for(i=0;i<6;i++)
	  {
		  sleep(1);
	  }
      printf("paretn v done\n");
	  struct sembuf  b1;
      b1.sem_num=0;
	  b1.sem_op=1;
	  b1.sem_flg=0;
      semop(semid,&b1,1);

	  sleep(1);      

	}	
	return 0;
}
