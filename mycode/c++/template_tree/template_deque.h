#ifndef _DEQUE_
#define _DEQUE_

#include "iostream"
using namespace std;
template <class T>
class deque_node
{
private:
	T data;
	deque_node *next;
public:
	deque_node()
	{
		next=NULL;
	}
};

template <class T>
class deque
{
private:
	deque_node<T> *head;
	deque_node<T> *tail;
	int size;
public:
	deque()
	{
		head=NULL;
		tail=NULL;
		size=0;
	}
	bool empty()
	{
		if(0==size)
			return true;
		else
			return false;
	}
	deque_node<T> front()
	{
		return head;
	}
	deque_node<T> rear()
	{
		return tail;
	}
	void push_back(T _data)
	{
		deque_node<T> *new_node=new deque_node<T>;
		new_node->data=_data;
		size++;
		if(NULL==head && NULL==tail)
		{
			head=new_node;
			tail=new_node;
		}
		else
		{
			tail->next=new_node;
			tail=new_node;
		}
	}
	deque_node<T> pop_front()
	{
		deque_node<T> *tmp=front;
		front=front->next;
		size--;
		return tmp;
	}
};
#endif

