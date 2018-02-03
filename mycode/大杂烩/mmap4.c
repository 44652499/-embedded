 #include <sys/mman.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
 #include <time.h>
 #include <stdio.h>
 #include <stdlib.h>
int main(int argc, char const *argv[])
{
	// srand((int)time(NULL));
	// int data[10];
	// int i;
	// for(i=0;i<10;i++)
	// {
	// 	data[i]=(int)rand()%100;
	// 	//printf("%d\t",data);
	// }
	// int fd=open("intfile",O_CREAT|O_EXCL|O_WRONLY,0676);
	// if(fd==-1)
	// {
	// 	perror("open:");
	// 	exit(-1);
	// }
	// write(fd,data,sizeof(int)*10);
	// close(fd);
	// printf("\n");

	int fd=open("intfile",O_RDWR);
	if(fd==-1)
	{
		perror("open:");
		exit(-1);
	}
	int file_length=lseek(fd,0,SEEK_END);
	void * ptr_addr=mmap(NULL,file_length,PROT_WRITE|PROT_READ,MAP_SHARED, fd,0);
	int *ptr_int=(int*)ptr_addr;
	int i,j;
	// for(i=0;i<10;i++)
	// {
	// 	printf("%d\t",ptr_int[i]);
	// }
    for(i=0;i<10;i++)
    {
    	for(j=0;j<10-i-1;j++)
    	{
    		if(ptr_int[j]>ptr_int[j+1])
    		{
    			int tmp=ptr_int[j];
    			ptr_int[j]=ptr_int[j+1];
    			ptr_int[j+1]=tmp;
    		}    		
    	}
    }
	printf("\n");
	munmap(ptr_addr,file_length);
	//close(fd);
    int array[10];
	lseek(fd,0,SEEK_SET);
	read(fd,array,sizeof(int)*10);
	for(i=0;i<10;i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n"); 
	return 0;
}