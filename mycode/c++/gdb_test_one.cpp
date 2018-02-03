#include <iostream>
using namespace std;
void * ThreadFun(void * arg)
{
	int *value=(int*)arg;
	cout<<"this is thread"<<*value<<endl;
	pthread_exit(0);
}
int main(int argc, char const *argv[])
{
	int ret=0;
	pthread_t thread_id1,thread_id2;
	int *v1=new int(1);
	int* v2=new int(2);
	ret=pthread_create(&thread_id1,NULL,ThreadFun,(void*)v1);
	if(ret)
	{
		cout<<"Create pthread error"<<endl;
		return 1;
	}
	ret=pthread_create(&thread_id2,NULL,ThreadFun,(void*)v2);
	if(ret)
	{
		cout<<"Create pthread error"<<endl;
		return 1;
	}
	pthread_join(thread_id1,NULL);
	pthread_join(thread_id2,NULL);
	return 0;
}