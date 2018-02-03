#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 10

typedef struct arcnode
{
    int arcvalue;
    int weight;
    struct arcnode *  nextarc;
}arcnode;

typedef struct vertexnode
{
    int vertexvalue;
    arcnode* next;
}vertexnode;

typedef struct
{
    vertexnode  vertexarray[MAX_VERTEX_NUM];
    int vertexnum;
    int arcnum;
}undigraph;

