#include <iostream>
using namespace std;
template<class T1,class T2>
class pair1
{
public:
	pair1(T1 _first,T2 _second)
	{
		first=_first;
		second=_second;
	}
	 T1  first;
	 T2  second;
};

template<class T>
class A
{
template<class T1>
friend ostream& operator <<(ostream& out,A<T1> a);
public:
	A()
	{

	}
	A(T _data)
	{
		data=_data;
	}
	T  data;
};
template<class T>
ostream& operator <<(ostream& out,A<T> a)
{
	out<<a.data<<endl;
	return out;
}

template<class T>
class B
{
template<class T1>
ostream& operator <<(ostream& out,typename B<T1> b);
public:
	B()
	{

	}
	B(T _value)
	{
		value=_value;
	}
	T value; 
};
template<class T>
ostream& operator <<(ostream& out,typename B<T> b)
{
	out<<b.value<<endl;
	return out;
}

void fun()
{
	B<string> b("abcd");
	A<B<string> > a(b);
	pair1<int,A<B<string> > > p(10,a);
	cout<<p.first<<"\t"<<p.second<<endl;
}


int main(int argc, char const *argv[])
{
	fun();
	return 0;
}
