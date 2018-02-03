#include <iostream>
using namespace std;
/*
++i  与 i++ 效率哪个高?
++i效率高
int a=i++;
A  obj
A a=obj++;//需要创建一个临时对象,需要调用构造函数,析构函数

++ 符号重载
*/
class Increment
{
friend ostream& operator <<(ostream& out,Increment  &obj);
public:
	Increment(int _counter=0)
	{
		counter=_counter;
	}
	Increment  operator++()//前置++
	{
		this->counter=this->counter+1;
		return *this;
	}
	Increment  operator++(int i)//后置++
	{
		Increment tmp_obj;
		tmp_obj=*this;
		this->counter=this->counter+1;
		return tmp_obj;
	}
private:
	int  counter;
};
ostream& operator <<(ostream& out,Increment  &obj)
{
	out<<obj.counter<<endl;
	return out;
}
int main(int argc, char const *argv[])
{
	Increment  obj1(1);
	Increment  obj2=obj1++;
	Increment  obj3=++obj1;
	cout<<obj2<<endl;
	cout<<obj3<<endl;
	return 0;
}