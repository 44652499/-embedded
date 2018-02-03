#include  <stdio.h>
#define MAX_VERTEX_NUM 10
#define  MAX_VALUE 99999
typedef  int  MARGIN[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

/*
图:由n个点 和m条弧线,任意两个点相互连接,形成一个网状图
图分类:
1.有向图:只能是单向
2.无向图:双向
图存储方式:邻接矩阵,邻接表,多重邻接表,十字邻接表
注意问题:
1.图中不存在绝对起点,相对起点和终点
2.一般在程序中,使用一个一维数组记录顶点编号

邻接矩阵:一般是用来处理有向图
*/
//定义有向图结构
typedef struct digraphic
{
    int vertexnum;
    int arcnum;
    int weight;
    int vartexarray[MAX_VERTEX_NUM];
    MARGIN  marginarray;
}digraphic;
//从存储顶点数组中获取顶点编号
int   get_vertex_point_no(digraphic  * ptr_digrahic,int v)
{
    int i;
    for(i=0;i<ptr_digrahic->vertexnum;i++)
    {
        if(ptr_digrahic->vartexarray[i]==v)
        {
            return i;
        }
    }
    return -1;
}
//初始化 有向图
void  initdigraphic(digraphic  * ptr_digrahic)
{
    printf("input  vertex num and arc  num:\n");
    scanf("%d%d",&ptr_digrahic->vertexnum,&ptr_digrahic->arcnum);
    printf("input vertex point no:\n");
    int i ;
    for(i=0;i<ptr_digrahic->vertexnum;i++)
    {
        scanf("%d",&ptr_digrahic->vartexarray[i]);
    }
    int j;
    for(i=0;i<ptr_digrahic->vertexnum;i++)
    {
        for(j=0;j<ptr_digrahic->vertexnum;j++)
        {
            ptr_digrahic->marginarray[i][j]=MAX_VALUE;
        }
    }
    printf("input  vertex point and arc:\n");
    for(i=0;i<ptr_digrahic->arcnum;i++)
    {
        int start_point,end_point,w;
        scanf("%d%d%d",&start_point,&end_point,&w);
        int r=get_vertex_point_no(ptr_digrahic,start_point);
        int c=get_vertex_point_no(ptr_digrahic,end_point);
        ptr_digrahic->marginarray[r][c]=w;
    }
}

//输出有向图
void  print_digraphic(digraphic * ptr_digrahic)
{
    int i,j;
    for(i=0;i<ptr_digrahic->vertexnum;i++)
    {
        for(j=0;j<ptr_digrahic->vertexnum;j++)
        {
            if(ptr_digrahic->marginarray[i][j]!=MAX_VALUE)
            {
                printf("%d\t",ptr_digrahic->marginarray[i][j]);
            }
            else
            {
                printf("N\t");
            }
        }
        printf("\n");
    }
}

int main(int argc,const char* argv[])
{
    digraphic  graphic;
    initdigraphic(&graphic);
    print_digraphic(&graphic);
    return 0;
}