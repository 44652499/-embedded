#ifndef _STACK_
#define _STACK_

#include "iostream"
using namespace std;

template <class T>
class stack;

template <class T>
class stack_node
{
	friend class stack<T>;
private:
	T data;
	stack_node* next;
public:
	stack_node()
	{
		next=NULL;
	}
};

template <class T>
class stack
{
private:
	stack_node<T>* top;
	int size;
public:
	stack()
	{
		top=NULL;
		size=0;
	}
	void push(T _data)
	{
		stack_node<T>* new_node=new stack_node<T>;
		new_node->data=_data;
		new_node->next=top;
		top=new_node;
		size++;
	}
	bool empty()
	{
		if(0==size)
		{
			return true;
		}
		return false;
	}
	stack_node<T> pop()
	{
		if(!empty())
		{
			stack_node<T>* tmp=top;
			top=top->next;
			size--;
			return tmp;		
		}
		else
		{
			cout<<"This stack is empty."<<endl;
		}
	}

};
#endif

