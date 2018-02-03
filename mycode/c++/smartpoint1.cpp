#include <iostream>
using namespace std;
/*
智能指针:
1.管理多个类的成员指针变量指向同一个对象,如果出现通过其中任意一个指针释放对象后,其它指针将成为悬浮指针
2.利用局部智能指针对象自动释放,自动调用析构函数,在析构函数中通过其引用类的计数器是否0判断是否该删除对象
3.设计中间一个引用类,通过计数器的是否为0判断
*/
// class  point
// {
// public:
// 	point(int _x,int _y):x(_x),y(_y){}
// 	int getx()
// 	{
// 		return x;
// 	}
// 	int gety()
// 	{
// 		return y;
// 	}
// 	void setx(int _x)
// 	{
// 		x=_x;
// 	}
// 	void sety(int _y)
// 	{
// 		y=_y;
// 	}
// private:
// 	int x;
// 	int y;
// };
// class refptr
// {
// private:
// 	refptr(point* _ptr):ptr(_ptr),count(1)
// 	{

// 	}
// 	~refptr()
// 	{
// 		if(ptr!=NULL)
// 		{
// 			delete ptr;
// 			ptr=NULL;
// 		}
// 	}
// 	point*  ptr;
// 	int count;
// };
// class smartptr
// {
// public:
// 	smartptr(point *  ptr)
// 	{
// 		ref_ptr=new refptr(ptr);
// 	}
// 	smartptr(const smartptr &  ref )
// 	{
// 		this->ref_ptr=ref.ref_ptr;
// 		ref.ref_ptr.count++;
// 	}
// 	smartptr& operator=(const smartptr& ref)
// 	{
// 		ref.ref_ptr.count++;
// 		this->ref_ptr.count--;
// 		if(this->ref_ptr.count==0)
// 		{
// 			delete  this->ref_ptr;
// 			 this->ref_ptr=NULL;
// 		}
// 		this->ref_ptr=ref.ref_ptr;
// 		return *this;
// 	}
// 	~smartptr()
// 	{
// 		if(--this->ref_ptr.count==0)
// 		{
// 			delete this->ref_ptr;
// 			this->ref_ptr=NULL;
// 		}
// 	}
// private:
// 	refptr * ref_ptr;
// };
// int main(int argc, char const *argv[])
// {
// 	point *p1=new point(10,8);
// 	smartptr  s1(p1);
// 	smartptr  s2(s1);
// 	point* p2=new point(5,5);
// 	smartptr  s3(p2);
// 	s3=s1;
// 	return 0;
// }

class base
{
public:
	base()
	{
		data=300;
	}
	void  fun()
	{
		cout<<"base fun"<<endl;
	}
private:
	int data;
};

class base1:public virtual base
{
public:
	base1()
	{
		data1=400;
	}
	void   fun1()
	{
		cout<<"base1  fun1"<<endl;
	}
private:
	int data1;
};

class base2:public virtual base
{
public:
	base2()
	{
		data2=500;
	}
	void  fun2()
	{
		cout<<"base2  fun2"<<endl;
	}
private:
	int data2;
};
class  derived:public base1,public base2
{

};
int main(int argc, char const *argv[])
{
	// cout<<sizeof(base)<<"\t"<<sizeof(base1)<<"\t"<<sizeof(base2)<<endl;
	// cout<<sizeof(derived)<<endl;
	// derived  d1;
	// int i;
	// int n;
	// for(i=0;i<5;i++)
	// {
	// 	//cout<<hex<<(int*)&d1+i<<endl;
	// 	n=*((int*)&d1+i);
	// 	cout<<n<<endl;
	// }
	// // base1 b1;
	// // int i;
	// // for(i=0;i<4;i++)
	// // {
	// // 	cout<<*((int*)&b1+i)<<endl;
	// // }
	base  b1;
	//derived  *d1=new derived;
	//base  *b=static_cast<base  *>(d1);
	//b->fun();
	//base1  b11;
	base1  *b11=new base1;
	//derived  *d1=static_cast<derived  *>(b1);
	//derived  *d1=static_cast<derived  *>(b11);
	derived  *d1=dynamic_cast<derived  *>(b11);//语法错误,但做法的正确的 ,需要安全性检查,检查转换之后是否存在对象
	//d1->fun();
	return 0;
}