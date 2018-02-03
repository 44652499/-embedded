#include <iostream>
using namespace std;

template<class T1,class T2>
class DefineMap;

template <class T1,class T2>
class  Stack;

template<class T1,class T2>
class Pair
{
public:
    Pair(T1 _first,T2 _second)
    {
        first=_first;
        second=_second;
    }
    T1  first;
    T2  second;
};

template<class T1,class T2>
class  TreeNode
{
friend  class DefineMap<T1,T2>;
public:
    TreeNode(T1 _key,T2 _value)
    {
        key=_key;
        value=_value;
        ptr_lchild=NULL;
        ptr_rchild=NULL;
    }
    T1  key;
    T2  value;
    TreeNode* ptr_lchild;
    TreeNode* ptr_rchild;
};

template<class T1,class T2>
class StackNode
{
friend class Stack<T1,T2>;
public:
    StackNode(TreeNode<T1,T2>*  _ptr_tree_node)
    {
        ptr_tree_root=_ptr_tree_node;
        ptr_next=NULL;
    }
private:
    TreeNode<T1,T2>* ptr_tree_root;
    StackNode<T1,T2>* ptr_next;
};

template<class T1,class T2>
class Stack
{
public:
    Stack()
    {
        ptr_top=NULL;
    }
    void push(TreeNode<T1,T2>*  ptr_tree_node)
    {
        StackNode<T1,T2>  *  ptr_stack_node=new StackNode<T1,T2>(ptr_tree_node);
        ptr_stack_node->ptr_next=ptr_top;
        ptr_top=ptr_stack_node;
        ptr_stack_node=NULL;
    }

    bool  is_empty()
    {
        return  ptr_top==NULL;
    }

    void pop()
    {
        if(!is_empty())
        {
            StackNode<T1,T2>*  ptr_st=ptr_top;
            ptr_top=ptr_top->ptr_next;
            delete   ptr_st;
            ptr_st=NULL;
        }       
    }

    TreeNode<T1,T2>*  get_stack_top()
    {
        return  ptr_top->ptr_tree_root;
    }
private:
    StackNode<T1,T2>* ptr_top;
};



template<class T1,class T2>
class DefineMap
{
public:
    class iterator
    {
    public:
        iterator()
        {
            ptr_stack=new Stack<T1,T2>;
            ptr_it_root=NULL;
        }
        iterator(TreeNode<T1,T2>*  ptr_tree_node)
        {
            ptr_stack=new Stack<T1,T2>;
            ptr_it_root=ptr_tree_node;
        }

        iterator  operator=(const iterator & it)
        {
            this->ptr_it_root=it.ptr_it_root;
        }

        bool  operator!=(const iterator  & it)
        {
            return  this->ptr_it_root!=it.ptr_it_root;
        }
        iterator  operator ++(int i)
        {
            TreeNode<T1,T2>* ptr_move=ptr_it_root;
            ptr_it_root=ptr_it_root->ptr_rchild;
            while(ptr_it_root!=NULL ||  !ptr_stack->is_empty())
            {
                while(ptr_it_root!=NULL)
                {
                    ptr_stack->push(ptr_it_root);
                    ptr_it_root=ptr_it_root->ptr_lchild;
                }
                if(!ptr_stack->is_empty())
                {
                    ptr_it_root=ptr_stack->get_stack_top();
                    ptr_stack->pop();
                    return  iterator(ptr_move);                
                }                
            }
            return iterator(NULL);
        }
        TreeNode<T1,T2>*  operator ->()
        {
            return this->ptr_it_root;
        }       

    private:
        TreeNode<T1,T2>* ptr_it_root;
        Stack<T1,T2>* ptr_stack;    
    };
    DefineMap()
    {
        ptr_root=NULL;
    }

    TreeNode<T1,T2>* insert(Pair<T1,T2>  value)
    {
        TreeNode<T1,T2> *  ptr_new_node=new TreeNode<T1,T2>(value.first,value.second);
        if(ptr_root==NULL)
        {
            ptr_root=ptr_new_node;
            ptr_new_node=NULL;
            return ptr_root;
        }
        if(ptr_root->ptr_lchild==NULL && value.first<ptr_root->key)
        {
            ptr_root->ptr_lchild=ptr_new_node;
            ptr_new_node=NULL;
            return  ptr_root;
        }
        if(ptr_root->ptr_rchild==NULL && value.first>ptr_root->key)
        {   
            ptr_root->ptr_rchild=ptr_new_node;
            ptr_new_node=NULL;
            return  ptr_root;
        }
        TreeNode<T1,T2>*  ptr_move=ptr_root;
        while(1)
        {           
            while(ptr_move->key>value.first)
            {               
                if(ptr_move->ptr_lchild==NULL)
                {
                    ptr_move->ptr_lchild=ptr_new_node;
                    ptr_new_node=NULL;
                    return  ptr_root;
                }
                ptr_move=ptr_move->ptr_lchild;
            }    

            while(ptr_move->key<value.first)
            {
                if(ptr_move->ptr_rchild==NULL)
                {
                    ptr_move->ptr_rchild=ptr_new_node;
                    ptr_new_node=NULL;
                    return  ptr_root;
                }
                ptr_move=ptr_move->ptr_rchild;
            }        
        } 
        return  ptr_root;
    }

    iterator begin()
    {    
        while(ptr_root->ptr_lchild!=NULL)
        {
            ptr_root=ptr_root->ptr_lchild;
        }      
        iterator  it(ptr_root);
        return it; 
    }
    iterator end()
    {
        return  iterator(NULL);
    }
private:
    TreeNode<T1,T2> *  ptr_root; 
    TreeNode<T1,T2> *  ptr_sta
};

int main(int argc,const char* argv[])
{
    DefineMap<int,string> m1;
    m1.insert(Pair<int,string>(6,"sdfsdf"));
    m1.insert(Pair<int,string>(4,"sdfsdf"));
    m1.insert(Pair<int,string>(5,"sdfsdf"));
    m1.insert(Pair<int,string>(10,"sdfsdf"));
    m1.insert(Pair<int,string>(8,"sdfsdf"));
    m1.insert(Pair<int,string>(9,"sdfsdf"));
    DefineMap<int,string>::iterator it;
    for(it=m1.begin();it!=m1.end();it++)
    {
        cout<<it->key<<"\t"<<it->value<<endl;
    }
    return 0;
}