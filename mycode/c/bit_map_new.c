#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUM  400000000

unsigned int *  init_bit_map()
{
	int bit_map_size=MAX_NUM%32?MAX_NUM/32+1:MAX_NUM/32;
	unsigned int *  ptr_bit_map=(unsigned int *)malloc(bit_map_size*sizeof(unsigned int));
	bzero(ptr_bit_map,bit_map_size);
	return ptr_bit_map;
}

void push_data_to_bit_map(unsigned int *  ptr_bit_map,unsigned int value)
{
	unsigned int tmp=0x1;
	int main_index=value/32;
	int remain_index=value%32;
	ptr_bit_map[main_index]|=tmp<<remain_index;
}

void  find_data_from_bit_map(unsigned int *  ptr_bit_map,unsigned int value)
{
	int tmp=0x1;
	int main_index=value/32;
	int remain_index=value%32;
	if(ptr_bit_map[main_index]&(tmp<<remain_index))
	{
		printf("find data=%d\n",main_index*32+remain_index);
		printf("find ok\n");
	}
	else
	{
		printf("not find\n");
	}
}

void  get_bit_value(unsigned int *  ptr_bit_map,int size)
{
  int i;
  int j;
  int tmp=0x1;
  for(i=0;i<size;i++)
  { 
  	tmp=0x1;
    for(j=0;j<32;j++)
    {
    	tmp=tmp<<j;
    	//printf("j=%d\n",j);
    	if(ptr_bit_map[i]&tmp)
    	{
    		//printf("%d\t",i*32+j);
    		//printf("%d\t",(*(ptr+i))&tmp);
    		printf("%d",1);
    	}
    	else
    	{
    		printf("%d",0);
    	}
    }
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
	unsigned int *  ptr_bit_map=init_bit_map();
	int array[]={23,21,56,8,9,0,10,2,100,54};
	int i;
	for(i=0;i<10;i++)
	{
		push_data_to_bit_map(ptr_bit_map,array[i]);
	}
	
	//find_data_from_bit_map(ptr_bit_map,1000);
	get_bit_value(ptr_bit_map,4);
	free(ptr_bit_map);
	ptr_bit_map=NULL;
	return 0;
}