#include <iostream>
using namespace std;
class A
{
public:
	int data;
public:
	A()
	{

	}
	A(int _data)
	{
		data=_data;
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
		return ::operator new[](sizeof(A)*size);
	}

	void    operator delete[](void* p)
	{
		cout<<"delete"<<endl;
        ::operator delete[](p);
	}
	~A()
	{
		cout<<"end"<<endl;
	}

};

int main(int argc, char const *argv[])
{
	A  *a1=new A(400);
	//a1->data=3000;
	cout<<a1->data<<endl;
	delete a1;
	a1=NULL;

	// A*a1=new A[4];
	// int i;
	// for(i=0;i<4;i++)
	// {
	// 	a1[i].data=23+i;
	// }
	// for(i=0;i<4;i++)
	// {
	//    cout<<a1[i].data<<'\t';
	// }
	// cout<<endl;
	// delete[] a1;
	return 0;
}