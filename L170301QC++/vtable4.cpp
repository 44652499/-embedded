#include  <iostream>
using namespace std;
typedef void (*PTR_FUN)();
/*
*/
class  Base1
{
public:
	Base1()
	{
		data=20;
	}
	virtual void  fun()
	{
		cout<<"Base1  fun"<<endl;
	}
	virtual void  fun2()
	{
		cout<<"Base1  fun2"<<endl;
	}
private:
	int data;
};
class  Base2
{
public:
	virtual void  fun3()
	{
		cout<<"Base2  fun3"<<endl;
	}
	virtual void  fun4()
	{
		cout<<"Base2  fun4"<<endl;
	}
};

class Child :public  Base1,public Base2
{
public:
	virtual  void fun5()
	{
		cout<<"Child  fun5"<<endl;
	}
};
int main(int argc, char const *argv[])
{
	//cout<<sizeof(Child)<<endl;//对象的前4个字节记录虚表地址
	 Child  obj_b1;
	 // int *ptr_vtable= (int*)&obj_b1;
	 // cout<<*ptr_vtable<<endl;
	 // cout<<*(ptr_vtable+1)<<endl;
	 // cout<<*(ptr_vtable+2)<<endl;//第二个指向虚表指针是在第一个基类最后一个数据成员下面
    //访问第一个虚表
	int *ptr_vtable= (int*)(*(int*)&obj_b1);
	int * ptr_fun=(int*)(*ptr_vtable);
	((PTR_FUN)ptr_fun)();

	ptr_fun=(int*)(*(ptr_vtable+1));
	((PTR_FUN)ptr_fun)();

	ptr_fun=(int*)(*(ptr_vtable+2));
	((PTR_FUN)ptr_fun)();//派生存在多个虚表时,自定义虚函数存放在第一个虚表的末尾

	//访问第二个虚表
	ptr_vtable= (int*)(*((int*)&obj_b1+2));
	ptr_fun=(int*)(*ptr_vtable);
	((PTR_FUN)ptr_fun)();

	ptr_fun=(int*)(*(ptr_vtable+1));
	((PTR_FUN)ptr_fun)();
	return 0;
}

//思考问题:
//1.虚析构函数是否存在虚表中?如果是,请用代码验证