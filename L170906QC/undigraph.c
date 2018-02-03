#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 10
typedef struct arcnode
{
    int vertex_point;
    int weight;
    struct arcnode*  next;  
}arcnode;

typedef struct node
{
    int data;
    arcnode * beginarc;
}node;

typedef struct 
{
    node vertexs[MAX_VERTEX_NUM];
    int vertex_num;
    int arc_num;
}undigraph;

int  locate_vertex_pos(undigraph* graph,int v)
{
    int i;
    for(i=0;i<graph->vertex_num;i++)
    {
        if(graph->vertexs[i].data==v)
        {
            return i;
        }
    }
    return -1;
}

void  init_undigraph(undigraph * graph)
{
    printf("please input vertex num and arc num:\n");
    scanf("%d%d",&graph->vertex_num,&graph->arc_num);
    printf("please input vertex value:\n");
    int i;
    for(i=0;i<graph->vertex_num;i++)
    {
        scanf("%d",&graph->vertexs[i].data);
        graph->vertexs[i].beginarc=NULL;
    }
    int v1,v2,weight;
    printf("please input vertex point and weight:\n");
    int j;
    for(j=0;j<graph->arc_num;j++)
    {        
        scanf("%d%d%d",&v1,&v2,&weight);
        int begin=locate_vertex_pos(graph,v1);
        int end=locate_vertex_pos(graph,v2);

        arcnode *  ptr_first=(arcnode*)malloc(1*sizeof(arcnode));
        ptr_first->vertex_point=end;
        ptr_first->weight=weight;
        ptr_first->next=graph->vertexs[begin].beginarc;
        graph->vertexs[begin].beginarc=ptr_first;

        arcnode *  ptr_second=(arcnode*)malloc(1*sizeof(arcnode));
        ptr_second->vertex_point=begin;
        ptr_second->weight=weight;
        ptr_second->next=graph->vertexs[end].beginarc;
        graph->vertexs[end].beginarc=ptr_second;
    }
}

void  print_undigraph(undigraph* graph)
{
    printf("\n");
    int i;
    for(i=0;i<graph->vertex_num;i++)
    {
        printf("vertex point %d arc is:",graph->vertexs[i].data);
        arcnode *ptr_tmp=graph->vertexs[i].beginarc;
        while(ptr_tmp!=NULL)
        {
            printf("v%d v%d(weight:%d)\t",graph->vertexs[i].data,graph->vertexs[ptr_tmp->vertex_point].data,ptr_tmp->weight);
            ptr_tmp=ptr_tmp->next;
        }
        printf("\n");
    }
}

int main(int argc,const char *argv[])
{
    undigraph graph;
    init_undigraph(&graph);
    print_undigraph(&graph);
    return 0;
}