#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  get_max_value(int * array,int len)
{
	int max=array[0];
	int i;
	for(i=0;i<len;i++)
	{
		if(max<array[i])
		{
			max=array[i];
		}
	}
	return max;
}

void  set_bit_array(int * ptr,int *array,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		int n_blck=array[i]/32;
		int n_bits=array[i]%32;
		ptr[n_blck]=ptr[n_blck]|(0x1<<n_bits);	
	}
}

void  get_bit_array(int *ptr,int *array,int len)
{
	int i,j;
	int value=0x1;
	for(i=0;i<len;i++)
	{
		for(j=1;j<32;j++)
		{
			if(ptr[i]&(value<<j))
       		{
       	 		printf("%d\t",i*32+j);
       		}
		}       
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int  array[]={11,23,14,6,90,87,5,45};
	int  max_value=get_max_value(array,8);
	int  n=max_value%32?max_value/32+1:max_value/32;
	int *  ptr=(int*)malloc(n*sizeof(int));
	bzero(ptr,sizeof(ptr));
	set_bit_array(ptr,array,8);
	get_bit_array(ptr,array,n);
	return 0;
}