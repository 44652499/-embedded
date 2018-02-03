#include <stdio.h>
#define  DELETE_VALUE  -999
/*9.有一个4 x 4的矩阵，编程将行和列的元素互换，输出互换后的矩阵
a=3 6 4 6    3  8  4  2
  8 3 1 3    6  3  7  9
  4 7 1 2    4  1  1  5
  2 9 5 3    6  3  2  3
*/

int main(int argc,const char* argv[])
{
   int array[4][4]={3,6,4,6,8,3,1,3,4,7,1,2,2,9,5,3};
   int i,j;
   for(i=0;i<4;i++)
   {
       for(j=i+1;j<4;j++)
       {          
            int tmp=array[i][j];
            array[i][j]=array[j][i];
            array[j][i]=tmp;
       }
   }

   for(i=0;i<4;i++)
   {
       for(j=0;j<4;j++)
       {        
            printf("%d\t",array[i][j]);
       }
       printf("\n");
   }

    return 0;
}
