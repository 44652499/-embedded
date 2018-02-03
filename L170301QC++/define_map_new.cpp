#include <iostream>
using namespace std;

template<class T1,class T2>
class define_map;

template<class T1,class T2>
class define_stack;

template<class T1,class T2>
class tree_node
{
friend class define_map<T1,T2>;
template<class T11,class T22>
friend void mid_print_tree_by_stack(tree_node<T11,T22>* root);
public:
	tree_node(T1 _key,T2 _value)
	{
		key=_key;
		value=_value;
		ptr_lchild=NULL;
		ptr_rchild=NULL;
	}
//private:
	T1 key;
	T2 value;
	tree_node* ptr_lchild;
	tree_node* ptr_rchild;
};

//定义栈，用来遍历输出树节点
template<class T1,class T2>
class stack_node
{
friend class define_stack<T1,T2>;
public:
	stack_node()
	{
		next=NULL;
	}
	stack_node(tree_node<T1,T2>* _t_node)
	{
		next=NULL;
		t_node=_t_node;
	}
private:
	tree_node<T1,T2> *t_node;
	stack_node* next;	
};

template<class T1,class T2>
class define_stack
{
public:
	define_stack()
	{
		top=NULL;
		size=0;
	}
	define_stack(stack_node<T1,T2>* s_node)
	{
		top=s_node;
		size=1;
	}
	void push_stack(tree_node<T1,T2>* s_node)
	{
		stack_node<T1,T2>* new_node=new stack_node<T1,T2>(s_node);
		new_node->next=top;
		top=new_node;
		size++;
	}
	bool stack_empty()
	{
		if(size==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	tree_node<T1,T2>* get_stack_top()
	{
		if(stack_empty())
		{
			return NULL;
		}
		else
		{
			return top->t_node;
		}
	}
	void pop_stack()
	{
		if(!stack_empty())
		{
			stack_node<T1,T2>* tmp=top;
			top=top->next;
			size--;
		}
		else
		{
			cout<<"this stack empty"<<endl;
		}
	}
private:
	stack_node<T1,T2>* top;
	int size;
};

template<class T1,class T2>
class define_map
{
public:
	class  iterator
	{
	public:
		iterator()
		{
			ptr=NULL;
			st=new define_stack<T1,T2>;
		}
		iterator(tree_node<T1,T2> *  _ptr)
		{
			ptr=_ptr;
			st=new define_stack<T1,T2>;
		}
		iterator  operator =(iterator  it)
		{
			while(it.ptr!=NULL || !st->stack_empty())
			{
				while(it.ptr!=NULL)
				{
					st->push_stack(it.ptr);
					it.ptr=it.ptr->ptr_lchild;
				}
				if(!st->stack_empty())
				{
					it.ptr=st->get_stack_top();
					this->ptr=it.ptr;
					break;
				}
			}
			return *this;			
		}	

		bool  operator !=(const iterator&  it)
		{
        	return  this->ptr!=it.ptr;
		}

        tree_node<T1,T2>  operator *()
        {
        	return *(this->ptr);
        }
		tree_node<T1,T2> *  operator ->()
		{
			return this->ptr;
		}

		iterator  operator ++(int i)
		{	
		    if(!st->stack_empty())
		    {
		    	this->ptr=st->get_stack_top();
		    	st->pop_stack();
				this->ptr=this->ptr->ptr_rchild;
		    }		    

			while(this->ptr!=NULL || !st->stack_empty())
			{
				while(this->ptr!=NULL)
				{
					st->push_stack(this->ptr);
					this->ptr=this->ptr->ptr_lchild;
				}
				if(!st->stack_empty())
				{
					this->ptr=st->get_stack_top();
					break;		
				}
			}
			return  *this;
		}
	private:
		tree_node<T1,T2> *  ptr;
		define_stack<T1,T2> *st;
	};
	define_map()
	{
		root=NULL;
	}
	tree_node<T1,T2>*  get_tree_root()
	{
		return root;
	}
	tree_node<T1,T2>* insert(tree_node<T1,T2>* node)
	{
		if(root==NULL)
		{
			root=node;
			return root;
		}
		if(root->ptr_lchild==NULL && root->key>node->key)
		{
			root->ptr_lchild=node;
			return root;
		}
		if(root->ptr_rchild==NULL && root->key<node->key)
		{
			root->ptr_rchild=node;
			return root;
		}
	    tree_node<T1,T2>* move=root;
	    while(move!=NULL)
	    {
	    	while(move->key<node->key)
	    	{
	    		if(move->ptr_rchild==NULL)
	    		{
	    			move->ptr_rchild=node;
	    			return root;
	    		}
	    		else
	    		{
	    			move=move->ptr_rchild;
	    		}
	    	}
	    	while(move->key>node->key)
	    	{
	    		if(move->ptr_lchild==NULL)
	    		{
	    			move->ptr_lchild=node;
	    			return root;
	    		}
	    		else
	    		{
	    			move=move->ptr_lchild;
	    		}
	    	}
	    }
	}

	iterator  begin()
	{

		return iterator(root);
	}

	iterator  end()
	{
		return  iterator();
	}
private:
	tree_node<T1,T2>* root;
};

template<class T1,class T2>
void mid_print_tree_by_stack(tree_node<T1,T2>* root)
{
	define_stack<T1,T2> *st;
	st=new define_stack<T1,T2>;
	while(root!=NULL || !st->stack_empty())
	{
		while(root!=NULL)
		{
			st->push_stack(root);
			root=root->ptr_lchild;
		}
		if(!st->stack_empty())
		{
			root=st->get_stack_top();
			cout<<root->key<<'\t'<<root->value<<endl;
			st->pop_stack();
			root=root->ptr_rchild;
		}
	}
	delete st;
	st=NULL;
}

int main(int argc, char const *argv[])
{
	define_map<int,string> m1;
	m1.insert(new tree_node<int,string>(1,"s1"));
    m1.insert(new tree_node<int,string>(3,"s3"));
    m1.insert(new tree_node<int,string>(2,"s2"));
    m1.insert(new tree_node<int,string>(6,"s6"));
    m1.insert(new tree_node<int,string>(5,"s5"));
    //mid_print_tree_by_stack(m1.get_tree_root());
    define_map<int,string>::iterator it;
    //it=m1.begin();
    //cout<<it->key<<"\t"<<it->value<<endl;
    //cout<<(*it).key<<"\t"<<(*it).value<<endl;
    for(it=m1.begin();it!=m1.end();it++)
    {
    	cout<<it->key<<"\t"<<it->value<<endl;
    }
    //cout<<it->key<<"\t"<<it->value<<endl;
	return 0;
}
