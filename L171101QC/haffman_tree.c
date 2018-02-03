#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
哈弗曼树(haffman):所有待处理数作为树的终端节点,其父节点为最小两个节点值之和
创建haffman 树目的是为了产生唯一haffman编码值:
左节点用0表示,右节点用1表示.所有待处理数都对应一个唯一二进制编码值
哈弗曼树优点:
1.减少实际数据传输/存储大小
2.传输存储的是二进制编码,非实际数.(类似于密文)
创建haffman树步骤:
1.对待处理数排序
2.选出最小的两个数并求出其和.构建一个子二叉树.将和放入待处理数中
3.重复完成第1 2 步
构建haffman树时根节点值大于左右节点值,左节点值小于右节点
哈弗曼树权重值:哈弗曼树终端节点值与其二进制编码长度相乘之和.
权重值越小哈弗曼树最优
*/

//定义树节点
typedef struct node
{
	int value;
	struct node *lchild;
	struct node *rchild;
}node;
//创建节点
node*  init_node(int _value)
{
	node*  ptrnewnode=(node*)malloc(1*sizeof(node));
	assert(ptrnewnode!=NULL);
	ptrnewnode->value=_value;
	ptrnewnode->lchild=NULL;
	ptrnewnode->rchild=NULL;
}
//排序待处理数据
void  sort_array(int *array,int len)
{
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				int tmp=array[j];
				array[j]=array[j+1];
				array[j+1]=tmp;
			}
		}
	}
}
//把有序待处理数构建节点并放入一个节点数中
node**  save_point_array(int *array,int len)
{
	sort_array(array,len);
	node ** ptrarray=(node**)malloc(len*sizeof(node*));
	assert(ptrarray!=NULL);
	int i;
	for(i=0;i<len;i++)
	{
		node* ptrnewnode=init_node(array[i]);
		ptrarray[i]=ptrnewnode;
	}
	return ptrarray;
}

//创建haffman树
node*  init_haffman_tree(node** ptrarray,int len)
{
  int i=0;
  int j=0;
  node* ptrnewnode=NULL;
  while(1)
  {
  	 int value=ptrarray[i]->value+ptrarray[i+1]->value;
     ptrnewnode=init_node(value);
     ptrnewnode->lchild=ptrarray[i];
     ptrnewnode->rchild=ptrarray[i+1];
     ptrarray[i]=NULL;
     ptrarray[i+1]=NULL;
     j=i+2;
     if(j==len)
     {
     	return ptrnewnode;
     }
     while(j<len && ptrarray[j]->value<ptrnewnode->value )
     {
     	ptrarray[j-1]=ptrarray[j];
     	j++;
     }
     ptrarray[j-1]=ptrnewnode;  
     i++;	 
  }
}

//输出haffman树编码值
void  print_haffman_code(node * root,int len)
{
	static  int codearray[20];//静态全局变量,递归时共享
	if(root->lchild==NULL && root->rchild==NULL)
	{
		printf("%d code:",root->value);
		int i;
		for(i=0;i<len;i++)
		{
			printf("%d",codearray[i]);
		}
		printf("\n");
	}
	else
	{
		codearray[len]=0;
		print_haffman_code(root->lchild,len+1);
		codearray[len]=1;
		print_haffman_code(root->rchild,len+1);
	}
}

//计算haffman权重值
int  get_haffman_weight(node * root,int len)
{
	if(root->lchild==NULL && root->rchild==NULL)
	{
		return root->value*len;
	}
	else
	{
		return get_haffman_weight(root->lchild,len+1)+
		get_haffman_weight(root->rchild,len+1);
	}
}

//输出haffman树
void  print_haffman_tree(node * root)
{
	if(root!=NULL)
	{
		print_haffman_tree(root->lchild);
		printf("%d\t",root->value);
		print_haffman_tree(root->rchild);
	}
}



int main(int argc, char const *argv[])
{
	int array[]={6,40,9,13,18,90,32,73};
	node** ptrarray=save_point_array(array,8);
	node* root=init_haffman_tree(ptrarray,8);
	//print_haffman_tree(root);
	print_haffman_code(root,0);
	printf("\n");
	int weight=get_haffman_weight(root,0);
	printf("weight=%d\n",weight);
	return 0;
}