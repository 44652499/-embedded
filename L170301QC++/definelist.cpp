#include <iostream>
using namespace  std;

template<class T>
class DefineList;

template<class T>
class  ListNode 
{
friend  class  DefineList<T>;
friend  class  iterator;
public:
	ListNode(T  _value)
	{
		value=_value;
		ptr_pre=NULL;
		ptr_next=NULL;
	}
private:
	T value;
	ListNode<T>*  ptr_pre;
	ListNode<T>*  ptr_next;
};
template<class T>
class DefineList
{
public:
	typedef  bool  (*UnPred)(T value);
	//定义迭代器类
	class  iterator
	{
	public:
		iterator()
		{
			ptr_list_node=NULL;
		}
		iterator(ListNode<T>*  _ptr_list_node)
		{
			ptr_list_node=_ptr_list_node;
		}

		iterator& operator =(const iterator& obj_it )
		{
			this->ptr_list_node=obj_it.ptr_list_node;
			return *this;
		}
		bool  operator !=(const iterator& obj_it)
		{
			return this->ptr_list_node!=obj_it.ptr_list_node;
		}
		iterator  operator ++(int i)
		{
			iterator  obj_tmp=*this;
			this->ptr_list_node=this->ptr_list_node->ptr_next;
			return *this;
		}

		T operator  *()
		{
			return  this->ptr_list_node->value;
		}

	private:
		ListNode<T>*  ptr_list_node;
	};
	DefineList()
	{
		ptr_head=NULL;
		ptr_move=NULL;
		size=0;
	}
	DefineList(int _size,T value)
	{
		int i;
		ptr_head=NULL;
		ptr_move=NULL;
		size=_size;
		ListNode<T> *  ptr_new_node=NULL;
		for(i=0;i<size;i++)
		{
			ptr_new_node=new ListNode<T>(value);
			if(ptr_head==NULL)
			{
				ptr_head=ptr_new_node;				
			}
			else
			{
				ptr_move->ptr_next=ptr_new_node;
				ptr_new_node->ptr_pre=ptr_move;
			}
			ptr_move=ptr_new_node;
			ptr_new_node=NULL;
		}
	}

	iterator begin()
	{
		return  iterator(ptr_head);
	}
	iterator end()
	{
		if(ptr_move!=NULL)
		{
			return iterator(ptr_move->ptr_next);
		}
		return iterator(ptr_move);		
	}
	void remove(T  value)
	{
		ListNode<T> *  ptr_tmp=ptr_head;
		while(ptr_tmp!=NULL)
		{
			if(ptr_tmp->value==value)
			{
				if(ptr_tmp->ptr_pre==NULL)
				{
					ptr_head=ptr_head->ptr_next;
					if(ptr_head!=NULL)
					{
						ptr_head->ptr_pre=NULL;
						delete  ptr_tmp;
						ptr_tmp=ptr_head;
					}
					else
					{
						ptr_head=NULL;
						ptr_move=NULL;
						delete  ptr_tmp;
						ptr_tmp=NULL;
					}					
				}
				else
				{
					ptr_tmp->ptr_pre->ptr_next=ptr_tmp->ptr_next;
					if(ptr_tmp->ptr_next!=NULL)
					{
						ptr_tmp->ptr_next->ptr_pre=ptr_tmp->ptr_pre;
						delete ptr_tmp;			
						ptr_tmp=ptr_tmp->ptr_next;	
					}
					else
					{
						ptr_move=ptr_tmp->ptr_pre;
						delete ptr_tmp;
						ptr_tmp=NULL;
					}									
				}
			}
			else
			{
				ptr_tmp=ptr_tmp->ptr_next;
			}
		}
	}

	void remove_if(UnPred pr)
	{
		ListNode<T> *  ptr_tmp=ptr_head;
		while(ptr_tmp!=NULL)
		{
			if(pr(ptr_tmp->value))
			{
				if(ptr_tmp->ptr_pre==NULL)
				{
					ptr_head=ptr_head->ptr_next;
					if(ptr_head!=NULL)
					{
						ptr_head->ptr_pre=NULL;
						delete  ptr_tmp;
						ptr_tmp=ptr_head;
					}
					else
					{
						ptr_head=NULL;
						ptr_move=NULL;
						delete  ptr_tmp;
						ptr_tmp=NULL;
					}					
				}
				else
				{
					ptr_tmp->ptr_pre->ptr_next=ptr_tmp->ptr_next;
					if(ptr_tmp->ptr_next!=NULL)
					{
						ptr_tmp->ptr_next->ptr_pre=ptr_tmp->ptr_pre;
						delete ptr_tmp;			
						ptr_tmp=ptr_tmp->ptr_next;	
					}
					else
					{
						ptr_move=ptr_tmp->ptr_pre;
						delete ptr_tmp;
						ptr_tmp=NULL;
					}									
				}
			}
			else
			{
				ptr_tmp=ptr_tmp->ptr_next;
			}
		}
	}
private:
	ListNode<T>*  ptr_head;
	ListNode<T>*  ptr_move;
	int size;
};

template<class T>
bool  remove_fun(T  value)
{
	return (value==8);
}

int main(int argc, char const *argv[])
{
	DefineList<int>  list(5,8);
	DefineList<int>::iterator it;
	//list.remove(8);
	list.remove_if(remove_fun<int>);
	for(it=list.begin();it!=list.end();it++)
	{
		cout<<*it<<"\t";
	}
	cout<<endl;
	return 0;
}
