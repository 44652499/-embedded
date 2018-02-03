#include  "define_header_file.h"
int main(int argc,const char* argv[])
{
    int fd,ret;
    struct aiocb my_aiocb;
    fd=open("passwd",O_RDONLY);
    if(fd<0)
    {
        perror("open:");
        exit(-1);
    }
    bzero(&my_aiocb,sizeof(my_aiocb));
    my_aiocb.aio_buf=malloc(1024+1);
    if(!my_aiocb.aio_buf)
    {
        perror("malloc:");
        exit(-1);
    }
    bzero((void*)my_aiocb.aio_buf,1024+1);
    my_aiocb.aio_fildes=fd;
    my_aiocb.aio_nbytes=1024;
    my_aiocb.aio_offset=0;
    ret=aio_read(&my_aiocb);
    if(ret<0)
    {
        perror("aio_read:");
        exit(-1);
    }
    while(aio_error(&my_aiocb)==EINPROGRESS)
    {
        ;
    }
    if((ret=aio_return(&my_aiocb))>0)
    {
        printf("ret=%d\n",ret);
        printf("%s\n",my_aiocb.aio_buf);
    }
    else 
    {
        perror("aio_return:");
        exit(-1);
    }
    return 0;
}