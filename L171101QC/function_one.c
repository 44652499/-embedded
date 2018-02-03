#include <stdio.h>
/*
函数:给具有一定功能语句块另取名称,方便重复使用.函数可以实现代码模块化.提高代码可读性
函数:
1.函数声明:一般出现在头文件中,只完成函数三要素描述.函数在调用前必须有声明
2.函数定义:一般出现源文件中,函数功能实现语句
函数三要素:
1.函数名:命名yo有一个含义
2.参数列表:用来接收函数传递值
3.返回值类型,如果没有返回值使用void 
参数分两类:
1.形参:函数声明或定义时命名变量
2.实参:函数 调用时传递参数变量

形参:在函数被调用时分配空间,函数返回结束释放
函数每调用一次都分配栈,存储函数局部变量 形参 返回值

一个函数如果存在返回值,一次只能返回一个值,使用 return返回

函数传参:把实参值传递给形参
函数传参方式:
1.值传递:实参值传递给形参(实参与形参时两个不同的空间)
2.地址传递
*/
//函数定义
int  fun(int a) //int  a形参
{
    printf("fun a=%d\n",a);
    a=400;
    return a;
}

void  fun2()
{

}

//数组名作为函数形参,退化成指针.
//void fun3(int array[5])
void fun3(int array[],int array_size)
{
    printf("fun3 array=%d\n",sizeof(array));//array 就是一个指针
    int i;
    for(i=0;i<array_size;i++)
    {
        //printf("%d\n",*(array+i));
        printf("%d\n",array[i]);
    }
}
int main(int argc,const char * argv[])
{
    //int a=20;
    //fun(a);//a实参
   // fun2();//调用无参函数
    //printf("%d\n",a);//访问的时main函数的局部变量,非fun 函数局部变量

    //a=fun(a);
    //printf("%d\n",a);

    //int  array[5]={1,2,3,4,5};
   // printf("main array=%d\n",sizeof(array));
    //fun3(array,5);

    // int array[]={1,2,3,4,5};
    // int array2[5]={1,2,3,4,45,5};//错误,防止出现数组越界
    // printf("%d\n",array2[8]);
    // printf("%d\n",*(array2+8));
    int array2[5]={1,2,(3,4,45)};//未初始到元素为0
    printf("%d\n",array2[2]);
    printf("%d\n",array2[3]);
    printf("%d\n",array2[4]);
    return 0;
}