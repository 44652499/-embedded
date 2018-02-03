#include "define_all_header.h"

//请在添加此头文件 #include <sys/uio.h>
int open_file(const char* filename)
{
	int fd=-1;
	fd=open(filename,OPEN_CWD_FLAGS,0777);
	if(fd==-1)
	{
		if(errno==EEXIST)
		{
			fd=open(filename,OPEN_RDWR_FLAGS);
		}
		else
		{
			perror("open error:");
			exit(-1);
		}
	}
	return fd;
}

int main(int argc, char const *argv[])
{
	ssize_t size1 ,size2;
	char buf1[1024];
	gets(buf1);
	char buf2[1024];
	gets(buf2);
	char buf3[1024];
	gets(buf3);
	char buf4[1024];
	gets(buf4);
	char buf5[1024];
	gets(buf5);
	char buf6[1024];
	gets(buf6);
	char buf7[1024];
	gets(buf7);
	char buf8[1024];
	gets(buf8);
	struct iovec iov1[3];
	struct iovec iov2[3];
	int fd1=open_file("w1");
	int fd2=open_file("w2");
	int fd3=open_file("w3");
	int fd4=open_file("w4");
	int fd5=open_file("w5");
	int fd6=open_file("w6");
	int fd7=open_file("w7");
	int fd8=open_file("w8");
	//read(fd1,buf1,sizeof(buf1));
	//read(fd2,buf2,sizeof(buf2));
	//read(fd3,buf3,sizeof(buf3));
	//write(fd5,buf5,strlen(buf5));
	//write(fd6,buf6,strlen(buf6));
	//write(fd7,buf7,strlen(buf7));
    iov1[0].iov_base=buf1;
    iov1[0].iov_len=sizeof(buf1);
    iov1[1].iov_base=buf2;
    iov1[1].iov_len=sizeof(buf2);
    iov1[2].iov_base=buf3;
    iov1[2].iov_len=sizeof(buf3);
    iov2[0].iov_base=buf5;
    iov2[0].iov_len=sizeof(buf5);
    iov2[1].iov_base=buf6;
    iov2[1].iov_len=sizeof(buf6);
    iov2[2].iov_base=buf7;
    iov2[2].iov_len=sizeof(buf7);
    size1=readv(fd8,iov2,3);//正确,返回值为0,应为fd8 指向的是一个空文件,没有内容,所以返回字节数为0
    if(size1==-1)
    {
    	perror("readv error:");
    }
    size2=writev(fd4,iov1,3);//正确,写入文件,但是你写的是3个buf的size,所以返回长度是1024*3=3072
    printf("%d\t%d\n",size1,size2);
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
    close(fd5);
    close(fd6);
    close(fd7);
    close(fd8);
	return 0;
}

