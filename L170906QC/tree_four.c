#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
/*
树:树是一种自定义结构.由n(n>0)个节点组成,有且只有一个节点作为树根.n-1个节点组成一个子树.树是一种递归定义.
节点为0的树称为空树
树节点由存储数据和指向其子树指针(n>=1)
树最大特点控制目标数比较次数,可以实现在O(logn a ,n>=1).提高搜索效率
树是一个无环的图
树名词:
1.子节点:节点指向一个个子树,子树的根称为子节点
2.终端节点(叶子节点):没有任何子树的节点,一般是树对下层节点
3.节点度:节点存在子树个数(一般为 0 1 2 3 ...)
4.树广度:节点度最大值
5.树深度:从树根到终端节点的最大层次数
有树度不定,导致程序中不好去定义一个通用树节点类型.一般我们使用二叉树
二叉树:树广度为2(节点最大度为2)
左孩子:节点左边的子树
右孩子:节点右边的子树
一般存在下面5种形式的二叉树:
1.空二叉树
2.只一个根节点
3.全左
4.全右
5.根左右
二叉树属性:
1.非空二叉树的第n层最大节点数是:2^(n-1)(n>=1 第几层)
2.非空二叉树树最大的节点树是:2^n-1(n>=1 树层次树)
3.完全二叉树:树的节点度可以是0,1,2.如果树的节点度为1,优先存在左子树.(树存在节点编号与对应满二叉树节点编号一致)
4.满二叉树:树的节点度只能是0 或2,满二叉树是一个完全二叉树
5.如果一个二叉树存在度为2节点数是n2,度为1节点数是n1,度为0节点数为n0,n2 n1 n0存在一个怎样关系?
n0=n2+1
树总结点数:n2+n1+n0  =       2*n2+n1+1 --> n0=n2+1

访问二叉树三种方式:
1.前序遍历:根 左  右
2.中序遍历:左 根  右
3.后续遍历:左 右  根
*/
//定义树的节点
typedef struct tree_node
{
    char value;
    //struct  node* parent;
    struct  tree_node* lchild;
    struct  tree_node* rchild;
}tree_node;

//定义队列节点
typedef struct  node
{
    tree_node* ptr_node;
    struct node * next;
}node;

//定义队列
typedef struct queue
{
    node* front;
    node* tail;
    int size;
    int capacity;
}queue;
//初始化队列
void  init_queue(queue *  ptr_queue)
{
    ptr_queue->front=ptr_queue->tail=NULL;
    ptr_queue->size=0;
    ptr_queue->capacity=MAX_SIZE;
}
//入队
void   push_queue(queue*  ptr_queue,tree_node *  ptr_node)
{
    if(!is_queue_full(ptr_queue))
    {
        node * ptr_new=(node*)malloc(1*sizeof(node));
        ptr_new->ptr_node=ptr_node;
        ptr_new->next=NULL;
    
        if(ptr_queue->front==NULL)
        {
            ptr_queue->front=ptr_new;      
        }
        else
        {
            ptr_queue->tail->next=ptr_new;
        }
        ptr_queue->size++;
        ptr_queue->tail=ptr_new;
        ptr_new=NULL;
    }
    else
    {
        printf("queue is full\n");
    }   
}
//出队
void  pop_queue(queue * ptr_queue)
{
    if(!is_queue_empty(ptr_queue))
    {
        node *  ptr_tmp=ptr_queue->front;
        ptr_queue->front=ptr_queue->front->next;
        if(ptr_queue->front==NULL)
        {
            ptr_queue->tail=NULL;
        }
        ptr_queue->size--;
        free(ptr_tmp);
        ptr_tmp=NULL;
    }
    else
    {
        printf("queue is empty\n");
    }
}

//队列是否满
int  is_queue_full(queue*  ptr_queue)
{
    if(ptr_queue->size>ptr_queue->capacity)
    {
        return 1;
    }
    return 0;
}
//队列是否空
int   is_queue_empty(queue*  ptr_queue)
{
    if(ptr_queue->front==NULL &&  ptr_queue->tail==NULL)
    {
        return 1;
    }
    return 0;
}
//返回队列元素个数
int   get_queue_cnt(queue * ptr_queue)
{
    return  ptr_queue->size;
}
//返回队首
tree_node*  get_queue_front(queue * ptr_queue)
{
    if(!is_queue_empty(ptr_queue))
    {
        return  ptr_queue->front->ptr_node;
    }
    return NULL;
}
//返回队尾
tree_node*   get_queue_tail(queue*  ptr_queue)
{
    if(!is_queue_empty(ptr_queue))
    {
        return  ptr_queue->tail->ptr_node;
    }
    return NULL;
}


//定义树结构

//构建一个树
tree_node*  init_binary_tree()
{
    char value;
    scanf("%c",&value);
    getchar();
    tree_node* root;
    if(value=='q')//'q输入结束字符'
    {
        root=NULL;
    }
    else
    {
        root=(tree_node*)malloc(1*sizeof(tree_node));
        root->value=value;
        root->lchild=init_binary_tree();
        root->rchild=init_binary_tree();
    }
    return root;    
}



//树广度遍历:从根开始访问,按照根节点左右顺序访问.每次把同层节点左右孩子访问完毕.再访问下一层
void  print_broadcast_tree(tree_node  * root)
{
    queue  qu;
    init_queue(&qu);
    //if 语句合并到while语句中
    if(root!=NULL)
    {
        push_queue(&qu,root);
    }
    while(root!=NULL ||  !is_queue_empty(&qu))
    {        
        root=get_queue_front(&qu);
        printf("%c\t",root->value);
        pop_queue(&qu);
        if(root->lchild!=NULL)
        {
            push_queue(&qu,root->lchild);
        }
        if(root->rchild!=NULL)
        {
            push_queue(&qu,root->rchild);
        }        
        root=NULL;
    }
}


int main(int argc, char const *argv[])
{
    tree_node* root=init_binary_tree();
    print_broadcast_tree(root);
    printf("\n");
    return 0;
}