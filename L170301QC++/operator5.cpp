#include  <iostream>
using namespace std;
// template<class T>
// typedef  bool  sort_fun(T a,T b);  错误,typedef 不支持模板参数
template<class T,class  T2>
class  Array
{
//声明友元模板函数
template<class T1,class TT1>
friend istream&  operator >>(istream& in,Array<T1,TT1>  & obj);
template<class T1,class TT1>
friend ostream &  operator <<(ostream& out,Array<T1,TT1>& obj);

public:
	Array(int _size,T2 sort_type_obj)//第二个参数使用默认值
	{
		size=_size;
		ptr=new T[size];
		cin>>*this;//当前对象输入值
		sort(sort_type_obj);
	}
	void sort(T2 sort_type_obj)
	{
		int i,j;
		for(i=0;i<size;i++)
		{
			for(j=0;j<size-i-1;j++)
			{
				//sort_type_obj 是排序类型的对象,()是排序类的符号重载
				if(sort_type_obj(ptr[j],ptr[j+1]))
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
template<class T,class T2>
istream&  operator >>(istream& in,Array<T,T2>  & obj)
{
	int i;
	for(i=0;i<obj.size;i++)
	{
		in>>obj.ptr[i];
	}
	return in;
}
template<class T,class T2>
ostream &  operator <<(ostream& out,Array<T,T2>& obj)
{
	int i;
	for(i=0;i<obj.size;i++)
	{
		cout<<obj.ptr[i]<<"\t";
	}
	cout<<endl;
	return out;
}

//定义排序类型
template<class T>
class  sort_type
{
public:
	bool  operator()(T a,T b)
	{
		return a>b;
	}
};

int main(int argc, char const *argv[])
{
	sort_type<int>  s_obj;
	Array<int,sort_type<int> >  a1(10,s_obj);//创建有序对象
	//sort_type<int> 称为排序类型,模板类
	cout<<a1;
	return 0;
}