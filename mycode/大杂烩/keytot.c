#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	key_t key=ftok("keytot.c",0x1234);
	if(key==-1)
	{
		return;
	}
	printf("%x\n",key);
	return 0;
}
//0x3400e196
//
