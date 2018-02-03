#include  <stdio.h>
#include  <stdlib.h>
/*图的表示方法 
DG(有向图)或者DN(有向网):邻接矩阵、邻接表(逆邻接表--为求入度)、十字链表 
UDG(无向图)或者UDN(无向网):邻接矩阵、邻接表、邻接多重表
*/ 

//无向网/图  邻接表
#define MAX_VERTEX_NUM 10 //最大顶点数目
//typedef int  VRType; //顶点关系类型,对于无权图或网,用0或1表示相邻否;对于带权图或网,则为相应权值
//typedef int   VertexType;//顶点类型

typedef struct  ArcNode
{
	int adjvex;//该弧所指向的顶点的在图中位置
	int w;//弧的相应权值
	struct ArcNode* nextarc;//指向下一条弧的指针 
}ArcNode; //弧结点信息  

typedef struct VNode
{
	int data;//顶点信息
	ArcNode* firstarc;//指向第一条依附该顶点的弧的指针
}VNode;//顶点结点信息  

typedef struct
{
	VNode vexs[MAX_VERTEX_NUM];//顶点向量
	int vexnum;
	int arcnum;//图的当前顶点数和弧数 
}ALGraph;//邻接表表示的图  

//若图G中存在顶点v,则返回v在图中的位置信息,否则返回其他信息
int locateVex(ALGraph *g,int v)
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

//采用邻接表表示法构造无向网G  
void  createUDN(ALGraph *g)
{
	printf("输入顶点数和弧数:");
	scanf("%d%d",&g->vexnum,&g->arcnum);
	//构造顶点向量,并初始化 
	printf("输入%d个顶点:",g->vexnum);
	int i;
	for(i=0;i<g->vexnum;i++)
	{
		scanf("%d",&g->vexs[i].data);
		g->vexs[i].firstarc=NULL;
	}

	//构造邻接表
	int  v1,v2;//分别是一条弧的弧尾和弧头（起点和终点） 
	int w;//对于无权图或网,用0或1表示相邻否;对于带权图或网，则为相应权值 
	printf("\n每行输入一条弧依附的顶点和权值:\n");
	int k,j;
	for(k=0;k<g->arcnum;k++)
	{
		scanf("%d%d%d",&v1,&v2,&w);
		i=locateVex(g,v1);
		j=locateVex(g,v2);        
        //采用"头插法"在各个顶点的弧链头部插入弧结点
        ArcNode *p1=(ArcNode*)malloc(1*sizeof(ArcNode)); //构造一个弧结点,作为弧vivj的弧头(终点)
        p1->adjvex=j;
        p1->w=w;
        p1->nextarc=g->vexs[i].firstarc;
        g->vexs[i].firstarc=p1;

        ArcNode* p2=(ArcNode*)malloc(1*sizeof(ArcNode));//构造一个弧结点,作为弧vivj的弧尾(起点)  
        p2->adjvex=i;
        p2->w=w;
        p2->nextarc=g->vexs[j].firstarc;
        g->vexs[j].firstarc=p2;
	}
}

//打印邻接表 
void  printAdjList(ALGraph *g)
{
	printf("\n");
	int i;
	for(i=0;i<g->vexnum;i++)
	{
		printf("依附顶点v%d的弧为:",g->vexs[i].data);
		ArcNode *p=g->vexs[i].firstarc;
		while(p)
		{
			printf("v%d v%d(weight:%d)\t",g->vexs[i].data,g->vexs[p->adjvex].data,p->w);
			p=p->nextarc;
		}
		printf("\n");
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	ALGraph g;
	createUDN(&g);
	printAdjList(&g);
	return 0;
}


