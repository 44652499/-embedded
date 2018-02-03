#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
template<class T>
class Heap
{
public:
	void addTreeSort(T * arr,int size)
	{
		assert(arr);
		int i;
		for(i=0;i<size;i++)
		{
			heap.push_back(arr[i]);
		}
		int root=(size-1)/2;
		while(root--)
		{
			addTreeDown(root);
		}
	}

	void  insert(T data)
	{
		heap.push_back(data);
		int root=(heap.size()-1)/2;
		int temp=heap.size()-1;
		while(temp>root)
		{
			if(heap[temp]<heap[root])
			{
				swap(heap[heap.size()-1],heap[root]);
				temp=root;
				root=(root-1)/2;
			}
			else
			{
				return;
			}
		}
	}

	void erase()
	{
		swap(heap[0],heap[heap.size()-1]);
		heap.pop_back();
		addTreeDown(0);
	}

	void  print()
	{
		int i=0;
		for(i=0;i<heap.size();i++)
		{
			cout<<heap[i]<<"->";
		}
		cout<<endl;
	}
	void  addTreeDown(int root)
	{
		int left=root*2+1;
		int right=left+1;
		int min=left;
		while(left<heap.size())
		{
			if(heap[left]>heap[right])
			{
				min=right;
			}
			if(heap[root]>heap[min])
			{
				swap(heap[root],heap[min]);
				root=min;
				left=root*2+1;
				right=left+1;
				min=left;
			}
			else
			{
				break;
			}
		}
	}
	void  swap(T & a,T &b)
	{
		int temp=a;
		a=b;
		b=temp;
	}

private:
	vector<T> heap;
};
void fun()
{
	int arr[]={1,5,6,3,4,7,9,8,0};
	Heap<int> h;
	h.addTreeSort(arr,9);
	//h.insert(2);
	h.print();
	//h.erase();
	//h.print();
}
int main(int argc, char const *argv[])
{
	fun();
	return 0;
}