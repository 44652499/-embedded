#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*
循环单链表：首尾相连的单链表
*/
//定义节点类型
typedef struct node
{
	int sid;
	char sname[20];
	char sex;
	struct node * next;
}node; 
//定义链表类型
typedef struct list
{
	node *  ptr_head; //指向链表头节点指针
	node *  ptr_tail; //指向链表尾节点指针
	node *  ptr_move; //移动指针
}list;

//初始化链表
void  init_list(list * ptr_list)
{
	//创建头节点固定链表位置
	node* ptr_new_node=(node*)malloc(1*sizeof(node));
	assert(ptr_new_node!=NULL);
	ptr_new_node->next=NULL;
	ptr_list->ptr_head=ptr_new_node;
	ptr_list->ptr_tail=ptr_new_node;
	ptr_list->ptr_move=ptr_new_node;
	ptr_new_node=NULL;
}
//链表插入10个新节点
void  append_list(list* ptr_list,int cnt)
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
       sprintf(ptr_tmp_node->sname,"student%d",i+1);
       if(i%2==0)
       {
       	ptr_tmp_node->sex='f';
       }
       else
       {
       	ptr_tmp_node->sex='m';
       }
       ptr_list->ptr_tail->next=ptr_tmp_node;
       ptr_list->ptr_tail=ptr_tmp_node;
       ptr_tmp_node=NULL;
	}
	ptr_list->ptr_tail->next=ptr_list->ptr_head;
}
//前面插入新节点
void insert_list(list* ptr_list,int dest_sid)
{
	node*  ptr_tmp_node=NULL;
	//创建新节点
	node*  ptr_new_node=(node*)malloc(1*sizeof(node));
	assert(ptr_new_node!=NULL);
	//初始化新节点
	ptr_new_node->sid=30;
	strcpy(ptr_new_node->sname,"sssss");
	ptr_new_node->next=NULL;
	ptr_list->ptr_move=ptr_list->ptr_head->next;
	while(ptr_list->ptr_move!=ptr_list->ptr_head)
	{
		if(ptr_list->ptr_move->sid==dest_sid)
		{			
			//如果找的是第一个节点
			if(ptr_list->ptr_head->next==ptr_list->ptr_move)
			{
				ptr_list->ptr_head->next=ptr_new_node;
				ptr_new_node->next=ptr_list->ptr_move;
			}
			else if(ptr_list->ptr_move==ptr_list->ptr_tail)
			{
				ptr_tmp_node->next=ptr_new_node;
				ptr_new_node->next=ptr_list->ptr_tail;
				ptr_list->ptr_tail=ptr_new_node;
			}
			else 
			{
				ptr_tmp_node->next=ptr_new_node;
				ptr_new_node->next=ptr_list->ptr_move;
			}			
			ptr_new_node=NULL;
			break;
		}
		else
		{
			//记录前一个节点
			ptr_tmp_node=ptr_list->ptr_move;
		}
		ptr_list->ptr_move=ptr_list->ptr_move->next;
	}
	//如果所有链表节点都不匹配
	if(ptr_tmp_node==ptr_list->ptr_tail)
	{
		ptr_list->ptr_tail->next=ptr_new_node;
		ptr_list->ptr_tail=ptr_new_node;
		ptr_list->ptr_tail->next=ptr_list->ptr_head;
		ptr_new_node=NULL;
	}	
}

//链表排序：使用节点一个数据域按照升序或降序
void  sort_list(list* ptr_list)
{
	node*  p1;
	node*  p2;
	ptr_list->ptr_move=ptr_list->ptr_head->next;
	p2=ptr_list->ptr_move;
	while(p2!=ptr_list->ptr_head)
	{		
		p1=p2->next;
		while(p1!=ptr_list->ptr_head)
	    {			
			if(p2->sid>p1->sid)
			{
				//交换节点
			    node tmp;
				tmp.sid=p2->sid;
				strcpy(tmp.sname,p2->sname);
				tmp.sex=p2->sex;

				p2->sid=p1->sid;
				strcpy(p2->sname,p1->sname);
				p2->sex=p1->sex;
    
            	p1->sid=tmp.sid;
            	strcpy(p1->sname,tmp.sname);
            	p1->sex=tmp.sex;
			}
			p1=p1->next;
		}		
		p2=p2->next;
	}		
}
//输出链表节点数据值
void  print_list(list*  ptr_list)
{
	ptr_list->ptr_move=ptr_list->ptr_head->next;
	while(ptr_list->ptr_move!=ptr_list->ptr_head)
	{
		printf("sid=%d\tname=%s\tsex=%c\n",ptr_list->ptr_move->sid,ptr_list->ptr_move->sname,ptr_list->ptr_move->sex);
		ptr_list->ptr_move=ptr_list->ptr_move->next;
	}
}
//删除指定的节点
void  delete_list(list* ptr_list,int dest_sid)
{
	ptr_list->ptr_move=ptr_list->ptr_head->next;
	node* ptr_tmp_node=NULL;
	while(ptr_list->ptr_move!=ptr_list->ptr_head)
	{
		if(ptr_list->ptr_move->sid==dest_sid)
		{
			if(ptr_list->ptr_head->next==ptr_list->ptr_move)
			{
				ptr_list->ptr_head->next=ptr_list->ptr_move->next;				
			}
			else if(ptr_list->ptr_tail==ptr_list->ptr_move)
			{
				ptr_tmp_node->next=ptr_list->ptr_head;
				ptr_list->ptr_tail=ptr_tmp_node;
				ptr_tmp_node=NULL;
			}
			else 
			{
				ptr_tmp_node->next=ptr_list->ptr_move->next;
			}
			free(ptr_list->ptr_move);
			ptr_list->ptr_move=NULL;
			break;
		}
		else
		{
			ptr_tmp_node=ptr_list->ptr_move;
		}
		ptr_list->ptr_move=ptr_list->ptr_move->next;
	}
	if(ptr_tmp_node==ptr_list->ptr_tail)
	{
		printf("not found\n");
	}
}

//释放链表
void  free_list(list* ptr_list)
{
	node* ptr_tmp=NULL;
	ptr_list->ptr_move=ptr_list->ptr_head;
	while(ptr_list->ptr_move!=NULL)
	{
		ptr_tmp=ptr_list->ptr_move;
		if(ptr_tmp==ptr_list->ptr_head)
		{
			ptr_list->ptr_head=NULL;
			ptr_list->ptr_tail->next=NULL;
		}
		if(ptr_tmp==ptr_list->ptr_tail)
		{
			ptr_list->ptr_tail=NULL;
		}
		ptr_list->ptr_move=ptr_list->ptr_move->next;
		free(ptr_tmp);
		ptr_tmp=NULL;		
	}
}


int main(int argc, char const *argv[])
{
	list define_list;
	init_list(&define_list);
	append_list(&define_list,10);
	print_list(&define_list);
	int dest_sid;
	// scanf("%d",&dest_sid);
	// insert_list(&define_list,dest_sid);
	// print_list(&define_list);
	// print_list(&define_list);
	scanf("%d",&dest_sid);
	delete_list(&define_list,dest_sid);
	//sort_list(&define_list);
	print_list(&define_list);
	free_list(&define_list);
	return 0;
}

/*
胡志贤:把以上单链表改成双链表.快排算法优化成时间复杂度位O(n*logn)
黎刚:把以上单链表改成循环单链表
赵磊:把以上链表改成循环双链表
张凯:在以上链表中增加一个排序函数,要求以上链表节点根据序号有序连接
*/