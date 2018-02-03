#include <stdio.h>
#include <stdlib.h>
#define  MAX_VEX_NUM  10
//以无向图的邻接表作为存储结构,实现图深/广度优先遍历算法  
//定义链表节点
typedef  struct ArcNode
{
	int ivex;//顶点位置(从0开始)
	int weight;//权重,顶点之间的距离
	struct ArcNode * next;
}ArcNode;

//定义顶点集合结构
typedef struct VexNode
{
	int vexname;//顶点名称(类似于v1,v2,...)
	ArcNode *  firstarc;
}VexNode,VexNodeArray[MAX_VEX_NUM];

//定义无向网
typedef struct UDG
{
	VexNodeArray vex_array;
	int  vex_num;
	int  arc_num;
}UDG;

//获取顶点在顶点集合中的位置(从0开始)
int  locateVex(UDG * g,int  vex_name)
{
	int i;
	for(i=0;i<MAX_VEX_NUM;i++)
	{
		if(g->vex_array[i].vexname==vex_name)
		{
			return i;
		}
	}
	return -1;
}

//构建无向网图
void   createUDG(UDG* g)
{
	printf("请输入顶点数和弧数:");
	scanf("%d%d",&g->vex_num,&g->arc_num);
	printf("请输入%d个顶点名:",g->vex_num);
	int i;
	for(i=0;i<g->vex_num;i++)
	{
		scanf("%d",&g->vex_array[i].vexname);
		g->vex_array[i].firstarc=NULL;
	}
	printf("请输入弧的起始顶点和结束顶点名和之间的权重值:\n");
	int  vex1,vex2;
	int  weight;
	int j;
	for(j=0;j<g->arc_num;j++)
	{
		scanf("%d%d%d",&vex1,&vex2,&weight);
		int vex1_pos=locateVex(g,vex1);
		int vex2_pos=locateVex(g,vex2);
		ArcNode *  p_ArcNode=(ArcNode*)malloc(1*sizeof(ArcNode));
		p_ArcNode->ivex=vex2_pos;
		p_ArcNode->weight=weight;
		p_ArcNode->next=NULL;

		p_ArcNode->next=g->vex_array[vex1_pos].firstarc;
		g->vex_array[vex1_pos].firstarc=p_ArcNode;	

		ArcNode *  p_ArcNode2=(ArcNode*)malloc(1*sizeof(ArcNode));
		p_ArcNode2->ivex=vex1_pos;
		p_ArcNode2->weight=weight;
		p_ArcNode2->next=NULL;

		p_ArcNode2->next=g->vex_array[vex2_pos].firstarc;
		g->vex_array[vex2_pos].firstarc=p_ArcNode2;	
	}
}

int visited[MAX_VEX_NUM];//访问标识数组
void DFS(UDG * g,int ivex)
{
	//从第i个顶点出发递归的深度优先遍历图G
	visited[ivex]=1;
	printf("%d",g->vex_array[ivex].vexname);//打印(访问)该顶点
	for(ArcNode*p=g->vex_array[ivex].firstarc;p;p=p->next)
	{
		//对于第ivex个顶点的每个未被访问的邻接点递归调用DFS
		if(!visited[p->ivex])
		{
			DFS(g,p->ivex);
		}
	}
}
//深度优先遍历无向图G(相当于树的先序遍历)(递归算法)
void   DFSTraverseGraph(UDG *g)
{
	int i;
	for(i=0;i<g->vex_num;i++)
	{
		visited[i]=0;//0表示未被访问,1表示已被访问
	}
	printf("请输入遍历的起始顶点:");
	int startVex;
	scanf("%d",&startVex);
	int startVexPos=locateVex(g,startVex);
	printf("一条深度优先遍历的序列为:");
	if(!visited[startVexPos])
	{
		DFS(g,startVexPos);
	}
	printf("\n");
}

//深度优先遍历无向图G(相当于树的先序遍历)(非递归算法)
void  DFSTraverseGraph2(UDG *g)
{
	int stack[MAX_VEX_NUM];//维护一个栈来存储访问图的顶点的(位置)信息
	int top=0;
	int i;
	for(i=0;i<g->vex_num;i++)
	{
		visited[i]=0;//0表示未被访问，1表示已被访问
	}
	printf("请输入遍历的起始点:");
	int startVex;
	scanf("%d",&startVex);
	int startVexPos=locateVex(g,startVex);
	printf("一条深度优先遍历序列为:");
	ArcNode *p;
	int ivex=startVexPos;
	while(!visited[ivex] || top!=-1)//栈不为空  
	{
		if(!visited[ivex])
		{
			visited[ivex]=1;
			printf("%d",g->vex_array[ivex].vexname);
			stack[top++]=ivex;
		}
		p=g->vex_array[ivex].firstarc;
		while(p && visited[p->ivex])//p不为空且p已经被访问过,就跳过
		{
			p=p->next;
		}
		if(p)
		{
			ivex=p->ivex;
		}
		else
		{
			ivex=stack[--top];
		}
	}
    printf("\n");
}

//广度优先遍历无向图G(相当于树的按层次遍历)(非递归算法)
void BFSTraverseGraph(UDG * g) 
{
	int queue[MAX_VEX_NUM];//维护一个队列来存储访问图的顶点的(位置)信息 
	int front=0,tail=0;//初始化队头、队尾指针,为空队列
	//初始化访问标志数组
	int i;
	for(i=0;i<g->vex_num;i++)
	{
		visited[i]=0;//0表示未被访问,1表示已被访问 
	}
	printf("请输入遍历的起始顶点:");
	int startVex;
	scanf("%d",&startVex);
	int startVexPos=locateVex(g,startVex);
	printf("一条广度遍历序列为:");
	queue[tail++]=startVexPos;
	int ivex;
	ArcNode *p;
	while(front!=tail)
	{
		ivex=queue[front++];
		if(!visited[ivex])
		{
			visited[ivex]=1;
			printf("%d",g->vex_array[ivex].vexname);
		}
		p=g->vex_array[ivex].firstarc;
		while(p)//p指向与ivex的邻接的(同一个层次的)还未被顶点
		{
			if(!visited[p->ivex])
			{
				queue[tail++]=p->ivex;
			}
			p=p->next;
		}
	}
}

void   printUDG(UDG* g)
{
	int i;
	for(i=0;i<g->vex_num;i++)
	{
		printf("%d\t",g->vex_array[i].vexname);
		ArcNode *tmp=g->vex_array[i].firstarc;
		while(tmp)
		{
			printf("--->%d(w=%d)\t",tmp->ivex+1,tmp->weight);
			tmp=tmp->next;
		}	
		printf("\n");	
	}
    printf("\n");
}

int main(int argc, char const *argv[])
{
	UDG  g;
	createUDG(&g);
	printUDG(&g);
	printf("\n深度优先遍历(递归算法):\n");
	DFSTraverseGraph(&g);

	printf("\n深度优先遍历(非递归算法):\n");
	//DFSTraverseGraph2(&g);

	printf("\n广度优先遍历(非递归算法):\n");
	BFSTraverseGraph(&g);
	return 0;
}