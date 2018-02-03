#include <stdio.h>
/*给定2维数组如下，求该数组2条对角线元素之和
a=3 6 4 6    
8 3 1 3   
4 7 1 2   
2 9 5 3   
要求：1，在主函数中实现：数组赋初值及求和结果的输出*/

int main(int argc,const char* argv[])
{
    int array[4][4];
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            //scanf("%d",&array[i][j]);
            scanf("%d",*(array+i)+j);
        }
    }
    int sum=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i==j || i+j==4-1)
            {
                sum+=array[i][j];
            }
        }
    }
    printf("sum=%d\n",sum);
    return 0;
}
//printf("%d,%d\n",a,b);
//scanf("%d%d",&a,&b)