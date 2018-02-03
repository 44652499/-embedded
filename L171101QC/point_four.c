#include  <stdio.h>
/*
指针与数组名之间关系:
1.指针可以当成数组名使用,数组名当成指针使用
2.如果数组作为函数形参,退化成指针,大小占用4字节
3.数组名表示的时指针只读,不能被赋值
4.数组名访问数组元素其下标值必须>=0,如果用指针访问,可以用负数
*/
int main(int argc,const char* argv[])
{
   // int  array[]={10,20,30,40,50,60,70};
    // int  *ptr=array+4;
    // printf("%d\n",ptr[0]);//ptr=ptr+0
    // printf("%d\n",ptr[1]);//ptr=ptr+1
    // printf("%d\n",ptr[-2]);////ptr=ptr-1
    //以上使用ptr 实现指针变来那个加减运算
    //指针赋值注意:1.必须地址值   2.两边的 地址+1,所表示的空间  字节数一样  
    //int *p=array;
    //int *p=&array;//错误,&array+1 增加的时28byte ,p+1 增加4个字节
    // int *p=(int*)&array;
    // printf("%d\n",*p++); //tmp=p;p=p+1 *tmp
    // printf("%d\n",(*p)++);//*p  *p=*p+1
    // printf("%d\n",++*p);//*p=*p+1
    // printf("%d\n",*++p);//
    // int i;
    // for(i=0;i<7;i++)
    // {
    //     printf("%d\t",array[i]);
    // }

    unsigned char i=0x80; 
    printf("0x%x\n", ~i>>3+1);
    return 0;
}