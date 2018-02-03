#include <stdio.h>
/*
希尔排序:是一种特殊插入排序,根据等长度比较对应的元素值
时间复杂度:O(n^1.25)
*/
void  sort_data(int * array,int len)
{
	int i;
	int j;
	int tmp;
	for(i=len/2;i>0;i=i/2)
	{		
        for(j=i;j<len;j++)
        {
           tmp=array[j];
           if(tmp<array[j-i])
           {
           	array[j]=array[j-i];
           	array[j-i]=tmp;
           }
        }
	}
}
int main(int argc, char const *argv[])
{
	int array[]={6,73,56,13,15,90,9,32};
	sort_data(array,8);
	int i;
	for(i=0;i<8;i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
	return 0;
}