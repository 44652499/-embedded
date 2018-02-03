#include <stdio.h>
#include <stdlib.h>
#define _PRETTY_FUNCTION    "aa"
#define _DEBUG_ASSERT(_Condition)  \
              do{          \
              		if(!(_Condition))   \
              		{                    \
              			define_assert(__FILE__,__LINE__,_PRETTY_FUNCTION,#_Condition);     \
              		}       \
              	}while(0)
 void  define_assert(const char * _file,int _line,const char*_function,const char* _condition)
 {
 	printf("%s:%d: %s:Asserttion '%s' failed. \n",_file,_line,_function,_condition);
 	abort();
 }
 int main(int argc, char const *argv[])
 {
 	_DEBUG_ASSERT(1==2);
 	return 0;
 }

#define B
// #ifdef A
// 	#error("hello")
// #endif
int main(int argc, char const *argv[])
{
	#ifdef A
		printf("A\n");
	#else
		printf("B\n");
	#endif
	return 0;
}