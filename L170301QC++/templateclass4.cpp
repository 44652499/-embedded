#include <iostream>
using namespace std;
/*
模板思想实现与类型无关,只与功能实现有关.
类模板:定义类时数据类型不定
模板类:使用类实例化对象,指定类型.构建一个具体对象
STL:标准模板库(模板类+算法)实现容器效果
*/
//定义类模板
template<class T=int,int size=5>//类模板参数默认值
class Array
{
public:
	Array(int _size)
	{
		//size=_size;
		ptr=new T[size];
	}
	void  inputvalue();
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
	//int size;//模板参数隐藏
};

template<class T1,int size>//只能用在最近作用域
void  Array<T1,size>::inputvalue()
{
		int i;
		for(i=0;i<size;i++)
		{
			cin>>ptr[i];
		}
}

int main(int argc, char const *argv[])
{
	//Array<int>  a1(5);//实例化对象 
	//Array<int>  模板类

	//Array<char>  a1(5);
	Array<>  a1(5);
	a1.inputvalue();
	a1.sortvalue();
	a1.outputvalue();
	return 0;
}