#include "appheader.h"
int main(int argc, char const *argv[])
{
    int fd=open("data.txt",O_RDWR);
    if(fd==-1)
    {
    	perror("open fail:");
    	exit(-1);
    }	
    int file_size=lseek(fd,0,SEEK_END);   
   // printf("%d\n",file_size);
    char* p_addr=(char*)mmap(NULL,file_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    close(fd);
    if(p_addr==NULL)
    {
    	perror("mmap:");
    	exit(-1);
    }
    char *p=p_addr; 
    while(*p!='\0')
    {
       if(*p=='\n'||*p==',')
       	 *p='\0';
       p++;
    }  
    int part_len=strlen(p_addr);
    while(part_len>0)
    {
       printf("%s\n",p_addr);
       p_addr=p_addr+part_len+1;
       part_len=strlen(p_addr);
    }    
    munmap(p_addr,file_size);
	return 0;
}
