#define VexNum  10 //顶点个数
#define MAX  36
#define MAXedg 30
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
//linux下的清屏函数,windows下是system("clr")
void clrscr()  
{ 
 system("clear"); 
}


typedef enum
{
  DG,DN,UDG,UDN  
}GaphKind;//{有向图,有向网,无向网}

typedef int AdjMatrix[MAX][MAX]; //邻接矩阵数组


//矩阵图结构体 
typedef struct 
{ 
 int vexs[MAX]; //顶点向量
 AdjMatrix arcs; //邻接矩阵
 int vexnum,arcnum;//图的当前顶点数和弧度数
 GaphKind kind;//图的种类标志

}Matrix_Graph;


typedef struct vexnode
{ 

 char  name[10];     
 char  information[100];     
 struct edgenode *link;       

}vexnode;                     

 
typedef struct edgenode 
{ 

 int  adjvex;     
 int  length;     
 char info[10];   
 char info2[100];    
 struct edgenode *next; 
}edgenode, *Node ;    

 
typedef  struct Edge 
{  
 
 int lengh;    
 int ivex, jvex;   
 struct Edge *next;   

} EdgeType;    


typedef struct vertex 
{ 
 int  num;    
 char name[10];   

}vertex; 

 
typedef struct adjmax
{ 
 vertex vexs[MAX];            
 int edges[MAX][MAX];   
}adjmax;    


void Name(int i)
{
  switch(i)
  {
    case 1:
    printf("1:行政楼 \n\n");break;
    case 2:
    printf("2:国家南方林业生态工程实验室 \n\n");break;
    case 3:
    printf("3:电子信息楼 \n\n");break;
    case 4:
    printf("图书馆 \n\n");break;
    case 5:
    printf("体育与艺术馆 \n\n");break;
    case 6:
    printf("东园体育场 \n\n");break;
    case 7:
    printf("稻米深加工及副产物国家工程实验室 \n\n");break;
    case 8:
    printf("文科综合楼 \n\n");break;
    case 9:
    printf("西园体育场和研究生院楼 \n\n");break;
    case 10:
    printf("生命科学楼 \n\n");break;
    default:
    printf("景点编号输入错误!请输入:1-10的数字编号: \n\n");
    break;

  }


}

void SceneryInformation(int i)
{
  switch(i)
  {
    case 1:
    printf("1:行政楼:中南林业科技大学行政楼主要用于迎接外宾和开会及学校的日常管理工作\n\n");break;
    case 2:
    printf("2:南方林业生态应用技术国家工程实验室:成立于2008年,由国家发改委委托中南林业科技大学进行组建,她的建设对于完善我国南方林业特色技术创新体系，强化林业产业技术原始创新能力，加强林业技术基础研究和产业研发之间的有机衔接，有效整合产学研优势资源，着力提升林业产业核心竞争力和林业生态工程技术的国际竞争力，促进我国南方林业产业发展、生态建设和国家重点工程的技术进步，加速产学研联合、科技成果转化和学科体系建设等诸多方面都有重要意义。\n\n");break;
    case 3:
    printf("3:电子信息楼:隶属于计算机与信息工程学院,计院的学生主要在这里上实验课,实验设备齐全\n\n");break;
    case 4:
    printf("图书馆:是中南林业科技大学的标志性建筑,于2007建成,外观漂亮壮观,内部环境宽敞明亮,藏书齐全 \n\n");break;
    case 5:
    printf("体育与艺术馆:中南林业科技大学的标志性建筑,外观设计洋溢着现代化的气息,可容纳6000多人,是湖南省一流的体育馆,也是中南地区一流的体育馆.2015,承办亚洲男子篮球竞标赛,副比赛场馆,中国羽协比赛 \n\n");break;
    case 6:
    printf("东园体育场:草坪是真草,日常会有一些业余足球队到这里比赛,晚上会有学生在这跑步 \n\n");break;
    case 7:
    printf("稻米深加工及副产物国家工程实验室:最近新建的实验室,隶属于食品科学与工程学院,用于稻米深加工及副产物的研究 \n\n");break;
    case 8:
    printf("文科综合楼:与2013动工,2016建成完工,外观特别壮观,洋溢这现代化的气息,大力的改善了学校的硬件设施,为学生提供了更好的学习条件\n\n");break;
    case 9:
    printf("西园体育场和研究生院楼:这里主要有足球场,篮球场,网球场,羽毛球场,游泳场,及研究生院楼也在其附近,场地宽阔可供众人娱乐 \n\n");break;
    case 10:
    printf("生命科学楼:也是林科大的标志性建筑,样子壮观漂亮 \n\n");break;
    default:
    printf("景点编号输入错误!请输入:1-10的数字编号: \n\n");
    break;

  }


}

void travgraph(vexnode g[], int n, adjmax adj)//查找指定景点
{
  
  int flag=1,i=1;
  int num; 
  char ch;   
 printf("\t\t\t 请输入您要查询的景点序号:\n\n");
 printf("\t\t\t 1.行政楼 2.南方林业生态应用技术国家工程实验室  3.电子信息楼 4.图书馆 \n\n");
 printf("\t\t\t 5.体育与艺术馆    6.东院体育场   7.稻米深加工及副产物国家工程实验室  \n\n");
 printf("\t\t\t 8.文科综合楼      9.西园体育场和研究生院楼       10.生命科学楼      \n\n");
 printf("你的选择是:");
 scanf("%d",&num);
 getchar();//清除缓存
 printf("该景点的名称是:");
 Name(num);
 printf("此景店的介绍是:");
 SceneryInformation(num);
 do{
 	printf("\t\t 是否继续? Y/N \n");
 	printf("\t\t 你的选择: ");
 	scanf("%c",&ch);
 	getchar();
 	if(ch=='Y' || ch=='y')
 	{
 		clrscr();
 		flag = 1;
 		i=1;
 		printf("\t\t\t 请再次输入您要查询的景点序号: \n\n");
 		printf("\t\t\t 1.行政楼 2.南方林业生态应用技术国家工程实验室  3.电子信息楼 4.图书馆 \n\n");
        printf("\t\t\t 5.体育与艺术馆    6.东院体育场   7.稻米深加工及副产物国家工程实验室  \n\n");
        printf("\t\t\t 8.文科综合楼      9.西园体育场和研究生院楼       10.生命科学楼      \n\n");
        printf("你的选择是:");
        scanf("%d",&num);
        getchar();//清除缓存
        printf("该景点的名称是:");
        Name(num);
        printf("此景店的介绍是:");
        SceneryInformation(num);
        continue;

 	}
  else
  {
  	flag = 0 ;
    printf("请再次按回车键返回至主菜单界面");

  }
  break;
  
 }while(1);

}

void CreateGraph(Matrix_Graph *G) //Matrix_Graph:矩阵图
{//采用数组(邻接矩阵)表示法,构造无向网表
  int i , j;
  for(i=1;i<=VexNum;i++)
  	{
  		G->vexs[i]=i;//构造顶点向量
    }

  for(i=1;i<=VexNum;i++)//初始化邻接矩阵

    for(j=1;j<VexNum;j++)  G->arcs[i][j]=0;
    	G->arcs[1][2]=7;G->arcs[1][4]=20;G->arcs[1][7]=30;
      

        G->arcs[2][1]=7;G->arcs[2][3]=3;G->arcs[2][10]=4;G->arcs[2][4]=12;
    	G->arcs[2][3]=3;

    	G->arcs[3][2]=3;G->arcs[3][4]=4;G->arcs[3][5]=9;
    	G->arcs[3][10]=2;

    	G->arcs[4][1]=20;G->arcs[4][2]=12;G->arcs[4][3]=4;G->arcs[4][5]=4;
        G->arcs[4][6]=1;G->arcs[4][7]=15;G->arcs[4][9]=21;

        G->arcs[5][3]=9;G->arcs[5][4]=4; G->arcs[5][6]=2;
        G->arcs[5][10]=4;

        G->arcs[6][4]=1; G->arcs[6][5]=2;G->arcs[6][7]=23;

        G->arcs[7][1]=30;G->arcs[7][4]=15;G->arcs[7][6]=23;G->arcs[7][8]=14;
        G->arcs[7][9]=17;

        G->arcs[8][7]=14; G->arcs[8][9]=25;

        G->arcs[9][4]=21;G->arcs[9][7]=17;G->arcs[9][8]=25;

        G->arcs[10][2]=6; G->arcs[10][3]=2; G->arcs[10][4]=2; G->arcs[10][5]=4;

for(i=1;i<VexNum;i++)
	for(j=1;j<VexNum;j++)
		if(G->arcs[i][j]==0)
			G->arcs[i][j]=MAX;

}




void path(Matrix_Graph *G,int s,int e) 
{ 

 int i,j,u,c=1,t,v; 
 int r[VexNum+1][VexNum+1]; 
 int T[VexNum],flag[VexNum],d[VexNum]; //d[N]是权值,因为这是无向网表,一个要被访问正反两次,所以flag[N]是访问次数的标志位
 for(i=0;i<=VexNum;i++) 
  for(j=0;j<=VexNum;j++) r[i][j]=0; //设置空路径
  
 for(i=1;i<=VexNum;i++) 
  { 
   T[i]=-1; 
   flag[i]=1; 
   d[i]=MAX; 
  } 

  flag[s]=0; 
  while(c<=VexNum) 

  {  
     t=MAX; 
    for(i=1;i<=VexNum;i++) 
    if(flag[i]&&G->arcs[s][i]<t) 
    { 
     t=G->arcs[s][i];v=i;r[v][1]=v;} 
    for(i=1;i<=c;i++) 
     for(j=1;j<=VexNum;j++) 
      if(flag[j]&&d[i]+G->arcs[T[i]][j]<t)//修改权值和路径 
      { 
       t=d[i]+G->arcs[T[i]][j];v=j; 
       if(r[v][0]!=-1) 
       { 
        u=1; 
        while(r[T[i]][u]!=0) 
        { 
         r[v][u]=r[T[i]][u];u++;} 
       } 
       r[v][u]=v; 
      } 

      r[v][0]=-1; 
      T[c]=v; 
      flag[v]=0; 
      d[c]=t; 
      c++; 
  } 

  printf("\n最短路径是以下这条:\n(%d)",s); 
  j=1; 
  while(r[e][j]!=0) 
  { 
   printf("-->(%d)",r[e][j]);
   j++;
  } 
   printf("\n\n"); 
} 






void JieMian()
{   

	int i,j ;
	Matrix_Graph G;
	CreateGraph(&G);
	int n =0;
    vexnode g[MAX];
    adjmax adj;
    EdgeType e[MAXedg];
  

	char choice ='x';
	while(1)
	{
		clrscr();
		printf("\n\n\t\t                  ***校--园--导--游--图***");
    	printf("\n\n\t\t          --------------------------------------\n\n");
	    printf("\t\t\t          1.林科大校园地图:\n\n");
	    printf("\t\t\t          2.林科大景点信息:\n\n");
	    printf("\t\t\t          3.查找两点间最短路径:\n\n");
	    printf("\t\t\t          0.退出\n\n");
	    printf("\n\t\t           ---------------------------------------\n\n");
	    printf("\t\t          中南林业科技大学校训:求实 求新 树木 树人\n\n");
	    printf("\n\t\t           ---------------------------------------\n\n");
	    printf("\t\t          请输入你的选择(0-3):\n\n");
	    choice=getchar();
	    switch(choice)
	    {
            case '1':
            clrscr();
printf("\t\t                             -------林-----科-----大-----地-----图--------           \n\n");


printf("                                  [5.体育与艺术馆].                  \n\n ");
printf("                                     .              .                             \n\n");          
printf("                                   .                     .                                     \n\n  ");
printf("                                 .                           . [3.电子信息楼]                 \n\n");
printf("                               .                                      .  .                          \n\n ");           
printf("                             .                                     .                          \n\n");
printf("                           .                         [10.生科楼].         .                       \n\n  ");
printf("                         .                               .                                      \n\n");           
printf("                       .                               .                 .                      \n\n");
printf("                [6.东园体育场]                        .                                         \n\n ");
printf("                             .                     .                     .                  \n\n ");       
printf("                               .                 .                                              \n\n");           
printf("                                 .             .                  . [2.林业工程实验室]                 \n\n");
printf("                                   .        .              .                          .                 \n\n  ");
printf("                                     .    .         .                                    .               \n\n");                    
printf("                                       .[4.图书馆].    .    .    .    .   .   .   .    .    .   .    . [1.行政楼]        \n\n");
printf("                                       .                      .                                            \n\n");
printf("                                     .                   .                                              \n\n");
printf("                                  .                 .                                                      \n\n");
printf("                                .            .                                                           \n\n");
printf("                      [7.稻米深加工实验室].                                                                \n\n");
printf("                               .                                                                        \n\n ");
printf("                               .                                                                       \n\n");
printf("                               .                                                                    \n\n");
printf("[8.文科综合楼].  .   .   .   .   .                                                                    \n\n");
printf("     .                           .                                                           \n\n");
printf("     .                             .                                                         \n\n");
printf("     .                              .                                                      \n\n");
printf("     .                                .                                                    \n\n");
printf("     .                                  .                                                \n\n");
printf("     .    .     .     .    .    .    .[9.西园体育场]                                   \n\n ");


printf("\t\t                                 请输入任意键返回主菜单");
getchar();
getchar();
break;

case '2':
clrscr();
travgraph(g,n,adj);
getchar();
break;

case '3':
clrscr();
printf("\t\t                             -----林-----科-----大-----地-----图-----\n\n");


printf("                                  [5.体育与艺术馆].                  \n\n ");
printf("                                     .              .                             \n\n");          
printf("                                   .                     .                                     \n\n  ");
printf("                                 .                           . [3.电子信息楼]                 \n\n");
printf("                               .                                      .  .                          \n\n ");           
printf("                             .                                     .      .                       \n\n");
printf("                           .                         [10.生科楼].         .                       \n\n  ");
printf("                         .                               .                .                       \n\n");           
printf("                       .                               .                  .                      \n\n");
printf("                [6.东园体育场]                        .                    .                     \n\n ");
printf("                             .                     .                      .                  \n\n ");       
printf("                               .                 .                        .                         \n\n");           
printf("                                 .             .                  . [2.林业工程实验室]                 \n\n");
printf("                                   .        .              .                                           \n\n  ");
printf("                                     .    .         .                                                   \n\n");                    
printf("                                       .[4.图书馆]......................................[1.行政楼]        \n\n");
printf("                                       .                           .                                       \n\n");
printf("                                     .                       .                                              \n\n");
printf("                                  .                 .                                                      \n\n");
printf("                                .            .                                                           \n\n");
printf("                      [7.稻米深加工实验室]                                                                \n\n");
printf("                               .                                                                        \n\n ");
printf("                               .                                                                       \n\n");
printf("                               .                                                                    \n\n");
printf("[8.文科综合楼]...................                                                                 \n\n");
printf("     .                           .                                                           \n\n");
printf("     .                             .                                                         \n\n");
printf("     .                              .                                                      \n\n");
printf("     .                                .                                                    \n\n");
printf("     .                                  .                                                \n\n");
printf("     ..................................[9.西园体育场]                                   \n\n ");

 
printf("\t\t 你现在的位置是 (请输入1-10的序号): \n");
printf("\t\t\t 1.行政楼 2.南方林业生态应用技术国家工程实验室  3.电子信息楼 4.图书馆 \n\n");
printf("\t\t\t 5.体育与艺术馆    6.东院体育场   7.稻米深加工及副产物国家工程实验室  \n\n");
printf("\t\t\t 8.文科综合楼      9.西园体育场和研究生院楼       10.生命科学楼      \n\n");
printf("\t\t你的输入是: \n");
scanf("%d",&i);
getchar();
printf("\t\t你要去的地方是: (请输入1-10的序号):  \n");
printf("\t\t\t 1.行政楼 2.南方林业生态应用技术国家工程实验室  3.电子信息楼 4.图书馆 \n\n");
printf("\t\t\t 5.体育与艺术馆    6.东院体育场   7.稻米深加工及副产物国家工程实验室  \n\n");
printf("\t\t\t 8.文科综合楼      9.西园体育场和研究生院楼       10.生命科学楼      \n\n");


printf("\t\t你的输入是: \n");
scanf("%d",&i);
getchar();


//求最短路径
path(&G ,i ,j);	 

getchar();


CreateGraph(&G);
do{
    printf("是否继续查询: Y/N");
 char ch;
 int flag=1;
 scanf("%c ,&ch");
 getchar();
 if(ch=='Y' || ch =='y' )
 {
     flag =1;
   i=1;
   printf("\2你现在的位置是: (请输入1-10的序号 ): \n");
   scanf("%d",&i);
   getchar();

   printf("\2你要去的地方是: (请输入1-10的序号 ): \n");
   scanf("%d",&j);
   getchar();
   
   path(&G,i,j);
   getchar();
   CreateGraph(&G);
   continue;
 }
 
else 
	flag=0;
    break;



}while(1);


case '0':
clrscr();
 printf("\n\t\t----------------------按任意键退出-----------------------\n\n");
 printf("\n\t\t----------------------谢谢您的使用-----------------------\n\n");
 getchar();
 exit(0);

 break;
 default:

printf("\n输入有误,请重新输入0-3之间的数字:  \n ");
getchar();
break;


	    }
	  

	}

 getchar();
}

 int main(int argc, char const *argv[])
{
    JieMian();
	return 0;
}










