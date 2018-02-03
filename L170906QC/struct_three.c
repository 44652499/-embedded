#include <stdio.h>
#include <string.h>
#include  <stdlib.h>
/*自定义复合数据类型:由多个子元素组成一种新类型
a.结构体
b.联合体
结构体:表示复杂信息自定义类型.如:节点  学生  电脑
结构体声明语法:
struct  类型名
{
    子元素....;
    子元素....;
    子元素....;
    子元素...;
}
*/
//定义一个学生类型,包含4个子信息
struct  student
{
    //子元素表示此类型的属性(子变量)
    int sid;
    char name[10];
    int sex;
    int age;
}student_1,student_2={1113,"s1113",1,21};//student_1是结构体变量 ,student2是结构体变量并初始化
//一般结构类型声明放在函数外,构成全局类型.
struct A
{
    int a;
    int b;
}a1={1};


struct AA
{
    int a;
    char  ch;
    char  chs[10];
};

int main(int argc, char const *argv[])
{
    //printf("%d\n",a1.a/a1.b);//异常,程序运行错误,除数不能为0

    struct AA  a1={20,'a',"123456"};
    int *  ptr=(int*)&a1;
    printf("%d\n",*ptr);
    ptr=ptr+1;
    printf("%c\n",*((char*)ptr));
    printf("%s\n",((char*)ptr+1));



    // struct A  *ptr_a=(struct A*)malloc(1*sizeof(struct A));
    // ptr_a->a=20;
    // ptr_a->b=30;

    // int *ptr=(int*)ptr_a;//结构体变量首地址表示结构体第一个成员首地址
    // printf("%d\n",*(++ptr));

    // student_1.sid=111;
    // strcpy(student_1.name,"student1");
    // student_1.sex=0;
    // student_1.age=20;    
    // printf("%d\t%s\t%d\t%d\n",student_1.sid,student_1.name,student_1.sex,student_1.age);

    // printf("%d\t%s\t%d\t%d\n",student_2.sid,student_2.name,student_2.sex,student_2.age);

    // struct student student_3={1115};//结构体初始化类似于数组初始化,未初始到的成员值默认为0
    // printf("%d\t%s\t%d\t%d\n",student_3.sid,student_3.name,student_3.sex,student_3.age);
   
    return  0;
}