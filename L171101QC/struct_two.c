#include <stdio.h>
#include <string.h>
/*
自定义类型:把单个变量组合并命名,可以直接用此名定义新的变量
结构体:由多个不同类型成员组成
联合体
枚举
*/
//结构体
// struct student
// {
// 	int  sid;
// 	char sname[20];
// 	char sex;
// 	int  age;
// 	//结构体不能定义函数
// }s3,s4={777,"s777",'f',23};  //s3表示的是结构体变量名
  //s4初始化结构体变量

// typedef struct  
// {
// 	int  sid;
// 	char sname[20];
// 	char sex;
// 	int  age;
// 	//结构体不能定义函数
// }student; //student 表示类型

typedef struct  student  //student 必须写明
{
	int  sid;
	char sname[20];
	char sex;
	int  age;
	struct student * ptr; //指针 指向同类型变量
	//结构体不能定义函数
}student; //student 表示类型

int main(int argc, char const *argv[])
{
	//定义结构体变量
	// struct student s1;
	// //结构体变来那个访问其成员
	// s1.sid=123;
	// strcpy(s1.sname,"student1");
	// s1.sex='f';
	// s1.age=20;
	// printf("%d\t%s\t%c\t%d\n",s1.sid,s1.sname,s1.sex,s1.age);

	// struct student s2;
	// s2.sid=456;
	// strcpy(s2.sname,"student2");
	// s2.sex='m';
	// s2.age=22;
 //    printf("%d\t%s\t%c\t%d\n",s2.sid,s2.sname,s2.sex,s2.age);

	// s3.sid=456;
	// strcpy(s3.sname,"student2");
	// s3.sex='m';
	// s3.age=22;
 //    printf("%d\t%s\t%c\t%d\n",s3.sid,s3.sname,s3.sex,s3.age);
 //    printf("%d\t%s\t%c\t%d\n",s4.sid,s4.sname,s4.sex,s4.age);

	//struct student s5={778,"s777",'f',23}; //初始化结构体
	//struct student s5[2]={{778,"s777",'f',23},{779,"s779",'f',21}};  //s5数组
	//struct student s5[2]={778,"s777",'f',23,779,"s779",'f',21};
	student s5[2]={778,"s777",'f',23,779,"s779",'f',21};
	int  i;
	for(i=0;i<2;i++)
	{
		printf("%d\t%s\t%c\t%d\n",s5[i].sid,s5[i].sname,s5[i].sex,s5[i].age);
	}
	return 0;
}