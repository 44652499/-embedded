#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define N 100
/*
图遍历:
1.DFS:深度遍历(从任意节点开开始按照右手原则递归访问相邻节点,找出离起点最远的终点)
2.BFS:广度遍历(从任意节点开始按照右手原则递归访问其所有相邻节点)
图遍历时每个节点只能被访问一次.
*/
//定义邻近表节点类型
typedef struct node
{
	int endpointindex;
	int weight;
	struct node  * next;
}node;
//定义存储节点信息的类型
typedef  struct  pointinfo
{
	int pointindex;
	char pointname[20];
	node *  phead;
}pointinfo;
//定义无向图
typedef struct UNDG
{
	int  pointnum;
	int  arcnum;
	pointinfo  pointinfoarray[N];	
}UNDG;

//根据顶点名获取其编号
int  get_point_index(UNDG * pundg,const char* pointname)
{
	int i;
	for(i=0;i<pundg->pointnum;i++)
	{
		if(strcmp(pundg->pointinfoarray[i].pointname,pointname)==0)
		{
			return i;
		}
	}
	return -1;
}
//初始化无向图
void init_undg(UNDG *  pundg)
{
	//输入图顶点数
	printf("please input  UNDG point num:\n");
	scanf("%d",&pundg->pointnum);
	//输入图边数
	printf("please input UNDG arc num:\n");
	scanf("%d",&pundg->arcnum);

	//初始化图顶点信息
	int i;
	printf("please input point name:\n");
	for(i=0;i<pundg->pointnum;i++)
	{
		scanf("%s",pundg->pointinfoarray[i].pointname);
		pundg->pointinfoarray[i].pointindex=i;
		pundg->pointinfoarray[i].phead=NULL;
	}
	//输入边信息
	char  beginpointname[20];
	char endpointname[20];
	int weight;
	printf("please input begin point and end point and weight:\n");
	for(i=0;i<pundg->arcnum;i++)
	{
		scanf("%s%s%d",beginpointname,endpointname,&weight);
		int beginpointindex=get_point_index(pundg,beginpointname);
		int endpointindex=get_point_index(pundg,endpointname);
		//printf("%d\t%d\n",beginpointindex,endpointindex);
		if(beginpointindex!=-1 &&  endpointindex!=-1)
		{
			node*  pnewnode=(node*)malloc(1*sizeof(node));
			assert(pnewnode!=NULL);
			pnewnode->endpointindex=endpointindex;
			pnewnode->weight=weight;
			pnewnode->next=NULL;

			node* ptmp=pundg->pointinfoarray[beginpointindex].phead;
			if(ptmp==NULL)
			{
				pundg->pointinfoarray[beginpointindex].phead=pnewnode;
			}
			else
			{
				while(ptmp->next!=NULL)
				{
					ptmp=ptmp->next;
				}
				ptmp->next=pnewnode;
			}
			pnewnode=NULL;
			pnewnode=(node*)malloc(1*sizeof(node));
			assert(pnewnode!=NULL);
			pnewnode->endpointindex=beginpointindex;
			pnewnode->weight=weight;
			pnewnode->next=NULL;
			ptmp=pundg->pointinfoarray[endpointindex].phead;
			if(ptmp==NULL)
			{ 
				pundg->pointinfoarray[endpointindex].phead=pnewnode;
			}
			else
			{
				while(ptmp->next!=NULL)
				{
					ptmp=ptmp->next;
				}
				ptmp->next=pnewnode;
			}
			ptmp=NULL;
			pnewnode=NULL;
		}
	}
}
//深度遍历图(递归)
void  print_DFS_ungraphic(UNDG * pundg,const char*  startpointname,const char*  deststartpointname)
{
	static int isfirst[N];
	int beginpointindex=get_point_index(pundg,startpointname);
	if(beginpointindex==-1)
	{
		return ;
	}
	char nextpointname[20];
	if(isfirst[beginpointindex]==0)
	{
		printf("%s\t",startpointname);
		isfirst[beginpointindex]=1;		
		node*  ptmp=pundg->pointinfoarray[beginpointindex].phead;
		while(ptmp!=NULL)
		{
		  strcpy(nextpointname,pundg->pointinfoarray[ptmp->endpointindex].pointname);
		  print_DFS_ungraphic(pundg,nextpointname,deststartpointname);
		  ptmp=ptmp->next;
		  if(ptmp!=NULL && strcmp(startpointname,deststartpointname)==0)
		  {
		  	printf("\n%s\t",startpointname);
		  }		  
		}	
	}	
}

//深度遍历图(非递归)
void  print_DFS_ungraphic2(UNDG * pundg, char*  startpointname)
{
	//定义顺序栈
	int stackarray[N];
	int top=-1;
	// //定义数组记录顶点是否是首次访问
	int isfirst[N];
	//全出初始化成0 表示首次访问
	int i;
	for(i=0;i<N;i++)
	{
		isfirst[i]=0;
	}
	int beginpointindex=get_point_index(pundg,startpointname);
	if(beginpointindex==-1)
	{
		return ;
	}
	while(!isfirst[beginpointindex] || top>=-1)
	{
		if(isfirst[beginpointindex]==0)
		{
			printf("%s\t",startpointname);
			isfirst[beginpointindex]=1;
			stackarray[++top]=beginpointindex;
	    }
	    node*  ptmp=pundg->pointinfoarray[beginpointindex].phead;
	    while(ptmp!=NULL &&  isfirst[ptmp->endpointindex])
	    {
	    	ptmp=ptmp->next;
	    }
		if(ptmp!=NULL)			
		{
			beginpointindex=ptmp->endpointindex;
			char pointname[20];
			strcpy(pointname,pundg->pointinfoarray[beginpointindex].pointname);
			startpointname=pointname;
		}
	    else
	    {
            beginpointindex=stackarray[top--];   
            if(top==-1)
            {
            	printf("\n%s\t",pundg->pointinfoarray[beginpointindex].pointname);
            }         
	    }
	}	
}
//图广度遍历(非递归)
void   print_BFS_ungraphic(UNDG * pundg, char*  startpointname)
{
	//定义顺序栈
	int queuearray[N];
	int front=-1,tail=-1;
	// //定义数组记录顶点是否是首次访问
	int isfirst[N];
	//全出初始化成0 表示首次访问
	int i;
	for(i=0;i<N;i++)
	{
		isfirst[i]=0;
	}
	int beginpointindex=get_point_index(pundg,startpointname);
	if(beginpointindex==-1)
	{
		return ;
	}
	queuearray[++tail]=beginpointindex;
	while(front!=tail)
	{
		beginpointindex=queuearray[++front];
		if(isfirst[beginpointindex]==0)
        {
            printf("%s\t",pundg->pointinfoarray[beginpointindex].pointname);
            isfirst[beginpointindex]=1;            
        }
        node  * ptr_tmp=pundg->pointinfoarray[beginpointindex].phead;
        while(ptr_tmp!=NULL )
        {
            if(!isfirst[ptr_tmp->endpointindex])
            {
                queuearray[++tail]=ptr_tmp->endpointindex ;
            }            
            ptr_tmp=ptr_tmp->next;
        }
	}
	printf("\n");
}
//打印输出无向图
void  print_undg(UNDG * pundg)
{
	int i;
	for(i=0;i<pundg->pointnum;i++)
	{
		if(pundg->pointinfoarray[i].phead!=NULL)
		{
			node* pmove=pundg->pointinfoarray[i].phead;
			printf("%s begin:\n",pundg->pointinfoarray[i].pointname);
			while(pmove!=NULL)
			{
				printf("\t%s\t%d\n",pundg->pointinfoarray[pmove->endpointindex].pointname,pmove->weight);
				pmove=pmove->next;
			}
		}
	}
}

//释放图
void  free_undg(UNDG *  pundg)
{
	int i;
	for(i=0;i<pundg->pointnum;i++)
	{
		node *  ptmp=pundg->pointinfoarray[i].phead;
		node * pfree=NULL;;
		while(ptmp!=NULL)
		{
			pfree=ptmp;
			ptmp=ptmp->next;
			if(pfree==pundg->pointinfoarray[i].phead)
			{
				pundg->pointinfoarray[i].phead=NULL;				
			}
			free(pfree);
			pfree=NULL;
			
		}
	}
}
int main(int argc, char const *argv[])
{
	UNDG undg;
	init_undg(&undg);
	//print_DFS_ungraphic(&undg,"v1","v1");
	//print_DFS_ungraphic2(&undg,"v1");
	print_BFS_ungraphic(&undg,"v1");
	//print_undg(&undg);
	//free_undg(&undg);
	return 0;
}