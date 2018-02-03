#include <iostream>
using namespace std;
template<class T>
class binarytree;

template<class T>
class  binarytreenode
{
friend class binarytree<T>;
public:
	binarytreenode(T  _data)
	{
		data=_data;
		lchild=NULL;
		rchild=NULL;
	}
private:
	T data;
	binarytreenode<T>*  lchild;
	binarytreenode<T>*  rchild;
};

template<class T>
class binarytree
{
public:
	binarytree()
	{
		root=NULL;
	}
	binarytreenode<T>*  buildbinarytree()
	{
		int nodevalue=0;
		binarytreenode<T>* root=NULL;
		cin>>nodevalue;
		if(nodevalue==-1)
		{
			return NULL;
		}
		else
		{
			root=new binarytreenode<T>(nodevalue);
			root->lchild=buildbinarytree();
			root->rchild=buildbinarytree();
			return root;
		}
	}

	binarytreenode<T>*  getbinarytreeroot()
	{
		return root;
	}

	void  preorder(binarytreenode<T>* _root)
	{
		if(_root!=NULL)
		{
			cout<<_root->data<<"\t";
			preorder(_root->lchild);
			preorder(_root->rchild);
		}
	}

	void  postorder(binarytreenode<T>* _root)
	{
		if(_root!=NULL)
		{
			preorder(_root->lchild);
			cout<<_root->data<<"\t";
			preorder(_root->rchild);
		}
	}

	void  lastorder(binarytreenode<T>* _root)
	{
		if(_root!=NULL)
		{			
			preorder(_root->lchild);
			preorder(_root->rchild);
			cout<<_root->data<<"\t";
		}
	}
private:
	binarytreenode<T>* root;
};
int main(int argc, char const *argv[])
{	
	binarytree<int>  tree;	
	binarytreenode<int>* root=tree.buildbinarytree();
	tree.preorder(root);
	tree.postorder(root);
	tree.lastorder(root);
	return 0;
}