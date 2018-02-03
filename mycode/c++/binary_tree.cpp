#include <iostream>
using namespace std;
//二叉树的节点类
class BinTreeNode
{
private:
        int data;
        BinTreeNode *left,*right;
public:
                //利用初始化列表完成data，left，rightn的初始化
        BinTreeNode(const int &item,BinTreeNode *lPtr = NULL,BinTreeNode *rPtr = NULL):data(item) ,left(lPtr),right(rPtr){};
        void set_data(int item)
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
class BinTree
 {
  private:
        BinTreeNode *root;
  public:
        BinTree(BinTreeNode *t = NULL):root(t){};
        ~BinTree(){delete root;};
        void set_root(BinTreeNode *t)
        {
                root = t;
        }
        BinTreeNode* get_root()const
        {
                return root;
        }
        //1.创建二叉树
        BinTreeNode* create_tree();
        //2.前序遍历
        void pre_order(BinTreeNode *r) const;
        //3.中序遍历
        void in_order(BinTreeNode *r) const;
        //4.后序遍历
        void post_order(BinTreeNode *r) const;
        //5.层次遍历
        void level_order(BinTreeNode *r) const;
        //6.获得叶子节点的个数
        int get_leaf_num(BinTreeNode *r) const;
        //7.获得二叉树的高度
        int get_tree_height(BinTreeNode *r) const;
        //8.交换二叉树的左右儿子
        void swap_left_right(BinTreeNode *r);
        //9.求两个节点pNode1和pNode2在以r为树根的树中的最近公共祖先
        BinTreeNode* get_nearest_common_father(BinTreeNode *r,BinTreeNode *pNode1,BinTreeNode *pNode2) const;
        //10.打印和为某一值的所有路径
        void print_rout(BinTreeNode *r,int sum) const;
        //11.判断一个节点t是否在以r为根的子树中
        bool is_in_tree(BinTreeNode *r,BinTreeNode *t) const;
 };
 //创建二叉树，这里不妨使用前序创建二叉树，遇到‘#’表示节点为空
 BinTreeNode* BinTree::create_tree()
{
        char item;
        BinTreeNode *t,*t_l,*t_r;
        cin>>item;
        if(item != '#')
        {
                BinTreeNode *pTmpNode = new BinTreeNode(item-48);
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
//前序遍历
 void BinTree::pre_order(BinTreeNode *r) const
 {
        BinTreeNode *pTmpNode = r;
        if(pTmpNode != NULL)
        {
                cout<<pTmpNode->get_data()<<" ";
                pre_order(pTmpNode->get_left());
                pre_order(pTmpNode->get_right());
        }
}
//中序遍历
void BinTree::in_order(BinTreeNode *r)  const
{
        BinTreeNode *pTmpNode = r;
        if(pTmpNode != NULL)
        {
                in_order(pTmpNode->get_left());
                cout<<pTmpNode->get_data()<<" ";
                in_order(pTmpNode->get_right());
        }
}
//后序遍历
void BinTree::post_order(BinTreeNode *r)  const
{
        BinTreeNode *pTmpNode = r;
        if(pTmpNode != NULL)
        {
                post_order(pTmpNode->get_left());
                post_order(pTmpNode->get_right());
                cout<<pTmpNode->get_data()<<" ";
        }
}
//层次遍历
 void BinTree::level_order(BinTreeNode *r) const
 {
         if(r == NULL)
                return;
        deque<BinTreeNode*> q;
        q.push_back(r);
        while(!q.empty())
        {
                BinTreeNode *pTmpNode = q.front();
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
int BinTree::get_leaf_num(BinTreeNode *r) const
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
int BinTree::get_tree_height(BinTreeNode *r) const
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
void BinTree::swap_left_right(BinTreeNode *r)
{
        if(r == NULL)
        {
                return;
        }
        BinTreeNode *pTmpNode = r->get_left();
        r->set_left(r->get_right());
        r->set_right(pTmpNode);
        swap_left_right(r->get_left());
        swap_left_right(r->get_right());
}
//判断一个节点t是否在以r为根的子树中
bool BinTree::is_in_tree(BinTreeNode *r,BinTreeNode *t) const
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
 BinTreeNode* BinTree::get_nearest_common_father(BinTreeNode *r,BinTreeNode *pNode1,BinTreeNode *pNode2) const
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
//注意这两个栈的使用
stack<BinTreeNode *>dfs_s;
stack<BinTreeNode *>print_s;
//打印出从r开始的和为sum的所有路径
void BinTree::print_rout(BinTreeNode *r,int sum) const
{
        if(r == NULL)
        {
                return;
        }
        //入栈
        sum -= r->get_data();
        dfs_s.push(r);
        if(sum <= 0)
        {
                if(sum == 0)
                {
                        while(!dfs_s.empty())
                        {
                        print_s.push(dfs_s.top());
                        dfs_s.pop();
                        }
                        while(!print_s.empty())
                        {
                                cout<<print_s.top()->get_data()<<" ";
                                dfs_s.push(print_s.top());
                                print_s.pop();
                        }
                        cout<<endl;
                }
                sum += r->get_data();
                dfs_s.pop();
                return;
        }
        //递归进入左子树
        print_rout(r->get_left(),sum);
        //递归进入右子树
        print_rout(r->get_right(),sum);
        //出栈
        sum += r->get_data();
        dfs_s.pop();
}
int main(int argc,const char argv[])
{
        BinTree tree; /*--------------------------------------------------------------------*/
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
        BinTreeNode *p1 = tree.get_root()->get_left()->get_right();
        BinTreeNode *p2 = tree.get_root()->get_left()->get_left();
        BinTreeNode *p3 = tree.get_root()->get_right()->get_right()->get_right();
        cout<<p1->get_data()<<" 和 "<<p2->get_data()<<"的最近公共祖先是：";
        BinTreeNode *p = tree.get_nearest_common_father(tree.get_root(),p1,p2);
        cout<<p->get_data()<<endl;
        cout<<p1->get_data()<<" 和 "<<p3->get_data()<<"的最近公共祖先是：";
        p = tree.get_nearest_common_father(tree.get_root(),p1,p3);
        cout<<p->get_data()<<endl<<endl;
        /*--------------------------------------------------------------------*/
        cout<<"路径如下："<<endl;
        tree.print_rout(tree.get_root(),12);
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