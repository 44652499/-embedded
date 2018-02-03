#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//定义二叉树节点
typedef  struct node
{
	char  value;
	struct  node* lchild;
	struct  node* rchild;
}node;
/*-------------栈实现------------------*/
//定义栈节点
typedef struct stack_node
{
	node *  ptrnode;
	struct stack_node * next;
}stack_node;
//定义栈
typedef struct stack
{
	stack_node * top;
}stack;
//初始化栈
void  init_stack(stack * st)
{
	st->top=NULL;
}
//判断栈是否为空
int  is_empty_stack(stack * st)
{
	if(st->top==NULL)
		return 1;
	return 0;
}
//入栈
void  push_stack(stack * st,node *  ptrnode)
{
	//创建栈节点
	stack_node *  ptrnewnode=(stack_node*)malloc(1*sizeof(stack_node));
	assert(ptrnewnode!=NULL);
	ptrnewnode->ptrnode=ptrnode;
	ptrnewnode->next=st->top;
	st->top=ptrnewnode;
}
//出栈
void pop_stack(stack * st)
{
	if(!is_empty_stack(st))
	{
		stack_node * ptrtmp=st->top;
		st->top=st->top->next;
		free(ptrtmp);
		ptrtmp=NULL;
	}
}
//获取栈顶存储树节点地址值
node*  get_top_stack(stack * st)
{
	if(!is_empty_stack(st))
	{
		return st->top->ptrnode;
	}
	return NULL;
}
/*-------------栈实现------------------*/
//构建二叉树
node*  init_binary_tree()
{
	char value;
	scanf("%c",&value);
	getchar();//清空输入缓存,连续多次输入char类型才会出现输入缓存问题
	if(value=='q')
	{
		return NULL;
	}
	node* root=(node*)malloc(1*sizeof(node));
	assert(root!=NULL);
	root->value=value;
	root->lchild=init_binary_tree();
	root->rchild=init_binary_tree();
	return root;
}
//二叉树非递归前序遍历
void  print_binary_tree_pre(node* root)
{
	stack st;
	init_stack(&st);
	while(root!=NULL || !is_empty_stack(&st))
	{
		while(root!=NULL)
		{
			printf("%c\t",root->value);
			push_stack(&st,root);
			root=root->lchild;
		}		

        if(!is_empty_stack(&st))
        {
        	root=get_top_stack(&st);
			pop_stack(&st);
			root=root->rchild;
        }		
	}
}
//二叉树非递归中序遍历
void  print_binary_tree_mid(node* root)
{
	stack st;
	init_stack(&st);
	while(root!=NULL || !is_empty_stack(&st))
	{
		while(root!=NULL)
		{
			push_stack(&st,root);
			root=root->lchild;
		}

		if(!is_empty_stack(&st))
		{
			root=get_top_stack(&st);
			printf("%c\t",root->value);
			pop_stack(&st);
			root=root->rchild;
		}		
	}
}


int main(int argc, char const *argv[])
{
	node* root=init_binary_tree();
	print_binary_tree_pre(root);
	printf("\n");
	print_binary_tree_mid(root);
	printf("\n");
	return 0;
}