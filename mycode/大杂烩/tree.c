#include <stdio.h>
#define STACKSIZE 100
#define STACKINCREMENT 10
typedef struct Tree
{
	int data;
	struct Tree * left;
    struct Tree * right;
}Tree;

typedef struct Stack
{
	Tree * base;
	Tree * top;
	int size;
}Stack;

void InitStack(Stack * s)
{
	s->base=(Tree*)malloc(STACKSIZE*sizeof(Tree));
	while(s->base==NULL)
	{
      s->base=(Tree*)malloc(STACKSIZE*sizeof(Tree));
	}
	s->top=s->base;
	s->size=STACKSIZE;
}

void Push(Stack *s,Tree newTreeNode)
{
	if(s->top-s->base>=s->size)
	{
		s->base=(Tree*)realloc(s->base,(s->size+STACKINCREMENT)*sizeof(Tree));
		while(s->base==NULL)
		{
           s->base=(Tree*)realloc(s->base,(s->size+STACKINCREMENT)*sizeof(Tree));
		}
		s->top=s->base+s->size;
		s->size=s->size+STACKSIZE;
	}
	*(s->top)=newTreeNode;
	s->top++;
}

Tree Pop(Stack *s)
{
	s->top--;
	return *(s->top);
}

int StackEmpty(Stack *s)
{
	if(s->top==s->base)
		return 1;
	else
		return 0;
}

Tree*  CreatTree(Tree* curr)
{
   int _data;
   scanf("%d",&_data);
   if(_data==-1)
	{
	   curr=NULL;
	}
   else
	{
     curr=(Tree*)malloc(1*sizeof(Tree));
     while(curr==NULL)
     {
       curr=(Tree*)malloc(1*sizeof(Tree));
     }
     curr->data=_data;
     curr->left=NULL;
     curr->right=NULL;
     CreatTree(curr->left);
     CreatTree(curr->right);
	}
	return curr;
}

void PreOrder(Tree * curr)
{
	if(curr!=NULL)
	{
		printf("%d\t",curr->data);
		PreOrder(curr->left);
		PreOrder(curr->right);
	}
}

void InOrder(Tree * curr)
{
	if(curr!=NULL)
	{
		InOrder(curr->left);
		printf("%d\t",curr->data);
		InOrder(curr->right);
	}
}

void PostOrder(Tree * curr)
{
	if(curr!=NULL)
	{
		PostOrder(curr->left);
		PostOrder(curr->right);
		printf("%d\t",curr->data);
	}
}

void InOrderTraverse(Tree *curr)
{
	Stack s;
	Tree *tmp;
	Push(&s,*curr);
	while(!StackEmpty(&s))
	{
		tmp=(Tree*)malloc(1*sizeof(Tree));
		while((tmp=s->top)&&tmp)
		{
			Push(&s,*(tmp->left));
			Pop(&s);
			if(!StackEmpty(&s))
			{
				tmp=s->top;
				Pop(&s);
				printf("%d\t",tmp->data);
				Push(&s,*(tmp->right));
			}
		}
	}
}
void PreOrder_Nonrecursive(Tree *curr)
{
	Stack s;
	Tree *tmp;
	Push(&s,*curr);
	while(!StackEmpty(&s))
	{
       while((tmp=s.top)&&tmp)
	   {
		   printf("%d\t",tmp->data);
		   Push(&s,*(tmp->left));
	   }
	   Pop(&s);
	   if(!StackEmpty(&s))
	   {
		   tmp=s.top;
		   Pop(&s);
		   Push(&s,*(tmp->right));
	   }
	}
}
int main(int argc, char *argv[])
{
	return 0;
}
