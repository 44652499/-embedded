#include <stdio.h>
#include <string.h>
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
// typedef struct  
// {
//     //子元素表示此类型的属性(子变量)
//     int sid;
//     char name[10];
//     int sex;
//     int age;
// }student;//student 类型别称

typedef struct  student  //student 必须写
{
    //子元素表示此类型的属性(子变量)
    int sid;
    char name[10];
    int sex;
    int age;
    struct  student  * ptr;//写完整形式struct  student 
}student;//student 类型别称

int main(int argc, char const *argv[])
{
    student  s1; //定义学生类型变量
    //通过学生类型变量访问类型的子元素
    s1.sid=111;
    strcpy(s1.name,"student1");
    s1.sex=0;
    s1.age=20;

    student  s2; //定义学生类型变量
    //通过学生类型变量访问类型的子元素
    s2.sid=112;
    strcpy(s2.name,"student2");
    s2.sex=1;
    s2.age=22;
    printf("%d\t%s\t%d\t%d\n",s1.sid,s1.name,s1.sex,s1.age);
    printf("%d\t%s\t%d\t%d\n",s2.sid,s2.name,s2.sex,s2.age);
    

    //定义学生类型指针变量
    student  * ptr_student;
    ptr_student=&s1;
    //通过指针访问其指向学生变量的成员,用"->"
   // printf("%d\t%s\t%d\t%d\n",ptr_student->sid,ptr_student->name,ptr_student->sex,ptr_student->age);
   //(*指针).访问子元素
   printf("%d\t%s\t%d\t%d\n",(*ptr_student).sid,(*ptr_student).name,(*ptr_student).sex,(*ptr_student).age);

   student  array[5];
   int i;
   for(i=0;i<5;i++)
   {
       array[i].sid=i+1;
       strcpy(array[i].name,"student");
       array[i].sex=1;
       array[i].age=23;
   }

   for(i=0;i<5;i++)
   {
      printf("%d\t%s\t%d\t%d\n",array[i].sid,array[i].name,array[i].sex,array[i].age);
   }
   //错误,不能直接访问s1.操作结构体实质操作结构体汇总子元素
   //printf("%s\n",s1);

    return  0;
}