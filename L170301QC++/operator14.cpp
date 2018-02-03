#include <iostream>
#include <stdlib.h>
using namespace std;
/*
new/new[]符号重载
new --->operator new ---->::operator new ---->malloc(brk)
new[] --->operator new[] ----> ::operator new[] ---->malloc(brk)
delete/delte[]符号重载
delete --->operator delete  ---> :: operator delete   ---->free
delete[] --->operator delete[]  ---> ::operator delete[]   --->free
*/
class A
{
public:
	A(int _data=0)
	{
		data=_data;
		cout<<"A  constructor"<<endl;
	}
	//重载 new
	void*   operator  new (size_t  size)
	{
		cout<<"operator new"<<endl;
		if(size==0)
		{
			throw  bad_alloc();//抛出异常
		}
		if(size!=sizeof(A))
		{
			throw bad_alloc();
		}
		void *  ptr=malloc(size);//size表示空间大小,非空间数
		return ptr;
	}

	//重载new[]
	void  *   operator  new[](size_t size)
	{
		cout<<"operator new[]"<<endl;
		if(size==0)
		{
			throw  bad_alloc();//抛出异常
		}
		void *  ptr=malloc(size);//size表示空间大小,非空间数
		return ptr;
	}

	//重载释放
	void   operator delete(void * ptr)
	{
		cout<<"operator delete"<<endl;
		if(ptr!=NULL)
		{
			free(ptr);
			ptr=NULL;
		}
	}

	//重载 delete[]
	void  operator delete[](void *  ptr)
	{
   		cout<<"operator delete[]"<<endl;
		if(ptr!=NULL)
		{
			free(ptr);
			ptr=NULL;
		}
	}

	~A()
	{
		cout<<"A  disconstructor"<<endl;
	}
private:
	int data;
};
int main(int argc, char const *argv[])
{
	//A *  ptr_one=new A(2);
	// delete  ptr_one;
	// ptr_one=NULL;

	A *  ptr_one=new A[2];
	delete[]  ptr_one;
	ptr_one=NULL;
	return 0;
}