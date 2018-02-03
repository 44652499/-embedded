#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int** shuzu2(int row,int col);
int* point1(int col);
int*add(int **mul,int row,int col,int len);
int main(int argc, char const *argv[])
{
	char m1[20];
	char m2[20];
	int **mul;
	scanf("%s%s",m1,m2);
	int x,y,c1,c2,lm1,lm2,lm,j,m,n,i;
	lm1=strlen(m1);
	lm2=strlen(m2);
	lm=lm1+lm2;
	mul=shuzu2(lm2,lm1);
    for(m=0,y=lm2-1;m<=lm2-1;m++,y--)
     {
     	   for (x=lm1-1,n=lm1-1;x>=0; x--,n--)
    	    {
    		  mul[m][n]=(m2[y]-'0')*(m1[x]-'0');
     	     }
     }

   // for (m=0; m <=lm2-1; m++)
   //  {
   //     for (n=lm1;n>=0;n--)
   //     {
   //       c1=mul[m][n]/10;
	  //    c2=mul[m][n]%10;
	  //    mul[m][n]=c2+'0';
	  //    mul[m][n-1]=mul[m][n-1]+c1+'0';
   //     }
   //  }
 //printf("%d\n",mul[1][1]);
  for (m=0; m<=lm2-1 ;m++)
   {
     for (n=0;n<=lm1-1;n++)
      {
        printf("%d",mul[m][n]);
       }
     printf("\n");
   }

   int *result=add(mul,lm2,lm1,lm);
   for(i=result[0]==0?1:0;i<lm;i++)
   {
         printf("%d",result[i]);
   }
   printf("\n");
   return 0;
}

int** shuzu2(int row,int col)
{
   int **p;
   p=(int**)malloc(row*sizeof(int*));
   int i;
   for(i=0;i<row;i++)
   {
     *(p+i)=(int*)malloc(col*sizeof(int));
   }
   return p;
}

int* point1(int col)
{
     int *p1;
     p1=(int*)malloc(col*sizeof(int));
     return p1;
}

int*add(int **mul,int row,int col,int len)
{
	int *result,*curr;
	result=point1(len);
	curr=point1(len);
	int r,c,index,i;
	index=len-1;
	for(r=0;r<row;r++)
	{
		//¿¼ÂÇÒÆÎ»
		for(i=0;i<r;i++)
		{
			index--;
		}
		for(c=col-1;c>=0;c--)
		{
			curr[index]=mul[r][c];
			index--;
		}

		for(i=0;i<len;i++)
		{
			result[i]=result[i]+curr[i];
		}

		for(i=0;i<len;i++)
		{
			curr[i]=0;
		}
		index=len-1;
	}

	int digit=0;
	for(i=len-1;i>=0;i--)
	{
		result[i]=result[i]+digit;
		digit=result[i]/10;
		result[i]=result[i]%10;
	}
	return result;
}
