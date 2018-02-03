#include  <iostream>
using namespace std;
typedef void (*PTR_FUN)();
/*
静态联编:编译时,明确函数参数类型
动态联编:编译时,函数基类参数指针或引用不确定对象具体类型(不做类型安全检测).在执行调用时根据传递实参确定类型.

虚表:存放类的虚汗地址值一维数组.类存在虚函数才存在一个虚表


*/
class  Base
{
private:
	virtual void  fun()
	{
		cout<<"Base  fun"<<endl;
	}
	virtual void  fun2()
	{
		cout<<"Base  fun2"<<endl;
	}
private:
	int data;
};

class Child :public  Base
{
public:
	//派生类覆盖基类的虚函数(派生类自定义函数地址值覆盖了基类虚表中的函数地址值)
	virtual void  fun2()
	{
		cout<<"Child  fun2"<<endl;
	}
	virtual void  fun3()
	{
		cout<<"Child  fun3"<<endl;
	}
};
int main(int argc, char const *argv[])
{
	//cout<<sizeof(Base)<<endl;//对象的前4个字节记录虚表地址
	Child  obj_b1;
	int *ptr_vtable= (int*)*((int*)&obj_b1);//找到虚表地址
	cout<<"Child vtable address:"<<ptr_vtable<<endl;//派生类复制基类虚表.

	int * ptr_fun=(int*)(*ptr_vtable);//取出虚表一个元素地址(第一个虚函数地址)
	((PTR_FUN)ptr_fun)();//把一个地址转换成函数地址

	ptr_fun=(int*)(*(ptr_vtable+1));
	((PTR_FUN)ptr_fun)();

	ptr_fun=(int*)(*(ptr_vtable+2));
	((PTR_FUN)ptr_fun)();//派生类自定义虚函数存放在虚表末尾(只有一个虚表)
	return 0;
}