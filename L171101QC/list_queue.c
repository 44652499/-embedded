#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define  MAX_SIZE 100
/*
队列:是一个顺序结构,符合 先进先出(FIFO)
队列分为:
1.顺序队列:把数组当成队列使用,按照先进先出访问队列
2.链表队列:节点组成
链表队列组成:
1.指向队首指针:负责出队
2.指向队尾指针:负责入队
*/
//定义队列节点
typedef struct node
{
	int value;
	struct node * next;
}node;
//定义队列结构
typedef struct queue
{
	node * front;
	node * tail;
	int size;
}queue;
//初始化队列
void  init_queue(queue * qu)
{
	qu->front=NULL;
	qu->tail=NULL;
	qu->size=0;
}

//判断队列是否满
int is_full_queue(queue *qu)
{
	if(qu->size==MAX_SIZE)
		return 1;
	return 0;
}
//判断队列是否为空
int  is_empty_queue(queue * qu)
{
	if(qu->front==NULL && qu->tail==NULL)
		return 1;
	return 0;
}
//入队
void push_queue(queue *qu,int _value)
{
	if(is_full_queue(qu))
	{
		printf("queue is full\n");
		return ;
	}
	node* ptrnew=(node*)malloc(1*sizeof(node));
	assert(ptrnew!=NULL);
	ptrnew->value=_value;
	ptrnew->next=NULL;
	if(qu->front==NULL)
	{
		qu->front=ptrnew;
	}
	else
	{
		qu->tail->next=ptrnew;
	}
	qu->tail=ptrnew;
	qu->size++;
	ptrnew=NULL;
}
//出队
void pop_queue(queue* qu)
{
	if(is_empty_queue(qu))
	{
		printf("queue is empty\n");
		return;
	}
	node *  ptrtmp=qu->front;
	qu->front=qu->front->next;
	if(qu->front==NULL)
	{
		qu->tail=NULL;
	}
	printf("pop %d\n",ptrtmp->value);
	free(ptrtmp);
	ptrtmp=NULL;
	qu->size--;
}
//获取队列元素个数
int  get_size_queue(queue * qu)
{
	return qu->size;
}
//返回队首元素
node*  get_front(queue* qu)
{
	if(!is_empty_queue(qu))
		return qu->front;
	return NULL;
}
//返回队尾元素
node*  get_tail(queue * qu)
{
	if(!is_empty_queue(qu))
		return qu->tail;
	return NULL;
}
int main(int argc, char const *argv[])
{	
	queue qu;
	init_queue(&qu);
	int i;
	for(i=0;i<5;i++)
	{
		push_queue(&qu,i+1);
	}
	printf("size=%d\n",get_size_queue(&qu));
	pop_queue(&qu);
	pop_queue(&qu);
	push_queue(&qu,200);
	printf("front %d\n",get_front(&qu)->value);
	pop_queue(&qu);
	pop_queue(&qu);
	pop_queue(&qu);
	pop_queue(&qu);
	pop_queue(&qu);
	pop_queue(&qu);
	push_queue(&qu,300);
	printf("tail %d\n",get_tail(&qu)->value);
	return 0;
}