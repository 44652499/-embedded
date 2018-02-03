#include <iostream>
using namespace std;

template <class T>
class rb_tree;

typedef enum col
{
	BLACK = 1,
	RED   = 0
}col;

template <class T>
class rb_node		//红黑树节点类型
{
	template <class T2>
	friend class rb_tree;		//友元申明
private:
	T data;
	rb_node<T> *left;
	rb_node<T> *right;
	rb_node<T> *parent;
	col color;
public:
	// rb_node()
	// {
	// 	data = 0;
	// 	left = NULL;
	// 	right = NULL;
	// 	parent = NULL;
	// 	color = RED;
	// }
	rb_node(T _data)
	{
		data = _data;
		left = NULL;
		right =  NULL;
		parent = NULL;
		color = RED;
	}
};

template <class T>
class rb_tree
{
public:
	rb_node<T> *root;
	rb_node<T> *NIL;	//叶节点

	rb_tree(rb_node<T> *r = NULL): root(r)
	{
		NIL = new rb_node<T>(-1);	//末尾空节点，不存数据
		NIL->color = BLACK;

		root->left = NIL;
		root->right = NIL;
		root->parent = NIL;
		root->color = BLACK;
	}
	~rb_tree()
	{

	}

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _

	node                          right
    /  \						  /   \
   a  right         --->        node   y
      /  \                      /  \
     b    y                    a    b
   
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/
	void rb_rotate_left(rb_node<T> *node)
	{
		rb_node<T> *tmp = node->right;
		if (tmp->left) 
		{
			node->right = tmp->left;
			tmp->left->parent = node;
		}
		tmp->parent = node->parent;
		if (node->parent)   //node节点不是根节点，上面还有节点
		{
			if (node->parent->left == node)
			{
				node->parent->left = tmp;
			}
			if (node->parent->right == node)
			{
				node->parent->right = tmp;
			}
		}
		else	//node是根节点
		{
			root = tmp;
		}
		tmp->left = node;
		node->parent = tmp;
	}

/*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _

         node                  left
        /   \				   /  \
	  left   y   ---->        a   node
	  /  \                        /  \
	 a    b                       b   y
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/
    void rb_rotate_right(rb_node<T> *node)
    {
    	rb_node<T> *tmp = node->left;
    	if (tmp->right)
    	{
    		node->left = tmp->right;
    		tmp->right->parent = node;
    	}

    	tmp->parent = node->parent;
    	if (node->parent)
    	{
    		if (node->parent->left == node)
    		{
    			node->parent->left = tmp;
    		}
    		if (node->parent->right == node)
    		{
    			node->parent->right = tmp;
    		}
    	}
    	else
    	{
    		root = tmp;
    	}
    	tmp->right = node;
    	node->parent = tmp;

    }

	void insert(rb_node<T> *node)
	{
		rb_node<T> *cur = root;
		//printf("%d\n",cur->data);
		rb_node<T> *tmp = NIL;
		while (cur != NIL)   //并不是指向NULL，而是指向NIL，NIL有地址
		{
			tmp = cur;
			if (node->data > cur->data)
			{
				cur = cur->right;
			}
			else if (node->data < cur->data)
			{
				cur = cur->left;
			}
		}
		node->parent = tmp;
		if (root == NIL)	//要插入的值刚好是第一个值，作为根结点
		{
			root = node;
			node->color = BLACK;
		}

		if (tmp->data > node->data)
		{
			tmp->left = node;	//node = tmp->left;写反了
		}
		if (tmp->data < node->data)
		{
			tmp->right = node;  //node = tmp->right;写反了
		}
		node->color = RED; 
		node->left = NIL;
		node->right = NIL;
		// insert_fix(node);
	}



	void insert_fix(rb_node<T> *node)
	{

	}

	void pre_output(rb_node<T> *_root)
	{
		if (_root == NIL)
		{
			return;
		}
		cout << _root->data << "--" << _root->color << '\t';
		pre_output(_root->left);
		pre_output(_root->right);
	}
	void mid_output(rb_node<T> *_root)
	{
		if (_root == NIL)
		{
			return;
		}
		mid_output(_root->left);
		cout << _root->data << "--"<< _root->color << '\t';		//多字节字符常量'--'
		// cout << _root->left << '\t' << _root->right << '\t' << _root->parent;

		mid_output(_root->right);
	}
	void back_output(rb_node<T> *_root)
	{
		if (_root == NIL)
		{
			return;
		}
		back_output(_root->left);
		back_output(_root->right);
		cout << _root->data << "--" << _root->color << '\t';
	}
};


int main(int argc, char const *argv[])
{
	rb_node<int> *node1  = new rb_node<int>(8);
	rb_node<int> *node2  = new rb_node<int>(5);
	rb_node<int> *node3  = new rb_node<int>(9);
	rb_node<int> *node4  = new rb_node<int>(1);
	rb_node<int> *node5  = new rb_node<int>(6);
	rb_node<int> *node6  = new rb_node<int>(3);
	rb_node<int> *node7  = new rb_node<int>(10);
	rb_node<int> *node8  = new rb_node<int>(2);
	//rb_node<int> *node9  = new rb_node<int>(4);
	//rb_node<int> *node10 = new rb_node<int>(7);

	rb_tree<int> *tree = new rb_tree<int>(node1);
	// tree->insert(node2);
	// tree->insert(node3);
	// tree->mid_output(tree->root);

	tree->insert(node2);
	tree->insert(node3);		
	tree->insert(node4);
	tree->insert(node5);
	tree->insert(node6);		
	tree->insert(node7);
	tree->insert(node8);
	//tree->pre_output(tree->root);
	//cout << endl;
	tree->mid_output(tree->root);
	cout << endl;
	//tree->back_output(tree->root);
	//cout << endl;

	return 0;
}