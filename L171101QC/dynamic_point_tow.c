#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
构造一个动态二维数组,行 列数输入
*/
int main(int argc, char const *argv[])
{
    int row,col;
    scanf("%d%d",&row,&col);

    int ** ptr=(int**)malloc(row*sizeof(int*));
    assert(ptr!=NULL);
    int i;
    for(i=0;i<row;i++)
    {
    	*(ptr+i)=(int*)malloc(col*sizeof(int));
    	assert(*(ptr+i)!=NULL);
    }
    int j;
    for(i=0;i<row;i++)
    {
    	for(j=0;j<col;j++)
    	{
    		ptr[i][j]=i+j;
    	}
    }

    for(i=0;i<row;i++)
    {
    	for(j=0;j<col;j++)
    	{
    		printf("%d\t",ptr[i][j]);
    	}
    	printf("\n");
    }


    //释放
    for(i=0;i<row;i++)
    {
    	free(*(ptr+i));
    	*(ptr+i)=NULL;
    }
    free(ptr);
    ptr=NULL;

	return 0;
}