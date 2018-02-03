#include <stdio.h>
#include <stdlib.h>
#define  MAX_VALUE 8888
#define  MAX_POINT_NUM 10
typedef int  matrix[MAX_POINT_NUM][MAX_POINT_NUM];

typedef struct 
{
    int vertex[MAX_POINT_NUM];
    matrix vertex_matrix;
    int vertex_num;
    int arc_num;
}digraph;

int  locatevertex(digraph * graph,int v)
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
    printf("please input vertex and arc:\n");
    scanf("%d%d",&(graph->vertex_num),&(graph->arc_num));
    int i;
    printf("please input vertex point value:\n");
    for(i=0;i<graph->vertex_num;i++)
    {
        scanf("%d",&graph->vertex[i]);
    }
    int j;
    i=0;
    for(i=0;i<graph->vertex_num;i++)
    {
        for(j=0;j<graph->vertex_num;j++)
        {
            graph->vertex_matrix[i][j]=MAX_VALUE;
        }
    }
    
    int v1,v2;
    int weight;
    printf("please input between arc two point and weight:\n");
    int k;
    for(k=0;k<graph->arc_num;k++)
    {
        scanf("%d%d%d",&v1,&v2,&weight);
        i=locatevertex(graph,v1);
        j=locatevertex(graph,v2);
        graph->vertex_matrix[i][j]=weight;
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
int main(int argc,const char *argv[])
{
    digraph  graph;
    init_digraph(&graph);
    print_digraph(&graph);
    return 0;
}