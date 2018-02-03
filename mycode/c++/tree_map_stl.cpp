#include <iostream>
using namespace std;

template<class T1,class T2>
class pair
{
public:
    pair(T1 _first,T2 _second)
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
public:
    TreeNode(T1 _key,T2 _value)
    {
        key=_key;
        value=_value;
        ptr_lchild=NULL;
        ptr_rchild=NULL;
    }
private:
    T1  key;
    T2  value;
    TreeNode* ptr_lchild;
    TreeNode* ptr_rchild;
};



template<class T1,class T2>
class DefineMap
{
public:
    DefineMap()
    {
        ptr_root=NULL;
    }
    TreeNode<T1,T2>* insert(pair<T1,T2>  value)
    {
        TreeNode *  ptr_new_node=new TreeNode(value.first,value.second);
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
        //while(ptr_move!=NULL)
        if(ptr_move!=NULL)
        {

        }

    }
private:
    TreeNode<T1,T2> *  ptr_root; 
};