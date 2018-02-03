#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
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
		fprintf(stderr,"%s\n",dlerror());
		exit(-1);
	}
	dlerror();
	fun=dlsym(handler,"add");
	printf("%d\n",fun(2,3));
	dlclose(handler);
	return 0;
}