#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int(*Comp)(const void* n1,const void * n2);
void Bubblesort(void* array,int size,int elemensize,Comp fun)
{
   int i,j;
   for(i=0;i<size;i++)
   {
	   for(j=0;j<size-1;j++)
	   {
          if(fun(array+j*elemensize,array+(j+1)*elemensize)==1)
		  {
             void* tmp=malloc(1*elemensize);
			 memcpy(tmp,array+j*elemensize,elemensize);
             memcpy(array+j*elemensize,array+(j+1)*elemensize,elemensize);
			 memcpy(array+(j+1)*elemensize,tmp,elemensize);
			 free(tmp);
			 tmp=NULL;
		  }
	   }
   }
}

int ComInt(const void* n1,const void* n2)
{
	int elem1=*(int*)n1;
	int elem2=*(int*)n2;
	if(elem1<elem2)
		return  -1;
	if(elem1>elem2)
		return 1;
	return 0;
}

int ComChar(const void* n1,const void* n2)
{
	char *c1=(char*)n1;
	char *c2=(char*)n2;
	return strcmp(c1,c2);
}

int main(int argc, char *argv[])
{
	int array[]={5,2,4,9,0,1};
	Bubblesort((void*)array,6,sizeof(array[0]),ComInt);
	int i;
	for(i=0;i<5;i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
	char arrayc[4][10]={"ybc","123213","eret","auit"};
	Bubblesort((void*)arrayc,4,10,ComChar);
	for(i=0;i<5;i++)
	{
		printf("%s\t",arrayc[i]);
	}
    printf("\n");
	return 0;
}
