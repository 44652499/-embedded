#include <stdio.h>
#include <string.h>

void ff(char *num)
{
	char tmp;
	int l,i;
	l=strlen(num);

	for(i=0;i<l/2;i++)
	{
       tmp=num[i];
       num[i]=num[l-1-i];
       num[l-i-1]=tmp;
	}
}
void f(char a[3])
{
	int l,i;
	l=strlen(a);
	for(i=0;i<l;i++)
	{
		a[i]=a[i]-'0';
	}
}
int main(int argc, char const *argv[])
{
	char num1[4],num2[4],sum1[8];
	int result[4][8]={0},sum[8]={0};
	int l1,l2,i,j,flag=0,t=-1,m,n,k;
	gets(num1);
	gets(num2);
	l1=strlen(num1);
	l2=strlen(num2);
	if(l1>l2)
	{
		m=l1;
	}
	else
		m=l2;
	ff(num1);
	ff(num2);
      //f(num1);
      //f(num2);

	for ( j = 0; j <l2; j++)
	{
		// t++;
		// for(k=0;k<t;k++)
		// {
		// 	result[i][k]=0;
		//
		// }
		for (i = 0; i < l1; i++)
		{
			//n=j+k;
			result[j][i+1]=(num1[i]-'0')*(num2[j]-'0');
		}
	}

      int t=1;
	for(i=0;i<l2;i++)
	{
		while(i>0)
		{
			t=t*10;
		}
		for(j=0;j<l1+1;j++)
		{
			sum[i]=sum[i]+result[i][j]*t;
		}
	}

	for(n=0;n<m+t;n++)
	{
		for(i=0;i<l2;i++)
		{

			sum[n]=result[i][n]+sum[n];
		}
		    sum[n]=sum[n]+flag;
			flag=sum[n]/10;
			sum[n]=sum[n]%10;

	}
	printf("%d",flag);
	for(n=0;n<t+m;n++)
	{
		sum1[n]=sum[n]+'0';
	}
	ff(sum1);
	for(n=0;n<t+m;n++)
	{
		printf("%c",sum1[n]);
	}
	return 0;
}
