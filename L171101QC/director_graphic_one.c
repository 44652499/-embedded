#include <stdio.h>
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
//定义顶点名与编号类型
typedef struct pointnameno
{
	char pointname[10];
	int pointindex;
}pointnameno;

//定义有向图结构
typedef struct DG
{
	int pointnum;
	int arcnum;
	int weight;
	pointnameno pointarray[N];//记录顶点名称与顶点编号
	int graphicarray[N][N];
}DG;

//根据顶点名获取其编号
int  get_point_index(DG *pdg,const char*  pointname)
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
//初始化邻接矩阵
void  init_dg_array(DG* pdg)
{
	int i,j;
	for(i=0;i<pdg->pointnum;i++)
	{
		for(j=0;j<pdg->pointnum;j++)
		{
			pdg->graphicarray[i][j]=-100;
		}
	}
}

//构建图
void init_dg(DG *  pdg)
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
	}
	//输入边信息
	init_dg_array(pdg);
	printf("please input begin point and end point and weight:");
	char beginpoint[10];
	char endpoint[10];
	int  weight;
	for(i=0;i<pdg->arcnum;i++)
	{
		scanf("%s%s%d",beginpoint,endpoint,&weight);
		int beginpointindex=get_point_index(pdg,beginpoint);
		int endpointindex=get_point_index(pdg,endpoint);
		if(beginpointindex!=-1 && endpointindex!=-1)
		{
			pdg->graphicarray[beginpointindex][endpointindex]=weight;
		}		
	}
}

//输出邻接矩阵
void  print_dg(DG *  pdg)
{
	int i,j;
	for(i=0;i<pdg->pointnum;i++)
	{
		for(j=0;j<pdg->pointnum;j++)
		{
			if(pdg->graphicarray[i][j]!=-100)
			{
				printf("%s -->%s weight=%d\n",pdg->pointarray[i].pointname,pdg->pointarray[j].pointname,pdg->graphicarray[i][j]);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	DG dg;
	init_dg(&dg);
	print_dg(&dg);
	return 0;
}