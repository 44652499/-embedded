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
	//定义深拷贝
	A(const A & obj)
	{
		p=new int[3];
		int i;
		for(i=0;i<3;i++)
		{
			p[i]=obj.p[i];
		}
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
	A a2(a1);
	return 0;
}
//实现一个数组类,需要有一个排序函数(非递归快排)
//用c++ 实现判断同一个平面任意两条直线是否平行
//用c++实现判断两个不同平面是否平行
//自定一个简单多线程类