#include <iostream>
#include <string.h>
//#include <stdio.h>
using namespace std;
template<class T>
class myvector
{
private:
	T *ptr;
	int size;
	int capacity;
public:
	typedef T *iterator;
	myvector()
	{
		ptr=NULL;
		size=0;
		capacity=0;
	}
	myvector(size_t _size,T value)
	{
		capacity=2*_size;
		ptr=new T[capacity];
		size=_size;
		int i;
		for(i=0;i<size;i++)
		{
			ptr[i]=value;
		}
	}
	myvector(const myvector<T> &m)
	{
		this->size=m.size;
		this->ptr=new T[capacity];
		int i=0;
		for(i=0;i<size;i++)
		{
			this->ptr[i]=m.ptr[i];
		}
		//strcpy(this->ptr,m.ptr);
	}
	
	myvector(iterator start,iterator end)
	{
		iterator it;
		size=end-start;
		capacity=2*size;
		this->ptr=new T[capacity];

		int i=0;
		for(it=start;it!=end;it++)
		{
			ptr[i]=*it;
			i++;
		}
		cout<<endl;
	}
	
	iterator begin()
	{
		return ptr;
	}
	iterator end()
	{
		return ptr+size;
	}
/*	void show()
	{
        int i;
		for(i=0;i<size;i++)
		{
			cout<<ptr[i]<<endl;
		}
		cout<<endl;
	}
*/	
	bool operator[](int index)
	{
		if(index>=this->size)
		{
			cout<<"out range"<<endl;
			return -1;
		}
		return this->ptr[index];
	}
	bool operator ==(const myvector<T> &m)//记得加引用
	{
		if(this->capacity!=m.capacity)
		{
			return false;
		}
	//	if(this->size==m.size&&this->capacity==m.capacity)
		else
		{
			int i;
			for(i=0;i<this->size;i++)
			{ 
				if((*this).ptr[i]!=m.ptr[i])
				{
					return false;
				}
			}
			cout<<"=="<<endl;
			return true;
		}
	}
	bool operator !=(const myvector<T> &m)
	{
		return !(*this==m);
	}
	bool operator <(const myvector<T> & m)
	{
		if(this->capacity>m.capacity)
		{
			return false;
		}	
		if(this->capacity<m.capacity)
		{
			cout<<"<<"<<endl;
			return true;
		}		
		if(this->capacity==m.capacity)
		{
			int i;
			for(i=0;i<this->size;i++)
			{
				if(this->ptr[i]>m.ptr[i])
				{
					return true;
				}
				return false;
			}
		}
	}
	bool operator >(const myvector<T> &m)
	{
		return !(*this<m||*this==m);
	}
	void assign(iterator start,iterator end)
	{
		iterator it;
		size=end-start;
		capacity=2*size;
		this->ptr=new T[capacity];

		int i=0;
		for(it=start;it!=end;it++)
		{
			ptr[i]=*it;
			i++;
		}
		cout<<endl;
	}
	void show(myvector<int> v)
	{
		cout<<"begin"<<endl;
	/*myvector<int>::iterator it;
		for(it=v.begin();it!=v.end();it++)
		{
			cout<<*it<<"\t";
		}
		cout<<endl; */    
	}
/*	void assign(size_t _size,T value)//已放弃
	{	
		capacity=2*_size;
		ptr=new T[capacity];
		size=_size;
		int i;
		for(i=0;i<size;i++)
		{
			ptr[i]=value;
		}
	}
	*/

};
//template <class T>
/*
void show(myvector<int> v)
{
	myvector<int>::iterator it;
	for(it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<"\t";
	}
	cout<<endl;     
}

*/
int main()
{
	myvector<int> v1(5,8);
	int a[]={5,6,7,8,9};
	myvector<int> v2(a,a+3);
	myvector<int> v3(4,8);
	myvector<int> v5;
//myvector<int> v6;
	
	myvector<int> v4(5,8);
	int b=(v1==v4);
	int c=(v2<v3); // 为什么两个不能一起？？
	v1.show(v1);
	//cout<<b<<endl;
	//cout<<c<<endl;

//	v5.assign(v2.begin(),v2.end());//和比较一起运行会放弃
//	v6.assign(3,7);
	
	//v1.show(v1);
	//v2.show(v2);
//	v5.show();
//	v6.show();

//	show(v1);
//	show(v2);
}