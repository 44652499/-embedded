#include <iostream>
#define  N 2
using namespace std;
//自定vector 向量容器
template<class T>
class DefineVector
{
public:
	//定义逆向迭代器
	class reverse_iterator
	{
	public:
		reverse_iterator()
		{

		}
		reverse_iterator(T  *  _ptr)
		{
			ptr=_ptr;
		}
		reverse_iterator   operator =(const reverse_iterator& it)
		{
			this->ptr=it.ptr;
			return *this;
		}
		reverse_iterator operator++(int i)
		{
			reverse_iterator  tmp=*this;
			this->ptr=this->ptr-1;
			return *this;
		}
		bool  operator !=(const reverse_iterator&  it)
		{
			return  this->ptr!=it.ptr;
		}
		T operator *()
		{
			return  *(this->ptr);
		}
	 private:
	 	T * ptr;
	};
	//定义迭代器类型
	typedef T*  iterator;
	typedef const T*  const_iterator;
	//typedef  iterator reverse_iterator;
	DefineVector()
	{
		ptr_vector=NULL;
		size=0;
		capacity=0;
	}

	DefineVector(int _size,T  value)
	{
		size=_size;
		capacity=_size*_size;
		ptr_vector=new T[capacity];
		int i;
		for(i=0;i<_size;i++)
		{
			ptr_vector[i]=value;
		}
	}
	iterator  begin()
	{
		return ptr_vector;
	}

	iterator  end()
	{
		return ptr_vector+size;
	}
	void resize(int  _capacity)
	{
		if(ptr_vector==NULL)
		{
			ptr_vector=new T[_capacity];
			capacity=_capacity;
			size=0;
		}
		else
		{
			T*  ptr_old=ptr_vector;
			ptr_vector=new T[_capacity];
			capacity=_capacity;
			int i;
			for(i=0;i<size;i++)
			{
				ptr_vector[i]=ptr_old[i];
			}
			delete  ptr_old;
			ptr_old=NULL;
		}
	}
	void  push_back(T  value)
	{
		if(capacity==0)
		{
			resize(N);
		}
		if(size>capacity)
		{			
			resize(capacity*capacity);			
		}
		ptr_vector[size++]=value;
	}
	reverse_iterator  rbegin()
	{
		return  reverse_iterator(ptr_vector+size-1);
	}
	reverse_iterator   rend()
	{
		return  reverse_iterator(ptr_vector-1);
	}
private:
	T  *ptr_vector;
	int size;
	int capacity;
};
int main(int argc, char const *argv[])
{
	//DefineVector<int>  v1(5,10);
	DefineVector<int>  v1;
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(1);
	v1.push_back(10);
	//DefineVector<int> ::iterator it;
	// for(it=v1.begin();it!=v1.end();it++)
	// {
	// 	cout<<*it<<"\t";
	// }
	DefineVector<int>::reverse_iterator it;
	for(it=v1.rbegin();it!=v1.rend();it++)
	{
		cout<<*it<<'\t';
	}
	cout<<endl;
	return 0;
}