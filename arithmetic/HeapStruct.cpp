#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
template <class T>
struct Less
{
	bool operator ()(const T& l,const T & r)
	{
		return l<r;
	}
};

template<class T>
struct Greater
{
	bool operator ()(const T & l,const T& r)
	{
		return l>r;
	}
};

template<class T,template<class> class Continer=Greater>
class Heap
{
public:
	Heap();
	Heap(const T * a,size_t size,Continer<T> con);
	Heap(const T & x);
	void Push(const T & x);
	void Pop();
	T &  GetTop();
	bool Empty();
	size_t Size();
	void HeapSort(T * a,size_t size);
	void AddJustDown(size_t parent);
	void AddJustUp(size_t child);
private:
	vector<T> _a;
	Continer<T> _con;
};