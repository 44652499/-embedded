#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define  N  32
/*1.设计一个程序实现任意的两个无符号整数的和与乘积(define UINT_MAX	4294967295U)  如果两个无符号整数 值已经是UINT_MAX 如何计算?*/

/*
错误输出函数
*/
void  system_error_message(const char* msgtitle,const char* msginfo)
{
	char  msg[200];
	strcpy(msg,msgtitle);
	strcat(msg,"---->");
	strcat(msg,msginfo);
	perror(msg);
	exit(-1);
}

/*
动态分配存放计算操作数空间
*/
char*  init_dynamic_mem(int size)
{
	char * ptr;
	ptr=(char*) malloc(size*sizeof(char));
	assert(ptr!=NULL);
	return ptr;
}
/*
检测操作数是否全是数字字符
*/
int  is_digit_character(char *  ptraddr)
{
	int i;
	int ret=1;
	for(i=0;i<strlen(ptraddr);i++)
	{
		if(*(ptraddr+i)<'0' ||  *(ptraddr+i)>'9')
		{
			ret=0;
			return ret;
		}
	}
	return ret;
}
/*
实现计算
*/
void  caculate_work(const char * ptra,const char * ptrb,char * ptrresult)
{
	int ptralen=strlen(ptra);
	int ptrblen=strlen(ptrb);
	int maxlen=(ptralen>ptrblen?ptralen:ptrblen)+1;
	int minlen=ptralen>ptrblen?ptrblen:ptralen;
	int i;
	int tmp=0;
	int resultindex=maxlen-minlen;
	for(i=minlen-1;i>=0;i--)
	{
     	int data=(ptra[ptralen-minlen+i]-'0')+(ptrb[ptrblen-minlen+i]-'0');
     	//考虑进位
     	data=data+tmp;
     	tmp=data/10;
     	data=data%10;
     	ptrresult[resultindex+i]=data+'0';
	}
	resultindex=maxlen-minlen-1;
	if(ptralen==ptrblen)
	{
		ptrresult[resultindex]=tmp+'0';
	}
	
	for(i=ptralen-minlen-1;i>=0;i--)
	{
		int data=(ptra[i]-'0');
     	//考虑进位
     	data=data+tmp;
     	tmp=data/10;
     	data=data%10;
     	ptrresult[resultindex--]=data+'0';
	}

	for(i=ptrblen-minlen-1;i>=0;i--)
	{
		int data=(ptrb[i]-'0');
     	//考虑进位
     	data=data+tmp;
     	tmp=data/10;
     	data=data%10;
     	ptrresult[resultindex--]=data+'0';
	}
	if(tmp!=0)
	{
		ptrresult[resultindex]=tmp+'0';
	}
	//输出结果
	if(ptrresult[0]=='\0')
	{
		ptrresult[0]='0';
	}
	for(i=0;i<maxlen;i++)
	{
		printf("%d",ptrresult[i]-'0');
	}
	printf("\n");
}

/*
释放动态空间
*/

void   free_dynamic_mem(void *  ptraddr)
{
	assert(ptraddr!=NULL);
	free(ptraddr);
	ptraddr=NULL;
}

int main(int argc, char const *argv[])
{
	char * ptra,*ptrb;
	ptra=init_dynamic_mem(N);
	ptrb=init_dynamic_mem(N);

	gets(ptra);
	gets(ptrb);

	int ret=is_digit_character(ptra);
	if(ret==0)
	{
		system_error_message("main","is_digit_character ptra :");
	}

	ret=is_digit_character(ptrb);
	if(ret==0)
	{
		system_error_message("main","is_digit_character ptrb :");
	}
	int ptralen=strlen(ptra);
	int ptrblen=strlen(ptrb);
	int maxlen=(ptralen>ptrblen?ptralen:ptrblen)+1;
    char *ptrresult=init_dynamic_mem(maxlen);

    caculate_work(ptra,ptrb,ptrresult);
	free_dynamic_mem(ptra);
	free_dynamic_mem(ptrb);
	free_dynamic_mem(ptrresult);
	return 0;
}