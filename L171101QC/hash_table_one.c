#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*
hash表:称为散列表,由键值对存储数据.加快查找效率.查找值时根据键值找到值存储的位置.存储数据结构称为hash表
体现键值与存储值关系称为hash函数
f(key)=value;
hash表需要使用hash计算计算值存储的位置.
一般设计hash表时借助于一个一维静态数组,通过hash函数计算出值存储的下标值
hash 函数是一个不固定函数,但是选择一个最优的hash函数:
1.尽量减少存储冲突
2.尽量均匀分散存储元素
常用的hash函数:
1.余数法
2.位运算
3.随机法
4.平方取中
5.直接地址法
6.数字分析法

hash表容易存在问题:
1.冲突问题
如何解决冲突问题?
1.多次hash
2.拉链法:使用链表存储冲突元素

著名hash函数:
1.MD5
2.SHA-1
*/
//实现一个简单通用hash表,使用链表解决冲突问题
//定义解决冲突链表节点
#define N 100
#define  MAXSIZE 30
typedef struct node
{
	char chvalue[N];
	struct node*  next;
}node;
//定义链表
typedef struct list
{
	node * ptrhead;
	node*  ptrtail;
}list;
//定义查找返回值类型
typedef struct findresult
{
	int isfind; //0:没找到 1:找到
    node *  ptrfindnode;//记录第一个匹配查找节点位置
    node *   ptrprefindnode;//记录第一个匹配查找节点前一个节点位置位置
}findresult;

//定义hash表
list *  hashtable[MAXSIZE];
//初始化hash表
void  init_hashtable()
{
	int i;
	for(i=0;i<MAXSIZE;i++)
	{
		hashtable[i]=NULL;
	}
}
//hash函数
int  hashtable_function(const char* ch)
{
	int sum=0;
	int i;
	for(i=0;i<strlen(ch);i++)
	{
		sum+=ch[i];
	}
	return sum%MAXSIZE;
}
//存储元素到hash表
void  save_hashtable(const char * ch)
{
	int key=hashtable_function(ch);
	node * ptrnewnode=(node*)malloc(1*sizeof(node));
	assert(ptrnewnode!=NULL);
	strcpy(ptrnewnode->chvalue,ch);
	ptrnewnode->next=NULL;
	if(hashtable[key]==NULL)
	{
		list *ptrlist=(list*)malloc(1*sizeof(list));
		assert(ptrlist!=NULL);
		ptrlist->ptrhead=NULL;
		ptrlist->ptrtail=NULL;
		hashtable[key]=ptrlist;
        ptrlist->ptrhead=ptrnewnode;
        ptrlist->ptrtail=ptrnewnode;
	}
	else
	{
		list* ptrtmp=hashtable[key];
        ptrtmp->ptrtail->next=ptrnewnode;
        ptrtmp->ptrtail=ptrnewnode;
	}
	ptrnewnode=NULL;
}

//查找元素值
findresult  find_hashtable(const char *  value)
{
	findresult  retfind;
	retfind.isfind=0;
	retfind.ptrfindnode=NULL;
	retfind.ptrprefindnode=NULL;
	int key=hashtable_function(value);
	if(hashtable[key]==NULL)
	{
		return retfind;
	}
	else
	{
		node*  ptrtmp=hashtable[key]->ptrhead;
		//printf("value=%s\n",hashtable[key]->ptrhead->chvalue);
		while(ptrtmp!=NULL)
		{
			if(strcmp(ptrtmp->chvalue,value)==0)
			{
				retfind.isfind=1;
				retfind.ptrfindnode=ptrtmp;
				return retfind;
			}
			else
			{
				retfind.ptrprefindnode=ptrtmp;
			}
			ptrtmp=ptrtmp->next;
		}
		return retfind;
	}
} 


//删除元素值
void delete_hashtable(const char*  value)
{
	findresult ret=find_hashtable(value);
	if(ret.isfind==0)
	{
		printf("not find  not delete\n");
		return;
	}
	while(ret.isfind==1)//删除多次重复出现记录
	{
		node*  ptrfind=ret.ptrfindnode;
		int key=hashtable_function(value);
		if(ptrfind==hashtable[key]->ptrhead)
        {
        	hashtable[key]->ptrhead=ptrfind->next;
		}
		else if(ptrfind==hashtable[key]->ptrtail)
		{
			hashtable[key]->ptrtail=ret.ptrprefindnode;
			hashtable[key]->ptrtail->next=NULL;			
		}
		else if(ptrfind==hashtable[key]->ptrhead &&
			ptrfind==hashtable[key]->ptrtail)
        {
        	hashtable[key]->ptrhead=NULL;
        	hashtable[key]->ptrtail=NULL;
        	free(hashtable[key]);
        	hashtable[key]=NULL;
		}
		else
		{
			ret.ptrprefindnode->next=ptrfind->next;
			free(ptrfind);
			ptrfind=NULL;
		}	
		ret=find_hashtable(value);
	}
}
//输出hash表
void  print_hashtable()
{
	int i;
	for(i=0;i<MAXSIZE;i++)
	{
		if(hashtable[i]!=NULL)
		{
			node* ptrtmp=hashtable[i]->ptrhead;
			while(ptrtmp!=NULL)
			{
				printf("%s\t",ptrtmp->chvalue);
				ptrtmp=ptrtmp->next;
			}
			printf("\n");
		}
	}
}

//释放hash表冲突链表
void  free_hashtable()
{
	int i;
	for(i=0;i<MAXSIZE;i++)
	{
		if(hashtable[i]!=NULL)
		{
			node* ptrmove=hashtable[i]->ptrhead;
			node * ptrtmp=NULL;
			while(ptrmove!=NULL)
			{
				ptrtmp=ptrmove;
				ptrmove=ptrmove->next;
				if(ptrtmp==hashtable[i]->ptrhead)
				{
					hashtable[i]->ptrhead=NULL;
					
				}
				if(ptrtmp==hashtable[i]->ptrtail)
				{
					hashtable[i]->ptrtail=NULL;
				}
				free(ptrtmp);
				ptrtmp=NULL;
			}
			free(hashtable[i]);
			hashtable[i]=NULL;
		}
	}
}

int main(int argc, char const *argv[])
{
	init_hashtable();
	save_hashtable("sdfdsfds");
	save_hashtable("123123");
	save_hashtable("asdasdq212");
	save_hashtable("dfdf234234");
	save_hashtable("fdgfdg");
	save_hashtable("768768");
	save_hashtable("hgfghfg123");
	save_hashtable("sdfds443");
	save_hashtable("fghfdge4543");
	save_hashtable("78967sd");
	save_hashtable("aaaadf");
	save_hashtable("123412321fd");
	save_hashtable("567546gh");
	save_hashtable("fdgfdgdf,");
	save_hashtable("123123");
	save_hashtable("sdfds[';");
	save_hashtable("1111qqsf");
	save_hashtable("123123");
	save_hashtable("vbcvbvbc");
	save_hashtable("0978978");
	save_hashtable("sddfghdfgert");
	save_hashtable("123123");
	print_hashtable();
	// save_hashtable("vbcvbvbc");
	// print_hashtable();
	// findresult ret=find_hashtable("567546gh");
	// if(ret.isfind==1)
	// {
	// 	printf("find ok\n");
	// }
	// else
	// {
	// 	printf("not find\n");
	// }

	delete_hashtable("123123");
	print_hashtable();
	free_hashtable();
	return 0;
}
//实现一个简单的MD5或SHA-1实现对明文加密解密(代码行>200)