#include <stdio.h>
#include <stdlib.h>
// #define __FUNCTION ""
// #define _DEBUG_ASSERT(_condition)    \
//         do                           \
//         {                            \
//         	if(!(_condition))          \
//         	{                        \
//         		define_assert(__FILE__,__LINE__,__FUNCTION,#_condition); \
//         	}                        \
//         }while(0)

// void   define_assert(const char* _file,int _line,const char* _function,const char* _condition)
// {
// 	printf("%s:%d: %s:Assersion '%s' failed \n",_file,_line,_function,_condition);
// 	return;
// }


//#define A
// #ifdef A
// #error("hello")
// #endif
[root@localhost c]# gcc -D  B  debug_assert_new.c -o dnew
//编译时相当于 #define  B
int main(int argc, char const *argv[])
{
	//_DEBUG_ASSERT(1==2);
	#ifdef A
		printf("A\n");
	#else
		printf("B\n");
	#endif
	return 0;
}