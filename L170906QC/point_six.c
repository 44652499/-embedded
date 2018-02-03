#include<stdio.h>
int main(int argc,const char* argv[])
{
   // int a[]={1,2,3,4,5,67};
    //int b[]={10,20,30,40};
    int b[]={10,20,30,40};
    int a[]={1,2,3,4,5,67};
    int *ptr=a;
    int i;
    for(i=0;i<6;i++)
    {
       // printf("%d\t",*(ptr+i));
       //printf("%d\t",ptr[i]);//ptr[i]  等价于  *(ptr+i)
       //printf("%d\t",*(a+i));
    }
  
    //ptr=a+4;
    //printf("%d\n",ptr[-2]);//ptr[-2]  ===>  *(ptr-2)
   // a=a+2;//错误 ,a=a-2  数组名相当于是一个指针只读
    printf("%d\n",a[8]);//虽然编译正确,有可能是退化成指针操作
    return 0;
}
//总结数组与指针区别?