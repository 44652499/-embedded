#include <stdio.h>
#include <stdlib.h>
#define  TITLE  "debug info:"
#define  DEBUG_MSG(condition)  \
					do         \
					{          \
						if(!(condition)) \
						{      \
				show_debug_msg(__FILE__,__LINE__,TITLE,#condition); \
						}      \
					}          \
					while(0)
void  show_debug_msg(const char* file_name,int line,const char*  title,const char* msg)
{
	printf("%s:%d ASEERTION:%s:%s\n",file_name,line,title,msg);
	//abort();//非正常结束进程
	//exit(0);//正常结束进程
	return;
}  
int main(int argc, char const *argv[])
{
	DEBUG_MSG(2==3);
	printf("1===2");
	const  int a;
	printf("a=%d\n",a);
	return 0;
}

/*
define 与 const 区别?
1.define 无类型 无安全检测,const 定义变量 类型及安全检测
2.define 预编译完成,不需要分配内存,const需要分配内存
*/