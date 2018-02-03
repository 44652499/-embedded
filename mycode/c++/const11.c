#include <stdio.h>
int main(int argc, char const *argv[])
{
	const int a=10;
	int *p=(int*)&a;
	printf("*p=%d\ta=%d\n",*p,a);
	//cout<<*p<<" "<<a<<endl;
	printf("p=%p\ta=%p\n",p,&a);
	//cout<<p<<" "<<&a<<endl;
	*p=20;
	//cout<<*p<<" "<<a<<endl;
	printf("*p=%d\ta=%d\n",*p,a);
	//cout<<p<<" "<<&a<<" "<<&p<<endl;
	printf("p=%p\ta=%p\n",p,&a);
	//cout<<*p<<" "<<a<<endl;
	printf("*p=%d\ta=%d\n",*p,a);
	return 0;
}