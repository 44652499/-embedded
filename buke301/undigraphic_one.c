#include  <stdio.h>
#include <stdlib.h>
#define  MAX_VERTEXT_NUM  10
/*邻接表存储无向图
*/
//定义节点
typedef struct node
{
    int  endpoint;
    int weight;
    struct node *  next;
}node;

//定义存储顶点一维数组的类型
typedef struct vertextype
{
    int startpoint;
    node *  ptr_first;
}vertextype;
//定义无向图
typedef struct undigraphic
{
    int vertextnum;
    int arcnum;
    vertextype  array[MAX_VERTEXT_NUM];
}undigraphic;

//从存储顶点数组中获取顶点编号
int   get_vertex_point_no(undigraphic  * ptr_digrahic,int v)
{
    int i;
    for(i=0;i<ptr_digrahic->vertextnum;i++)
    {
        if(ptr_digrahic->array[i].startpoint==v)
        {
            return i;
        }
    }
    return -1;
}
//初始化无向图
void  innit_undigraphic(undigraphic  * ptr_digrahic)
{
    printf("input  vertex num and arc  num:\n");
    scanf("%d%d",&ptr_digrahic->vertextnum,&ptr_digrahic->arcnum);
    printf("input vertex point no:\n");
    int i;
    for(i=0;i<ptr_digrahic->vertextnum;i++)
    {
        scanf("%d",&ptr_digrahic->array[i].startpoint);
        ptr_digrahic->array[i].ptr_first=NULL;
    }
    printf("input  vertex point and arc:\n");
    for(i=0;i<ptr_digrahic->arcnum;i++)
    {
        int startpoint,endpoint,weight;
        scanf("%d%d%d",&startpoint,&endpoint,&weight);
        int s=get_vertex_point_no(ptr_digrahic,startpoint);
        int e=get_vertex_point_no(ptr_digrahic,endpoint);

        node  *  ptr_new_node=(node*)malloc(1*sizeof(node));
        ptr_new_node->endpoint=e;
        ptr_new_node->weight=weight;

        ptr_new_node->next=ptr_digrahic->array[s].ptr_first;
        ptr_digrahic->array[s].ptr_first=ptr_new_node;

        node  *  ptr_new_node2=(node*)malloc(1*sizeof(node));
        ptr_new_node2->endpoint=s;
        ptr_new_node2->weight=weight;

        ptr_new_node2->next=ptr_digrahic->array[e].ptr_first;
        ptr_digrahic->array[e].ptr_first=ptr_new_node2;
    }
}
//输出无向图
void  print_undigraphic(undigraphic  * ptr_digrahic)
{
    int i;
    for(i=0;i<ptr_digrahic->vertextnum;i++)
    {
        printf("start point no :%d\n",ptr_digrahic->array[i].startpoint);
        node *  ptr_tmp=ptr_digrahic->array[i].ptr_first;
        while(ptr_tmp!=NULL)
        {
            printf("\t end point no :%d  weidht:%d\n",ptr_tmp->endpoint,ptr_tmp->weight);
            ptr_tmp=ptr_tmp->next;
        }
    }
}

int main(int argc,const char* argv[])
{
    undigraphic graphic;
    innit_undigraphic(&graphic);
    print_undigraphic(&graphic);
    return 0;
}