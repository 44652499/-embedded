#include  <iostream>
using namespace std;
template<class T1,class T2>
class  tree_node
{
public:
	tree_node(T1  _key,T2  _value)
	{
		key=_key;
		value=_value;
		lchild=NULL;
		rchild=NULL;
	}
private:
	T1  key;
	T2  value;
	tree_node *  lchild;
	tree_node *  rchild;
};
template<class T1,class T2>
class  tree
{
public:
	tree()
	{
		root=NULL;
		move=NULL;
	}
	insert(tree_node<T1,T2> * node)
	{
		if(root==NULL)
		{
			root=node;
			move=node;
		}	
		else
		{

		}
	}
private:
	tree_node<T1,T2> *  root;
	tree_node<T1,T2> *  move;
};
int main(int argc, char const *argv[])
{
	
	return 0;
}