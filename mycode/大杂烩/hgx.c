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

	//(int***)p+=1;//�������
	//printf("%d\n",***p);
	//��֪����Ҫ���ʲô��˼??
	
	
	//printf("%d\n",**(*p+1));
	//printf("%d\n",*(*p)[1]);
	//ͨ��pȥ��b��ֵ,Ӧ�����������!!
	//����ͼ��������

		
	return 0;
}
	
