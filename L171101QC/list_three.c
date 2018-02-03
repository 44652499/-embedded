#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*

*/
//定义节点类型
typedef struct node
{
	int sid;
	struct node * front;
	struct node * next;
}node; 
//定义链表类型
typedef struct list
{
	node *  ptrhead; //指向链表头节点指针
	node *  ptrtail; //指向链表尾节点指针
	node *  ptrmove; //移动指针
}list;

//初始化链表
void  init_list(list*  ptrlist)
{
	//创建头节点 固定链表位置
	node *  ptrhead=(node*)malloc(1*sizeof(node));
	assert(ptrhead!=NULL);
	ptrhead->next=NULL;
	ptrhead->front=NULL;

	ptrlist->ptrhead=ptrhead;
	ptrlist->ptrtail=ptrhead;
	ptrlist->ptrmove=ptrhead;
}

//构造10个节点放入链表中
void  append_list(list* ptrlist,int cnt)
{
	node *  ptrnew=NULL;
	int i;
	for(i=0;i<cnt;i++)
	{
		ptrnew=(node*)malloc(1*sizeof(node));
		assert(ptrnew!=NULL);
		ptrnew->sid=(i+1);
		ptrnew->front=NULL;
		ptrnew->next=NULL;

		ptrlist->ptrtail->next=ptrnew;
		ptrnew->front=ptrlist->ptrtail;
		ptrlist->ptrtail=ptrnew;
		ptrnew=NULL;
	}
}

//输出双链表
void  print_list(list* ptrlist)
{
	ptrlist->ptrmove=ptrlist->ptrhead->next;
	while(ptrlist->ptrmove!=NULL)
	{
		printf("sid=%d\n",ptrlist->ptrmove->sid);
		ptrlist->ptrmove=ptrlist->ptrmove->next;
	}
}

//释放双链表
void  free_list(list *  ptrlist)
{
	ptrlist->ptrmove=ptrlist->ptrhead;
	node*  ptrtemp=NULL;
	while(ptrlist->ptrmove!=NULL)
	{
		ptrtemp=ptrlist->ptrmove;
		ptrlist->ptrmove=ptrlist->ptrmove->next;
		if(ptrtemp==ptrlist->ptrhead)
		{
			ptrlist->ptrhead=NULL;			
		}
		if(ptrtemp==ptrlist->ptrtail)
		{
			ptrlist->ptrtail=NULL;
		}
		if(ptrlist->ptrmove!=NULL)
		{
			ptrlist->ptrmove->front=NULL;
		}		
		free(ptrtemp);
		ptrtemp=NULL;
	}
}

int main(int argc, char const *argv[])
{
	list   l;
	init_list(&l);
	append_list(&l,10);
	print_list(&l);
	free_list(&l);
	return 0;
}
