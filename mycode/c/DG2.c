#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE  88999
#define MAX_VEX_NUM 10
typedef struct 
{
	int vex_array[MAX_VEX_NUM];
	int ** ptr_array;
	int vex_num;
	int arc_num;
}DG;
int  visited[MAX_VEX_NUM];
//系统错误信息输出
void  sys_error_msg(const char *error_msg)
{
	printf("%s\n",error_msg);
	exit(-1);
}
//初始化二维数组,作为有向图的矩阵
int**  init_two_array(int row,int col)
{
	int** ptr_array=(int**)malloc(row*sizeof(int*));
	if(ptr_array==NULL)
	{
		sys_error_msg("init_two_array  malloc  fail");
	}
	int i;
	for(i=0;i<row;i++)
	{
		*(ptr_array+i)=(int*)malloc(col*sizeof(int));
		if(*(ptr_array+i)==NULL)
		{
			sys_error_msg("init_two_array  malloc row fail");
		}
	}
	int j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			ptr_array[i][j]=MAX_VALUE;
		}
	}
	return ptr_array;
}

//释放动态有向图矩阵
void  free_two_array(int** ptr_array,int row)
{
	int i;
	for(i=0;i<row;i++)
	{
		free(*(ptr_array+i));
		*(ptr_array)=NULL;
	}
	free (ptr_array);
	ptr_array=NULL;
}

//若图G中存在顶点v,则返回v在图中的位置信息,否则返回其他信息
int locate_vex(DG * g,int v)
{
	int i;
	for(i=0;i<g->vex_num;i++)
	{
		if(g->vex_array[i]==v)
		{
			return i;
		}
	}
	return -1;
}

//采用邻接矩阵表示法构造有向网G
void  create_DG(DG* g)
{
	printf("请输入顶点数和弧数:");
	scanf("%d%d",&g->vex_num,&g->arc_num);

	printf("请输入顶点编号(1,2,3,...):");
	int i;
	for(i=0;i<g->vex_num;i++)
	{
		scanf("%d",&g->vex_array[i]);
	}

	g->ptr_array=init_two_array(g->vex_num,g->vex_num);
	int vex1,vex2,weight;
	int vex1_index,vex2_index;
	printf("请输入弧的起点和终点及权重值:\n");
	for(i=0;i<g->arc_num;i++)
	{
		scanf("%d%d%d",&vex1,&vex2,&weight);
		vex1_index=locate_vex(g,vex1);
		vex2_index=locate_vex(g,vex2);
		g->ptr_array[vex1_index][vex1_index]=0;
		g->ptr_array[vex1_index][vex2_index]=weight;
	}
}

//打印邻接矩阵
void  print_DG(DG * g)
{
	int i,j;
	printf("\n打印有向网的邻接矩阵:\n");
	for(i=0;i<g->vex_num;i++)
	{
		for(j=0;j<g->vex_num;j++)
		{
			if(g->ptr_array[i][j]!=MAX_VALUE)
			{
				printf("%d\t",g->ptr_array[i][j]);
			}
			else
			{
				printf("NULL\t");
			}
		}
		printf("\n");
	}
	printf("\n");
}

int arc_sum(int * vex_flags,int n)
{
	int sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		sum+=vex_flags[i];
	}
	return sum;
}

void  min_distance_vex(DG *g,int v)
{
	int *dis_array=(int*)malloc(sizeof(int)*g->vex_num);
	if(dis_array==NULL)
	{
		sys_error_msg("min_distince_vex  dis_array malloc fail");
	}

	int* flags_array=(int*)malloc(sizeof(int)*g->vex_num);
	if(flags_array==NULL)
	{
		sys_error_msg("min_distince_vex  flags_array malloc fail");
	}

	int i,j;
	for(i=0;i<g->vex_num;i++)
	{
		if(g->vex_array[i]==v)
		{
			flags_array[i]=1;
			for(j=0;j<g->vex_num;j++)
			{
				dis_array[j]=g->ptr_array[i][j];			
			}
			break;
		}
	}
	while(arc_sum(flags_array,g->vex_num)!=g->vex_num)
	{
		int i=0;
		int min=MAX_VALUE;
		int next=-1;
		for(i=0;i<g->vex_num;i++)
		{
			if(flags_array[i]!=1)
			{
				if(dis_array[i]<min)
				{
					min=dis_array[i];
					next=i;
				}
			}
		}
		flags_array[next]=1;
		for(i=0;i<g->vex_num;i++)
		{
			if(dis_array[next]+g->ptr_array[next][i]<dis_array[i])
			{
				dis_array[i]=dis_array[next]+g->ptr_array[next][i];
			}
		}
	}
	printf("the min distance between %d and other vex:\n",v);
	for(i=0;i<g->vex_num;i++)
	{
		printf("%d\t",dis_array[i]);
	}

	free(flags_array);
	free(dis_array);
	flags_array=NULL;
	dis_array=NULL;
}

int main(int argc, char const *argv[])
{
	DG g;
	create_DG(&g);
	print_DG(&g);

	min_distance_vex(&g,1);
	printf("\n\n");
	free_two_array(g.ptr_array,g.vex_num);
	return 0;
}