#include "define_all_header.h"

int open_file(const char * filename)
{
	int fd=open(filename,OPEN_CWD_FLAGS,0777);
	if(fd==-1)
	{
		if(errno==EEXIST)
		{
			fd=open(filename,OPEN_RDWR_FLAGS);
		}
		else
		{
			perror("open file:");
			return -1;
		}
	}
	else
	{
		perror("open file:");
		return -1;
	}
	return fd;
}

int get_file_size(int fd)
{
	int file_size=lseek(fd,0,SEEK_END);
	return file_size;
}

void creat_cavity_file(int fd ,int file_size)
{
	lseek(fd,file_size-1,SEEK_SET);
	write(fd," ",1);
	//close(fd);//这里不能关闭,还没有建立映射.
}

void * mmap_p(int fd,int size)
{
	void * ptr_addr=mmap(NULL,size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	close(fd);//只有在建立成功后,才能关闭文件描述符
    return ptr_addr;
}

void copy_file(void* dest_addr,void* src_addr,int size)
{
	if(dest_addr!=NULL && src_addr!=NULL)
	{
		memcpy(dest_addr,src_addr,size);
	}	
}

void destroy_mmap(void* ptr_addr,int file_size)
{
	munmap(ptr_addr,file_size);
	ptr_addr=NULL;
	
}
int main(int argc, char const *argv[])
{
	int src_fd=open_file("signal_io.c");
	int dest_fd=open_file("new_signal_io.c");
	int src_file_size=get_file_size(src_fd);
    void* src_addr=mmap_p(src_fd,src_file_size);
	creat_cavity_file(dest_fd,src_file_size);
	void*  dest_addr=mmap_p(dest_fd,src_file_size); 

	//以下两句话顺序不对,必须是先有空洞文件也就是明确知道文件大小,才能映射到内存.  
    // void*  dest_addr=mmap_p(dest_fd,src_file_size);
    // creat_cavity_file(dest_fd,src_file_size);
	
    printf("%s\n","dd" );
    copy_file(dest_addr,src_addr,src_file_size);
    printf("%s\n","ddd" );
    destroy_mmap(dest_addr,src_file_size);
    destroy_mmap(src_addr,src_file_size);
	return 0;
}
