/*给定单链表头结点，删除链表中倒数第k个结点(要求时间复杂度最坏为(O(N)))*/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//定义节点类型
typedef struct node
{
    int sid;
    struct node * next;
}node;
//定义链表类型
typedef struct list
{
  node * ptr_heade;
  node * ptr_tail;
  node * ptr_move;
}list;
//初始化链表
void init_list(list * ptr_list)
{
    node * ptr_new=(node*)malloc(1*sizeof(node));
    assert(ptr_new!=NULL);
    ptr_new->next=NULL;
    ptr_list->ptr_heade=ptr_new;
    ptr_list->ptr_tail=ptr_new;
    ptr_list->ptr_move=ptr_new;
    ptr_new=NULL;
}
//新建节点
void append_list(list * ptr_list,int cnt)
{
  int i;
	node*  ptr_tmp_node=NULL;
	//创建节点病放入到链表中
	for(i=0;i<cnt;i++)
	{
       ptr_tmp_node=(node*)malloc(1*sizeof(node));
       assert(ptr_tmp_node!=NULL);
	   //初始化节点数据域和指针域
       ptr_tmp_node->sid=i+1;
       ptr_tmp_node->next=NULL;

       ptr_list->ptr_tail->next=ptr_tmp_node;
       ptr_list->ptr_tail=ptr_tmp_node;
	     ptr_tmp_node=NULL;
    }
}
//计算链表节点个数
int list_node(list * ptr_list)
{
    int i=0;
    ptr_list->ptr_move=ptr_list->ptr_heade->next;
    while(ptr_list->ptr_move!=NULL)
    {
      i=i+1;
      ptr_list->ptr_move=ptr_list->ptr_move->next;
    }
    return i;
}
//删除链表中倒数第k个结点(要求时间复杂度最坏为(O(N)))
void delete_list(list* ptr_list,int k)
{
    node * ptr1=NULL;
    node * ptr2=NULL;
    int i=list_node(ptr_list);
    int j;
    ptr_list->ptr_move=ptr_list->ptr_heade->next;
    if(k==6)//删除倒数第6个节点,需要放在循环里吗??
    {
        ptr_list->ptr_heade->next=ptr_list->ptr_move->next;
        free(ptr_list->ptr_move);
        ptr_list->ptr_move=NULL;
        return;
    }
    
    for(j=0;j<i;j++)
     {
        // if(k==6)//删除倒数第6个节点,需要放在循环里吗??
        // {
        //   ptr_list->ptr_heade->next=ptr_list->ptr_move->next;
        //   free(ptr_list->ptr_move);
        //   ptr_list->ptr_move=NULL;
        // }    
        if(j==(i-k))
        { 
          printf("2\n");
          ptr2=ptr_list->ptr_move;
          ptr1->next=ptr2->next; 
          free(ptr2);
          ptr2=NULL;
          break;
        }      
        // if(k==1)//这种情况不已经在上面包含了吗.是不是多此一举呀!
    // {
    //      printf("3");
    //      ptr2=ptr_list->ptr_move;
    //      ptr1->next=NULL;
    //      free(ptr2);
    //      ptr2=NULL;
    //      break;
    // }
        ptr1=ptr_list->ptr_move;
        //ptr_list->ptr_move=ptr_list->ptr_move;//看出来错没
        ptr_list->ptr_move=ptr_list->ptr_move->next;

     }
}
//输出链表节点数据值
void  print_list(list*  ptr_list)
{
	ptr_list->ptr_move=ptr_list->ptr_heade->next;
	while(ptr_list->ptr_move!=NULL)
	{
		printf("sid=%d\n",ptr_list->ptr_move->sid);
		ptr_list->ptr_move=ptr_list->ptr_move->next;
	}
}
//释放链表
void free_list(list * ptr_list)
{
    node * pnew=NULL;//new  变量名与关键字冲突,建议换个名字
    //ptr_list->ptr_move=ptr_list->ptr_heade->next;//这样赋值,是不是会少释放头节点
    ptr_list->ptr_move=ptr_list->ptr_heade;
    //while(new!=NULL)//请问这循环能进去吗?
    while(ptr_list->ptr_move!=NULL)
    {
        pnew=ptr_list->ptr_move;
        if(pnew==ptr_list->ptr_heade)
        {
            ptr_list->ptr_heade=NULL;
        }
        if(pnew==ptr_list->ptr_tail)
        {
            ptr_list->ptr_tail=NULL;
        }
        ptr_list->ptr_move=ptr_list->ptr_move->next;
        free(pnew);
        pnew=NULL;
    }
}

int main(int argc,const char * argv[])
{
    list list;
    int dest_sid;
    init_list(&list);
    append_list(&list,6);
    print_list(&list);
    scanf("%d",&dest_sid);
    delete_list(&list,dest_sid); 
    print_list(&list);
    printf("\n");
    free_list(&list);
    return 0;
}