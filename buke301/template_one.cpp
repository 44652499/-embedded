#include <iostream>
#define  PI  3.14
using namespace std;
/*
模板类继承:
*/
template<class T>
class  circle
{
public:
	circle(T _r)
	{
		r=_r;
	}
	T  getlength()
	{
		return 2*PI*r;
	}
	T  getarea()
	{
		return PI*r*r;
	}
private:
	T r;
};
//派生类继承模板基类,调用基类的方法时.必须基类带上模板参数
template <class T,class T1>
class   child:public circle<T>
{
private:
	T1  h;
public:
	child(T _r,T1 _h):circle<T>(_r)
	{
		h=_h;
	}
	T1  getnewarea()
	{
		return  2*circle<T>::getarea()+circle<T>::getlength()*h;
	}

	T1  gettiji()
	{
		return circle<T>::getarea()*h;
	}
};
int main(int argc, char const *argv[])
{
	child<int,double> c1(10,20);
	cout<<c1.getnewarea()<<endl;
	cout<<c1.gettiji()<<endl;
	return 0;
}