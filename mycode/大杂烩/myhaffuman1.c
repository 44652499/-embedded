#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#define PATH "/\\mnt\\hgfs\\win\\haffu.txt"//可以自定义叶节点字符值，大小写都可以
/*编译请用 gcc -lm*/
typedef struct haffunode
{
    int weight;
    int parent;
    int left;
    int right;
    char word;
}haffunode;        //haffuman树的结点结构体

typedef struct hfcode
{
  unsigned char codenum;
}hfcode;

int wei[256];//存放每个字符的权值
int num=0;//存放编码个数
unsigned char *q;//存放指向存放编码的一维字符数组的地址

int weight()//计算字符串中每个字符的权值
{
  int i=0;
  int j;
  int count=0;
  int m=0;
  char ch;
  for(j=0;j<256;j++)
  {
   FILE *fp=fopen("haffu.txt","rt");
   ch=fgetc(fp);
   count=0;
  while(ch!=EOF)
  {
    if(ch==j)
     {count++;}
     ch=fgetc(fp);
  }
  if(count!=0)
   {
    wei[j]=count;
    m++;
   }
  } 

  if(m==1)
  {
    printf("error,char number is one\n");
    exit(1);
  } 

  else
  // for(i=97;i<123;i++)
  // printf("%d\t",wei[i] );
  // printf("\n");
  // printf("%d\n", m);//test
  return m; //字符种类个数
}


void creathaff(haffunode haff[],int n)//haff[]数组为存放权值的字符的树结点的集合
{
    int m=2*n-1;
    int i;
    for(i=0;i<m;i++)//给m个结点赋初始值；
    {
        haff[i].weight=0;
        haff[i].parent=-1;
        haff[i].left=-1;
        haff[i].right=-1;
        haff[i].word=-1;
    }
     int r=0;
    for(i=0;i<256;i++)//给n个叶节点赋权值，以及相应的字符值
    {
        if(wei[i]!=0)//小写赋值
        {
        haff[r].weight=wei[i];
        haff[r].word=i;
        r++;
        }
    }
    // for(i=0;i<n;i++)
    // {
    //   printf("%d\t%c\n",haff[i].weight,haff[i].word );
    // }//test测试字符和权值是否成功赋值


//构建huffuman树
    int j,k;
    int m1,m2;
    int x1;
    int x2;
    for(i=0;i<n-1;i++)
    //i=0;//test
    {  m1=1000;//赋一个够大的值，方便和其他权值比较大小
       m2=1000;
       x1=0;
       x2=0;

        for (j=0; j<n+i; j++)
        {
            if (haff[j].weight < m1 && haff[j].parent==-1)
            {
                m2=m1; 
                x2=x1; 
                m1=haff[j].weight;
                x1=j;
            }
            else if (haff[j].weight < m2 && haff[j].parent==-1)
            {
                m2=haff[j].weight;
                x2=j;
            }
        }
        haff[x1].parent=n+i; //给两个小的叶结点找父节点
        haff[x2].parent=n+i;
        haff[n+i].weight=m1+m2; //给父节点赋权值
        haff[n+i].left=x1;     //给父节点左右孩子赋值
        haff[n+i].right=x2;
    }
    //printf("%d\n",haff[1].left);//test   
}


//编码haffuman树
void haffucode(haffunode haff[],int n)
{
  int i,j,p,c;
  int a[n][n];
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      a[i][j]=0;
  }
  for(i=0;i<n;i++)
  { 
    j=n-1;
    c=i;
    p=haff[c].parent;
    while(p != -1) //父节点存在时候
    {
        if(haff[p].left==c)  //如果结点在左边，赋值0
         { a[i][j]=0;}
        else                 //如果结点在右边，赋值1
          {a[i][j]=1;}
        j--;
        c=p;
        p=haff[p].parent;   
    }
    a[i][j]=-1;   //结束标志，
   }
   
// for(i=0;i<n;i++)
// {
//   for(j=0;j<n;j++)
//   printf("%d\t",a[i][j] );
//   printf("\n");
// }//test测试编码情况

//将字符串每个字符用编码保存在一维数组code[]中
  int m=0,k=0; 
  char ch;
  FILE *fp=fopen("haffu.txt","rt");
  ch=fgetc(fp);
  char code[1000]={0};
  while(ch!=EOF)
{
  for(i=0;i<n;i++)
  {
    if(ch==haff[i].word)
   {  
      j=0;
    while(a[i][j]!=-1)
    {
      j++;
    }
    j++;
    for(;j<n;j++)
    {
      code[m]=a[i][j];
      m++;
    }
   }
  }
  ch=fgetc(fp);
}
  code[m]=-1;//编码结束标志符

//计算编码个数num
  m=0;
  while(code[m]!=-1)
  {
   //printf("%d\t",code[m] );//test 可以输出所有字符的编码值组合
    m++;
    num++;//计算编码个数
  }
  //printf("\n");

//将编码每8位转换成二进制存在key[]内，共需要num/8+1个字符
  k=0;
  m=num/8;
  int w=num%8;
  int y=0;
  int x=2;
  int cd=0;
  //char key[m+1];
  unsigned char key[m+1];
  for(j=0;j<m;j++)  
  {
  y=0;
  for(i=7+k;i>=0+k;i--)
  {
    cd=cd+code[i] * pow (x,y) ;
    y++;
  }
  key[j]=cd;
  k=k+8;
  cd=0;
  }

//最后几位不足8位的单独处理
  y=0;
  cd=0;
  for(i=num-1;i>=num-w;i--)
  {
    cd=cd+code[i] * pow (x,y) ;
    y++;
  }
  key[j]=cd;

  for(j=0;j<m+1;j++)
  printf("%d\n",key[j] );//测试转换成十进制的编码



  //q=key;  

//生成新的压缩文件
i=0;
hfcode hf;
hf.codenum=0;
FILE *fb=fopen("compress.txt","wb+");
while(i<m+1)
{
  hf.codenum=(char)key[i];
  fwrite(&hf,sizeof(hf),1,fb);
  i++;
}
if(fclose(fb))
{
  perror("cannot close");
  exit(0);
}
}
  


//译码
void decode(haffunode haff[],int n,unsigned char *q)
{
  int i,j,m,p;
  int k=0;
  int w=num%8;
  int a[8]={0};
  int *code;
  hfcode ch;
  int back;
  code=(int*)malloc(num*sizeof(int)/8);
  for(j=0;j<num/8;j++)
  {
   code[j]=-1;
  }


  FILE *fp;
  if((fp=fopen("compress.txt","rb"))==NULL)
  {
    perror("open error");
    exit(0);
  }

  back=fread(&ch,sizeof(ch),1,fp);
  i=0;
  while(back!=0)
  {
    code[i]=(int)ch.codenum; 
    printf("ret1=%d\n",code[i]); 
    i++;
    back=fread(&ch,sizeof(ch),1,fp);   
  }
  printf("num=%d\ti=%d\n",num,i);

  for(i=0;i<num/8;i++)
  {
   //if(code[i]!=-1)
    {
      printf("ret=%d\n",code[i]);
    }    
  }

  if(fclose(fp))
  {
    perror("cannot close");
    exit(0);
  }
  
 
    

// //将所有十进制编码翻译成二进制赋到数组code中  
// for(j=0;j<(num/8);j++)
// {
//   m=*(q+j);
//   int a[8]={0};//初始化，以防万一  
//   for(i=7;i>=0;i--)
//   {
//     a[i]=m%2;
//     m=m/2;
//   }
//   for(i=0;i<8;i++)
//   {
//     code[k]=a[i];
//     k++;
//   }
// }

// //最后一个单独处理
//   m=*(q+(num/8));
//   for(i=7;i>=0;i--)
//   {
//     a[i]=m%2;
//     m=m/2;
//   }
//   for(i=(8-w);i<8;i++)
//   {
//     code[k]=a[i];
//     k++;
//   }

// //根据数组code中编码翻译
//   i=0;
//   while(i<num)
//   { p=2*n-2;
//     while(haff[p].left!=-1 ||haff[p].right!=-1 )
//   {
//     if(code[i]==1)
//       p=haff[p].right;
//     else if(code[i]==0)
//       p=haff[p].left;
//     i++; 
//   }
//   printf("%c",haff[p].word );
//   }
//   printf("\n");
//   // for(i=0;i<num;i++)
//   // printf("%d\t",code[i] );//test测试编码翻译是否准确
  
 }

int main(int argc, char const *argv[])
{
    int NUM;
    NUM=weight();  
    int m=2*NUM-1;//NUM个叶节点的树，共有2*NUM-1个结点
    haffunode haff[m];
    creathaff(haff,NUM);
    haffucode(haff,NUM);
    decode(haff,NUM,q); 
    return 0;
}
