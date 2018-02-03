#include  <stdio.h>
#include  <string.h>
/*
字符拼接:
*/
/*自定义拼接函数*/
char *  define_strcat(char *  dest,const char* src)
{
	//判断是否存在足够空间存储src 指向字符数组值
	// if(sizeof(dest)>strlen(src)+1)///错误 sizeof(形参)==4
	// {

	// }

	while(*dest!='\0')
	{
		dest++;
	}
	while(1)
	{
		if(*src=='\0')
			break;
		*dest++=*src++;
    }
    *dest='\0';
}
int main(int argc, char const *argv[])
{
	// char ch1[]="abcde";
	// char ch2[]="12345";
	// //char ch3[]=ch1+ch2;//错误
	// char ch3[20];
	// bzero(ch3,sizeof(ch3));
	// // strcat(ch3,ch1);
	// // strcat(ch3,ch2);

	// if(sizeof(ch3)>=strlen(ch1)+strlen(ch2)+1)
	// {
	// 	define_strcat(ch3,ch1);
	// 	define_strcat(ch3,ch2);
	// }
	// printf("%s\n",ch3);	

	int  array[3][2]={1,2,3,4,5,6};
	//int *ptr=&array[0][0];
	int *ptr=(int*)array;//ptr++   !=  array++
	int i;
	for(i=0;i<2*3;i++)
	{
		printf("%d\t",*(ptr+i));
	}
	printf("\n");
	return 0;
}