#include <iostream>
#include <dlfcn.h>
using namespace std;
#define LIBRARYPATH   "./cacaulate.so"
typedef int (*CAC_FUN)(int,int);
int main(int argc, char const *argv[])
{
	void *handler;
	char *error;
	CAC_FUN fun=NULL;
	handler=dlopen(LIBRARYPATH,RTLD_LAZY);
	if(handler==NULL)
	{
		cout<<dlerror()<<endl;
		exit(-1);
	}
	dlerror();
	fun=(CAC_FUN)dlsym(handler,"add");
	cout<<fun(3,4)<<endl;
	fun=(CAC_FUN)dlsym(handler,"sub");
	cout<<fun(3,4)<<endl;
	dlclose(handler);
	return 0;
}