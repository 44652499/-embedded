#include <stdio.h>
/*
索引顺序查找(分块查找)
    查找思想:是顺序查找的一种改进方法,就是把被查找的表分成若干块,每块中记录的存放顺序是无序的,但块与块之间必须按关键字有序.即第一块中任一记录的关键字都小于第二块中任一记录的关键字,而第二块中任一记录的关键字都小于第三块中任一记录的关键字,依此类推.
    该方法要为被查找的表建立一个索引表,索引表中的一项对应于表中的一块,索引表中含有这一块中的最大关键字和指向块内第一个记录位置的指针,索引表中各项关键字有序.

查找步骤:
1)折半查找索引表(当然也可以顺序查找索引表,整体的查找速度也是比原始的顺序查找高的,但远不及折半查找),确定要找的记录所在块;
2)在相应的块中顺序查找.
*/
int  searchIndex(int **index,int * array,int  block_size,int len,int key)
{
	int low=0;
	int high=block_size-1;
	int elements_block=len/block_size;
	int start;
	int mid=0;
	while(low<high)
	{
		mid=(low+high)/2;
		if(index[0][mid]==key)
		{
			start=mid;
			break;
		}
		else if(index[0][mid]>key)
		{
			high=mid;
		}
		else
		{
			low=mid+1;
		}
		start=index[1][low];
		int i=0;
		while(i<elements_block && array[start+i]!=key)
		{
			i++;
		}
		if(i==elements_block)
		{
			return -1;
		}
		return start+i;
	}
}
int main(int argc, char const *argv[])
{
	int index[][3]={{20,53,89},{0,5,10}};//索引表
	int array[]={18,12,8,5,20,51,36,22,29,53,89,60,72,66,76};//查找表  
	int key=22;
	int result=searchIndex(index,array,5,15,key);
	if(result>-1)
	{
		printf("查找 %d 成功,在查找表中的位置是 %d\n",key,result);
	}
	else
	{
		printf("查找 %d 失败\n",key);
	}

	key=6;
	result=searchIndex(index,array,5,15,key);
	if(result>-1)
	{
		printf("查找 %d 成功,在查找表中的位置是 %d\n",key,result);
	}
	else
	{
		printf("查找 %d 失败\n",key);
	}
	return 0;
}