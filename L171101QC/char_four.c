#include  <stdio.h>
/*
字符比较大小:
1.比较的时ascii编码值
2.先大则大,与字符数组长度无关
*/
/*
自定一实现字符数组比较函数
*/
int  define_strcmp(const char*  ch1,const char * ch2)
{
	int ret=0;
	while(1)
	{
		if(*ch1==0 && *ch2==0)
		{
			break;
		}
		if(*ch1>*ch2)
		{
			ret=1;
			break;
		}
		if(*ch1<*ch2)
		{
			ret=-1;
			break;
		}
		ch1++;
		ch2++;
	}
	return ret;
}

int  define_strncmp(const char*  ch1,const char * ch2,int n)
{
	int ret=0;
	while(1)
	{
		if(*ch1==0 && *ch2==0)
		{
			break;
		}
		if(*ch1>*ch2)
		{
			ret=1;
			break;
		}
		if(*ch1<*ch2)
		{
			ret=-1;
			break;
		}
		ch1++;
		ch2++;
		if(--n==0)
		{
			break;
		}
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	
	char  ch1[10];
	char  ch2[20];
	//scanf("%s",ch1);'\n' 空格字符 结束输入
	gets(ch1);//'\n' 结束输入,空格字符有效
	gets(ch2);
	//puts(ch2);//输出
	//int ret=strcmp(ch1,ch2);
	//int ret=define_strcmp(ch1,ch2);
	//int ret=strncmp(ch1,ch2,4);
	int ret=define_strncmp(ch1,ch2,4);
	if(ret==0)
	{
		printf("ch1==ch2\n");
	}
	if(ret>0)
	{
		printf("ch1>ch2\n");
	}
	if(ret<0)
	{
		printf("ch1<ch2\n");
	}
	return 0;
}