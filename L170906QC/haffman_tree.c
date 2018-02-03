#include <stdio.h>
#include <stdlib.h>
/*
哈夫曼树:是一个有序查找树.符号左节点<=根节点  右节点<=根节点.与查找树区别主要是所有目标数节点作为树终端节点
哈夫曼树创建之后,可以给每个终端节点产生一个唯一二进制编码(0,1)
如: 终端节点存储值100,如果产生haffman树 生成一个编码值(0011).一般用haffman 编码值用来压缩或加密
构造haffman树,如何产生编码:
1.升序排列节点存储数
2.取最小的两个数作为树的终端节点,并将其和作为根节点
3.把根节点存储的值 放入到升序数组中
4.重复执行2 3 4步骤
左孩子编码为0,右孩子编码为1
从树根节点出发到达终端节点连接成一段二进制编码串
如何评估haffman树最优:
计算树权重值
weight=终端节点存储值*层次数 之和  
权重值最小haffman 树最优
*/
//定义树节点类型
typedef struct tree_node
{
    int data;
    struct tree_node * lchild;
    struct tree_node * rchild;
}tree_node;

//排序
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

//构建haffman树
tree_node *  init_haffman_tree(int *array,int len)
{
    sort_array(array,len);
    //定义一个指针数组,指向节点
    tree_node** ptr_array=(tree_node**)malloc(len*sizeof( tree_node*));

    //把待处理树生成节点;
    int i;
    tree_node* ptr_new;
    for(i=0;i<len;i++)
    {
       ptr_new=(tree_node*)malloc(1*sizeof(tree_node));
       ptr_new->data=array[i];
       ptr_new->lchild=NULL;
       ptr_new->rchild=NULL;
       //把节点地址保存到指针数组中
       ptr_array[i]=ptr_new;
       ptr_new=NULL;
    }
    //取指针数组中最小两个元素组成子树,并将子树根节点存入到数组中并保持升序.
    int  index=0;
    while(1)
    {
        //创建子树根节点
        ptr_new=(tree_node*)malloc(1*sizeof(tree_node));
        ptr_new->data=ptr_array[index]->data+ptr_array[index+1]->data;
        ptr_new->lchild=ptr_array[index];
        ptr_new->rchild=ptr_array[index+1];
        ptr_array[index]=NULL;
        ptr_array[index+1]=NULL;

        //子树根节点存入到数组中
        int  j=index+2;
        index++;
        if(index==len-1)
        {
            break;
        }
        while(ptr_new->data>ptr_array[j]->data)
        {
            ptr_array[j-1]=ptr_array[j];
            j++;
            if(j==len)
             break;
        }
        ptr_array[j-1]=ptr_new;   
    }
    return ptr_new;
}

//中序输出haffman树
void  print_mid_haffman_tree(tree_node*  root)
{
    if(root!=NULL)
    {
        print_mid_haffman_tree(root->lchild);
        printf("%d\t",root->data);
        print_mid_haffman_tree(root->rchild);
    }
}

//输出haffman编码
void  get_haffman_code(tree_node *  root,int len)
{
    static int code_array[10];
    if(root->lchild==NULL && root->rchild==NULL)
    {
        printf("%d:",root->data);
        int i;
        for(i=0;i<len;i++)
        {
            printf("%d",code_array[i]);
        }
        printf("\n");
    }
    else
    {
        code_array[len]=0;
        get_haffman_code(root->lchild,len+1);
        code_array[len]=1;
        get_haffman_code(root->rchild,len+1);
    }
}

//haffman　树权重值
int   get_haffman_weight(tree_node* root,int len)
{
    if(root->lchild==NULL && root->rchild==NULL)
    {
        return root->data*len;
    }
    else
    {
        return  get_haffman_weight(root->lchild,len+1)+ get_haffman_weight(root->rchild,len+1);
    }
}

int main(int argc,const char* argv[])
{
    int array[]={35,23,67,12,16,98,68,37,52,71};
    tree_node*  root=init_haffman_tree(array,10);
    print_mid_haffman_tree(root);
    printf("\n");
    get_haffman_code(root,0);
    printf("weight=%d\n",get_haffman_weight(root,0));
    return 0;
}
//了解haffman 编码实现文本文件压缩域解压原理？
