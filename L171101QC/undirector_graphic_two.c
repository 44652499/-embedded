#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define  N  10
/*
图:是一种非线性结构,由顶点和顶点之间线或弧组成.形成顶点多对多关系
线性结构:节点之间1对1关系
树:父与子节点1对多关系
图:顶点多对多关系
图根据顶点之间路径方向分为:
1.有向图
2.无向图
图存储方式:
1.邻接矩阵(有向图)
2.邻接链表(无向图)
3.十字邻接链表(无向图)
4.多重邻接链表(无向图)
*/
//定义邻接链表节点
typedef  struct  node
{
	int weight;
	int beginpointindex;
	struct  node * beginpointnext;
	int endpointindex;
	struct  node * endpointnext;
}node;
//定义顶点名与编号类型
typedef struct pointnameno
{
	char pointname[10];
	int pointindex;
	node * ptrhead;
	node * ptrtail;

}pointnameno;

//定义有向图结构
typedef struct UNDG
{
	int pointnum;
	int arcnum;
	pointnameno pointarray[N];//记录顶点名称与顶点编号
}UNDG;

//根据顶点名获取其编号
int  get_point_index(UNDG *pdg,const char*  pointname)
{
	int i;
	for(i=0;i<pdg->pointnum;i++)
	{
		if(strcmp(pdg->pointarray[i].pointname,pointname)==0)
		{
			return i;
		}
	}
	return -1;
}

//构建图
void init_dg(UNDG *  pdg)
{
	//输入顶点和边数量
	printf("please input point num:");
	scanf("%d",&pdg->pointnum);
	//输入边数
	printf("please input arc num:");
	scanf("%d",&pdg->arcnum);
	//输入顶点名称
	printf("please input point name:");
	int i;
	for(i=0;i<pdg->pointnum;i++)
	{
		scanf("%s",pdg->pointarray[i].pointname);
		pdg->pointarray[i].pointindex=i;
		pdg->pointarray[i].ptrhead=NULL;
		pdg->pointarray[i].ptrtail=NULL;
	}
	//输入边信息
	printf("please input begin point and end point and weight:");
	char beginpoint[10];
	char endpoint[10];
	int  weight;
	for(i=0;i<pdg->arcnum;i++)
	{
		scanf("%s%s%d",beginpoint,endpoint,&weight);
		int beginpointindex=get_point_index(pdg,beginpoint);
		int endpointindex=get_point_index(pdg,endpoint);	
		//printf("%d\t%d\n",beginpointindex,endpointindex);
		if(beginpointindex!=-1 && endpointindex!=-1)
		{
			node*  ptrnode=(node*)malloc(1*sizeof(node));
			assert(ptrnode!=NULL);
			ptrnode->beginpointindex=beginpointindex;
			ptrnode->endpointindex=endpointindex;
			ptrnode->weight=weight;
			ptrnode->beginpointnext=NULL;
			ptrnode->endpointnext=NULL;

			if(pdg->pointarray[beginpointindex].ptrhead==NULL)
			{
				pdg->pointarray[beginpointindex].ptrhead=ptrnode;			
			}
			else
			{

				if(pdg->pointarray[beginpointindex].ptrtail->beginpointindex
					==ptrnode->endpointindex)
				{
					pdg->pointarray[beginpointindex].ptrtail->endpointnext=ptrnode;
				}
				else
				{
					pdg->pointarray[beginpointindex].ptrtail->beginpointnext=ptrnode;
				}				
			}
			pdg->pointarray[beginpointindex].ptrtail=ptrnode;

			if(pdg->pointarray[endpointindex].ptrhead==NULL)
			{
				pdg->pointarray[endpointindex].ptrhead=ptrnode;
			}
			else
			{
				if(pdg->pointarray[endpointindex].ptrtail->endpointindex
					==ptrnode->beginpointindex)
				{
					pdg->pointarray[endpointindex].ptrtail->endpointnext=ptrnode;
				}
				else
				{
					pdg->pointarray[endpointindex].ptrtail->beginpointnext=ptrnode;
				}			
				//pdg->pointarray[endpointindex].ptrtail->endpointnext=ptrnode;
			}	
			pdg->pointarray[endpointindex].ptrtail=ptrnode;		
			ptrnode=NULL;
		}		
	}
}

//输出邻接矩阵
void  print_dg(UNDG *  pdg)
{
	int i;
	for(i=0;i<pdg->pointnum;i++)
	{
		if(pdg->pointarray[i].ptrhead!=NULL)
		{
			printf("%s:\n",pdg->pointarray[i].pointname);
			node* ptrmove=pdg->pointarray[i].ptrhead;
			while(ptrmove!=NULL)
			{
				//printf("\t%s weight=%d\n",pdg->pointarray[ptrmove->endpointindex].pointname,ptrmove->weight);
				if(pdg->pointarray[i].pointindex==ptrmove->beginpointindex)
				{
					printf("\t%s weight=%d\n",pdg->pointarray[ptrmove->endpointindex].pointname,ptrmove->weight);
				}
				else
				{
					printf("\t%s weight=%d\n",pdg->pointarray[ptrmove->beginpointindex].pointname,ptrmove->weight);
				}
				
				ptrmove=ptrmove->beginpointnext;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	UNDG dg;
	init_dg(&dg);
	print_dg(&dg);
	return 0;
}