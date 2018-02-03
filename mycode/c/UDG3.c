#include  <stdio.h>
#include  <stdlib.h>
/*图的表示方法 
DG(有向图)或者DN(有向网):邻接矩阵、邻接表(逆邻接表--为求入度)、十字链表 
UDG(无向图)或者UDN(无向网):邻接矩阵、邻接表、邻接多重表
*/ 

//无向网/图  十字链表
#define MAX_VERTEX_NUM 10 //最大顶点数目
//typedef int  VRType; //顶点关系类型,对于无权图或网,用0或1表示相邻否;对于带权图或网,则为相应权值
//typedef int   VertexType;//顶点类型

typedef struct  ArcNode
{
	int tailvex;
	int headvex;//该弧的弧尾(起点)和弧头(终点)所指向的顶点的在图中位置
	struct  ArcNode *  tailNextarc;
	struct  ArcNode *  headNextarc;//分别为指向弧尾(起点)相同的弧的下一条弧的指针、弧头(终点)相同的弧的下一条弧的指针  
}ArcNode; //弧结点信息  

typedef struct VNode
{
	int data;//顶点信息
	ArcNode* firstIn;//指向第一条以该顶点为弧尾(起点)的指针 
	ArcNode* firstOut;//指向第一条以该顶点的弧头(终点)的指针
}VNode,VexList[MAX_VERTEX_NUM];//顶点结点信息  

typedef struct
{
	VexList vexs;//顶点向量
	int vexnum;
	int arcnum;//图的当前顶点数和弧数 
}OLGraph;//邻接表表示的图  

//若图G中存在顶点v,则返回v在图中的位置信息,否则返回其他信息
int locateVex(OLGraph *g,int v)
{
	int i;
	for(i=0;i<g->vexnum;i++)
	{
		if(g->vexs[i].data==v)
		{
			return i;
		}
	}
	return -1;
}

//采用邻接多重表表示法构造无向图G 
void  createDG(OLGraph *g)
{
	printf("输入顶点数和弧数:");
	scanf("%d%d",&g->vexnum,&g->arcnum);
	//构造顶点向量,并初始化 
	printf("输入%d个顶点:",g->vexnum);
	int i;
	for(i=0;i<g->vexnum;i++)
	{
		scanf("%d",&g->vexs[i].data);
		g->vexs[i].firstIn=NULL;
		g->vexs[i].firstOut=NULL;
	}

	//构造十字链表
	int  v1,v2;//分别是一条弧的弧尾和弧头(起点和终点)
	printf("\n每行输入一条弧依附的顶点和权值:\n");
	int k,j;
	for(k=0;k<g->arcnum;k++)
	{
		scanf("%d%d",&v1,&v2);
		i=locateVex(g,v1);//边依附的两个顶点的在图中的位置 
		j=locateVex(g,v2);
        
        //采用“头插法”在各个顶点的弧链头部插入弧结点
        ArcNode *p=(ArcNode*)malloc(1*sizeof(ArcNode)); //构造一个弧结点,作为弧vivj的弧头(终点)
        p->tailvex=i;
        p->tailNextarc=g->vexs[i].firstOut;
        g->vexs[i].firstOut=p;

        p->headvex=j;
        p->headNextarc=g->vexs[j].firstIn;
        g->vexs[j].firstIn=p;       
	}
}

//打印十字链表 
void  printOrthogonalList(OLGraph *g)
{
	printf("\n");
	int i;
	for(i=0;i<g->vexnum;i++)
	{
		printf("依附顶点v%d的弧为:",g->vexs[i].data);
		ArcNode *p=g->vexs[i].firstOut;
		while(p)
		{
			printf("v%d v%d\t",g->vexs[i].data,g->vexs[p->headvex].data);
				p=p->tailNextarc;
		}
		printf("\n");
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	OLGraph g;
	createDG(&g);
	printOrthogonalList(&g);
	return 0;
}


