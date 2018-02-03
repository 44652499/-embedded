#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
/*
数据结构中特殊类型:
1.链表
2.栈
3.队列
4.树
5.图
链表:是顺序结构,由多个非连续节点组成.通过节点中指针连接相邻的节点
节点:组成链表元素,是一个结构体,由数据域和指针域组成
如果节点存存储一个指针称为单链表
如果节点存储两个指针称为双链表
操作链表是通常定义三个特殊指针指向三个节点:
1.指向链表头结点指针.一般用来标记链表起始地址值.不存储任何有效数据
2.指向链表当前访问节点指针.移动指针访问链表每个节点
3.指向链表新节点指针.
*/
//定义节点
typedef struct node
{
    int sid;
    char sname[10];
    struct node *  next;//单链表
}node;
//定义链表
typedef  struct list
{
    node*  ptr_head;
    node*  ptr_cur;
}list;

//初始化一个只有头节点链表
list*  init_list()
{
    list *  ptr_list=(list*)malloc(1*sizeof(list));
    if(ptr_list==NULL)
    {
        printf("init list fail\n");
        exit(-1);
    }
    ptr_list->ptr_head=NULL;
    ptr_list->ptr_cur=NULL;

    node*  ptr_new=(node*)malloc(1*sizeof(node));
    if(ptr_new==NULL)
    {
        printf("init head node fail\n");
        exit(-1);
    }
    ptr_new->next=NULL;


    ptr_list->ptr_head=ptr_new;
    ptr_list->ptr_cur=ptr_new;
    ptr_new=NULL;
    return ptr_list;
}
//在链表末尾追加节点
void  list_append(list* ptr_list,int num)
{
    int i;
    node * ptr_new=NULL;
    for(i=0;i<num;i++)
    {
        ptr_new=(node*)malloc(1*sizeof(node));
        ptr_new->sid=i+1;        
        sprintf(ptr_new->sname,"student%d",i+1);
        ptr_new->next=NULL;
        if(ptr_list->ptr_head->next==NULL)
        {
            ptr_list->ptr_head->next=ptr_new;           
        }
        else
        {
            ptr_list->ptr_cur->next=ptr_new;           
        }  
        ptr_list->ptr_cur=ptr_new;   
        ptr_new=NULL;   
    }
}

//在链表插入新节点(根据dest_sid 找到目标节点并将新节点插入到前面,否则插入到链表末尾)
void   list_insert(list *  ptr_list,int dest_sid,int src_sid)
{
        node * ptr_new=(node*)malloc(1*sizeof(node));
        ptr_new->sid=src_sid;
        sprintf(ptr_new->sname,"student%d",src_sid);
        ptr_new->next=NULL;
        node*  ptr_pre=NULL;
        node * ptr_move=ptr_list->ptr_head->next;
        int is_find=0;
        while(ptr_move!=NULL)
        {
            if(ptr_move->sid==dest_sid)
            {
                is_find=1;
                if(ptr_move==ptr_list->ptr_head->next)
                {
                    ptr_new->next=ptr_move;
                    ptr_list->ptr_head->next=ptr_new;
                }
                else
                {
                    ptr_pre->next=ptr_new;
                    ptr_new->next=ptr_move;
                }
                break;
            }
            else
            {
                ptr_pre=ptr_move;
            }
            ptr_move=ptr_move->next;
        }  
        if(is_find==0)
        {
            ptr_list->ptr_cur->next=ptr_new;
            ptr_list->ptr_cur=ptr_new;
        }
        ptr_new=NULL;      
}
//删除节点
void  list_delete(list*  ptr_list,int dest_sid)
{
    node* ptr_move=ptr_list->ptr_head->next;
    node * ptr_pre=NULL;
    while(ptr_move!=NULL)
    {
        if(ptr_move->sid==dest_sid)
        {
            if(ptr_move==ptr_list->ptr_head->next)
            {
                ptr_list->ptr_head->next=ptr_move->next;               
            }
            else
            {
                if(ptr_move==ptr_list->ptr_cur)
                {
                    ptr_list->ptr_cur=ptr_pre;
                    ptr_pre->next=NULL;
                }
                else
                {
                    ptr_pre->next=ptr_move->next;
                    ptr_move->next=NULL;
                }                
            }
            free(ptr_move);
            ptr_move=NULL;
            break;
        }
        else
        {
            ptr_pre=ptr_move;
        }
        ptr_move=ptr_move->next;
    }
}

//输出链表节点值
void  list_print(list*  ptr_list)
{
    node*  ptr_move=ptr_list->ptr_head->next;
    while(ptr_move!=NULL)
    {
        printf("%d\t%s\n",ptr_move->sid,ptr_move->sname);
        ptr_move=ptr_move->next;
    }
}
//链表排序
void list_sort(list * ptr_list)
{
    node*  ptr_move=ptr_list->ptr_head->next;
    node*  ptr_tmp1;
    node*  ptr_tmp2;
    while(ptr_move!=NULL)
    {
        ptr_tmp1=ptr_move;
        while(ptr_tmp1->next!=NULL)
        {
            ptr_tmp2=ptr_tmp1->next;
            if(ptr_tmp1->sid>ptr_tmp2->sid)
            {
                int sid=ptr_tmp1->sid;
                ptr_tmp1->sid=ptr_tmp2->sid;
                ptr_tmp2->sid=sid;

                char sname[10];
                strcpy(sname,ptr_tmp1->sname);
                strcpy(ptr_tmp1->sname,ptr_tmp2->sname);
                strcpy(ptr_tmp2->sname,sname);
            }
            ptr_tmp1=ptr_tmp2;
            ptr_tmp2=ptr_tmp1->next;
        }
        ptr_move=ptr_move->next;
    }
}

//释放链表及其节点
void  list_free(list*  ptr_list)
{
    node*  ptr_move=ptr_list->ptr_head->next;
    ptr_list->ptr_head->next=NULL;
    ptr_list->ptr_cur=NULL;
    node*  ptr_tmp=NULL;
    while(ptr_move!=NULL)
    {
        ptr_tmp=ptr_move;
        ptr_move=ptr_move->next;
        free(ptr_tmp);
        ptr_tmp=NULL;
    }
    free(ptr_list->ptr_head);
    ptr_list->ptr_head=NULL;
    free(ptr_list);
    ptr_list=NULL;
}

int main(int argc, char const *argv[])
{
    list *  ptr_list=init_list();
    list_append(ptr_list,10);
    list_insert(ptr_list,1,20);
    list_insert(ptr_list,3,15);
    list_insert(ptr_list,10,12);
    list_insert(ptr_list,13,13);
    // list_delete(ptr_list,20);
    // list_delete(ptr_list,10);
    // list_delete(ptr_list,13);
    // list_delete(ptr_list,114);
    list_sort(ptr_list);
    list_print(ptr_list);
    list_free(ptr_list);
    return 0;
}

//把上面的单链表改成双链表
//把上面的单链表改成循环单链表
//把上面的单链表改成循环双链表