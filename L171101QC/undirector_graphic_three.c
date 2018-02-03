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
	int endpointindex;
	struct  node * endpointnext;
	struct  node * beginpointnext;
}node;
//定义顶点名与编号类型
typedef struct pointnameno
{
	char pointname[10];
	int pointindex;
	node * ptrendpoint;
	node * ptrbeginpoint;

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
		pdg->pointarray[i].ptrendpoint=NULL;
		pdg->pointarray[i].ptrbeginpoint=NULL;
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
			ptrnode->endpointnext=NULL;
			ptrnode->beginpointnext=NULL;

			node*  ptrtmp=pdg->pointarray[beginpointindex].ptrbeginpoint;
			if(ptrtmp==NULL)
			{
				pdg->pointarray[beginpointindex].ptrbeginpoint=ptrnode;			
			}
			else
			{
				while(ptrtmp->beginpointnext!=NULL)
				{
              		ptrtmp=ptrtmp->beginpointnext;
				}
				ptrtmp->beginpointnext=ptrnode;
			}			

			ptrtmp=pdg->pointarray[endpointindex].ptrendpoint;
			if(ptrtmp==NULL)
			{
				pdg->pointarray[endpointindex].ptrendpoint=ptrnode;
			}
			else
			{
				while(ptrtmp->endpointnext!=NULL)
				{
               		ptrtmp=ptrtmp->endpointnext;
				}
				ptrtmp->endpointnext=ptrnode;
			}
			
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
		if(pdg->pointarray[i].ptrbeginpoint!=NULL)
		{
			printf("%s begin:\n",pdg->pointarray[i].pointname);
			node* ptrmove=pdg->pointarray[i].ptrbeginpoint;
			while(ptrmove!=NULL)
			{
				printf("\t%s weight=%d\n",pdg->pointarray[ptrmove->endpointindex].pointname,ptrmove->weight);
				ptrmove=ptrmove->beginpointnext;
			}
		}

		if(pdg->pointarray[i].ptrendpoint!=NULL)
		{
			printf("%s end:\n",pdg->pointarray[i].pointname);
			node* ptrmove=pdg->pointarray[i].ptrendpoint;
			while(ptrmove!=NULL)
			{
				printf("\t%s weight=%d\n",pdg->pointarray[ptrmove->beginpointindex].pointname,ptrmove->weight);
				ptrmove=ptrmove->endpointnext;
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