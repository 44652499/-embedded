#include <iostream>
using namespace std;
// template<class  T,int a=100>
// void fun(T b)
// {
// 	//int a=10;
// 	cout<<a+b<<endl;
// }
// int main(int argc, char const *argv[])
// {
// 	fun(20);
// 	return 0;
// }
// class A
// {
// public:
//     A()
//     {
//     	a=10;
//     }
// 	int a;
// };
// class B: virtual A
// {
// public:
// 	B()
//     {
//     	b=2;
//     }
// 	int b;
// };
// class C: virtual A
// {
// public:
// 	C()
//     {
//     	c=3;
//     }
// 	int c;
// };
// class D:public B,public C
// {
// public:
// 	D()
//     {
//     	d=4;
//     }
// 	int d;
// };
// int main(int argc, char const *argv[])
// {
// 	// cout<<sizeof(A)<<endl;
// 	// cout<<sizeof(B)<<endl;
// 	// cout<<sizeof(C)<<endl;
// 	// cout<<sizeof(D)<<endl;
// 	//B b;
// 	//C  c;
// 	D d;
// 	int *ptr_a=(int*)&d;
//     cout<<*ptr_a<<endl;
//     cout<<*(ptr_a+1)<<endl;
//     cout<<*(ptr_a+2)<<endl;
//     cout<<*(ptr_a+3)<<endl;
//     cout<<*(ptr_a+4)<<endl;
//     cout<<*(ptr_a+5)<<endl;
// 	return 0;
// }

class A
{
public:
	A()
	{
		fun();
	}
	virtual void  fun()
	{
		cout<<"A::fun"<<endl;
	}
};

class B :public A
{
public:
	void  fun()
	{
		cout<<"B::fun"<<endl;
	}
};
int main(int argc, char const *argv[])
{
	// //cout<<sizeof(B)<<endl;
	// A *ptr_a=new B(10);
	// ptr_a->fun();
	B  b;
	return 0;
}