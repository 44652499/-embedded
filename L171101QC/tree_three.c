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
//非递归后序访问树,每个节点要入栈和出栈两次.
typedef struct stack_node
{
	node *  ptrnode;	
	int     isfirst;//1:第一次入栈,2:第二次入栈
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
void  push_stack(stack * st,node *  ptrnode,int  isfirst)
{
	//创建栈节点
	stack_node *  ptrnewnode=(stack_node*)malloc(1*sizeof(stack_node));
	assert(ptrnewnode!=NULL);
	ptrnewnode->ptrnode=ptrnode;
    ptrnewnode->isfirst=isfirst;
	ptrnewnode->next=st->top;
	st->top=ptrnewnode;
}
//二次入栈,不创建新节点,继续使用上一次出栈栈节点
void  push_stack_new(stack * st,stack_node *  node,int  isfirst)
{
    node->isfirst=isfirst;
	node->next=st->top;
	st->top=node;
}
//出栈
void pop_stack(stack * st)
{
	if(!is_empty_stack(st))
	{
		stack_node * ptrtmp=st->top;
		st->top=st->top->next;
		if(ptrtmp->isfirst==1)
		{
			ptrtmp->next=NULL;//不释放栈节点,继续使用.与栈断开
			return;
		}
		if(ptrtmp->isfirst==2)
		{
			free(ptrtmp);//最后释放栈节点
			ptrtmp=NULL;
			return;
		}		
	}
}
//获取栈顶存储树节点地址值
stack_node*  get_top_stack(stack * st)
{
	if(!is_empty_stack(st))
	{
		return st->top;
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
//二叉树递归后序遍历
void  print_binary_tree_last(node* root)
{
	stack st;
	init_stack(&st);
	stack_node* ptrtmp=NULL;
	while(root!=NULL || !is_empty_stack(&st))
	{
		while(root!=NULL)
		{
			push_stack(&st,root,1);
			root=root->lchild;
		}

		if(!is_empty_stack(&st))
		{
			ptrtmp=get_top_stack(&st);
			root=ptrtmp->ptrnode;			
			if(ptrtmp->isfirst==2)
			{
				printf("%c\t",root->value);
				root=NULL;
			}
			pop_stack(&st);
			if(ptrtmp->isfirst==1)
			{
				push_stack_new(&st,ptrtmp,2);
				root=root->rchild;
			}				
		}
		
	}
}

int main(int argc, char const *argv[])
{
	node* root=init_binary_tree();
	print_binary_tree_last(root);
	printf("\n");
	return 0;
}