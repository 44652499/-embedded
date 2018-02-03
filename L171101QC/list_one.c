#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*
链表list:顺序结构,非连续存储.通过指针记录其前后元素的位置.
适合内存动态分配使用(根据需要分配,可以使用碎片).
链表由节点组成,通过节点的指针把前后节点连城一种顺序结构
链表中特殊三个节点:
1.头节点:固定链表起始位置
2.尾节点:链表最后一个节点,方便往链表后面插入新节点
3.访问链表的移动节点:访问整个链表的移动节点

节点(node):结构体类型,由数据域和指针域组成
根据节点存在指针数不同分为:
1.单链表
2.双链表
根据首尾节点是否相连分为:
1.循环单链表
2.循环双链表
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
	while(ptr_list->ptr_move!=NULL)
	{
		if(ptr_list->ptr_move->sid==dest_sid)
		{			
			//如果找的是第一个节点
			if(ptr_list->ptr_head->next==ptr_list->ptr_move)
			{
				ptr_list->ptr_head->next=ptr_new_node;
			}
			else
			{
				ptr_tmp_node->next=ptr_new_node;
			}
			ptr_new_node->next=ptr_list->ptr_move;
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
	while(p2!=NULL)
	{		
		p1=p2->next;
		while(p1!=NULL)
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
	while(ptr_list->ptr_move!=NULL)
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
	while(ptr_list->ptr_move!=NULL)
	{
		if(ptr_list->ptr_move->sid==dest_sid)
		{
			if(ptr_list->ptr_head->next==ptr_list->ptr_move)
			{
				ptr_list->ptr_head->next=ptr_list->ptr_move->next;				
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
	// int dest_sid;
	// scanf("%d",&dest_sid);
	// insert_list(&define_list,dest_sid);
	// print_list(&define_list);
	// print_list(&define_list);
	// scanf("%d",&dest_sid);
	// delete_list(&define_list,dest_sid);
	// sort_list(&define_list);
	// print_list(&define_list);
	// free_list(&define_list);
	return 0;
}

/*
胡志贤:把以上单链表改成双链表.快排算法优化成时间复杂度位O(n*logn)
黎刚:把以上单链表改成循环单链表
赵磊:把以上链表改成循环双链表
张凯:在以上链表中增加一个排序函数,要求以上链表节点根据序号有序连接
*/