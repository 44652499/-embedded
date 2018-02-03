#include <stdio.h>
#include <string.h>
void change(char *a)
{
	int l,i;
	char tmp;
	l=strlen(a);
	for(i=0;i<l/2;i++)
	{
       tmp=a[i];
       a[i]=a[l-i-1];
       a[l-i-1]=tmp;
	}
}
int main(int argc, char const *argv[])
{
	char a[3],b[3],muli[6];
	gets(a);
	gets(b);
	change(a);
	change(b);
	int i,j,l1,l2;
	l1=strlen(a);
	l2=strlen(b);
	int mul[6]={0};
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
		{
			mul[i+j]=(a[i]-'0')*(b[j]-'0')+mul[i+j];
		}
	}
	int m,n,t,flag=0;
	for(n=0;n<6-1;n++)
	{
		t=mul[n]+flag;
		flag=t/10;
		mul[n]=t%10;
	}
	mul[n]=flag;
	for(m=0;m<6;m++)
	{
		muli[m]=mul[m]+'0';
		
	}
	change(muli);
	for(m=0;m<6;m++)
	{
		printf("%c",muli[m]);
	}
	
	return 0;
}
