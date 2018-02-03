#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#define MAX_SIZE 100
/*
队列:符合先进先出结构.
队列特点:先进先出(FIFO)
队列分为:
1.顺序队列(按照队列特点操作一个数组)
2.链表队列(按照队列特点操作一个链表)
队列组成由两个指针:
1.指向队首指针
2.指向队尾指针
队首指针:负责出队
队尾指针:负责入队
*/
//定义队列节点
typedef struct  node
{
    int data;
    struct node * next;
}node;

//定义队列
typedef struct queue
{
    node* front;
    node* tail;
    int size;
    int capacity;
}queue;
//初始化队列
void  init_queue(queue *  ptr_queue)
{
    ptr_queue->front=ptr_queue->tail=NULL;
    ptr_queue->size=0;
    ptr_queue->capacity=MAX_SIZE;
}
//入队
void   push_queue(queue*  ptr_queue,int value)
{
    if(!is_queue_full(ptr_queue))
    {
        node * ptr_new=(node*)malloc(1*sizeof(node));
        ptr_new->data=value;
        ptr_new->next=NULL;
    
        if(ptr_queue->front==NULL)
        {
            ptr_queue->front=ptr_new;      
        }
        else
        {
            ptr_queue->tail->next=ptr_new;
        }
        ptr_queue->size++;
        ptr_queue->tail=ptr_new;
        ptr_new=NULL;
    }
    else
    {
        printf("queue is full\n");
    }   
}
//出队
void  pop_queue(queue * ptr_queue)
{
    if(!is_queue_empty(ptr_queue))
    {
        node *  ptr_tmp=ptr_queue->front;
        ptr_queue->front=ptr_queue->front->next;
        if(ptr_queue->front==NULL)
        {
            ptr_queue->tail=NULL;
        }
        printf("pop queue data:%d\n",ptr_tmp->data);
        ptr_queue->size--;
        free(ptr_tmp);
        ptr_tmp=NULL;
    }
    else
    {
        printf("queue is empty\n");
    }
}

//队列是否满
int  is_queue_full(queue*  ptr_queue)
{
    if(ptr_queue->size>ptr_queue->capacity)
    {
        return 1;
    }
    return 0;
}
//队列是否空
int   is_queue_empty(queue*  ptr_queue)
{
    if(ptr_queue->front==NULL &&  ptr_queue->tail==NULL)
    {
        return 1;
    }
    return 0;
}
//返回队列元素个数
int   get_queue_cnt(queue * ptr_queue)
{
    return  ptr_queue->size;
}
//返回队首
node*  get_queue_front(queue * ptr_queue)
{
    if(!is_queue_empty(ptr_queue))
    {
        return  ptr_queue->front;
    }
    return NULL;
}
//返回队尾
node*   get_queue_tail(queue*  ptr_queue)
{
    if(!is_queue_empty(ptr_queue))
    {
        return  ptr_queue->tail;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    queue  que;
    init_queue(&que);
    int i;
    for(i=0;i<5;i++)
    {
        push_queue(&que,i+1);
    }
    pop_queue(&que);
    pop_queue(&que);
    pop_queue(&que);
    push_queue(&que,200);
    push_queue(&que,300);
    pop_queue(&que);
    pop_queue(&que);
    pop_queue(&que);
    pop_queue(&que);
    pop_queue(&que);
    pop_queue(&que);
    return 0;
}
