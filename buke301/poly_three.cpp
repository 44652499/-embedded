#include <iostream>
using namespace std;
typedef  void  (*FUN)();
/*
*/
class  base
{
private:
	int  a;
public:
	base()
	{
		a=10;
	}
    virtual void  fun()
    {
    	cout<<"base  fun"<<endl;
    }
};

class  base2
{
public:
	virtual void  fun()
	{
		cout<<"base2 fun"<<endl;
	}
};

class  child :public base,public  base2
{
public:
	// virtual  void  fun()
	// {
	// 	cout<<"child fun"<<endl;
	// }
};
int main(int argc, char const *argv[])
{	
	// base b;
	// FUN f=(FUN)*(int*)*(int*)&b;
	// f();
    //调用第一个基类虚表函数
	// child c;
	// FUN f=(FUN)*(int*)*(int*)&c;
	// f();
    //调用第二个基类虚表函数
	child c;
	FUN f=(FUN)*(int*)*((int*)&c+2);
	f();
	return 0;
}
//模板类+rbtree实现一个map容器