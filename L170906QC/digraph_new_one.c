#include <stdio.h>
#include <stdlib.h>
#define   MAX_POINT_NUM 10
#define   MAX_VALUE  888888
/*
图:是一种线性结构,由n个点和m条边组成,任意两个点之间可以用连线连接.
图分为:
1.有向图(DG)
2.无向图(UDG)

图存储方法:
1.邻接矩阵(有向图)
2.邻接表
3.多重邻接表
3.十字交叉链表(有向图)
*/

//邻接矩阵
//定义有向图结构
typedef struct 
{
    int vertex[MAX_POINT_NUM];//记录顶点名成员编号关系
    int martrix[MAX_POINT_NUM][MAX_POINT_NUM];//记录点与点之间权重值
    int vertex_point_num;//顶点数
    int arc_num;//边数
    int weight;//权重
}digraph;

//根据顶点编号计算出在矩阵 的下标值
int  get_locat_position(digraph * graph,int v)
{
    int i;
    for(i=0;i<graph->vertex_point_num;i++)
    {
        if(graph->vertex[i]==v)
        {
            return i;
        }
    }
    return -1;
}
//初始化有向图
void  init_digraph(digraph * graph)
{
    //输出图顶点树和边数
    printf("please input vertex num and arc num:\n");
    scanf("%d%d",&graph->vertex_point_num,&graph->arc_num);

    //输入顶点名称,并记录到vertex中
    int i  ;
    for(i=0;i<graph->vertex_point_num;i++)
    {
        scanf("%d",&graph->vertex[i]);
    }
    //初始矩阵值为最大值
    int j;
    for(i=0;i<graph->vertex_point_num;i++)
    {
        for(j=0;j<graph->vertex_point_num;j++)
        {
            graph->martrix[i][j]=MAX_VALUE;
        }
    }

    //输入边(起始点 终止点 权重值)
    for(i=0;i<graph->arc_num;i++)
    {
        int  v1,v2,weight;
        scanf("%d%d%d",&v1,&v2,&weight);
        int r=get_locat_position(graph,v1);
        int c=get_locat_position(graph,v2);
        graph->martrix[r][c]=weight;
    }
}


//输出矩阵(输出有向图)
void   print_digraph(digraph * graph)
{
    int i ,j;
    for(i=0;i<graph->vertex_point_num;i++)
    {
        for(j=0;j<graph->vertex_point_num;j++)
        {
            if(graph->martrix[i][j]==MAX_VALUE)
            {
                printf("N\t");
            }
            else
            {
                printf("%d\t",graph->martrix[i][j]);
            }
        }
        printf("\n");
    }
}
int main(int argc,const char* argv[])
{
    digraph  graph;
    init_digraph(&graph);
    print_digraph(&graph);
    return 0;
}