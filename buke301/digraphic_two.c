#include  <stdio.h>
#include <stdlib.h>
#define  MAX_VERTEXT_NUM  10
/*
图遍历:
1.DFS:深度遍历
2.BFS:广度遍历
注意点:任何一个顶点在访问路线中只能出现一次.
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

//DFS 深度遍历(递归实现)
int   visited[MAX_VERTEXT_NUM];
void  printf_undigraphic(undigraphic  * ptr_digrahic,int startvextex,int   startpoint)//startpoint 永远记录起点
{
    if(!visited[startvextex])
    {
        printf("%d\t",startvextex);
        visited[startvextex]=1;
        node  *  ptr_tmp=ptr_digrahic->array[startvextex].ptr_first;
        while(ptr_tmp!=NULL)
        {
            printf_undigraphic(ptr_digrahic,ptr_tmp->endpoint,startpoint);
            ptr_tmp=ptr_tmp->next;
            if(ptr_digrahic->array[startvextex].startpoint==startpoint && ptr_tmp!=NULL)
            {
                printf("\n");
                printf("%d\t",startvextex);
            }           
        }
    }   
}

//DFS 深度遍历(非递归实现)
void  printf_undigraphic_two(undigraphic  * ptr_digrahic,int startvextex)
{
    int  visited_two[MAX_VERTEXT_NUM];
    int i;
    for(i=0;i<ptr_digrahic->vertextnum;i++)
    {
        visited_two[i]=0;
    }
    int stack[ptr_digrahic->vertextnum];
    int top=0;
    while(!visited_two[startvextex]||top!=-1)
    {
        if(!visited_two[startvextex])
        {
            printf("%d\t",startvextex);
            visited_two[startvextex]=1;
            stack[top++]=startvextex;
        }
        node  * ptr_tmp=ptr_digrahic->array[startvextex].ptr_first;
        while(ptr_tmp!=NULL && visited_two[ptr_tmp->endpoint])
        {
            ptr_tmp=ptr_tmp->next;
        }
        if(ptr_tmp!=NULL)
        {
            startvextex=ptr_tmp->endpoint;
        }
        else
        {
            startvextex=stack[--top];
        }
    }
}

//BFS
void  printf_undigraphic_BFS(undigraphic  * ptr_digrahic,int startvextex)
{
    int  visited_two[MAX_VERTEXT_NUM];
    int i;
    for(i=0;i<ptr_digrahic->vertextnum;i++)
    {
        visited_two[i]=0;
    }
    int queue[ptr_digrahic->vertextnum];
    int front=-1,tail=-1;
    queue[++tail]=startvextex;
    while(front!=tail)
    {
        startvextex=queue[++front];
        if(!visited_two[startvextex])
        {
            printf("%d\t",startvextex);
            visited_two[startvextex]=1;            
        }
        node  * ptr_tmp=ptr_digrahic->array[startvextex].ptr_first;
        while(ptr_tmp!=NULL )
        {
            if(!visited_two[ptr_tmp->endpoint])
            {
                queue[++tail]=ptr_tmp->endpoint ;
            }            
            ptr_tmp=ptr_tmp->next;
        }
    }
}

int main(int argc,const char* argv[])
{
    undigraphic graphic;
    innit_undigraphic(&graphic);
    print_undigraphic(&graphic);
    //printf_undigraphic(&graphic,0,0);
   // printf_undigraphic_two(&graphic,0);
    printf_undigraphic_BFS(&graphic,0);
    return 0;
}