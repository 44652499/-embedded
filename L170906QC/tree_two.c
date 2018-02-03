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

//定义树结构


//定义栈节点
typedef struct node
{
    tree_node*  ptr_node;
    struct node * next;
}node;

//定义栈
typedef struct stack
{
    node * top;
    int size;//当前栈节点个数
    int capacity;//限制栈存储最大节点数
}stack;
//初始化栈
void  init_stack(stack * ptr_stack)
{
    ptr_stack->top=NULL;
    ptr_stack->size=0;
    ptr_stack->capacity=MAX_SIZE;
}
//进栈
void  push_stack(stack * ptr_stack,tree_node* ptr_node)
{
    if(!is_stack_full(ptr_stack))
    {
        node*  ptr_new=(node*)malloc(1*sizeof(node));
        ptr_new->ptr_node=ptr_node;
        ptr_new->next=NULL;
    
        //入栈
        ptr_new->next=ptr_stack->top;
        ptr_stack->top=ptr_new;
        ptr_stack->size++;
        ptr_new=NULL;
    }
    else
    {
        printf("stack is full\n");
    }    
}
//出栈
void  pop_stack(stack * ptr_stack)
{
    if(!is_stack_empty(ptr_stack))
    {
        node*  ptr_tmp=ptr_stack->top;
        ptr_stack->top=ptr_stack->top->next;
        ptr_stack->size--;        
   
        free(ptr_tmp);
        ptr_tmp=NULL;
    }
    else
    {
        printf("stack is empty\n");
    }
}
//栈是否满
int  is_stack_full(stack * ptr_stack)
{
    if(ptr_stack->size>ptr_stack->capacity)
    {
        return 1;
    }
    return 0;
}
//栈是否为空
int  is_stack_empty(stack *  ptr_stack)
{
    if(ptr_stack->size==0)
    {
        return 1;
    }
    return 0;
}
//返回栈顶节点
tree_node*  get_stack_top(stack* ptr_stack)
{
    if(!is_stack_empty(ptr_stack))
    {
        return  ptr_stack->top->ptr_node;
    }
    return NULL;
}
//返回栈的节点个数
int get_stack_cnt(stack* ptr_stack)
{
    return  ptr_stack->size;
}

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

//非递归前序遍历
void   print_pre_tree(tree_node*  root)
{
    stack st;
    init_stack(&st);
    while(root!=NULL || !is_stack_empty(&st))
    {
        while(root!=NULL)
        {
            printf("%c\t",root->value);
            push_stack(&st,root);
            root=root->lchild;
        }
        if(!is_stack_empty(&st))
        {
            root=get_stack_top(&st);
            pop_stack(&st);
            root=root->rchild;
        }
    }
}

//非递归中序
void   print_mid_tree(tree_node * root)
{
    stack st;
    init_stack(&st);
    while(root!=NULL || !is_stack_empty(&st))
    {
        while(root!=NULL)
        {           
            push_stack(&st,root);
            root=root->lchild;
        }
        if(!is_stack_empty(&st))
        {
            root=get_stack_top(&st);
            printf("%c\t",root->value);
            pop_stack(&st);
            root=root->rchild;
        }
    }
}


int main(int argc, char const *argv[])
{
    tree_node* root=init_binary_tree();
    print_pre_tree(root);
    printf("\n");
    print_mid_tree(root);
    printf("\n");
   // print_last_tree(root);
    printf("\n");
    return 0;
}