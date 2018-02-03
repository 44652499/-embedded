/*******************************************************************************************
*
*
* File name:    腾讯面试题3
* Author:       廖刚
* Version:      1th
* Date:         2016/3/5
* Description:  
*               题目：4.设计一个算法，找出二叉树上任意两个结点的最近共同父结点。
*                       空间复杂度允许的最大值为树的深度，时间复杂度要小于O(n2)。
*                       每个节点不存在指向父节点的指针。
*                    
*                    
*                    
*               解决方案：定义一个栈来存储当前遍历路径上的所有父节点，curr的父亲，爷爷，祖宗。。
*                         每次递归到哪个节点哪个节点就入栈，当某个节点的子节点都被遍历过了，那该节点出栈；
*                         找到第一个节点时就用一个（common——father）指针指向当该节点地址在栈中的位置，                       
*                         当（common——father）所指向的栈的位置要出栈时，（common——father）向栈底移动一位；
*                         找到第二个节点时所有递归结束退出函数；（common——father）指向的栈的位置就是结果值
*                     
*                         遍历只需要遍历一遍，时间复杂度为（On），空间复杂度为存放父亲节点的栈的大小；
*                         
* Others:       无
* Function List:
* History:      第一次编辑：2016/3/5
*
********************************************************************************************
*/
#if 0

#include <stdio.h>
#include <stdlib.h>

/*定义树节点*/

typedef struct tree_node
{
    int values;
    struct tree_node* left_child;
    struct tree_node* right_child;
}tree_node;

tree_node* create_tree(int *tree_level,int curr_level)
{
	int temp_values;
	scanf("%d",&temp_values);
	if (temp_values == 0)
	{
		return NULL;
	}
	if (curr_level > *tree_level)
	{
		*tree_level = curr_level;
	}
	tree_node* new_node = (tree_node *)malloc(1 * sizeof(tree_node));
    new_node.values = temp_values;
    new_node.left_child = create_tree(tree_level, curr_level+1);
    new_node.right_child = create_tree(tree_level, curr_level+1);
    return new_node;
}

/*遍历释放节点*/
void free_tree(tree_node *curr_node)
{
	if (curr_node != NULL)
	{
		free_tree(curr_node->left_child);
		free_tree(curr_node->right_child);
		free (curr_node);
		curr_node = NULL;
	}
}

tree_node *find_child1_all_father(tree_node **father_node,
                             tree_node *curr_node, int child1_values)
{
	if ((curr == NULL) || (curr_node->values == child1_values))
	{
		return curr;
	}
	tree_node *curr_node_left_child =  
	      find_child1_all_father(++father_node, curr_node->left_child, child1_values);
	if (curr_node_left_child != NULL)
	{
		*(--father_node) =  curr_node_left_child;
		return curr_node; 
	}
	tree_node *curr_node_right_child = 
	      find_child1_all_father(father_node, curr_node->right_child, child1_values);
	if (curr_node_right_child != NULL)
	{
		*(--father_node) =  curr_node_right_child;
		return curr_node; 
	}
	return NULL;
}

tree_node *is_same_forefather(tree_node *root,int child2_values)
{
	if (root->values == child2_values)
	{
		return root; 
	}
}

tree_node *find_same_father(tree_node **father_node, tree_node * root, 
	                         int child1_values, int child2_values,int tree_level)
{
	tree_node *child1_node = NULL;
	tree_node *child2_node = NULL	child1_node = find_child1_all_f;
ather(father_node, root, child1_values);
	if (child1 == NULL)  
		printf("not find child1\n");
		return NULL;
	}
	while((tree_level+1) && (child2_node == NULL))
	{
		if (father_node[tree_level] == NULL)
		{
			tree_level--;
			continue;
		}
		child2_node = is_same_forefather(father_node[tree_level], child2_values);
		tree_level--;
	}j       
	if (child2_node != NULL)
	{
		return father_node[tree_level+1];
	}
	else
	{
		printf("not find child2\n");
		return NULL;
	}
	
}

int main(int argc, char const *argv[])
{
	int *tree_level = NULL;
	*tree_level = 0;
	tree_node* root = NULL;
	root = create_tree(tree_level, 1);
	tree_node **father_node = (tree_node **)malloc(tree_level * (sizeof(tree_node*)));
	tree_node *same_father_node = NULL;
	int child_values[2];
	scanf("%d%d",child_values[0],child_values[1]);
	same_father_node = 
	     find_same_father(father_node, root, child_values[0], child_values[1], *tree_level);
	printf("%d\n",same_father_node->values );
	return 0;
}

#endif
#if 1
/*定义树节点*/
#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int values;
    struct tree_node* left_child;
    struct tree_node* right_child;
}tree_node;

typedef struct 
{
   	tree_node *top;         //栈顶
   	tree_node *bottom;      //栈底（可有可无）
   	tree_node *common_father;//指向两个节点的最近父节点
}father_node_stack;

tree_node* create_tree(int *tree_level,int curr_level)
{
	int temp_values;
	scanf("%d",&temp_values);
	if (temp_values == 0)
	{
		return NULL;
	}
	if (curr_level > *tree_level)
	{
		*tree_level = curr_level;
	}
	tree_node *new_node = (tree_node *)malloc(1 * sizeof(tree_node));
    new_node->values = temp_values;
    new_node->left_child = create_tree(tree_level, curr_level+1);
    new_node->right_child = create_tree(tree_level, curr_level+1);
    return new_node;
}

/*遍历释放节点*/
void free_tree(tree_node *curr_node)
{
	if (curr_node != NULL)
	{
		free_tree(curr_node->left_child);
		free_tree(curr_node->right_child);
		free (curr_node);
		curr_node = NULL;
	}
}

void push_stack(tree_node *push_node,father_node_stack *con_father_stack)
{
	++(con_father_stack->top);
	con_father_stack->top = push_node;
}

void pop_stack(father_node_stack *con_father_stack)
{
	/* 当未找到第一个节点时。con_father_stack->common_father为空不会执行if语句
	   当找到第一个节点后，栈顶值要出栈先判断栈顶指针top是否等于common_father，
	   如果是就让common_father--
	*/
	if (con_father_stack->common_father == con_father_stack->top)
	{
		con_father_stack->common_father--;
		printf("ttttttt%d\n",con_father_stack->common_father->values);
	}
	printf("出栈：%d\n",con_father_stack->top->values );
	(con_father_stack->top)--;
	printf("出栈后：%d\n",con_father_stack->top->values );
}

tree_node *find_same_father(father_node_stack *con_father_stack, tree_node *curr_node,
                              int child1_values, int child2_values)
{
	if (curr_node !=NULL)
	{
		push_stack(curr_node, con_father_stack);//每来一个节点就压栈
		//找到第一节点，让common_father指针指向找的的第一个节点，然后继续找第二个节点
		//找到第二个节点后退出所有遍历;那么common_father指针指向的就是两个节点最近的父节点；
		if ((curr_node->values == child1_values) || (curr_node->values == child2_values))
		{
			if (con_father_stack->common_father != NULL)
			{   
				return NULL;
			}
			con_father_stack->common_father = con_father_stack->top;
		}
		if(find_same_father(con_father_stack, curr_node->left_child, 
			                  child1_values,child2_values)==NULL)
		{
			return NULL;
		}
		if(find_same_father(con_father_stack, curr_node->right_child,
		                      child1_values,child2_values)==NULL)
		{
			return NULL;
		}
		/*改函数的精华就在出栈函数*/
		pop_stack(con_father_stack);//该节点的所有孩子都被遍历过后出栈，注意出栈是需要判断。
		return curr_node;
	}
	return con_father_stack;
}

int main(int argc, char const *argv[])
{
	int level=0;
	int *tree_level = &level;//用来存储树的深度；
	tree_node* root = NULL;  //树的根节点；
	root = create_tree(tree_level, 1);   //第二个参数为当前创造的节点在该树的深度
	tree_node *father_node[*tree_level]; //用于存储当前遍历到的当前节点的所有祖先(父亲。爷爷。祖宗。。。)
	tree_node *same_father_node = NULL;  //这个没什么用
	int child_values[2];                 //存放要查找的两个节点的值
	printf("请输入要查找的值\n");
	scanf("%d%d",child_values,child_values+1);
	father_node_stack con_father;       //定义栈和初始化栈
	con_father.top = father_node[-1];   //每次入栈都是先让栈顶指针先++，再放值，
	                                    //所以在放第一个值的时候top要退后一格
	con_father.bottom = father_node[0]; //指向栈底
	con_father.common_father = NULL;    //指向两个节点共同的父节点
    /*rugo返回值为null，说明找，否则没找到*/
	same_father_node =    
	   find_same_father(&con_father, root, child_values[0], child_values[1]);
	printf("%d\n",con_father.common_father->values);
	return 0;
}

#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int values;
    struct tree_node* left_child;
    struct tree_node* right_child;
}tree_node;

typedef struct lianbiao
{
	tree_node* node;
	struct lianbiao *pre;
}lianbiao;

typedef struct father_node_stack
{
	lianbiao *bottom;
   	lianbiao *top;
   	lianbiao *common_father;
}father_node_stack;

tree_node* create_tree(int *tree_level,int curr_level)
{
	int temp_values;
	scanf("%d",&temp_values);
	if (temp_values == 0)
	{
		return NULL;
	}
	if (curr_level > *tree_level)
	{
		*tree_level = curr_level;
	}
	tree_node *new_node = (tree_node *)malloc(1 * sizeof(tree_node));
    new_node->values = temp_values;
    new_node->left_child = create_tree(tree_level, curr_level+1);
    new_node->right_child = create_tree(tree_level, curr_level+1);
    return new_node;
}

/*遍历释放节点*/
void free_tree(tree_node *curr_node)
{
	if (curr_node != NULL)
	{
		free_tree(curr_node->left_child);
		free_tree(curr_node->right_child);
		free (curr_node);
		curr_node = NULL;
	}
}

void push_stack(tree_node *push_node,father_node_stack *con_father_stack)
{
	lianbiao* new_node=(lianbiao*)malloc(sizeof(lianbiao));
	new_node->node=push_node;
	if (con_father_stack->top==NULL)
	{
		con_father_stack->top=new_node;
		con_father_stack->bottom=new_node;
		new_node->pre=NULL;
	}
	else
	{
		new_node->pre=con_father_stack->top;
	    con_father_stack->top=new_node;
	}	
}

void pop_stack(father_node_stack *con_father_stack)
{
	if (con_father_stack->common_father == con_father_stack->top)
	{
		con_father_stack->common_father = con_father_stack->common_father->pre;
	}
	lianbiao *temp = con_father_stack->top;
	con_father_stack->top = con_father_stack->top->pre;
	free (temp);
	temp = NULL;
}

tree_node *find_same_father(father_node_stack *con_father_stack, tree_node *curr_node,
                              int child1_values, int child2_values)
{
	if (curr_node !=NULL)
	{
		push_stack(curr_node,con_father_stack);
		if ((curr_node->values == child1_values) || (curr_node->values == child2_values))
		{
			if (con_father_stack->common_father != NULL)
			{   
				return NULL;
			}
			con_father_stack->common_father = con_father_stack->top;
		}
		if(find_same_father(con_father_stack, curr_node->left_child, 
			                  child1_values,child2_values)==NULL)
		{
			return NULL;
		}
		if(find_same_father(con_father_stack, curr_node->right_child,
		                      child1_values,child2_values)==NULL)
		{
			return NULL;
		}
		 pop_stack(con_father_stack);
		return curr_node;
	}
	return con_father_stack;
}

int main(int argc, char const *argv[])
{
	int level=0;
	int *tree_level = &level;
	tree_node* root = NULL;
	root = create_tree(tree_level, 1);
	int child_values[2];
	printf("请输入要查找的值\n");
	scanf("%d%d",child_values,child_values+1);
	father_node_stack con_father;
	con_father.top = NULL;
	con_father.bottom= NULL;
	con_father.common_father=NULL;
	  if( find_same_father(&con_father, root, child_values[0], child_values[1]) == NULL)
	  {
	  	printf("zzzz%d\n",con_father.common_father->node->values);
	  }
	  else
	  {
	  	printf("not exist node:\n");
	  }
	return 0;
}
#endif
