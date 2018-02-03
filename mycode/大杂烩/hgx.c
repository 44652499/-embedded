#include <stdio.h>

int main(int argc, char *argv[])
{
	int a=2;
	int b=3;
	int* q=&a;
	int* qq=&b;
	int* data[5]={q,qq,0,0,0};
    int* (*p)[5];

	p=&data;	
	printf("%d\n",***p);

	//(int***)p+=1;//编译错误
	//printf("%d\n",***p);
	//不知道你要表达什么意思??
	
	
	//printf("%d\n",**(*p+1));
	//printf("%d\n",*(*p)[1]);
	//通过p去除b的值,应该是这样表达!!
	//画画图就明白了

		
	return 0;
}
	
