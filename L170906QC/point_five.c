#include  <stdio.h>
/*
指针运算:一般是指地址值+-运算,
指针运算本质就是移动指针指向地址的空间字节数

*/
int main(int argc,const char * argv[])
{
    // int * ptr=NULL;
    // int  a=30;
    // ptr=&a;
    // printf("%X\n",ptr);
    // printf("%X\n",ptr+1);//ptr=ptr+1*sizeof(int),1表示一个单位,空间字节数
    // printf("%X\n",*ptr+1);//1整数值
    // printf("%X\n",(int)ptr+1);//(int)ptr 强制把地址值转换成整数值,1表示整数
    int a[]={10,20,30,40,50};
    //int *ptr=&a;
    // int *ptr=a;
    // printf("%d\n",*ptr++);
    // printf("%d\n",*(++ptr));
    // printf("%d\n",(*ptr)++);//*ptr=*ptr+1

    // int i;
    // for(i=0;i<5;i++)
    // {
    //     printf("%d\n",a[i]);
    // }
    //使用一个char 指针访问数组a元素
    // char *  ptr=(char*)a;
    // int i;
    // for(i=0;i<5;i++)
    // {
    //     //printf("%d\n",*(ptr+i*4));//
    //     printf("%d\n",*((int*)ptr+i));
    // }

    // int  data=0x12345678;
    // char *ch=(char*)&data;
    // int i;
    // for(i=0;i<4;i++)
    // {
    //     printf("%X",*(ch+i));
    // }
    //实现把一个长整数分解成两个短整数
    // unsigned long   l_data=0x12345678;
    // unsigned short  * ptr_s=(unsigned short  *)&l_data;
    // int i;
    // for(i=0;i<2;i++)
    // {
    //     printf("%X\n",*(ptr_s+i));
    // }

    unsigned long   l_data=0x12345678;
    unsigned  int   p_addr=(unsigned  int)&l_data;//把地址值转换成整数值
    int i;
    for(i=0;i<2;i++)
    {
        printf("%X\n",*((unsigned short *)(p_addr+i*2)));
        ///printf("%X\n",*((p_addr+i*2)));//错误,无法获取结束地址
    }
    printf("\n");
    return 0;
}