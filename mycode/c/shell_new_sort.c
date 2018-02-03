#include <stdio.h>
void  shell_sort(int *array,int len)
{
	int j,step;
	for(step=len/2;step>0;step=step/2)
	{
		for(j=step;j<len;j++)
		{
			if(array[j]<array[j-step])
			{
				int tmp=array[j];
				int k=j-step;
				while(k>=0 && array[k]>tmp)
				{
					array[k+step]=array[k];
					k-=step;
				}
				array[k+step]=tmp;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int array[]={21,3,56,89,12,4,9,43,6};
	shell_sort(array,9);
	int i;
	for(i=0;i<9;i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
	return 0;
}