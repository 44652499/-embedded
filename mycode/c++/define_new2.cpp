#include <iostream>
using namespace std;
class A
{
public:
	A()
	{

	}
	void *  operator new(size_t size)
	{
		cout<<size<<endl;
		// if(size==sizeof(A))
		// {
		// 	return ::operator new(size);
		// }
		// else
		// 	return NULL;
		//return ::operator new(size);
		return malloc(1*sizeof(A));
	}
	void    operator delete(void* p)
	{
		cout<<"delete"<<endl;
        ::operator delete(p);
	}

	void *  operator new[](size_t size)
	{
		cout<<"size="<<size<<endl;
		return ::operator new[](sizeof(A)*size);
	}

	void    operator delete[](void* p)
	{
		cout<<"delete[]"<<endl;
        ::operator delete[](p);
	}
	~A()
	{
		cout<<"end"<<endl;
	}
private:
	int data;

};

int main(int argc, char const *argv[])
{
	// A  *a1=new A;
	// delete a1;
	// a1=NULL;

	A  *a1=new A[5];
	int num=*((int*)a1-1);
	cout<<"num="<<num<<endl;
	delete[] a1;
	//delete a1;
	a1=NULL;
	return 0;
}