#include <stdio.h>
#include <stdlib.h>
/*
查找树:根据树节点存储值排序,成为有序树.根据目标值与根节点比较.如果小于根节点,则比较右子树,如果大于根节点,则比较左子树.等根节点查找成功
有序树必须满足下面两个条件:
1.右节点值大于根节点值
2.左节点值小于根节点值
3.根据中序遍历  输出一个有序集合

注意构建二叉树时,防止出现特殊只有左 或右孩子二叉树
(AVL)平衡二叉树

堆排序:根据二叉树结构排序(不会构建二叉树),根据下标值域树节点关系处理
下标值为n=1,根据公式计算出右孩子下标值为:2*n  左孩子下标值为:2*n+1
堆排序分为大堆和小堆:
大堆:树根节点大于左 孩子 右孩子节点值
小堆:树根节点小于左 孩子 右孩子节点值
*/

typedef struct tree_node
{
    int   value;
    struct  tree_node* lchild;
    struct  tree_node* rchild;
}tree_node;

//计算待排序数平均值,作为构建树的根
int  get_array_avg(int *array,int len)
{
    int  sum=0;
    int i;
    for(i=0;i<len;i++)
    {
        sum=sum+array[i];
    }
    return sum/len;
}

//构建树节点函数
tree_node*  init_tree_node(int  value)
{
   tree_node * ptr_new=(tree_node*)malloc(1*sizeof(tree_node));
   ptr_new->value=value;
   ptr_new->lchild=NULL;
   ptr_new->rchild=NULL;
   return ptr_new;
}

//构建有序树
tree_node * build_sort_tree(tree_node * root,tree_node* ptr_new)
{
    if(root==NULL)
    {
        root=ptr_new;
        return root;
    }
    if(root->lchild==NULL && root->value>ptr_new->value)
    {
        root->lchild=ptr_new;
        return root;
    }
    if(root->rchild==NULL &&  root->value<ptr_new->value)
    {
        root->rchild=ptr_new;
        return root;
    }
    if(root->lchild!=NULL &&  root->value>ptr_new->value)
    {
        build_sort_tree(root->lchild,ptr_new);
    }
    if(root->rchild!=NULL &&  root->value<ptr_new->value)
    {
        build_sort_tree(root->rchild,ptr_new);
    }
}

//初始化有序二叉树
tree_node *  init_sort_tree(int * array,int len)
{
    int avg=get_array_avg(array,len);
    tree_node * root=init_tree_node(avg);
    int i;
    for(i=0;i<len;i++)
    {
        tree_node * ptr_new=init_tree_node(array[i]);
        build_sort_tree(root,ptr_new);
    }
    return root;
}

//递归中序输出
void   print_mid_tree(tree_node * root)
{
    if(root!=NULL)
    {
        print_mid_tree(root->lchild);
        printf("%d\n",root->value);
        print_mid_tree(root->rchild);
    }
}

int main(int argc, char const *argv[])
{
    int array[]={21,23,14,1,78,90,25,76};
    tree_node* root=init_sort_tree(array,8);
    print_mid_tree(root);
    printf("\n");
}