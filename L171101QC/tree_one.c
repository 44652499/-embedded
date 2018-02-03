#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
树(tree):是一种非线性结构.是一种递归的定义.
1.树(Tree)的概念:树是一种递归定义的数据结构,是一种重要的非线性数据结构.树可以是一棵空树,它没有任何的结点;也可以是一棵非空树,至少含有一个结点
2.根(Root):有且仅有一个结点的非空树,那个结点就是根
3.子树(Subtree):在一棵非空树中,除根外,其余所有结点可以分为m(m>=0)个互不相交的集合.每个集合本身又是一棵树,称为根的子树
一般使用的是二叉树.限制每个节点拥有子树最多不能超过2.否则程序无法访问树的每个节点
二叉树:树的每个节点最多只有两个子节点,一个称为左孩子,一个称为右孩子
树个概念:
节点度:节点存在子节点数
叶子节点:节点度大于0,又是另一个节点子节点
终端节点:节点度为0,一般数子树最底层节点
树度(广度)最大节点度值
树深度从树根到树的终端节点最长的路径数
如果存在3个节点可以组成几不同二叉树:
1.6个二叉树(空树是一种特殊二叉树)
满二叉树:除开终端节点,其它节点度都为2,左孩子节点编号为2*n,右孩子节点编号为2*n+1(n>=1)
完全二叉树:是一个非满二叉树,除开终端节点外,必定存在一个叶子节点度小于2,其存在节点编号必定与对应满二叉树的节点编号一直
二叉树几个重要的属性:
1.二叉树访问某个节点的时间复杂度位log2 n
2.如果存在一个深度为K二叉树,其最大的节点数为:2^n-1
3.如果存在一个深度为K二叉树,其第k层存在的最大的节点数为:2^(n-1);
4.如果一个二叉树存在度为0 节点n0,度为1 节点n1 度为2的节点n2,n0 n2存在怎样关系
  n0=n2+1(二叉树总节点数=n0+n1+n2  = 另一种求法:2*n2+n1+1) 
二叉树节点访问三种方式:
1.前序遍历:根节点  左节点 右节点
2.中序遍历:左节点  根节点  右节点
3.后序遍历: 左节点  右节点 根节点

二叉树节点定义:
typedef struct node
{
	数据域;
	struct node * lchild;
	struct node * rchild;
	struct node * parent;
};
*/

//定义二叉树节点
typedef  struct node
{
	char  value;
	struct  node* lchild;
	struct  node* rchild;
}node;
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
//二叉树递归前序遍历
void  print_binary_tree_pre(node* root)
{
	if(root!=NULL)
	{
		printf("%c\t",root->value);
		print_binary_tree_pre(root->lchild);
		print_binary_tree_pre(root->rchild);
	}	
}
//二叉树递归中序遍历
void  print_binary_tree_mid(node* root)
{
	if(root!=NULL)
	{		
		print_binary_tree_mid(root->lchild);
		printf("%c\t",root->value);
		print_binary_tree_mid(root->rchild);
	}	
}
//二叉树递归后序遍历
void  print_binary_tree_last(node* root)
{
	if(root!=NULL)
	{		
		print_binary_tree_last(root->lchild);		
		print_binary_tree_last(root->rchild);
		printf("%c\t",root->value);
	}	
}


int main(int argc, char const *argv[])
{
	node* root=init_binary_tree();
	print_binary_tree_pre(root);
	printf("\n");
	print_binary_tree_mid(root);
	printf("\n");
	print_binary_tree_last(root);
	printf("\n");
	return 0;
}