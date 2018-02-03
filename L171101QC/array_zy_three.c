#include <stdio.h>
/*求出数组int a[10]的最大数和最小数*/

int main(int argc,const char* argv[])
{
    int  array[10]={1,5,-4,67,90,21,-45,0,34,89};
    int max=array[0];
    int min=array[0];
    int i;
    for(i=0;i<10;i++)
    {
        if(max<array[i])
        {
            max=array[i];
        }
        if(min>array[i])
        {
            min=array[i];
        }
    }
    printf("%d\t%d\n",max,min);
    return 0;
}
