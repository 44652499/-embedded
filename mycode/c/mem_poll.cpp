#include <iostream>
using namespace std;
#define  BLOCK_SIZE 1024
template<class T>
class stack;

//定义节点
template<class T>
class  node
{
friend class stack<T>;
private:
	T  data[BLOCK_SIZE];
	int curr_pos;
	T*  curr_ptr;
	node* next;
public:
	node(node* _next=NULL):next(_next)
	{
       bzero(data,sizeof(data));
       curr_pos=0;
       curr_ptr=&data[curr_pos];
	}
};

//定义链表
template<class T>
class link_list
{
private:
	node<T>* head;
	node<T>* curr;
	int node_size;
public:
	link_list()
	{
		head=NULL;
		curr=NULL;
		size=0;
	}
	void insert_link_list()
	{
		node<T>* new_node=new node<T>; 
		if(head==NULL&& curr==NULL)
		{
			head=new_node;
			curr=new_node;
		}
		else
		{
			curr->next=new_node;
			curr=new_node;
		}
		size++;
	}

	void pop()
	{
		if(isstackempty())
		{
			cout<<"stack is empty"<<endl;
		}
		else
		{
			node<T>* tmp=top;
			top=top->next;
			size--;
			cout<<tmp->data<<endl;
			delete tmp;
			tmp=NULL;
        }
	}
	node<T>*  getstacktop()
	{
       if(!isstackempty())
       {
       	  return top;
       }
       return NULL;
	}

	int getstacksize()
	{
      return size;
	}

	bool isstackempty()
	{
		if(size==0)
			return true;
		return false;
	}
};