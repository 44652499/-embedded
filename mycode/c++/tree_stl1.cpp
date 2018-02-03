#include <iostream>
using namespace std;

class BinTreeNode
{
private:
	char data;
	BinTreeNode *left,*right;
public:
	BinTreeNode(const int &item,BinTreeNode *lPtr=NULL,BinTreeNode *rPtr=NULL):data(item),left(lPtr),right(rPtr){};
	void set_data(int item)
	{
		data=item;
	}
	int get_data() const
	{
		return data;
	}
	void set_left(BinTreeNode* l)
	{
		left=l;
	}
	BinTreeNode* get_left() const
	{
		return left;
	}
	void set_right(BinTreeNode* r)
	{
		right=r;
	}
	BinTreeNode* get_right() const
	{
		return right;
	}
};

class BinTree
{
private:
	BinTreeNode* root;
public:
	BinTree(BinTreeNode* t=NULL):root(t){};
	~BinTree(){if(root!=NULL){delete root;root=NULL;}};
	void set_root(BinTreeNode* t)
	{
		root=t;
	}
	BinTreeNode* get_root() const
	{
		return root;
	}
	BinTreeNode* create_tree();
	void  print_pre_tree();

	void print_rout(BinTreeNode* r,int sum) const;
};

BinTreeNode* BinTree::create_tree()
{
	char item;
	BinTreeNode* t,*t_l,*t_r;
	cin>>item;
	getchar();
	if(item!='0')
	{
		BinTreeNode* pTmpNode=new BinTreeNode(item-48);
		t=pTmpNode;
		t_l=create_tree();
		t->set_left(t_l);
		t_r=create_tree();
		t->set_right(t_r);
		return t;
	}
	else
	{
		t=NULL;
		return t;
	}
}
void  BinTree::print_pre_tree()
{
	if(root!=NULL)
	{
		// root=root->get_left();
		// cout<<root->get_data();
		// root=root->get_right();
		cout<<root->get_data()<<endl;
	}
}

//stack<BinTreeNode*>dfs_s;
class stack_node
{
	friend class dfs_s1;
	friend class print_s1;
public:
	stack_node():next(NULL)
	{

	}
private:
	stack_node* next;
	BinTreeNode* ptr_node;
};

class dfs_s1
{
	friend class BinTree;
public:
	dfs_s1()
	{
		top=NULL;
		size=0;
	}
	void push(BinTreeNode* r)
	{
		stack_node* new_node=new stack_node;
		new_node->ptr_node=r;
		new_node->next=top;
		top=new_node;
		size++;
	}

	bool empty()
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

	void pop()
	{
		if(!empty())
		{
			stack_node* tmp=top;
			top=top->next;
			size--;
			delete tmp;
			tmp=NULL;
		}
		else
		{
			cout<<"stack is empty"<<endl;
		}
	}

	BinTreeNode* get_top()
	{
		if(!empty())
		{
			return top->ptr_node;
		}
		else
		{
			return NULL;
		}
	}
private:
	stack_node* top;
	int size;
};
//stack<BinTreeNode*>print_s;
class print_s1
{
	friend class BinTree;
public:
	print_s1()
	{
		top=NULL;
		size=0;
	}
	void push(BinTreeNode* r)
	{
		stack_node* new_node=new stack_node;
		new_node->ptr_node=r;
		new_node->next=top;
		top=new_node;
		size++;
	}

	bool empty()
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

	void pop()
	{
		if(!empty())
		{
			stack_node* tmp=top;
			top=top->next;
			size--;
			delete tmp;
			tmp=NULL;
		}
		else
		{
			cout<<"stack is empty"<<endl;
		}
	}

	BinTreeNode* get_top()
	{
		if(!empty())
		{
			return top->ptr_node;
		}
		else
		{
			return NULL;
		}
	}
private:
	stack_node* top;
	int size;
};
//打印出从r开始的和为sum的所有路径
void BinTree::print_rout(BinTreeNode* r,int sum) const
{
	dfs_s1 dfs_s;
	print_s1 print_s;
	if(r==NULL)
	{
		return;
	}
	sum-=r->get_data();
	dfs_s.push(r);
	if(sum<=0 && r->get_left()==NULL && r->get_right()==NULL)
	{
		if(sum==0 && r->get_left()==NULL && r->get_right()==NULL)
		{
			while(!dfs_s.empty())
			{
				print_s.push(dfs_s.get_top());
				//cout<<dfs_s.get_top()->get_data()<<" ";
				dfs_s.pop();
			}
			while(!print_s.empty())
			{
				cout<<print_s.get_top()->get_data()<<" ";
				dfs_s.push(print_s.get_top());
				print_s.pop();
			}
			cout<<endl;
		}
		sum+=r->get_data();
	    dfs_s.pop();
	    return;
	}
    //递归进入左子树
	print_rout(r->get_left(),sum);
    //递归进入右子树
	print_rout(r->get_right(),sum);
    //出栈
	sum+=r->get_data();
	dfs_s.pop();
}

int main(int argc, char const *argv[])
{
	BinTree tree;
	cout<<"请输入二叉树："<<endl;
	tree.set_root(tree.create_tree());
	cout<<endl;

	tree.print_pre_tree();
	cout<<endl;
	
	cout<<"路径如下："<<endl;
	//tree.print_rout(tree.get_root(),15);
	return 0;
}

