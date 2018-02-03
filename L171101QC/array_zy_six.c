#include <stdio.h>
#define  DELETE_VALUE  -999
/*假如数组a有4行4列的整数，请输出每行的最大者
*/
int main(int argc,const char* argv[])
{
    int array[4][4]={3,6,4,6,8,3,1,3,4,7,1,2,2,9,5,3};
    int i,j;
    int max;
    for(i=0;i<4;i++)
    {
        max=array[i][0];
        for(j=0;j<4;j++)
        {          
             if(max<array[i][j])
             {
                 max=array[i][j];
             }
        }
        printf("%d\n",max);
    }
    return 0;
}
