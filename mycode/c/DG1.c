#include  <stdio.h>
/*图的表示方法 
DG(有向图)或者DN(有向网):邻接矩阵、邻接表(逆邻接表--为求入度)、十字链表 
UDG(无向图)或者UDN(无向网):邻接矩阵、邻接表、邻接多重表
*/ 

//有向图/网存储   邻接矩阵
#define MAX_VALUE   88888 //最大值:假定为无穷大
#define MAX_VERTEX_NUM 10 //最大顶点数目
//typedef int  VRType; //顶点关系类型,对于无权图或网,用0或1表示相邻否;对于带权图或网,则为相应权值
//typedef int   VertexType;//顶点类型
typedef  int  AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct 
{
	int vexs[MAX_VERTEX_NUM];//顶点向量
	AdjMatrix arcs;//邻接矩阵
	int vexnum;
	int arcnum;//图的当前顶点数和弧数
}MGraph; //邻接矩阵表示的图

//若图G中存在顶点v,则返回v在图中的位置信息,否则返回其他信息  
int  locatevex(MGraph* g,int v)
{
	int i;
	for(i=0;i<g->vexnum;i++)
	{
		if(g->vexs[i]==v)
		{
			return i;
		}
	}
	return -1;
}

//采用邻接矩阵表示法构造有向网G
void  createDN(MGraph* g)
{
	printf("输入顶点和弧数:");
	scanf("%d%d",&(g->vexnum),&(g->arcnum));

	//构造顶点编号(0 1 2)
	int i;
	for(i=0;i<g->vexnum;i++)
	{
		scanf("%d",&(g->vexs[i]));
	}

	//初始化邻接矩阵
	int j=0;
	i=0;
	for(i=0;i<g->vexnum;i++)
	{
		for(j=0;j<g->vexnum;j++)
		{
			g->arcs[i][j]=MAX_VALUE;
		}
	}

	//构造邻接矩阵
	int v1,v2;//分别是一条弧的弧尾和弧头(起点和终点)
	int w;//对于无权图或网,用0或1表示相邻否;对于带权图或网,则为相应权值
	printf("\n每行输入一条弧依附的顶点(先弧尾后弧头)和权值:\n");
	int k;
	for(k=0;k<g->arcnum;k++)
	{
		scanf("%d%d%d",&v1,&v2,&w);
		i=locatevex(g,v1);
		j=locatevex(g,v2);
		g->arcs[i][j]=w;
	}
}

//打印邻接矩阵
void  printDN(MGraph* g)
{
	int i,j;
	printf("\n打印有向网的邻接矩阵:\n");
	for(i=0;i<g->vexnum;i++)
	{
		for(j=0;j<g->vexnum;j++)
		{
			if(g->arcs[i][j]!=MAX_VALUE)
				printf("%d\t",g->arcs[i][j]);
			else
				printf("NULL\t");
		}
		printf("\n");
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	MGraph g;
	createDN(&g);
	printDN(&g);
	return 0;
}


