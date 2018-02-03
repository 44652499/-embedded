#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#define MAX_SIZE 100
/*
栈:一种符合栈操作特点结构
栈操作特点:先进后出(FILO)
栈分为:
1.顺序栈(按照栈操作规则操作一个数组)
2.链表栈(按照栈操作规则操作一个链表)
栈中其实只有一个指针,指向栈顶的节点
*/
//定义栈节点
typedef struct node
{
    int data;
    struct node * next;
}node;

//定义栈
typedef struct stack
{
    node * top;
    int size;//当前栈节点个数
    int capacity;//限制栈存储最大节点数
}stack;
//初始化栈
void  init_stack(stack * ptr_stack)
{
    ptr_stack->top=NULL;
    ptr_stack->size=0;
    ptr_stack->capacity=MAX_SIZE;
}
//进栈
void  push_stack(stack * ptr_stack,int value)
{
    if(!is_stack_full(ptr_stack))
    {
        node*  ptr_new=(node*)malloc(1*sizeof(node));
        ptr_new->data=value;
        ptr_new->next=NULL;
    
        //入栈
        ptr_new->next=ptr_stack->top;
        ptr_stack->top=ptr_new;
        ptr_stack->size++;
        ptr_new=NULL;
    }
    else
    {
        printf("stack is full\n");
    }    
}
//出栈
void  pop_stack(stack * ptr_stack)
{
    if(!is_stack_empty(ptr_stack))
    {
        node*  ptr_tmp=ptr_stack->top;
        ptr_stack->top=ptr_stack->top->next;
        ptr_stack->size--;
        printf("pop stack data:%d\n",ptr_tmp->data);
        free(ptr_tmp);
        ptr_tmp=NULL;
    }
    else
    {
        printf("stack is empty\n");
    }
}
//栈是否满
int  is_stack_full(stack * ptr_stack)
{
    if(ptr_stack->size>ptr_stack->capacity)
    {
        return 1;
    }
    return 0;
}
//栈是否为空
int  is_stack_empty(stack *  ptr_stack)
{
    if(ptr_stack->size==0)
    {
        return 1;
    }
    return 0;
}
//返回栈顶节点
node*  get_stack_top(stack* ptr_stack)
{
    if(!is_stack_empty(ptr_stack))
    {
        return  ptr_stack->top;
    }
    return NULL;
}
//返回栈的节点个数
int get_stack_cnt(stack* ptr_stack)
{
    return  ptr_stack->size;
}

int main(int argc, char const *argv[])
{
    stack * ptr_stack=(stack*)malloc(1*sizeof(stack));
    init_stack(ptr_stack);
    int i;
    for(i=0;i<5;i++)
    {
        push_stack(ptr_stack,i+1);
    }
    pop_stack(ptr_stack);
    pop_stack(ptr_stack);
    pop_stack(ptr_stack);
    push_stack(ptr_stack,200);
    push_stack(ptr_stack,300);
    pop_stack(ptr_stack);
    pop_stack(ptr_stack);
    pop_stack(ptr_stack);
    pop_stack(ptr_stack);
    pop_stack(ptr_stack);
    pop_stack(ptr_stack);
    free(ptr_stack);
    ptr_stack=NULL;
    return 0;
}