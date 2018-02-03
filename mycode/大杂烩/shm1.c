#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	
	key_t key=ftok("shm1.c",0x1234);
	if(key==-1)
	{
		perror("ftok error\n");
	}
	int shmid=shmget(key,1024,O_RDWR);
	if(shmid==-1)
	{
		perror("shmget error\n");
	}
	void * addr=shmat(shmid,NULL,0);
	if(addr==NULL)
	{
		perror("shmat error\n");
	}
	char *ch=(char*)addr;
	printf("%s\n",ch);
	shmdt(addr);
	return 0;
}
