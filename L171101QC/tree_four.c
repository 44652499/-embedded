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


/*------------------------------队列-----------------------*/
typedef struct queue_node
{
	node* ptrnode;
	struct queue_node * next;
}queue_node;

typedef struct queue
{
	queue_node * front;
	queue_node * tail;
}queue;
void  init_queue(queue * qu)
{
	qu->front=NULL;
	qu->tail=NULL;
}

int  is_empty_queue(queue * qu)
{
	if(qu->front==NULL && qu->tail==NULL)
		return 1;
	return 0;
}

void  push_queue(queue * qu,node * ptrtreenode)
{
	if(ptrtreenode!=NULL)
	{
		queue_node *  ptrnewnode=(queue_node*)malloc(1*sizeof(queue_node));
		assert(ptrnewnode!=NULL);
		ptrnewnode->ptrnode=ptrtreenode;
		ptrnewnode->next=NULL;
		if(qu->front==NULL)
		{
			qu->front=ptrnewnode;		
		}
		else
		{
			qu->tail->next=ptrnewnode;
		}
		qu->tail=ptrnewnode;
		ptrnewnode=NULL;
	}	
}

void pop_queue(queue* qu)
{
	if(!is_empty_queue(qu))
	{
		queue_node* ptrnode=qu->front;
		qu->front=qu->front->next;
		if(qu->front==NULL)
		{
			qu->tail=NULL;
		}
		free(ptrnode);
		ptrnode=NULL;
	}
}

node*  get_front_queue(queue* qu)
{
	if(!is_empty_queue(qu))
	{
		return qu->front->ptrnode;
	}
	return NULL;
}
/*------------------------------队列-----------------------*/


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
//输出二叉树深度
//取左子树和右子树最大长度
int  get_depth_binary_tree(node* root)
{
	int ldepth;
	int rdepth;
	if(root==NULL)
	{
		return 0;
	}
	if(root!=NULL)
	{
		 ldepth=get_depth_binary_tree(root->lchild);
		 rdepth=get_depth_binary_tree(root->rchild);
	}
	return ldepth>rdepth?ldepth+1:rdepth+1;
}

//二叉树广度遍历:一层一层遍历,每层从左到右遍历.需要使用队列
void  print_broadcast_binary_tree(node* root)
{
	queue qu;
	init_queue(&qu);   
	if(root!=NULL)
	{
		push_queue(&qu,root);
		while(!is_empty_queue(&qu))
		{
			root=get_front_queue(&qu);
			printf("%c\t",root->value);		
			root=root->lchild;
			push_queue(&qu,root);	
			root=get_front_queue(&qu);	
			root=root->rchild;
			push_queue(&qu,root);
			pop_queue(&qu);
		}	
		printf("\n");
	}	
}



int main(int argc, char const *argv[])
{
	node* root=init_binary_tree();
	print_broadcast_binary_tree(root);
	return 0;
}