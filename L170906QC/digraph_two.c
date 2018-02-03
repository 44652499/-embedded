#include <stdio.h>
#include <stdlib.h>
#define  MAX_VALUE 8888
#define  MAX_VERTEX_NUM 10
typedef int matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
    int    vertex[MAX_VERTEX_NUM];
    matrix vertex_matrix;
    int vertex_num;
    int arc_num;
}digraph;

int locate_vertex_pos(digraph* graph,int v)
{
    int i;
    for(i=0;i<graph->vertex_num;i++)
    {
        if(graph->vertex[i]==v)
        {
            return i;
        }
    }
    return -1;
}

void  init_digraph(digraph * graph)
{
    printf("please input vertex num and arc num:\n");
    scanf("%d%d",&graph->vertex_num,&graph->arc_num);
   
    printf("please input vertex num:\n");
    int i;
    for(i=0;i<graph->vertex_num;i++)
    {
        scanf("%d",&graph->vertex[i]);
    }

    int j=0;
    for(j=0;j<graph->vertex_num;j++)
    {
        for(i=0;i<graph->vertex_num;i++)
        {
            graph->vertex_matrix[i][j]=MAX_VALUE;
        }
    }
    printf("please input points and arcs:\n");
    for(j=0;j<graph->arc_num;j++)
    {
        int v1,v2;
        int weight;
        scanf("%d%d%d",&v1,&v2,&weight);
        int row=locate_vertex_pos(graph,v1);
        int col=locate_vertex_pos(graph,v2);
        graph->vertex_matrix[row][col]=weight;
    }
}

void print_digraph(digraph * graph)
{
    int i,j;
    for(i=0;i<graph->vertex_num;i++)
    {
        for(j=0;j<graph->vertex_num;j++)
        {
            if(graph->vertex_matrix[i][j]==MAX_VALUE)
            {
                printf("N\t");
            }
            else
            {
                printf("%d\t",graph->vertex_matrix[i][j]);
            }
        }
        printf("\n");
    }
}
int main(int argc,const char* argv[])
{
    digraph graph;
    init_digraph(&graph);
    print_digraph(&graph);
    return 0;
}