#include "define_all_header.h"
#define BLOCK_SIZE (2*1024*1024)//2M大小
//定义队列节点
typedef struct queue_node
{
	void* (*f_task)(void* arg);
	//void* arg_value;//
	struct queue_node* next;
}queue_node;
//定义任务队列
typedef struct task_queue
{
	queue_node* head;
	queue_node* tail;
}task_queue;
//定义线程池类型
typedef struct pthread_pool
{
	int task_num;//任务总数
	int task_done;//已做完任务数
	int task_undone;//未做完任务数
	task_queue* t_queue;//任务队列
	int is_destroy;//释放标志 0 不能释放 1 可以释放
	pthread_t * pthreads;//定义线程
	pthread_t pthread_num;//线程数量
	pthread_mutex_t mutex;//定义互斥锁
	pthread_cond_t cond;//定义条件变量
}pthread_pool;
//文件分块信息
typedef struct file_block
{
	int src_fd;//源文件文件描述符
	int dest_fd;//目标文件文件描述符
	int file_pos;//复制起始位置
	int block_size;//文件块大小
}file_block;
//文件信息
typedef struct file_pthread_pool
{
	pthread_pool * p_pthread_pool;
	file_block * f_block;
}file_pthread_pool;
//打开文件
int open_file(const char* filename)
{
	int fd=open(filename,OPEN_CWD_FLAGS,0777);
	if(fd==-1)
	{
		if(errno==EEXIST)
		{
			fd=open(filename,O_RDWR);
		}
		else
		{
			perror("open error:");
			exit(-1);
		}
	}
	else
	{
		fd=(filename,O_RDWR);
	}
	return fd;
}
//获取文件大小
int get_file_size(int fd)
{
	int file_size=lseek(fd,0,SEEK_END);
	return file_size;
}
//获取文件块数
int get_block_num(int file_size)
{
	int file_block=file_size%BLOCK_SIZE;
	if(file_block==0)
	{
		return file_size/BLOCK_SIZE;
	}
	return file_size/BLOCK_SIZE+1;
}
//获取文件最后一块大小
int get_last_file_block(int file_size,int file_block)
{
	int last_block_size=file_size%file_block;
	if(last_block_size==0)
	{
		return BLOCK_SIZE;
	}
	return last_block_size;
}
//队列有关函数

//初始化任务队列
void init_queue(task_queue* t_queue)
{
	t_queue->head=NULL;
	t_queue->tail=NULL;
}
//入队
void push_node_queue(task_queue* t_queue,queue_node* node)
{
	if(t_queue->head==NULL)
	{
		t_queue->head=node;
	}
	else
	{
		t_queue->tail->next=node;
	}
	t_queue->tail=node;
	node=NULL;
}
//判断队列是否为空
int is_queue_empty(task_queue* t_queue)
{
	if(t_queue->head==NULL && t_queue->tail==NULL)
	{
		return 1;
	}
	return 0;
}
//出队函数
queue_node* pop_task_queue(task_queue* t_queue)
{
	queue_node* temp=NULL;
	if(!is_queue_empty(t_queue))
	{
	    temp=t_queue->head;
		t_queue->head=t_queue->head->next;
		if(t_queue->head==NULL)
		{
			t_queue->tail=NULL;//判断是否为空时，条件为t_queue->head==NULL && t_queue->tail==NULL
		}
	}
	return temp;
}
//记录文件分块信息
file_block* get_file_block_message(int src_fd,int dest_fd)
{
	int file_size=get_file_size(src_fd);
	int f_block_num=get_block_num(file_size);
	int last_block_size=get_last_file_block(file_size,f_block_num);
	file_block* f_block=(file_block*)malloc(f_block_num*sizeof(file_block));
	while(f_block==NULL)
	{
		 f_block=(file_block*)malloc(f_block_num*sizeof(file_block));
	}
	int i;
	for(i=0;i<f_block_num;i++)
	{
		f_block[i].src_fd=src_fd;
		f_block[i].dest_fd=dest_fd;
		f_block[i].file_pos=i*BLOCK_SIZE;
		if(i==f_block_num-1)
		{
			f_block[i].block_size=last_block_size;
		}
		f_block[i].block_size=BLOCK_SIZE;
	}
	return f_block;
}
//线程实际执行函数
void* pthread_really_doing(void* arg)
{
	file_pthread_pool *p_file_pthread=(file_pthread_pool*)arg;
	pthread_pool p_pthread_pool=*(p_file_pthread->p_pthread_pool);
	file_block f_block=*(p_file_pthread->f_block);
	//你这个文件分块没有任何意义了,每个子线程与文件块没任何关系,是不是???

	pthread_mutex_lock(p_pthread_pool.mutex);   
    lseek(f_block.src_fd,f_block.file_pos,SEEK_SET);
    lseek(f_block.dest_fd,f_block.file_pos,SEEK_SET);
    char buf[4096];
    while(1)
    {

        bzero(buf,sizeof(buf));
        int ret=read(f_block.src_fd,buf,f_block.block_size>sizeof(buf)?sizeof(buf):f_block.block_size);
       
        f_block.block_size=f_block.block_size-ret;
        write(f_block.dest_fd,buf,ret);
        if(f_block.block_size==0)
        {
        	printf("1\n");
            break;
        }
    }
    pthread_mutex_unlock(p_pthread_pool.mutex);
}
//线程执行函数
void* pthread_doing(void* arg)
{
	 // file_pthread_pool *p_file_pthread=(file_pthread_pool*)malloc(1*sizeof(file_pthread_pool));
	 // while(p_file_pthread==NULL)
	 // {
	 // 	p_file_pthread=(file_pthread_pool*)malloc(1*sizeof(file_pthread_pool));
	 // }
	  file_pthread_pool * p_file_pthread=(file_pthread_pool*)arg;
	  pthread_pool*  p_pthread_pool=p_file_pthread->p_pthread_pool;
	 // file_block* f_block=p_file_pthread->f_block;
	 // printf("%d\n",f_block->block_size);
    while(1)
    {
        pthread_mutex_lock(&p_pthread_pool->mutex);
        if(p_pthread_pool->task_undone==0 && p_pthread_pool->is_destroy==0)
        {
            pthread_cond_wait(&p_pthread_pool->cond,&p_pthread_pool->mutex);    
        }
        //线程收到任务唤醒执行
        if(p_pthread_pool->task_undone>0 && p_pthread_pool->is_destroy==0)
        {
            queue_node * p_task_node=pop_task_queue(p_pthread_pool->t_queue);
            p_pthread_pool->task_done++;
            p_pthread_pool->task_undone--;

            //线程干事
            if(p_task_node!=NULL)
            {
            	
                //(*p_task_node->f_task)((void*)&p_file_pthread);//看不懂你为何要这样取,既然我是用队列存储任务节点,那么复制文件的信息参数也应该存储在节点中
                //你这样就是每个线程都把整个文件复制了.肯定不行的
                 
                free(p_task_node);
                p_task_node=NULL;

            }           
        }
        pthread_mutex_unlock(&p_pthread_pool->mutex);
        if(p_pthread_pool->task_undone==0 && p_pthread_pool->is_destroy==1)
        {
            pthread_exit(NULL);
        }     
    }
}

//初始化线程池
pthread_pool* init_pthread_pool(int pthread_num)
{
	pthread_pool* p_pthread_pool=(pthread_pool*)malloc(1*sizeof(pthread_pool));
	while(p_pthread_pool==NULL)
	{
		p_pthread_pool=(pthread_pool*)malloc(1*sizeof(pthread_pool));
	}
	
	p_pthread_pool->pthread_num=pthread_num;

	p_pthread_pool->task_done=0;
	p_pthread_pool->task_undone=0;
	p_pthread_pool->t_queue=NULL;
	//printf("2\n");
	p_pthread_pool->task_num=0;
	p_pthread_pool->is_destroy=0;
	pthread_mutex_init(&p_pthread_pool->mutex,NULL);
	pthread_cond_init(&p_pthread_pool->cond,NULL);
	return p_pthread_pool;
}
//创建线程
pthread_pool* create_pthread(int pthread_num,int src_fd,int dest_fd)
{
	pthread_pool* p_pthread_pool=init_pthread_pool(pthread_num);
	file_block* f_block=get_file_block_message(src_fd,dest_fd);
	file_pthread_pool* p_file_pthread=(file_pthread_pool*)malloc(1*sizeof(file_pthread_pool));
	while(p_file_pthread==NULL)
	{
		p_file_pthread=(file_pthread_pool*)malloc(1*sizeof(file_pthread_pool));	
	}
	p_file_pthread->p_pthread_pool=p_pthread_pool;
	p_file_pthread->f_block=f_block;
	p_pthread_pool->pthreads=(pthread_t*)malloc(pthread_num*sizeof(pthread_t));//给线程分配空间
	while(p_pthread_pool->pthreads==NULL)
	{
		p_pthread_pool->pthreads=(pthread_t*)malloc(pthread_num*sizeof(pthread_t));
	}
	int i;
	for(i=0;i<p_pthread_pool->pthread_num;i++)
	{
		int ret=pthread_create(&p_pthread_pool->pthreads[i],NULL,pthread_doing,(void*)p_file_pthread);
		while(ret==-1)
		{
			ret=pthread_create(&p_pthread_pool->pthreads[i],NULL,pthread_doing,(void*)p_file_pthread);
		}
	}
	return p_pthread_pool;
}
//初始化任务
void init_task(int src_fd,task_queue* t_queue,pthread_pool* p_pthread_pool)
{
	int file_size=get_file_size(src_fd);
	int file_block=get_block_num(file_size);
	int last_block_size=get_last_file_block(file_size,file_block);
	queue_node* t_queue_node=NULL;
	int i;
	for(i=0;i<file_block;i++)
	{
		t_queue_node=(queue_node*)malloc(1*sizeof(queue_node));
		while(t_queue_node==NULL)
		{
			t_queue_node=(queue_node*)malloc(1*sizeof(queue_node));
		}

		t_queue_node->f_task=pthread_really_doing;
		t_queue_node->next=NULL;
		push_node_queue(t_queue,t_queue_node);
		p_pthread_pool->task_num=file_block;//任务总数为文件块数
		p_pthread_pool->task_undone++;
		if(p_pthread_pool->task_undone>0)
		{
			p_pthread_pool->t_queue=t_queue;
		}
		if(p_pthread_pool->t_queue!=NULL)
		{
			 pthread_cond_signal(&p_pthread_pool->cond);
		}
	}
}
//释放线程池
void destroy_pthread_pool(pthread_pool* p_pthread_pool)
{
	if(p_pthread_pool->is_destroy==0)
    {
        p_pthread_pool->is_destroy=1;
    }
    if(p_pthread_pool->is_destroy==1)
    {
        pthread_cond_broadcast(&p_pthread_pool->cond);
        int i;
        for(i=0;i<p_pthread_pool->pthread_num;i++)
        {
            pthread_join(p_pthread_pool->pthreads[i],NULL);
        }
        free(p_pthread_pool->pthreads);
        p_pthread_pool->pthreads=NULL;
        free(p_pthread_pool);
        p_pthread_pool=NULL;
    }
}
int main(int argc, char const *argv[])
{
	int src_fd=open_file("descktop.png");
	int dest_fd=open_file("new_descktop.png");
	pthread_pool* p_pthread_pool=create_pthread(8,src_fd,dest_fd);
	task_queue t_queue;
	init_queue(&t_queue);
	init_task(src_fd,&t_queue,p_pthread_pool);
	while(1)
	{	
		if(p_pthread_pool->task_done==p_pthread_pool->task_num)
		{
			//printf("1\n");
			break;
		}
	}
	destroy_pthread_pool(p_pthread_pool);
	return 0;
}