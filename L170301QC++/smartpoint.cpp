#include  <iostream>
using namespace std;
/*
智能指针:是一种类,管理多个指针指向同一个动态分配对象释放问题.如果对象过早释放会产生悬浮指针.如果不释放会造成内存泄漏.
智能指针是如何实现有效合理释放动态对象?
存在三个类:
1.智能指针类(A)
2.动态分配对象类(B)
3.引用类(C)
构造A 类的局部对象,自动释放时调用析构函数.在析构函数中释放引用A类一个对象.调用引用A类的析构函数,释放动态分配对象
利用析构函数在在释放对象时系统自动调用
实现智能类:
1.智能指针类(A) 必定存在一个指针成员指向 引用类(C)
2.智能指针类(A) 存在一个有参数构造函数,参数为 动态分配对象地址.在构造函数中构造一个引用类对象,把参数传递给引用类(C) 中的指针成员
3.引用类(C)   存在一个计数数据成员和一个指针成员指向动态分配对象

引用类必须存在一个计数成员,记录动态对象仍然存在多少个指针指向.
*/
//智能指针测试类
class  SmartTest
{
public:
	void  fun()
	{
		cout<<"fun"<<endl;
	}
};

//引用类(要求引用类的成员都为私有,防止在类外直接访问引用的成员,只能在智能指针类中访问)
class SmartRef
{
friend class  Smart;
private: 
	SmartRef(SmartTest * _ptr_smarttest)
	{
		ptr_smarttest=_ptr_smarttest;
		counter=0;
	}
	~SmartRef()
	{
		if(ptr_smarttest!=NULL)
		{
			delete ptr_smarttest;
			ptr_smarttest=NULL;
		}
	}
	int  counter;
	SmartTest * ptr_smarttest;
};

//智能指针类
class  Smart
{
public:
	Smart(SmartTest *  ptr_obj)
	{
		ptr_smartref=new SmartRef(ptr_obj);
		ptr_smartref->counter++;
	}
	Smart(Smart &  smart_obj)
	{
		ptr_smartref=smart_obj.ptr_smartref;
		ptr_smartref->counter++;
	}

	Smart&  operator =(Smart & smart_obj)
	{
		if(this->ptr_smartref->counter==1)
		{
			this->ptr_smartref->counter=0;
			delete this->ptr_smartref;
			this->ptr_smartref=NULL;			
		}
		else
		{
			this->ptr_smartref->counter--;
			this->ptr_smartref=NULL;
		}
		this->ptr_smartref=smart_obj.ptr_smartref;
		smart_obj.ptr_smartref->counter++;
	}

	~Smart()
	{
		if(ptr_smartref!=NULL&& ptr_smartref->counter==1)
		{
			ptr_smartref->counter=0;
			delete ptr_smartref;
			ptr_smartref=NULL;			
		}
		else
		{
			ptr_smartref->counter--;
			ptr_smartref=NULL;
		}
	}
private:
	SmartRef  *  ptr_smartref;
};
int main(int argc, char const *argv[])
{
	SmartTest  *  ptr_obj=new SmartTest();
	Smart  smart_obj_one(ptr_obj);
	Smart  smart_obj_two(smart_obj_one);


	SmartTest  *  ptr_obj_two=new SmartTest();
	Smart  smart_obj_three(ptr_obj_two);

	smart_obj_three=smart_obj_one;
	return 0;
}