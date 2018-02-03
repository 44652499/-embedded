#include  <iostream>
using namespace std;
template<class T>
class BinaryTree;

template<class T>
class Stack;

//定义节点类
template<class T>
class  BinaryTreeNode
{
friend  class BinaryTree<T>;
public:
	BinaryTreeNode(T _nodevalue)
	{
		nodevalue=_nodevalue;
		lchild=NULL;
		rchild=NULL;
	}
private:
	T  nodevalue;
	BinaryTreeNode<T>* lchild;
	BinaryTreeNode<T>* rchild;
};
//定义链表栈节点
template<class T>
class  StackNode
{
friend  class  Stack<T>;
public:
	StackNode(BinaryTreeNode<T>* _ptr_treenode)
	{
		ptr_treenode=_ptr_treenode;
		ptr_next=NULL;
	}
private:
	BinaryTreeNode<T>* ptr_treenode;
	StackNode<T> *  ptr_next;
};
//定义链表栈
template<class T>
class Stack
{
public:
	Stack()
	{
		ptr_top=NULL;
	}
	bool isstatckempty()
	{
		return  ptr_top==NULL;
	}
	void  push(BinaryTreeNode<T>* ptr_treenode)
	{
		StackNode<T> *  ptr_stacknode=new StackNode<T>(ptr_treenode);
		ptr_stacknode->ptr_next=ptr_top;
		ptr_top=ptr_stacknode;
		ptr_stacknode=NULL;
	}

	void  pop()
	{
		if(!isstatckempty())
		{
			StackNode<T> *  ptr_stacknode=ptr_top;
			ptr_top=ptr_top->ptr_next;
			delete ptr_stacknode;
			ptr_stacknode=NULL;
		}
	}

	BinaryTreeNode<T> *  getstatcktop()
	{
		if(!isstatckempty())
		{
			return  ptr_top->ptr_treenode;
		}
		return NULL;
	}
private:
	StackNode<T>*  ptr_top;
};
//定义二叉树类
template<class T>
class  BinaryTree
{
public:
	BinaryTree()
	{
		ptr_treeroot=NULL;
		treenodecnt=0;
	}
	//构建二叉树
	BinaryTreeNode<T>*  buildbinarytree()
	{
		//输入节点值,构成二叉树
		T  treenodevalue;
		cin >>treenodevalue;
		if(treenodevalue==0)
		{
			return NULL;
		}
		else
		{
			//ptr_treeroot=new  BinaryTreeNode<T>(treenodevalue);//递归函数中不要使用类数据成员作为递归变量
			BinaryTreeNode<T>* ptr_root=new  BinaryTreeNode<T>(treenodevalue);
			treenodecnt++;
			ptr_root->lchild=buildbinarytree();
			ptr_root->rchild=buildbinarytree();
			return ptr_root;
		}
	}

	//递归前序输出
	void  preorder(BinaryTreeNode<T>* ptr_node)
	{
		if(ptr_node!=NULL)
		{
			cout<<ptr_node->nodevalue<<"\t";
			preorder(ptr_node->lchild);
			preorder(ptr_node->rchild);
		}
	}

	//递归中序输出
	void  midorder(BinaryTreeNode<T>* ptr_node)
	{
		if(ptr_node!=NULL)
		{
			midorder(ptr_node->lchild);
			cout<<ptr_node->nodevalue<<"\t";
			midorder(ptr_node->rchild);
		}
	}

	//递归后序输出
	void  lastorder(BinaryTreeNode<T>* ptr_node)
	{
		if(ptr_node!=NULL)
		{
			lastorder(ptr_node->lchild);
			lastorder(ptr_node->rchild);
			cout<<ptr_node->nodevalue<<"\t";
		}
	}

	//非递归前序输出
	void  notrepreorder()
	{
		Stack<T> s_obj;
		BinaryTreeNode<T> *   ptr_root=ptr_treeroot;
		while(!s_obj.isstatckempty() || ptr_root!=NULL)
		{
            while(ptr_root!=NULL)
            {
            	cout<<ptr_root->nodevalue<<"\t";
            	s_obj.push(ptr_root);
				ptr_root=ptr_root->lchild;
            }
            if(!s_obj.isstatckempty())
            {
            	ptr_root=s_obj.getstatcktop();
            	s_obj.pop();
            	ptr_root=ptr_root->rchild;
            }
        }
	}
	//设置a指向数根指t针值
	void  settreeeroot(BinaryTreeNode<T>*  ptr_root)
	{
		ptr_treeroot=ptr_root;
	}
	//获取树根值
	BinaryTreeNode<T>* gettreeroot()
	{
		return  ptr_treeroot;
	}
	//获取数的几点数
	int   getnodecnt()
	{
		return treenodecnt;
	}	
private:
	BinaryTreeNode<T> *  ptr_treeroot;
	int  treenodecnt;
};

int main(int argc, char const *argv[])
{
	BinaryTree<int>  tree;
	BinaryTreeNode<int> *ptr_root=tree.buildbinarytree();
	tree.settreeeroot(ptr_root);
	tree.preorder(ptr_root);
	cout<<endl;
	tree.midorder(ptr_root);
	cout<<endl;
	tree.lastorder(ptr_root);
	cout<<endl;
	tree.notrepreorder();
	cout<<endl;
	return 0;
}