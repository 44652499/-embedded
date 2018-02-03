#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
查找树:二叉树节点排列有序,方便快速查找.左孩子节点必须小于根节点,右孩子节点必须大于根节点
1.lchild 值  <=根节点
2.rchild 值  >=根节点
如果对以上树按照中序遍历,输出一个升序序列
创建查找树,树根节点选择很重要,否则就会出现全是左子树,或全是右子树,实际就是一个链表,查找时是时间复杂度o(n).如果根节点选择合适,左右子树的深度尽量均衡,查找时间复杂度O(log2 n).
AVL(平衡二叉树):是一种查找树,要求左右子树深度相差的绝对不能超过1.一般是通过旋转实现调整平衡.
旋转二叉树一般分为:
1.左旋转
2.右旋转
RBtree(红黑树):是一种特殊平衡二叉树.节点分为红色和黑色.判断红黑树必须满足5个条件

堆排序:把待排序的元素按照查找二叉树存储,单堆排序不需要构建树.根据数组下标值访问.如果下标值为n,其对应左节点下标值为2*n,其对应右节点下标值为2*n+1.
堆排序分为大堆和小堆:
大堆:最大的元素作为树根
小堆:最小的元素作为树根
王琦礼拜六讲堆排序(大堆排序),时间复杂度?
*/
//定义二叉树节点类型
typedef struct node
{
	int data;
	struct node * lchild;
	struct node * rchild;
}node;
//获取待排序数的平均值,作为查找树根节点
int  get_avg(int *array,int len)
{
	int sum=0;
	int i;
	for(i=0;i<len;i++)
	{
		sum+=array[i];
	}
	return sum/len;
}
//构造树节点函数
node*  init_tree_node(int value)
{
	node*  ptrnewnode=(node*)malloc(1*sizeof(node));
	assert(ptrnewnode!=NULL);
	ptrnewnode->data=value;
	ptrnewnode->lchild=NULL;
	ptrnewnode->rchild=NULL;
	return ptrnewnode;
}


//构造查找二叉树
node *  init_find_tree(node* root,node* ptrnewnode)
{
	if(root==NULL)
	{
		root=ptrnewnode;
		return root;
	}
	if(root->lchild==NULL&&root->data>=ptrnewnode->data)
	{
		root->lchild=ptrnewnode;
		return root;
	}
	if(root->rchild==NULL && root->data<ptrnewnode->data)
	{
		root->rchild=ptrnewnode;
		return root;
	}
	if(root->lchild!=NULL&&root->data>=ptrnewnode->data)
	{
		init_find_tree(root->lchild,ptrnewnode);
	}
	if(root->rchild!=NULL && root->data<ptrnewnode->data)
	{
		init_find_tree(root->rchild,ptrnewnode);
	}
}
//创建查找二叉树
node*  create_binary_find_tree(int * array,int len)
{
	int avg=get_avg(array,len);
	node*  ptrnewnode=init_tree_node(avg);
	assert(ptrnewnode!=NULL);
	node * root=NULL;
	root=init_find_tree(root,ptrnewnode);
	int i=0;
	for(i=0;i<len;i++)
	{
		ptrnewnode=init_tree_node(array[i]);
		init_find_tree(root,ptrnewnode);
	}
	return root;
}
//递归中序输出二叉树
void  print_tree_mid(node* root)
{
	if(root!=NULL)
	{
		print_tree_mid(root->lchild);
		printf("%d\t",root->data);
		print_tree_mid(root->rchild);
	}
}
int main(int argc, char const *argv[])
{
	int array[]={6,40,9,13,18,90,32,73};
	node* root=create_binary_find_tree(array,8);
	print_tree_mid(root);
	printf("\n");
	return 0;
}