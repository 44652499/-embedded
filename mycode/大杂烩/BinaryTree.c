#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree
{
	int value;
	struct BinaryTree *lchild;
	struct BinaryTree *rchild;
}BinaryTree;

BinaryTree*  createTreeNode(int _value)
{
	BinaryTree * treenode=NULL;
	treenode=(BinaryTree*)malloc(1*sizeof(BinaryTree));
	while(treenode==NULL)
	{
		treenode=(BinaryTree*)malloc(1*sizeof(BinaryTree));
	}
	treenode->value=_value;
	treenode->lchild=NULL;
	treenode->rchild=NULL;
	return treenode;
}

int  createTreeByInsertNode(BinaryTree ** binarytree,int  _value)
{
	if(binarytree==NULL)
		  return 0;
	if(*binarytree==NULL)
		{
			*binarytree=createTreeNode(_value);
			return 1;
		}
	else
		{
			if(_value<(*binarytree)->value)
				{
					return createTreeByInsertNode(&(*binarytree)->lchild,_value);
				}
			else if(_value>(*binarytree)->value)
				{
					return createTreeByInsertNode(&(*binarytree)->rchild,_value);
				}
			else
				return 0;
		}
		return 0;
}

BinaryTree* findTreeNodeByValue(BinaryTree * binarytree,int key)
{
	if(binarytree==NULL)
		return NULL;
	if(key==binarytree->value)
		return binarytree;
	if(key<binarytree->value)
		{
			return findTreeNodeByValue(binarytree->lchild,key);
		}
	else
		{
			return findTreeNodeByValue(binarytree->rchild,key);
		}
}

BinaryTree* findMinByKey(BinaryTree * binarytree)
{
	if(binarytree==NULL)
		return NULL;
	if(binarytree->lchild==NULL)
		return binarytree;
	return findMinByKey(binarytree->lchild);
}

//非递归实现
BinaryTree* findMaxByKey(BinaryTree * binarytree)
{
	if(binarytree!=NULL)
		{
			while(binarytree->rchild)
			{
				binarytree=binarytree->rchild;
			}
		}
	return binarytree;
}

int deleteNodeByKey(BinaryTree** binarytree,int key)
{
	BinaryTree * tmptree=NULL;
	if(binarytree==NULL && (*binarytree)==NULL)
		return 0;
	else if(key<(*binarytree)->value)
		{
			return deleteNodeByKey(&(*binarytree)->lchild,key);
		}
	else if(key>(*binarytree)->value)
		{
			return deleteNodeByKey(&(*binarytree)->rchild,key);
		}
	else if((*binarytree)->lchild && (*binarytree)->rchild)
		{
			tmptree=findMinByKey((*binarytree)->rchild);
			(*binarytree)->value=tmptree->value;
			return deleteNodeByKey(&(*binarytree)->rchild,(*binarytree)->value);
		}
	else 
		{
			if((*binarytree)->lchild && (*binarytree)->rchild==NULL)
		   {
			    tmptree=findMaxByKey((*binarytree)->lchild);
			    (*binarytree)->value=tmptree->value;
			    return deleteNodeByKey(&(*binarytree)->lchild,(*binarytree)->value);
		   }
		  else if((*binarytree)->lchild==NULL && (*binarytree)->rchild)
		   {
		   	  tmptree=findMinByKey((*binarytree)->rchild);
			    (*binarytree)->value=tmptree->value;
			    return deleteNodeByKey(&(*binarytree)->rchild,(*binarytree)->value);
		   }
		 else
		 	 {
		 	    free(*binarytree);	
		 	    *binarytree=NULL;
		 	 }
	  }
	  return 1;
}

//递归中序遍历
void  printInorder(BinaryTree* root)
{
	if(root!=NULL)
	{
     printInorder(root->lchild);
	   printf("%d\t",root->value);
	   printInorder(root->rchild);
	}
}

int main()
{
	BinaryTree *pBinaryTree = NULL;
	pBinaryTree = createTreeNode(6);
	createTreeByInsertNode(&pBinaryTree, 2);
	createTreeByInsertNode(&pBinaryTree, 8);
	createTreeByInsertNode(&pBinaryTree, 1);
	createTreeByInsertNode(&pBinaryTree, 4);
	createTreeByInsertNode(&pBinaryTree, 30);
	createTreeByInsertNode(&pBinaryTree, 10);
	createTreeByInsertNode(&pBinaryTree, 3);
	deleteNodeByKey(&pBinaryTree, 30);
	printInorder(pBinaryTree);
	return 0;
}
