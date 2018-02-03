#include  <iostream>
using namespace std;
/*
链表类模板
*/
//前置申明模板类
template <class T>
class  List;
//定义节点模板类
template <class T>
class Node
{
//申明友元类模板(必须要前置声明)
friend class  List<T>;
public:
	Node(T  _value)
	{
		value=_value;
		next=NULL;
	}
private:
	T value;
	Node*  next;
};

//定义链表类
template<class T>
class List
{
public:
	List()
	{
		ptr_head=NULL;
		ptr_tail=NULL;
	}
	void  insertnodelist(T _value)
	{
		int i;
		Node<T> *  ptr_new=new Node<T>(_value);
		if(ptr_head==NULL)
		{
			ptr_head=ptr_new;
		}
		else
		{
			ptr_tail->next=ptr_new;
		}
		ptr_tail=ptr_new;
	}

	void  printlist()
	{
		Node<T> * ptr_query=ptr_head;
		while(ptr_query!=NULL)
		{
			cout<<ptr_query->value<<"\t";
			ptr_query=ptr_query->next;
		}
		cout<<endl;
	}
private:
	Node<T>*  ptr_head;
	Node<T>*  ptr_tail;
};

int main(int argc, char const *argv[])
{
	List<int> l1;
	int i;
	for(i=0;i<5;i++)
	{
		l1.insertnodelist(i+1);
	}
	l1.printlist();
	return 0;
}