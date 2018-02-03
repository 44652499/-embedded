#include <stdio.h>
#include <stdlib.h>
/*
哈希表(hash table):是基于数组顺序结构,每一个存储目标值都会存在一个键值,也称为散列表.存放目标值与键值是同一个制定函数实现,此函数称为哈希函数
哈希函数:主要功能首先根据目标计算键值 ,F(value)=key
hash表作用:
方便快速查找
hash表缺点:
1.浪费空间(散列存储)
2.容易出现冲突(多个目标值用同hash函数计算出相同位置)

以上缺点只能尽量取避免:
1.一般制定一个好的hash 函数
常用hash函数:
1.寻址法
2.数字分析法
3.平方取中法
4.折叠法
5.随机数法
6.除留余数法
2.解决冲突存储
  常用解决冲突方法:
  1.多次hash
  2.拉链发:用链表存储冲突目标值
  3.嵌套hash
*/
//定义hash 函数
int hash_fun(int value)
{
    return value;
}

int hash_fun2(int value)
{
    return value%10;
}
// int*  save_array(int* array,int len)
// {
//     //int * hash_table=(int*) malloc(100*sizeof(int));
//     int * hash_table=(int*) malloc(10*sizeof(int));
//     int i;
//     for(i=0;i<len;i++)
//     {
//         int key=hash_fun(array[i]);
//         hash_table[key]=array[i];
//     }
//     return hash_table;
// }

int*  save_array(int* array,int len)
{
    int * hash_table=(int*) malloc(10*sizeof(int));
    int i;
    for(i=0;i<len;i++)
    {
        int key=hash_fun2(array[i]);
        hash_table[key]=array[i];
    }
    return hash_table;
}
//查找
// int  find_hash(int * hash_table,int value)
// {
//     int key=hash_fun(value);
//     if(hash_table[key]==value)
//     {
//         return 1;
//     }
//     return 0;
// }

int  find_hash(int * hash_table,int value)
{
    int key=hash_fun2(value);
    if(hash_table[key]==value)
    {
        return 1;
    }
    return 0;
}

int main(int argc,const char* argv[])
{
    int array[]={1,78,65,23,78,90,99};
    int* hash_table=save_array(array,7);
    int ret=find_hash(hash_table,78);
    if(ret)
    {
        printf("find ok\n");
    }
    else
    {
        printf("not find \n");
    }
    return 0;
}