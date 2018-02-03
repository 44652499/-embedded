// 2.输入一行字符串,找出其中出现的相同且长度最长的字符串,输出它及其首字符的位
// 置.如yyabcdabjcabceg,则输出为abc,3.

#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	// char ch[100];
	// gets(ch);
	// int m;
	// m=strlen(ch);
	char ch[]="yyabcdabjcabceg";
	int m;
	m=strlen(ch);
	char ch1[10];//输出结果的数组
	int i,j;//循环的两个变量一个从头数一个从后面数
	char *p;
	char *q;
	int num=0;//最长时候的字符串长度
	int may_num=0;//计算每次遇到重复开头字符的时最长的字符串
	int a=0;
	for(i=0;i<m;i++)
	{
		for(j=m-1;j>=0;j--)
		{
			may_num=0;
			if(i+j<m-1 && ch[i]==ch[j])
			{
				q=(ch+i);
				p=(ch+j);
				while(1)
				{
					if(*p!=*q)
					{
						break;
					}
					may_num++;
					++q;
					++p;
					//这里是不是要考虑p移动到字符数组最后
					if(*p=='\0')
					{
						break;
					}
					//段错误问题解决了,但是结果不正确,估计你的思路有问题.我发个代码共你参考下
				}
				if(may_num>num)
				{
					num=may_num;
					q=(ch+i);
					p=(ch+j);
					int a=0;
					while(*p==*q)
					{
						ch1[a]=*p;
						a++;
						p++;
						q++;
					}
				}
			}
		}
	}
	for(i=0;i<strlen(ch1);i++)
	{
		printf("%c",ch1[i]);
	}
	printf("\n");
	return 0;
}
