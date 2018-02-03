//创造一个排序二叉树
#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int item;
	struct tree *lchild;
	struct tree *rchild;
}tree;

void create_bstree(tree ** t,int value)
{
	if(*t==NULL)
		{
			*t=(tree*)malloc(1*sizeof(tree));
			(*t)->item=value;
			(*t)->lchild=NULL;
			(*t)->rchild=NULL;
			}
	else
		{
			if((*t)->item>value)
				{
					create_bstree(&(*t)->lchild,value);
					}
			else
				{
					create_bstree(&(*t)->rchild,value);
					}
			}
}

void  printtree(tree* t)
{
	if(t==NULL)
		return;
	else
		{
			printtree(t->lchild);
			printf("%d\t",t->item);
			printtree(t->rchild);
		}
	}

int main()
{
	int i;
	tree *t=NULL;
	int value[]={5,8,14,36,21,1,3};
	for(i=0;i<7;i++)
	{
		create_bstree(&t,value[i]);
	}
	printtree(t);
	printf("\n");
	return 0;
}