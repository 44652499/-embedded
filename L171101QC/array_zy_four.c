#include <stdio.h>
#define  DELETE_VALUE  -999
/*数组的元素的删除，从数组中删除指定的元素n
静态数组是不可以修改地址,删除元素只能设置一个值表示次元素被删除,但是元素空间仍然存在,只有在进程结束后,一起释放整个数组空间
*/

int main(int argc,const char* argv[])
{
    int  array[10]={1,5,3,67,90,3,-45,3,34,89};
    int i;
    for(i=0;i<10;i++)
    {
        if(array[i]==33)
        {
            array[i]=DELETE_VALUE;
        }
        if(array[i]!=DELETE_VALUE)
        {
            printf("%d\t",array[i]);
        }
    }
    printf("\n");
   
    return 0;
}
