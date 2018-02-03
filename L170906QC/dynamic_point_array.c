#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
//int main(int argc,const char* argv[])
//{
    // int  row ,col;
    // scanf("%d%d",&row,&col);
    // int ** ptr=malloc(row*sizeof(int*));
    // int i;
    // for(i=0;i<row;i++)
    // {
    //     //ptr[i]=malloc(col*sizeof(int));
    //     *(ptr+i)=malloc(col*sizeof(int));
    // }
    // int j;
    // for(i=0;i<row;i++)
    // {
    //     for(j=0;j<col;j++)
    //     {
    //         ptr[i][j]=i+j;
    //     }
    // }
    // for(i=0;i<row;i++)
    // {
    //     for(j=0;j<col;j++)
    //     {
    //         printf("%d\t",ptr[i][j]);
    //     }
    //     printf("\n");
    // }

    // //释放
    // for(i=0;i<row;i++)
    // {
    //     free (ptr[i]);
    //     ptr[i]=NULL;
    // }
    // free(ptr);
    // ptr=NULL;  
   // return 0;
//}
void getmemory(char **p)
{
  *p=(char*)malloc(100);
  strcpy(*p,"hello world");
}
int main( )
{
  char *str=NULL;
  getmemory(&str);
  printf("%s/n",str);
  free(str);
  str=NULL;
  return 0;
}
//1.什么是内存泄漏?在什么情况下发生内存泄漏