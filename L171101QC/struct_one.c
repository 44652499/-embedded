#include <stdio.h>
#include <string.h>
/*
自定义类型:把单个变量组合并命名,可以直接用此名定义新的变量
结构体:由多个不同类型成员组成
联合体
枚举
*/
//结构体
struct student
{
	int  sid;
	char sname[20];
	char sex;
	int  age;
};

int main(int argc, char const *argv[])
{
	//定义结构体变量
	struct student s1;
	//结构体变来那个访问其成员
	s1.sid=123;
	strcpy(s1.sname,"student1");
	s1.sex='f';
	s1.age=20;
	printf("%d\t%s\t%c\t%d\n",s1.sid,s1.sname,s1.sex,s1.age);

	struct student s2;
	s2.sid=456;
	strcpy(s2.sname,"student2");
	s2.sex='m';
	s2.age=22;
    printf("%d\t%s\t%c\t%d\n",s2.sid,s2.sname,s2.sex,s2.age);
	return 0;
}