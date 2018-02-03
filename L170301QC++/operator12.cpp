#include <iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout<<"A  constructor"<<endl;
	}
	~A()
	{
		cout<<"A  disconstructor"<<endl;
	}
};
int main(int argc, char const *argv[])
{
	A *  ptr_one=new A;//分配空间   调用构造函数初始化
	A *  ptr_two=new A[3];//分配空间   调用3次构造函数初始化

	//delete[]  ptr_two;//调用3次析构函数,释放空间
	//delete  ptr_two;//错误
	//ptr_two=NULL;

	//delete ptr_one;//调用1次析构函数,释放空间
	//delete[] ptr_one;//错误
	//ptr_one=NULL;
    //验证 多分配4个字节存放分配的空间数
	int * ptr_i=((int*)ptr_two-1);//new 返回值的前4个字节
	cout<<*ptr_i<<endl;
	return 0;
}