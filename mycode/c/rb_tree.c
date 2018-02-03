#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int key_t;
typedef int data_t;

typedef enum color_t
{
	RED=0,
	BLACK=1
}color_t;

typedef struct rb_node_t
{
	struct rb_node_t * left;
	struct rb_node_t * right;
	struct rb_node_t * parent;
	key_t key;
	data_t data;
	color_t color;
}rb_node_t;

rb_node_t *  rb_insert(key_t key,data_t data,rb_node_t* root);
rb_node_t *  rb_search(key_t key,rb_node_t* root);
rb_node_t *  rb_erase(key_t key,rb_node_t* root);

int main(int argc, char const *argv[])
{
	int i,count=900000;
	key_t key;
	rb_node_t* root=NULL;
	rb_node_t* node=NULL;
	srand(time(NULL));
	for(i=1;i<count;i++)
	{
		key=rand()%count;
		if((root=rb_insert(key,i,root)))
		{
			printf("[i=%d] insert key %d sucess!\n",i,key);
		}
		else
		{
			printf("[i=%d] insert key %d error!\n",i,key);
			exit(-1);
		}

		if((node=rb_search(key,root)))
		{
			printf("[i=%d] search key %d sucess!\n",i,key);
		}
		else
		{
			printf("[i=%d] search key %d error!\n",i,key);
			exit(-1);
		}
		if(!(i%10))
		{
			if((root=rb_erase(key,root)))
			{
				printf("[i=%d] search key %d sucess!\n",i,key);
			}
			else
			{
				printf("[i=%d] search key %d error!\n",i,key);
			}
		}
	}
	return 0;
}

static rb_node_t * rb_new_node(key_t key,data_t data)
{
	rb_node_t * node=(rb_node_t*)malloc(sizeof(rb_node_t));
	if(!node)
	{
		printf("malloc error!\n");
		exit(-1);
	}
	node->key=key;
	node->data=data;
	return node;
}

static rb_node_t * rb_rotate_left(rb_node_t* node,rb_node_t* root)
{
	rb_node_t* right=node->right;
	if((node->right=right->left))
	{
		right->left->parent=node;
	}
	right->left=node;
	if((right->parent=node->parent))
	{
		if(node==node->parent->right)
		{
			node->parent->right=right;
		}
		else
		{
			node->parent->left=right;
		}
	}
	else
	{
		root=right;
	}
	node->parent=right;
	return root;
}

static rb_node_t* rb_rotate_right(rb_node_t * node,rb_node_t* root)
{
	rb_node_t * left=node->left;
	if((node->left=left->right))
	{
		left->right->parent=node;
	}
	left->right=node;
	if((left->parent=node->parent))
	{
		if(node==node->parent->right)
		{
			node->parent->right=left;
		}
		else
		{
			node->parent->left=left;
		}
	}
	else
	{
		root=left;
	}
	node->parent=left;
	return root;
}
/*
红黑数的3种插入情况
用z 表示当前节点,p[z]表示父母,p[p[z]]表示祖父,y表示叔叔
*/
static rb_node_t* rb_insert_rebalance(rb_node_t* node,rb_node_t* root)
{
	rb_node_t * parent,*gparent,*uncle,*tmp;
	//父母p[z] 祖父p[p[z]] 叔叔y 临时节点
	while((parent=node->parent)&& parent->color==RED)
	{//parent 为node的父母,且当父母的颜色为红时
		gparent=parent->parent;//gparent为祖父
		if(parent==gparent->left)//当祖父的左孩子即为父母是
		//上述几行语句,无非就是理顺孩子 父母 祖父的关系
		{
			uncle=gparent->right;//定义叔叔的概念,叔叔y就是父母的右孩子
			if(uncle&& uncle->color==RED)//情况1:z的叔叔y是红色的
			{
				uncle->color=BLACK;//将叔叔节点y着为黑色
				parent->color=BLACK;//z的父母p[z]也着为黑色,解决z,p[z]都是红色的问题
				gparent->color=RED;
				node=gparent;//将祖父当做新增节点z,指针z上移两层,且着为红色
				//上述情况1中,只考虑了 z作为父母的右孩子的情况
			}
			else //情况2:z的叔叔y是黑色的
			{
				if(parent->right==node)//且z为右孩子
				{
					root=rb_rotate_left(parent,root);//左旋[节点z,与父母节点]
					tmp=parent;
					parent=node;
					node=tmp;//parent 与node 互换角色
				}
				//情况3:z的叔叔y是黑色的,此时z成为了左孩子
				//注意 1:情况3是由上述情况2 变化而来的
				//     2:z的叔叔总是黑色的,否则就是情况1了
				parent->color=BLACK;//z的父母p[z]着为黑色
				gparent->color=RED;//原祖父节点着为红色
				root=rb_rotate_right(gparent,root);//右旋[节点z,与祖父节点]
			}
		}
		else
		{
			//这部分是特别为情况1中,z作为左孩子情况而写的
			uncle=gparent->left;//祖父的左孩子作为叔叔节点[原理还是与上部分一样的]
			if(uncle&&uncle->color==RED)//情况1 : z的叔叔y是红色的
			{
				uncle->color=BLACK;
				parent->color=BLACK;
				gparent->color=RED;
				node=gparent;//同上
			}
			else  // 情况2:z的叔叔y是黑色的
			{
				if(parent->left==node)//且z为左孩子
				{
					root=rb_rotate_right(parent,root); //以节点parent  root 右旋
					tmp=parent;
					parent=node;
					node=tmp;//parent与node互换角色
				}
				//经过情况2的变化,成为了情况3
				parent->color=BLACK;
				gparent->color=RED;
				root=rb_rotate_left(gparent,root); //以节点gparent 和root左旋
			}			
		}
	}
	root->color=BLACK;
	return root;
}

static rb_node_t*  rb_erase_rebalance(rb_node_t* node,rb_node_t* parent,rb_node_t* root)
{
	rb_node_t * other,*o_left,*o_right;
	while((!node || node->color==BLACK) && node!=root)
	{
		if(parent->left==node)
		{
			other=parent->right;
			if(other->color==RED)
			{
				other->color=BLACK;
				parent->color=RED;
				root=rb_rotate_left(parent,root);
				other=parent->right;
			}
			if((!other->left || other->left->color==BLACK) &&(!other->right||other->right->color==BLACK))
			{
				other->color=RED;
				node=parent;
				parent=node->parent;
			}
			else
			{
				if(!other->right || other->right->color==BLACK)
				{
					if((o_left=other->left))
					{
						o_left->color=BLACK;
					}
					other->color=RED;
					root=rb_rotate_right(other,root);
					other=parent->right;
				}
				other->color=parent->color;
				parent->color=BLACK;
				if(other->right)
				{
					other->right->color=BLACK;
				}
				root=rb_rotate_left(parent,root);
				node=root;
				break;
			}
		}
		else
		{
			other=parent->left;
			if(other->color==RED)
			{
				other->color=BLACK;
				parent->color=RED;
				root=rb_rotate_right(parent,root);
				other=parent->left;
			}
			if((!other->left || other->left->color==BLACK) &&(!other->right || other->right->color==BLACK))
			{
				other->color=RED;
				node=parent;
				parent=node->parent;
			}
			else
			{
				if(!other->left || other->left->color==BLACK)
				{
					if((o_right=other->right))
					{
						o_right->color=BLACK;
					}
					other->color=RED;
					root=rb_rotate_left(other,root);
					other=parent->left;
				}
				other->color=parent->color;
				parent->color=BLACK;
				if(other->left)
				{
					other->left->color=BLACK;
				}
				root=rb_rotate_right(parent,root);
				node=root;
				break;
			}
		}
	}
	if(node)
	{
		node->color=BLACK;
	}
	return root;
}

static rb_node_t* rb_search_auxiliary(key_t key,rb_node_t* root,rb_node_t** save)
{
	rb_node_t* node=root,*parent=NULL;
	int ret;
	while(node)
	{
		parent=node;
		ret=node->key-key;
		if(0<ret)
		{
			node=node->left;
		}
		else if(0>ret)
		{
			node=node->right;
		}
		else
		{
			return node;
		}
	}
	if(save)
	{
		*save=parent;
	}
	return NULL;
}

rb_node_t* rb_insert(key_t key,data_t data,rb_node_t * root)
{
	rb_node_t * parent=NULL,*node;
	parent=NULL;
	if((node=rb_search_auxiliary(key,root,&parent)))
	{
		return root;
	}
	node=rb_new_node(key,data);
	node->parent=parent;
	node->left=node->right=NULL;
	node->color=RED;
	if(parent)
	{
		if(parent->key > key)
		{
			parent->left=node;
		}
		else
		{
			parent->right=node;
		}
	}
	else
	{
		root=node;
	}
	return rb_insert_rebalance(node,root);
}

rb_node_t * rb_search(key_t key,rb_node_t* root)
{
	return rb_search_auxiliary(key,root,NULL);
}

rb_node_t *  rb_erase(key_t key,rb_node_t* root)
{
	rb_node_t* child,*parent,*old,*left,*node;
	color_t color;
	if(!(node=rb_search_auxiliary(key,root,NULL)))
	{
		printf("key %d is not exist!\n");
		return root;
	}
	old=node;
	if(node->left && node->right)
	{
		node=node->right;
		while((left=node->left)!=NULL)
		{
			node=left;
		}
		child=node->right;
		parent=node->parent;
		color=node->color;
		if(child)
		{
			child->parent=parent;
		}
		if(parent)
		{
			if(parent->left==node)
			{
				parent->left=child;
			}
			else
			{
				parent->right=child;
			}
		}
		else
		{
			root=child;
		}
		if(node->parent==old)
		{
			parent=node;
		}
		node->parent=old->parent;
		node->color=old->color;
		node->right=old->right;
		node->left=old->left;

		if(old->parent)
		{
			if(old->parent->left==old)
			{
				old->parent->left=node;
			}
			else
			{
				old->parent->right=node;
			}
		}
		else
		{
			root=node;
		}
		old->left->parent=node;
		if(old->right)
		{
			old->right->parent=node;
		}
	}
	else
	{
		if(!node->left)
		{
			child=node->right;
		}
		else if(!node->right)
		{
			child=node->left;
		}
		parent=node->parent;
		color=node->color;
		if(child)
		{
			child->parent=parent;
		}
		if(parent)
		{
			if(parent->left==node)
			{
				parent->left=child;
			}
			else
			{
				parent->right=child;
			}
		}
		else
		{
			root=child;
		}
	}
	free(old);
	old=NULL;
	if(color==BLACK)
	{
		root=rb_erase_rebalance(child,parent,root);
	}
	return root;
}