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
//邻接节点类型
typedef struct arcnode
{
    int  end_point_no;
    int weight;
    struct arcnode* next_arcnode;
}arcnode;

//定义记录节点编号与指向第一个节点指针
typedef struct
{
    int  begin_point_no;
    arcnode *  ptr_first;
}vartex_node;

//定义无向图
typedef struct
{
    vartex_node  array[MAX_POINT_NUM];
    int vertex_num;
    int arc_num;
}undigraph;

//根据顶点编号计算出在矩阵 的下标值
int  get_locat_position(undigraph * graph,int v)
{
    int i;
    for(i=0;i<graph->vertex_num;i++)
    {
        if(graph->array[i].begin_point_no==v)
        {
            return i;
        }
    }
    return -1;
}
//初始化有向图
void  init_undigraph(undigraph * graph)
{
    //输出图顶点树和边数
    printf("please input vertex num and arc num:\n");
    scanf("%d%d",&graph->vertex_num,&graph->arc_num);

    //输入顶点名称,并记录到vertex中
    printf("please input  vertex info:\n");
    int i  ;
    for(i=0;i<graph->vertex_num;i++)
    {
        scanf("%d",&graph->array[i].begin_point_no);
        graph->array[i].ptr_first=NULL;
    }

    //输入边(起始点 终止点 权重值)
    for(i=0;i<graph->arc_num;i++)
    {
        int  v1,v2,weight;
        scanf("%d%d%d",&v1,&v2,&weight);
        int r=get_locat_position(graph,v1);
        int c=get_locat_position(graph,v2);
        arcnode *  ptr_new_node=(arcnode*)malloc(1*sizeof(arcnode));
        ptr_new_node->end_point_no=c;
        ptr_new_node->weight=weight;
        ptr_new_node->next_arcnode=graph->array[r].ptr_first;
        graph->array[r].ptr_first=ptr_new_node;

        arcnode*  ptr_new_node_two=(arcnode*)malloc(1*sizeof(arcnode));
        ptr_new_node_two->end_point_no=r;
        ptr_new_node_two->weight=weight;
        ptr_new_node_two->next_arcnode=graph->array[c].ptr_first;
        graph->array[c].ptr_first=ptr_new_node_two;
    }
}


//输出邻接表(输出无向图)
void   print_undigraph(undigraph * graph)
{
    int  i;
    for(i=0;i<graph->vertex_num;i++)
    {
        if(graph->array[i].ptr_first!=NULL)
        {
            printf("begin point %d \n:",graph->array[i].begin_point_no);
            arcnode * ptr_tmp=graph->array[i].ptr_first;
            while(ptr_tmp!=NULL)
            {
                printf(" \t\tend point %d  weight %d:\n",ptr_tmp->end_point_no,ptr_tmp->weight);
                ptr_tmp=ptr_tmp->next_arcnode;
            }
        }
    }
}
int main(int argc,const char* argv[])
{
    undigraph  graph;
    init_undigraph(&graph);
    print_undigraph(&graph);
    return 0;
}