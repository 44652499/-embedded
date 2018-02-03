#include <iostream>
#include <stack>
using namespace std;
static const int RED=0;
static const int BLACK=1;
template <class T>
class redblacktreenode
{
public:
	redblacktreenode(T _key):key(_key),tparent(NULL),tleft(NULL),tright(NULL),color(BLACK)
	{
	}
	T key;
	redblacktreenode<T>* tparent;
	redblacktreenode<T>* tleft;
	redblacktreenode<T>* tright;
	int color;   
};
template<class T>
class redblacktree
{
public:
	redblacktree()
	{

	}
private:
	redblacktreenode<T>* root;
    static redblacktreenode<T> *NIL;
};
template <class T>
RedBlackTreeNode<T>* RedBlackTree<T>::NIL = new RedBlackTreeNode<T>;