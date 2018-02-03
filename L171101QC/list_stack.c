#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define  MAX_SIZE 100
/*
栈：是一个顺序结构。符合先进后出(FILO) 特点。
栈分为：
1.顺序栈：把数组当成栈使用（不能随机访问数组元素）
2.链表栈：链表的节点组成
链表栈存在一个特殊指针，指向栈顶节点
*/
//定义栈节点类型
typedef struct node
{
	int value;
	struct node * next;
}node;
//定义栈
typedef struct stack
{
	node * top;
	int size;
}stack;
//初始化化栈
void  init_stack(stack* st)
{
	st->top=NULL;
	st->size=0;
}
//栈是否满
int  is_full_stack(stack * st)
{
	if(st->size==MAX_SIZE)
		return 1;
	return 0;
}
//栈是否空
int is_empty_stack(stack * st)
{
	if(st->top==NULL)
		return 1;
	return 0;
}
//进栈
void  push_stack(stack * st,int _value)
{
	if(is_full_stack(st))
	{
		printf("stack is full\n");
		return;
	}
	node * ptrnew=(node*)malloc(1*sizeof(node));
	assert(ptrnew!=NULL);
	ptrnew->value=_value;
	ptrnew->next=NULL;

	ptrnew->next=st->top;
	st->top=ptrnew;
	ptrnew=NULL;
	st->size++;
}
//出栈
void  pop_stack(stack *st)
{
	if(is_empty_stack(st))
	{
		printf("stack is empty\n");
		return;
	}
	node* ptrtmp=st->top;
	st->top=st->top->next;
	printf("pop :%d\n",ptrtmp->value);
	free(ptrtmp);
	st->size--;
	ptrtmp=NULL;
}
//获取栈大小(元素个数)
int get_size_stack(stack * st)
{
	return st->size;
}
//返回栈顶元素
node* get_top_stack(stack* st)
{
	if(!is_empty_stack(st))
	{
		return st->top;
	}
	return NULL;
}
//释放栈
void  free_stack(stack * st)
{
	if(!is_empty_stack(st))
	{
		node*  ptrtmp=NULL;
		while(st->top!=NULL)
		{
			ptrtmp=st->top;
			st->top=st->top->next;
			free(ptrtmp);
			ptrtmp=NULL;
		}
	}
}



int main(int argc, char const *argv[])
{
	stack st;
	init_stack(&st);
	int i;
	for(i=0;i<5;i++)
	{
		push_stack(&st,i+1);
	}
	pop_stack(&st);
	pop_stack(&st);
	pop_stack(&st);
	push_stack(&st,300);
	pop_stack(&st);
	printf("top value=%d\n",st.top->value);
	pop_stack(&st);
	pop_stack(&st);
	pop_stack(&st);
	push_stack(&st,300);
	printf("top value=%d\n",st.top->value);
	free_stack(&st);
	return 0;
}