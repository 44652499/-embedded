#include  "define_header_file.h"
#define    BUFFSIZE  892470
int main(int argc, char const *argv[])
{
	struct aiocb  rd_aiocb;
	int fd=open("descktop.png",O_RDONLY);
	if(fd==-1)
	{
		perror("open error");
		exit(-1);
	}
	int counter=1;
	int ret;
	bzero(&rd_aiocb,sizeof(rd_aiocb));
	rd_aiocb.aio_buf=malloc(BUFFSIZE+1);
	rd_aiocb.aio_fildes=fd;
	rd_aiocb.aio_nbytes=BUFFSIZE;
	rd_aiocb.aio_offset=0;

	ret=aio_read(&rd_aiocb);
	if(ret==-1)
	{
		perror("aio_read error");
		exit(-1);
	}
	while(aio_error(&rd_aiocb)==EINPROGRESS)
	{
		printf("第%d次\n",counter++);
	}
	ret=aio_return(&rd_aiocb);
	printf("bytes=%d\n",ret);
    close(fd);
	return 0;
}