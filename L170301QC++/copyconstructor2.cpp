#include <iostream>
using namespace std;
/*
拷贝:
1.浅拷贝:只拷贝对象成员值
2.深拷贝:拷贝对象成员值,还拷贝成员指向其它值
*/
class A
{
public:
	A()
	{
		p=new int[3];
	}
	//浅拷贝
	A(const  A&  obj)
	{
		p=obj.p;
	}
	
	~A()
	{
		//释放语句
		if(p!=NULL)
		{
			delete p;
		    p=NULL;
		}		
	}
private:
	int *p;
};
int main(int argc, char const *argv[])
{
	A a1;
	A a2(a1);//浅拷贝,在对象释放时,执行析构函数,析构函数释放的是同一个堆空间,出现错误
	return 0;
}