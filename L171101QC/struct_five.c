#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct student
{
	int sid;
	char name[20];
}student;
int main(int argc, char const *argv[])
{
	student *ptr=(student*)malloc(1*sizeof(student));
	assert(ptr!=NULL);
	ptr->sid=2345;
	strcpy(ptr->name,"sssss");
	printf("%d\t%s\n",(*ptr).sid,(*ptr).name);
	free(ptr);
	ptr=NULL;
	return 0;
}