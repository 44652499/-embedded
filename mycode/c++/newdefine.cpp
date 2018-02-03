#include <iostream>
using namespace std;
// class A
// {
// public:
// 	// A()
// 	// {
// 	// 	cout<<"A constructor"<<endl;
// 	// }
// 	~A()
// 	{
// 		cout<<"A disconstructor"<<endl;
// 	}
// private:
// 	int data;
// };

// void nomorememory()
// {
// 	cerr << "unable to satisfy request for memory\n";
// 	//abort();//一般用这个执行
// }

// int main(int argc, char const *argv[])
// {
// 	A *p1=new A[10];
// 	int num=*(int*)((A**)p1-1);
// 	cout<<num<<endl;
// 	delete[] p1;
// 	p1=NULL;
	// try
	// {
	// 	//这样如果 new 失败了，就不会抛出异常，而是返回空指针
	// 	// double *ptr=new(std::nothrow) double[1000000000];
	// 	// if(ptr==0)
	// 	// {
	// 	// 	cout<<"NULL"<<endl;
	// 	// }
	// 	//内存分配失败,只能抛出异常,但绝不能返回NULL
	// 	double *ptr=new double[1000000000];

	// }catch(bad_alloc & ex)//bad_alloc 内存分配失败抛出异常类
	// {
	// 	//cout<<"error"<<endl;
	// 	cerr<<ex.what()<<endl;
	// }

    //内存分配失败,执行注册函数(循环执行直到分配成功为止)
	// set_new_handler(nomorememory);
	// double *ptr=new double[1000000000];
//}




// int main(int argc, char const *argv[])
// {
// 	int * ch=new int[10](23);
// 	int i=0;
// 	for(i=0;i<10;i++)
// 	{
// 		cout<<ch[i]<<endl;
// 	}

// 	return 0;
// }


class A
{
public:
	A()
	{
		cout<<"A constructor"<<endl;
	}
	virtual ~A()
	{
		cout<<"A disconstructor"<<endl;
	}
	// virtual void  fun1()=0;
	// virtual ~A()=0;
};
//  void  fun1()
//  {

//  }
// A::~A()
// {

// }
class  B  :public A
{

};
int main(int argc, char const *argv[])
{
	A* a1=new A;
	cout<<sizeof(a1)<<endl;
	a1->~A();
	//B  b1;
	return 0;
}