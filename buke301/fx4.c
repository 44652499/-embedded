#include <stdio.h>
#include <string.h>
/*
如何用c结构体实现c++类封装
句柄(handler):是一个void*   指针
*/
struct student
{
   int sid;
   char sname[10];
};
void init_student(void* ptrobj,int _sid,const  char* _sname)
{
	((struct student*)ptrobj)->sid=_sid;
	strcpy(((struct student*)ptrobj)->sname,_sname);
}
void getsid(void* ptrobj)
{
	printf("%d\n",((struct student*)ptrobj)->sid);
}
void getsname(void*  ptrobj)
{
	printf("%s\n",((struct student*)ptrobj)->sname);
}
int main(int argc, char const *argv[])
{
	struct student s1;
	init_student(&s1,111,"s111");
	getsid(&s1);
	getsname(&s1);
	return 0;
}