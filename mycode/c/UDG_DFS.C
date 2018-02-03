#include <stdio.h>
#include <stdlib.h>
//以无向图的邻接表作为存储结构,实现图深度优先遍历算法 
#define MAX_VERTEX_NUM 10//最大顶点数目  
typedef struct ArcNode
{
	int adjvex;//该弧所指向的顶点的在图中位置
	int w;
	struct ArcNode *nextarc;//指向下一条边的指针 
}ArcNode;//弧结点信息 

typedef struct VNode
{
	int data;//顶点信息 
	ArcNode * firstarc;//指向第一条依附该顶点的弧的指针
}VNode,AdjvexList[MAX_VERTEX_NUM];//顶点结点信息  

typedef struct
{
	AdjvexList vexs;//顶点向量
	int vexnum;//图的当前顶点数和弧数 
	int arcnum;
}ALGraph;//邻接表表示的图

//若图G中存在顶点v,则返回v在图中的位置信息,否则返回其他信息 
int  locateVex(ALGraph* g,int v)
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

//采用邻接表表示法构造无向图G 
void createUDN(ALGraph* g)
{
	printf("请输入顶点数和弧数:");
	scanf("%d%d",&g->vexnum,&g->arcnum);
	//构造顶点向量,并初始化  
    printf("输入%d个顶点:",g->vexnum);
    int i,j,k;
    for(i=0;i<g->vexnum;i++)
    {
    	scanf("%d",&g->vexs[i].data);
    	g->vexs[i].firstarc=NULL;
    }
    int  v1,v2;
    int w;
    printf("每行输入弧的起点与终点:\n");
   
    for(k=0;k<g->arcnum;k++)
    {
    	scanf("%d%d%d",&v1,&v2,&w);
    	i=locateVex(g,v1);
    	j=locateVex(g,v2);
    	ArcNode *p1=(ArcNode*)malloc(1*sizeof(ArcNode));
    	p1->adjvex=j;
    	p1->w=w;
    	p1->nextarc=g->vexs[i].firstarc;
    	g->vexs[i].firstarc=p1;

    	ArcNode* p2=(ArcNode*)malloc(1*sizeof(ArcNode));
    	p2->adjvex=i;
    	p2->w=w;
    	p2->nextarc=g->vexs[j].firstarc;
    	g->vexs[j].firstarc=p2;
    }
}

int  visited[MAX_VERTEX_NUM];//访问标识数组 
void DFS(ALGraph  *g,int  ivex)
{
	//从第i个顶点出发递归的深度优先遍历图G
	visited[ivex]=1;
	printf("%d",g->vexs[ivex].data);//打印(访问)该顶点
	for(ArcNode *p=g->vexs[ivex].firstarc;p;p=p->nextarc)
	{
		//对于第ivex个顶点的每个未被访问的邻接点递归调用DFS
		if(!visited[p->adjvex])
		{
			DFS(g,p->adjvex);
		}
	}
}

//深度优先遍历无向图G(相当于树的先序遍历)(递归算法)
void  DFSTraverseGraph(ALGraph * g)
{
	//初始化访问标志数组
	int i;
	for(i=0;i<g->vexnum;i++)
	{
		visited[i]=0;//0表示未被访问,1表示已被访问
	}
	printf("请输入遍历的起始顶点:");
	int startVex;
	scanf("%d",&startVex);
	int startVexPos=locateVex(g,startVex);
	printf("一条深度优先遍历序列为:");
	if(!visited[startVexPos])
	{
		DFS(g,startVexPos);
	}
	printf("\n");
} 

//深度优先遍历无向图G(相当于树的先序遍历)(非递归算法)
void  DFSTraverseGraph2(ALGraph * g)
{
	int stack[MAX_VERTEX_NUM];//维护一个栈来存储访问图的顶点的(位置)信息
	int top=0;//初始化栈顶指针,为空栈
	//初始化访问标志数组
	int i;
	for(i=0;i<g->vexnum;i++)
	{
		visited[i]=0;//0表示未被访问，1表示已被访问
	}
	printf("请输入遍历的起始顶点:");
	int startVex;
	scanf("%d",&startVex);
	int startVexPos=locateVex(g,startVex);
	printf("一条深度优先遍历序列为:");
	ArcNode * p;
	int ivex=startVexPos;
	while(!visited[ivex]||top!=-1)//栈不为空  
	{
		if(!visited[ivex])//第vex结点没有被访问过 
		{
			visited[ivex]=1;
			printf("%d",g->vexs[ivex].data);
			stack[top++]=ivex;
		}
		p=g->vexs[ivex].firstarc;
		while(p && visited[p->adjvex])//p不为空且p已经被访问过,就跳过
			p=p->nextarc;
	    //此时p指向以当前顶点为头的且未被访问第一个尾顶点 
	    if(p)//如果p不为空
	    {
	    	ivex=p->adjvex;
	    }
	    else//如果p为空,说明当前顶点的所有和他有路径相通的顶点均已访问,则栈顶元素出栈,查找下一个尚未被访问的顶点  
	    {
	    	ivex=stack[--top];//栈顶元素出栈  
	    }
	}
	printf("\n");
} 

//广度优先遍历无向图G(相当于树的按层次遍历)(非递归算法)
void  BFSTraverseGraph(ALGraph * g) 
{
	int queue[MAX_VERTEX_NUM];//维护一个队列来存储访问图的顶点的(位置)信息 
	int front=0,tail=0;//初始化队头、队尾指针,为空队列
	//初始化访问标志数组
	int i;
	for(i=0;i<g->vexnum;i++)
	{
		visited[i]=0;//0表示未被访问,1表示已被访问 
	} 
	printf("请输入遍历的起始顶点:");
	int startVex;
	scanf("%d",&startVex);
	int startVexPos=locateVex(g,startVex);
	printf("一条广度优先遍历序列为:");
	queue[tail++]=startVexPos;//起点先入队 
	int ivex;
	ArcNode *p;
	while(front!=tail)//不是空队列 
	{
		ivex=queue[front++];//队头元素出队 
		if(!visited[ivex])
		{
			visited[ivex]=1;
			printf("%d",g->vexs[ivex].data);
		}
		p=g->vexs[ivex].firstarc;
		while(p)//p指向与ivex的邻接的(同一个层次的)还未被顶点
		{
			if(!visited[p->adjvex])
				queue[tail++]=p->adjvex;
			p=p->nextarc;
		}
	}
    printf("\n");
}

int main(int argc, char const *argv[])
{
	ALGraph g;
	createUDN(&g);
	printf("\n深度优先遍历(递归算法):\n");
	DFSTraverseGraph(&g);

	printf("\n深度优先遍历(非递归算法):\n");
	DFSTraverseGraph2(&g);

	printf("\n广度优先遍历(非递归算法):\n");
	BFSTraverseGraph(&g);
	return 0;
}