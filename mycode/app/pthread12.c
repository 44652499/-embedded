#include  "define_header_file.h"
/*
多线程复制文件
*/
#define  PTHREADCNT 5
#define  BLOCK_SIZE   ((10)*(1024))

//定义文件类型结构
typedef  struct  file_info
{
    int  fsize;
    char fname[256];
}file_info;

pthread_mutex_t  g_mutex;

//定义文件块结构
typedef struct  file_block_info
{
    int src_fd;
    int dest_fd;
    int begin_pos;
    int block_size;
}file_block_info;
//打开文件
int   open_file(const char*  filename)
{
    int fd =open(filename,FILE_CW_FLAG,0777);
    if(fd==-1)
    {
        if(errno==EEXIST)
        {
           fd =open(filename,FILE_RW_FLAG); 
           if(fd==-1)
           {
               perror("open error:");
               return -1;
           }
        }
        else
        {
            perror("open error:");
            return -1;
        }        
    }
    return fd;
}
//获取文件大小
file_info  get_file_info(int fd)
{
    file_info  f_info;    
    int file_size=lseek(fd,0,SEEK_END);
    f_info.fsize=file_size;
   // strcpy(f_info.fname,filename);
    return f_info;
}
//文件分块的块数
int  get_file_block(int file_size)
{
     if(file_size%BLOCK_SIZE==0)
     {
         return  file_size/BLOCK_SIZE;
     }
     return file_size/BLOCK_SIZE+1;
}
//获取文件最后一块大小(<BLOCK_SIZE)
int  get_last_block_size(int file_size)
{
    return  file_size%BLOCK_SIZE;
}
//文件分块信息,传递给线程
file_block_info*  get_file_div_block(int src_fd,int dest_fd,file_info  f_info)
{
    file_block_info * blocks=NULL;
    int block_cnt=get_file_block(f_info.fsize);
    int last_block_size=get_last_block_size(f_info.fsize);
    blocks=(file_block_info*)malloc(block_cnt*sizeof(file_block_info));
    while(blocks==NULL)
    {
       blocks=(file_block_info*)malloc(block_cnt*sizeof(file_block_info)); 
    }
    int i;
    for(i=0;i<block_cnt;i++)
    {
        blocks[i].src_fd=src_fd;
        blocks[i].dest_fd=dest_fd;
        blocks[i].begin_pos=i*BLOCK_SIZE;
        if(i==block_cnt-1 && last_block_size<BLOCK_SIZE)
        {
            blocks[i].block_size=last_block_size;
        }
        else 
        {
             blocks[i].block_size=BLOCK_SIZE;
        }        
    }
    return blocks;
}

void *  copy_file(void * arg)
{
    pthread_mutex_lock(&g_mutex);
    char buf[1024*3];
    file_block_info block=*(file_block_info*)arg;
    lseek(block.src_fd,block.begin_pos,SEEK_SET);
    lseek(block.dest_fd,block.begin_pos,SEEK_SET);    
    //循环读取一块文件
    while(1)
    {           
        int ret=read(block.src_fd,buf,block.block_size<sizeof(buf)?block.block_size:sizeof(buf));
        block.block_size=block.block_size-ret;
        write(block.dest_fd,buf,ret);        
        if(block.block_size<=0)
        {
            break;
        }
    }
    pthread_mutex_unlock(&g_mutex); 
}

int main(int argc,const char* argv[])
{
    int src_fd=open_file("descktop.png");
    int dest_fd=open_file("new_descktop.png");
    file_info  f_info=get_file_info(src_fd);
    int block_cnt=get_file_block(f_info.fsize);
    file_block_info* blocks=get_file_div_block(src_fd,dest_fd,f_info);
    pthread_mutex_init(&g_mutex,NULL);
    pthread_t *  pthread_ids=(pthread_t*)malloc(block_cnt*sizeof(pthread_t));
    while(pthread_ids==NULL)
    {
        pthread_ids=(pthread_t*)malloc(block_cnt*sizeof(pthread_t));
    }
    int i;
    for(i=0;i<block_cnt;i++)
    {
        int ret=pthread_create(&pthread_ids[i],NULL,copy_file,(file_block_info*)&blocks[i]);
        while(ret!=0)
        {
            ret=pthread_create(&pthread_ids[i],NULL,copy_file,(file_block_info*)&blocks[i]);
        }
    }
    for(i=0;i<block_cnt;i++)
    {
        pthread_join(pthread_ids[i],NULL);
    }
    pthread_mutex_destroy(&g_mutex);
    close(src_fd);
    close(dest_fd);
    free(pthread_ids);
    pthread_ids=NULL;
    free(blocks);
    blocks=NULL;

    return 0;
}

//10240  5578