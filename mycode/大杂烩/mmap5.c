#include "appheader.h"

int main(int argc, char const *argv[])
{
    int fd=open("dataa.dat",O_CREAT|O_EXCL|O_RDWR,0777);
    if(fd==-1)
    {
    	perror("open fail:");
    	exit(-1);
    }	
    lseek(fd,100,SEEK_SET);  
    write(fd," ",1);  
    char* p_addr=(char*)mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    close(fd);
    char p[]="abcd";
    strcpy(p_addr,p);
    munmap(p_addr,100);
	return 0;
}
/*
我测试了可以全部写进去,估计是你其它地方出了问题
*/
