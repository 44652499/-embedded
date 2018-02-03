#include  <iostream>
using namespace std;
// template<class T>
// typedef  bool  sort_fun(T a,T b);  错误,typedef 不支持模板参数
template<class T>
class  Array
{
//声明友元模板函数
template<class T1>
friend istream&  operator >>(istream& in,Array<T1>  & obj);
template<class T1>
friend ostream &  operator <<(ostream& out,Array<T1>& obj);

typedef  bool  sort_fun(T a,T b);//定义排序函数指针
public:
	Array(int _size)
	{
		size=_size;
		ptr=new T[size];
	}
	void sort(sort_fun  fun)
	{
		int i,j;
		for(i=0;i<size;i++)
		{
			for(j=0;j<size-i-1;j++)
			{
				if(fun(ptr[j],ptr[j+1]))
				{
					T  temp=ptr[j];
					ptr[j]=ptr[j+1];
					ptr[j+1]=temp;
				}
			}
		}
	}
private:
	T*  ptr;
	int size;
};
//模板类的输入输出重载
template<class T>
istream&  operator >>(istream& in,Array<T>  & obj)
{
	int i;
	for(i=0;i<obj.size;i++)
	{
		in>>obj.ptr[i];
	}
	return in;
}
template<class T>
ostream &  operator <<(ostream& out,Array<T>& obj)
{
	int i;
	for(i=0;i<obj.size;i++)
	{
		cout<<obj.ptr[i]<<"\t";
	}
	cout<<endl;
	return out;
}

//定义排序函数
template<class T>
bool asc_fun(T a,T b)
{
	return a>=b;
}
template<class T>
bool  desc_fun(T a,T b)
{
	return a<=b;
}

int main(int argc, char const *argv[])
{
	Array<int>  a1(10);
	cin>>a1;
	//a1.sort(asc_fun);//传递一个函数指针作为排序参数(升序|降序)
	a1.sort(desc_fun);
	cout<<a1;
	return 0;
}