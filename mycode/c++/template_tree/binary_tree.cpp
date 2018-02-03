#include <iostream>
//#include "template_stack.h"
//#include "template_deque.h"
using namespace std;
template< class T>
class deque;

template <class T>
class deque_node
{
friend class deque<T>;
private:
	T data;
	deque_node *next;
public:
	deque_node()
	{
		next=NULL;
	}
};

template <class T>
class deque
{
private:
	deque_node<T> *head;
	deque_node<T> *tail;
	int size;
public:
	deque()
	{
		head=NULL;
		tail=NULL;
		size=0;
	}
	bool empty()
	{
		if(0==size)
			return true;
		else
			return false;
	}
	deque_node<T> front()
	{
		return head;
	}
	deque_node<T> rear()
	{
		return tail;
	}
	void push_back(T _data)
	{
		deque_node<T> *new_node=new deque_node<T>;
		new_node->data=_data;
		size++;
		if(NULL==head && NULL==tail)
		{
			head=new_node;
			tail=new_node;
		}
		else
		{
			tail->next=new_node;
			tail=new_node;
		}
	}
	deque_node<T> pop_front()
	{
		deque_node<T> *tmp=front;
		front=front->next;
		size--;
		return tmp;
	}
};


template <class T>
class stack;

template <class T>
class stack_node
{
	friend class stack<T>;
private:
	T data;
	stack_node* next;
public:
	stack_node()
	{
		next=NULL;
	}
};

template <class T>
class stack
{
private:
	stack_node<T>* top;
	int size;
public:
	stack()
	{
		top=NULL;
		size=0;
	}
	void push(T _data)
	{
		stack_node<T>* new_node=new stack_node<T>;
		new_node->data=_data;
		new_node->next=top;
		top=new_node;
		size++;
	}
	bool empty()
	{
		if(0==size)
		{
			return true;
		}
		return false;
	}
	stack_node<T> pop()
	{
		if(!empty())
		{
			stack_node<T>* tmp=top;
			top=top->next;
			size--;
			return tmp;		
		}
		else
		{
			cout<<"This stack is empty."<<endl;
		}
	}

};
//二叉树的节点类
template <class T>
class BinTreeNode
{
private:
        T data;
        BinTreeNode *left,*right;
public:
                //利用初始化列表完成data，left，rightn的初始化
        BinTreeNode(const T &item,BinTreeNode *lPtr = NULL,BinTreeNode *rPtr = NULL):data(item) ,left(lPtr),right(rPtr){};
        void set_data(T item)
        {
                data = item;
        }
        int get_data()const
        {
                return data;
        }
        void set_left(BinTreeNode *l)
        {
                left = l;
        }
        BinTreeNode* get_left()const
        {
                return left;
        }
        void set_right(BinTreeNode *r)
        {
                right = r;
        }
        BinTreeNode* get_right()const
        {
                return right;
        }
};
//二叉树
template <class T>
class BinTree
 {
  private:
        BinTreeNode<T> *root;
  public:
        BinTree(BinTreeNode<T> *t = NULL):root(t){};
        ~BinTree(){delete root;};
        void set_root(BinTreeNode<T> *t)
        {
                root = t;
        }
        BinTreeNode<T>* get_root()
        {
            return root;
        }
        //1.创建二叉树
        BinTreeNode<T>*  create_tree();
        //2.前序遍历
        void pre_order(BinTreeNode<T> *r);
        //3.中序遍历
        void in_order(BinTreeNode<T> *r);
        //4.后序遍历
        void post_order(BinTreeNode<T> *r);
        //5.层次遍历
        void level_order(BinTreeNode<T> *r);
        //6.获得叶子节点的个数
        int get_leaf_num(BinTreeNode<T> *r);
        //7.获得二叉树的高度
        int get_tree_height(BinTreeNode<T> *r);
        //8.交换二叉树的左右儿子
        void swap_left_right(BinTreeNode<T> *r);
        //9.求两个节点pNode1和pNode2在以r为树根的树中的最近公共祖先
        BinTreeNode<T>* get_nearest_common_father(BinTreeNode<T> *r,BinTreeNode<T> *pNode1,BinTreeNode<T> *pNode2);
        //10.打印和为某一值的所有路径
        void print_rout(BinTreeNode<T> *r,int sum);
        //11.判断一个节点t是否在以r为根的子树中
        bool is_in_tree(BinTreeNode<T> *r,BinTreeNode<T> *t);
 };
 //创建二叉树，这里不妨使用前序创建二叉树，遇到‘#’表示节点为空
template <class T>
//BinTreeNode<T>* BinTree<T>::create_tree()//错误一
BinTreeNode<T>* BinTree<T>::create_tree()
{
    char item;
    BinTreeNode<T> *t,*t_l,*t_r;
    cin>>item;
    if(item != '#')
    {
       BinTreeNode<T> *pTmpNode = new BinTreeNode<T>(item-48);
        t = pTmpNode;
        t_l = create_tree();
        t->set_left(t_l);
        t_r = create_tree();
        t->set_right(t_r);
        return t;
    }
    else
    {
        t = NULL;
        return t;
    }
}
// //前序遍历
template <class T>
void BinTree<T>::pre_order(BinTreeNode<T> *r)
{
    BinTreeNode<T> *pTmpNode = r;
    if(pTmpNode != NULL)
    {
        cout<<pTmpNode->get_data()<<" ";
        pre_order(pTmpNode->get_left());
        pre_order(pTmpNode->get_right());
    }
}
//中序遍历
template <class T>
void BinTree<T>::in_order(BinTreeNode<T> *r) 
{
    BinTreeNode<T> *pTmpNode = r;
    if(pTmpNode != NULL)
    {
        in_order(pTmpNode->get_left());
        cout<<pTmpNode->get_data()<<" ";
        in_order(pTmpNode->get_right());
    }
}
//后序遍历
template <class T>
void BinTree<T>::post_order(BinTreeNode<T> *r) 
{
    BinTreeNode<T> *pTmpNode = r;
    if(pTmpNode != NULL)
    {
        post_order(pTmpNode->get_left());
        post_order(pTmpNode->get_right());
        cout<<pTmpNode->get_data()<<" ";
    }
}
//层次遍历
template <class T>
 void BinTree<T>::level_order(BinTreeNode<T> *r) 
 {
    if(r == NULL)
        return;
    //deque<BinTreeNode*> q;//错误
    deque<BinTreeNode<T> > q;
    q.push_back(r->get_data());
    while(!q.empty())
    {
        //BinTreeNode *pTmpNode = q.front();//错误
        BinTreeNode<T> *pTmpNode =  q.front();
        cout<<pTmpNode->get_data()<<" ";
        q.pop_front();
        if(pTmpNode->get_left() != NULL)
        {
            q.push_back(pTmpNode->get_left());
        }
        if(pTmpNode->get_right() != NULL)
        {
            q.push_back(pTmpNode->get_right());
        }
    }
}
//获取叶子节点的个数
template <class T>
int BinTree<T>::get_leaf_num(BinTreeNode<T> *r) 
{
        if(r == NULL)//该节点是空节点，比如建树时候用'#'表示
        {
                return 0;
        }
        if(r->get_left()==NULL && r->get_right()==NULL)//该节点并不是空的，但是没有孩子节点
        {
                return 1;
        }
       //递归整个树的叶子节点个数 = 左子树叶子节点的个数 + 右子树叶子节点的个数
        return get_leaf_num(r->get_left()) + get_leaf_num(r->get_right());
}
//获得二叉树的高度
template <class T>
int BinTree<T>::get_tree_height(BinTreeNode<T> *r) 
{
        if(r == NULL)//节点本身为空
        {
                return 0;
        }
        if(r->get_left()==NULL && r->get_right()==NULL)//叶子节点
        {
                return 1;
        }
        int l_height = get_tree_height(r->get_left());
        int r_height = get_tree_height(r->get_right());
        return l_height >= r_height ? l_height + 1 : r_height + 1; 
}
//交换二叉树的左右儿子
template <class T>
void BinTree<T>::swap_left_right(BinTreeNode<T> *r)
{
        if(r == NULL)
        {
                return;
        }
        BinTreeNode<T> *pTmpNode = r->get_left();
        r->set_left(r->get_right());
        r->set_right(pTmpNode);
        swap_left_right(r->get_left());
        swap_left_right(r->get_right());
}
//判断一个节点t是否在以r为根的子树中
template <class T>
bool BinTree<T>::is_in_tree(BinTreeNode<T> *r,BinTreeNode<T> *t)
{
        if(r == NULL)
        {
                return false;
        }
        else if(r == t)
        {
                return true;
        }
        else
        {
                bool has = false;
                if(r->get_left() != NULL)
                {
                        has = is_in_tree(r->get_left(),t);
                }
                if(!has && r->get_right()!= NULL)
                {
                        has = is_in_tree(r->get_right(),t);
                }
                return has;
        }
}
//求两个节点的最近公共祖先
template <class T>
BinTreeNode<T>* BinTree<T>::get_nearest_common_father(BinTreeNode<T> *r,BinTreeNode<T> *pNode1,BinTreeNode<T> *pNode2)
{
    //pNode2在以pNode1为根的子树中（每次递归都要判断，放在这里不是很好。）
    if(is_in_tree(pNode1,pNode2))
    {
        return pNode1;
    }
    //pNode1在以pNode2为根的子树中
    if(is_in_tree(pNode2,pNode1))
    {
        return pNode2;
    }
    bool one_in_left,one_in_right,another_in_left,another_in_right;
    one_in_left = is_in_tree(r->get_left(),pNode1);
    another_in_right = is_in_tree(r->get_right(),pNode2);
    another_in_left = is_in_tree(r->get_left(),pNode2);
    one_in_right = is_in_tree(r->get_right(),pNode1);
    if((one_in_left && another_in_right) || (one_in_right && another_in_left))
    {
        return r;
    }
    else if(one_in_left && another_in_left)
    {
        return get_nearest_common_father(r->get_left(),pNode1,pNode2);
    }
    else if(one_in_right && another_in_right)
    {
        return get_nearest_common_father(r->get_right(),pNode1,pNode2);
    }
    else
    {
        return NULL;
    }
}
//打印出从r开始的和为sum的所有路径
template <class T>
void BinTree<T>::print_rout(BinTreeNode<T> *r,int sum)
{
            //注意这两个栈的使用
        stack<BinTreeNode<T> > dfs_s;
        stack<BinTreeNode<T> > print_s;
        // if(r == NULL)
        // {
        //         return;
        // }
        // //入栈
        // sum -= r->get_data();
        // dfs_s.push(r);
        // if(sum <= 0)
        // {
        //         if(sum == 0)
        //         {
        //                 while(!dfs_s.empty())
        //                 {
        //                     print_s.push(dfs_s.top());
        //                     dfs_s.pop();
        //                 }
        //                 while(!print_s.empty())
        //                 {
        //                     cout<<print_s.top()->get_data()<<" ";
        //                     dfs_s.push(print_s.top());
        //                     print_s.pop();
        //                 }
        //                 cout<<endl;
        //         }
        //         sum += r->get_data();
        //         dfs_s.pop();
        //         return;
        // }
        // //递归进入左子树
        // print_rout(r->get_left(),sum);
        // //递归进入右子树
        // print_rout(r->get_right(),sum);
        // //出栈
        // sum += r->get_data();
        // dfs_s.pop();
}
int main(int argc,const char argv[])
{
    BinTree<int> tree; 
    /*--------------------------------------------------------------------*/
    cout<<"请输入二叉树前序序列进行建树，'#'代表空节点："<<endl;
    tree.set_root(tree.create_tree());
    cout<<endl;
    /*--------------------------------------------------------------------*/
    cout<<"前序遍历的结果：";
    tree.pre_order(tree.get_root());
    cout<<endl<<endl;
    /*-------------------------------------------------------------------*/
    cout<<"中序遍历的结果：";
    tree.in_order(tree.get_root());
    cout<<endl<<endl;
    /*--------------------------------------------------------------------*/
    cout<<"后序遍历的结果：";
    tree.post_order(tree.get_root());
    cout<<endl<<endl;
    /*--------------------------------------------------------------------*/
    cout<<"层次遍历的结果：";
    tree.level_order(tree.get_root());
    cout<<endl<<endl;
    /*--------------------------------------------------------------------*/
    cout<<"该二叉树叶子节点的个数：";
    cout<<tree.get_leaf_num(tree.get_root())<<endl<<endl;
    /*--------------------------------------------------------------------*/
    cout<<"该二叉树的高度是：";
    cout<<tree.get_tree_height(tree.get_root())<<endl<<endl;
    /*--------------------------------------------------------------------*/
    tree.swap_left_right(tree.get_root());
    cout<<"交换左右子树之后的先序遍历结果为：";
    tree.pre_order(tree.get_root());
    cout<<endl<<endl;
    /*--------------------------------------------------------------------*/
    BinTreeNode<int> *p1 = tree.get_root()->get_left()->get_right();
    BinTreeNode<int> *p2 = tree.get_root()->get_left()->get_left();
    BinTreeNode<int> *p3 = tree.get_root()->get_right()->get_right()->get_right();
    cout<<p1->get_data()<<" 和 "<<p2->get_data()<<"的最近公共祖先是：";
    BinTreeNode<int> *p = tree.get_nearest_common_father(tree.get_root(),p1,p2);
    cout<<p->get_data()<<endl;
    cout<<p1->get_data()<<" 和 "<<p3->get_data()<<"的最近公共祖先是：";
    p = tree.get_nearest_common_father(tree.get_root(),p1,p3);
    cout<<p->get_data()<<endl<<endl;
    /*--------------------------------------------------------------------*/
    cout<<"路径如下："<<endl;
    //tree.print_rout(tree.get_root(),12);
    return 0;
}
/*请大家修改以上代码,编译并通过.要求如下:
1.以上类都必须设置成模版类
2.以上出现的队列与栈都必须自定义实现,不准用系统函数
3.树操作代码增加如下函数:
   a.非递归实现:前序 中序 后序遍历
   b.将树分别按照前序 中序 后序方式实现转换成一个双向链表(在创建链表不能在新增节点)
   c.实现将以上的树转换成haffman树,并输出其每个终端节点的haffman编码及其权重值
   d.任意输入一个整数值,从树的任意节点开始搜索,输出其所有搜索连续节点之和等于输入整数值的节点路径信息
*/
