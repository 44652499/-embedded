#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_HASH_CLASS  10
#define MAX_HASH_STUDENT 40
typedef int (*HASH_FUN)(const char* value,int flags);

typedef struct student
{
	int sid;
	char sname[20];
	char class_name[20];
}student;

typedef struct list_node
{
	student stu_value;
	struct list_node* next;
}list_node;

typedef struct hash_array
{
	list_node *  hash_child_table[MAX_HASH_STUDENT];
}hash_array;

typedef struct hash_table
{
	hash_array * hash_parent_table[MAX_HASH_CLASS];
}hash_table;

void init_hash_table(hash_table * ptr_hash_table)
{
	int i;
	for(i=0;i<MAX_HASH_CLASS;i++)
	{
		ptr_hash_table->hash_parent_table[i]=NULL;
	}
}

void  insert_hash_table(hash_table* ptr_hash_table,student  s,HASH_FUN h_fun)
{
	int hash_key=h_fun(s.class_name,MAX_HASH_CLASS);

	list_node *  ptr_new_node=(list_node*)malloc(1*sizeof(list_node));
	if(ptr_new_node==NULL)
	{
		printf("ptr_new_node  malloc fail\n");
		exit(-1);
	}
	ptr_new_node->stu_value=s;
	ptr_new_node->next=NULL;

	hash_array *  ptr_hash_array=NULL;

	if(ptr_hash_table->hash_parent_table[hash_key]==NULL)
	{
		ptr_hash_array=(hash_array *)malloc(1*sizeof(hash_array));
		if(ptr_hash_array==NULL)
		{
			printf("ptr_hash_array malloc fail\n");
			exit(-1);
		}
		int i;
		for(i=0;i<MAX_HASH_STUDENT;i++)
		{
			ptr_hash_array->hash_child_table[i]=NULL;
		}	
		ptr_hash_table->hash_parent_table[hash_key]=ptr_hash_array;	
	}
	else
	{
		ptr_hash_array=ptr_hash_table->hash_parent_table[hash_key];
	}

	int hash_child_key=h_fun(s.sname,MAX_HASH_STUDENT);
	if(ptr_hash_array->hash_child_table[hash_child_key]==NULL)
	{
		ptr_hash_array->hash_child_table[hash_child_key]=ptr_new_node;
	}
	else
	{
		ptr_new_node->next=ptr_hash_array->hash_child_table[hash_child_key];
		ptr_hash_array->hash_child_table[hash_child_key]=ptr_new_node;
	}
	ptr_new_node=NULL;
}

void  print_hash_table(hash_table* ptr_hash_table)
{
	int i,j;
	for(i=0;i<MAX_HASH_CLASS;i++)
	{		
		if(ptr_hash_table->hash_parent_table[i]!=NULL)
		{
			printf("i=%d\n",i);
			for(j=0;j<MAX_HASH_STUDENT;j++)
			{
				if(ptr_hash_table->hash_parent_table[i]->hash_child_table[j]!=NULL)
				{
					printf("\t\tj=%d\n",j);
					list_node*  ptr_tmp_node=ptr_hash_table->hash_parent_table[i]->hash_child_table[j];
					while(ptr_tmp_node!=NULL)
					{
						printf("\t\t\tsid=%d\tsname=%s\tclass_name=%s\n",ptr_tmp_node->stu_value.sid,ptr_tmp_node->stu_value.sname,ptr_tmp_node->stu_value.class_name);
						ptr_tmp_node=ptr_tmp_node->next;
					}
				}
			}
		}
	}
}

int  hash_fun(const char* value,int flags)
{
	int sum=0;
	int i;
	for(i=0;i<strlen(value);i++)
	{
		sum+=value[i]-'0';
	}
	return sum%flags;
}

int main(int argc, char const *argv[])
{
	hash_table  h_table;
	init_hash_table(&h_table);
	student s1={12,"student12","class1"};
	student s2={11,"student11","class2"};
	student s3={14,"student14","class6"};
	student s4={16,"student16","class8"};
	student s5={9,"student9","class9"};
	student s6={21,"student21","class21"};
	student s7={8,"student8","class8"};
	student s8={13,"student13","class13"};
	student s9={8,"student8","class8"};
	student s10={13,"student13","class13"};
	insert_hash_table(&h_table,s1,hash_fun);
	insert_hash_table(&h_table,s2,hash_fun);
	insert_hash_table(&h_table,s3,hash_fun);
	insert_hash_table(&h_table,s4,hash_fun);
	insert_hash_table(&h_table,s5,hash_fun);
	insert_hash_table(&h_table,s6,hash_fun);
	insert_hash_table(&h_table,s7,hash_fun);
	insert_hash_table(&h_table,s8,hash_fun);
	insert_hash_table(&h_table,s9,hash_fun);
	insert_hash_table(&h_table,s10,hash_fun);
	print_hash_table(&h_table);
	return 0;
}