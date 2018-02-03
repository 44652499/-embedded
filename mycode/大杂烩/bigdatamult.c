#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void   freemem(void * addr)
{
      if(addr!=NULL)
      {
            free(addr);
            addr=NULL;
      }
}

void freemem2(void **addr, int row)
{
      int i;
      for(i=0;i<row;i++)
      {
            free(*(addr+i));
            *(addr+i)=NULL;
      }
      free(addr);
      addr=NULL;
}
int main(int argc, char const *argv[]) {
      char data1[20];
      char data2[20];
      scanf("%s%s",data1,data2);
      int len1=strlen(data1);
      int len2=strlen(data2);
      int*d1=(int*)malloc(len1*sizeof(int));
      int *d2=(int*)malloc(len2*sizeof(int));
      int i,j,m,n,ii;
      for(i=0;i<len1;i++){
           d1[i]=data1[i]-'0';
         }

     for(i=0;i<len2;i++){
           d2[i]=data2[i]-'0';
         }

   //定义一个存放结果二维数组
   //行数=第二个数长度
 //列数=第一个数长度+1
 //每行存储的是结果(第二个数每个数字与第一个数相乘)
    int** result;
    result=(int**)malloc(len2*sizeof(int*));
    for(i=0;i<len2;i++)
    {
          *(result+i)=(int*)malloc(len1*sizeof(int));
   }
   int resulcol=len1;
   for(i=0;i<len2;i++)
   {
 	   for(j=0;j<resulcol;j++)
            {
 	    		result[i][j]=0;
 	    	}
      }

      for(i=0;i<len2;i++)
      {
	    	for(j=0;j<len1;j++)
            {
              result[i][j]=d2[i]*d1[j];
	    	}
	}

      //定义最终结果存放数组
      int* res=(int*)malloc((len1+len2)*sizeof(int));
	for(i=0;i<len1+len2;i++)
      {
	    	res[i]=0;
	 }
    //实现数据移位(*1  *10 *100 *1000)
       int* tmp=(int*)malloc((len1+len2)*sizeof(int));
	 for(i=0;i<len1+len2;i++)
       {
	    	tmp[i]=0;
	 }

       int index=len1+len2-1;
	 for(i=len2-1;i>=0;i--)
       {
             //实现移位
	    	for(n=len2-1;n>i;n--)
            {
	    		tmp[index]=0;
	    		index--;
	    	}

           for(j=len1-1;j>=0;j--)
            {
	    		tmp[index]=result[i][j];
	    		index--;
	       }

           for(m=len1+len2-1;m>=0;m--)
            {
	    		res[m]=res[m]+tmp[m];
	       }

           for(ii=0;ii<len1+len2;ii++)
            {
	 	    	tmp[ii]=0;
	       }
	    index=len1+len2-1;
    }

    int prefix=0;
   for(i=len1+len2-1;i>=0;i--)
   {
           res[i]=res[i]+prefix;
	    	prefix=res[i]/10;
	    	res[i]=res[i]%10;
   }
   for(i=res[0]==0?1:0;i<len1+len2;i++)
   {
	    	printf("%d",res[i]);
   }
   printf("\n");
   freemem(d1);
   freemem(d2);
   freemem(res);
   freemem(tmp);
   freemem2((void**)result,len2);
   return 0;
}
