// 2.以上出现的队列与栈都必须自定义实现,不准用系统函数
// 3.树操作代码增加如下函数:
//    a.非递归实现:前序 中序 后序遍历
#include <iostream>
using namespace std;
class BinTreeNode
{
private:
	char data;
	BinTreeNode *left,*right;
	friend class stack_node1;
	friend class stack1;
	friend class BinTree;
public:
	BinTreeNode(const char &item,BinTreeNode* lPtr=NULL,BinTreeNode* rPtr=NULL):data(item),left(lPtr),right(rPtr){};
	void set_data(char item)
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
	BinTreeNode * root;
	//friend class stack1;
	friend class stack2;
public:
	BinTree(BinTreeNode* t=NULL):root(t){};
	~BinTree(){delete root;};
	void set_root(BinTreeNode* t)
	{
		root=t;
	}
	BinTreeNode* get_root() const
	{
		return root;
	}
	BinTreeNode* create_tree();

	void pre_order_by_stack1(BinTreeNode* r) const;

	void in_order_by_stack1(BinTreeNode* r) const;

	void post_order_by_stack2(BinTreeNode* r) const;
};

BinTreeNode* BinTree::create_tree()
{
	char item;
	BinTreeNode *t,*t_l,*t_r;
	cin>>item;
	if(item!='#')
	{
		//BinTreeNode* pTmpNode=new BinTreeNode(item-48);
		BinTreeNode* pTmpNode=new BinTreeNode(item);
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

//-------------------------------------------//
//stack1的实现
// class stack_node1
// {
// private:
// 	BinTreeNode* ptr_node;
// 	stack_node1* next;
// 	friend class stack1;
// public:
//     stack_node1(stack_node1* _next=NULL):next(_next)
//     {

//     }
// };

// class stack1
// {
// private:
// 	stack_node1* top;
// 	int size;
// 	friend class BinTree;
// public:
// 	stack1()
// 	{
// 		top=NULL;
// 		size=0;
// 	}
// 	void push_stack1(BinTreeNode* tree_node)
// 	{
// 		stack_node1* new_node=new stack_node1;
// 		new_node->ptr_node=tree_node;
// 		new_node->next=top;
// 		top=new_node;
// 		size++;
// 	}

// 	bool isstackempty()
// 	{
// 		if(size==0)
// 			return true;
// 		return false;
// 	}

// 	void pop_stack1()
// 	{
// 		if(isstackempty())
// 		{
// 			cout<<"stack is empty"<<endl;
// 		}
// 		else
// 		{
// 			stack_node1* tmp=top;
// 			top=top->next;
// 			size;
// 			delete tmp;
// 			tmp=NULL;
// 		}
// 	}

// 	BinTreeNode* getstacktop()
// 	{
// 		if(!isstackempty())
// 		{
// 			return top->ptr_node;
// 		}
// 		return NULL;
// 	}

// 	int getstacksize()
// 	{
// 		return size;
// 	}
// };

// void BinTree::pre_order_by_stack1(BinTreeNode* root) const
// {
// 	stack1 *st1;
// 	st1=new stack1;
// 	while(root!=NULL || !st1->isstackempty())
// 	{
// 		while(root!=NULL)
// 		{
// 			//printf("%c\t",root->data);
// 			cout<<root->data<<endl;
// 			st1->push_stack1(root);
// 			root=root->left;
// 		}
// 		if(!st1->isstackempty())
// 		{
// 			root=st1->getstacktop();
// 			st1->pop_stack1();
// 			root=root->right;
// 		}
// 	}
// 	delete st1;
// 	st1=NULL;
// }

// void BinTree::in_order_by_stack1(BinTreeNode* root) const
// {
// 	stack1 *st1;
// 	st1=new stack1;
// 	while(root!=NULL || !st1->isstackempty())
// 	{
// 		while(root!=NULL)
// 		{
// 			st1->push_stack1(root);
// 			root=root->left;
// 		}
// 		if(!st1->isstackempty())
// 		{
// 			root=st1->getstacktop();
// 			cout<<root->data<<endl;
// 			st1->pop_stack1();
// 			root=root->right;
// 		}
// 	}
// 	delete st1;
// 	st1=NULL;
// }


// int main(int argc, char const *argv[])
// {
// 	// BinTree tree;
// 	// BinTreeNode* root=tree.create_tree();
// 	BinTree tree;
// 	cout<<"请输入二叉树："<<endl;
// 	tree.set_root(tree.create_tree());
// 	cout<<endl;
// 	// tree.pre_order_by_stack1(tree.get_root());
// 	// printf("\n");
// 	tree.in_order_by_stack1(tree.get_root());
// 	printf("\n");
// 	return 0;
// }

//--------------------------------------------//
//stack2的实现
class stack_node2
{
private:
	BinTreeNode* ptr_node;
	stack_node2* next;
	int isfirst;
	friend class stack2;
	friend class BinTree;
public:
    stack_node2(stack_node2* _next=NULL):next(_next)
    {
    	isfirst=1;
    }
};

class stack2
{
private:
	stack_node2* top;
	int size;
	friend class BinTree;
public:
	stack2()
	{
		top=NULL;
		size=0;
		//isfirst=1;
	}
	void push_stack2(BinTreeNode* tree_node)
	{
		stack_node2* new_node=new stack_node2;
		new_node->ptr_node=tree_node;
		new_node->next=top;
		top=new_node;
		size++;
	}

	bool isstackempty()
	{
		if(size==0)
			return true;
		return false;
	}

	void pop_stack2()
	{
		if(isstackempty())
		{
			cout<<"stack is empty"<<endl;
		}
		else
		{
			stack_node2* tmp=top;
			top=top->next;
			size--;
			delete tmp;
			tmp=NULL;
		}
	}

	//BinTreeNode* getstacktop()
	stack_node2* getstacktop()
	{
		if(!isstackempty())
		{
			//return top->ptr_node;
			return top;
		}
		return NULL;
	}

	int getstacksize()
	{
		return size;
	}
};

void BinTree::post_order_by_stack2(BinTreeNode* root) const
{
	stack2 *st2;
	st2=new stack2;
	stack_node2 *s_node;
	while(root!=NULL || !st2->isstackempty())
	{
		while(root!=NULL)
		{
			//printf("%c\t",root->data);
			//cout<<root->data<<endl;
			st2->push_stack2(root);
			root=root->left;
		}
		if(!st2->isstackempty())
		{	
			s_node=st2->getstacktop();
			root=s_node->ptr_node;
			if(s_node->isfirst==1)
			{
				s_node->isfirst=0;
				root=root->right;
			}
			else
			{
				cout<<root->data<<endl;
				st2->pop_stack2();
				root=NULL;
			}
			// if(!st2->isstackempty())
			// {
			// 	root=st2->getstacktop();
			// 	st2->pop_stack1();
			// 	root=root->right;
			// }
		}
		printf("end\n");
	}
	printf("end2\n");
	//delete st2;
	//st2=NULL;
}

int main(int argc, char const *argv[])
{
	// BinTree tree;
	// BinTreeNode* root=tree.create_tree();
	BinTree tree;
	cout<<"请输入二叉树："<<endl;
	tree.set_root(tree.create_tree());
	cout<<endl;
	// tree.pre_order_by_stack1(tree.get_root());
	// printf("\n");
	//tree.in_order_by_stack1(tree.get_root());
	tree.post_order_by_stack2(tree.get_root());
	printf("\n");
	return 0;
}
