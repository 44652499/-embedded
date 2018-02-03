#include <iostream>
#include <string.h>
using namespace std;
/*
模板思想实现与类型无关,只与功能实现有关.
类模板:定义类时数据类型不定
模板类:使用类实例化对象,指定类型.构建一个具体对象
STL:标准模板库(模板类+算法)实现容器效果
*/

//定义个学生类
class student
{
friend istream&   operator >>(istream & in,student& s);
friend ostream &  operator <<(ostream & out,student& s);
public:
	student()
	{

	}
	student(int _suid,const char * _name)
	{
		sid=_suid;
		strcpy(name,_name);
	}
	bool operator>(student s)
	{
		return this->sid>s.sid;
	}
private:
	int sid;
	char name[10];
};
//定义标准输入
istream&   operator >>(istream & in,student& s)
{
	in>>s.sid>>s.name;
	return in;
}
//定义标准输出
ostream &  operator <<(ostream & out,student& s)
{
	out<<s.sid<<'\t'<<s.name<<endl;
	return out;
}


//定义类模板
template<class T>
class Array
{
public:
	Array(int _size)
	{
		size=_size;
		ptr=new T[size];
	}
	void  inputvalue()
	{
		int i;
		for(i=0;i<size;i++)
		{
			cin>>ptr[i];
		}
	}
	void  outputvalue()
	{
		int i;
		for(i=0;i<size;i++)
		{
			cout<<ptr[i]<<"\t";
		}
		cout<<endl;
	}
	void  sortvalue()
	{
		int i,j;
		for(i=0;i<size;i++)
		{
			for(j=0;j<size-i-1;j++)
			{
				if(ptr[j]>ptr[j+1])
				{
					T tmp=ptr[j];
					ptr[j]=ptr[j+1];
					ptr[j+1]=tmp;
				}
			}
		}
	}
private:
	T *ptr;
	int size;
};
int main(int argc, char const *argv[])
{
	Array<student> a1(5);
	a1.inputvalue();
	a1.sortvalue();
	a1.outputvalue();
	return 0;
}