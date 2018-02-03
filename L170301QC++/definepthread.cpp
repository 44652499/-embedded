#include <iostream>
#include <pthread.h>
typedef  void*  (*p_fun)(void * arg);
using namespace std;
/*
自定一个简单多线程类
*/
//定义线程运行函数
void*  pthread_fun1(void* arg)
{
	cout<<"pthread_fun1  running"<<endl;
}

void*  pthread_fun2(void* arg)
{
	cout<<"pthread_fun2  running"<<endl;
}

class  DefinePthread
{
public:
	DefinePthread()
	{
	}
	void start()
	{
		int ret=pthread_create(&id,NULL,pthread_fun1,NULL);
		if(ret==-1)
		{
			cout<<"start fail"<<endl;
		}
	}
	void start(p_fun fun)
	{
		int ret=pthread_create(&id,NULL,fun,NULL);
		if(ret==-1)
		{
			cout<<"start fail"<<endl;
		}
	}
	void  stop()
	{
		pthread_join(id,NULL);
	}
private:
	pthread_t  id;
};
int main(int argc, char const *argv[])
{
	DefinePthread  p1;
	//p1.start();
	p1.start(pthread_fun1);//启动线程是指定执行的函数
	p1.stop();

	DefinePthread  p2;
	//p1.start();
	p2.start(pthread_fun2);//启动线程是指定执行的函数
	p2.stop();
	return 0;
}