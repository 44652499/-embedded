#include <stdio.h>
#include <stdlib.h>
typedef struct avl_tree_node
{
        int data;
        int bf;
        struct avl_tree_node * left;
        struct avl_tree_node * right;
}avl_tree_node;

void  print_error(char * title,char *msg)
{
        printf("%s:%s\n",title,msg);
        return;
}

void  trun_left_left(avl_tree_node * root)
{
        avl_tree_node * temp=root->left;
        root->left=temp->right;
        temp->right=root;
        root=temp;
}

void  trun_right_right(avl_tree_node* root)
{
        avl_tree_node * temp=root->right;
        roo->right=temp->left;
        temp->left=root;
        root=temp;
}

void  trun_right_left(avl_tree_node* root)
{
        avl_tree_node * p1,*p2;
        p1=root->right;
        p2=p1->left;
        root->right=p2->left;
        p1->lchild=p2->rchild;
	p2->lchild=root;
        p2->right=p1;
	root=p2;
}

void   trun_left_right(avl_tree_node * root)
{
        avl_tree_node* p1,*p2;
	p1 = root->lchild;
	p2 = p1->rchild;
	p1->rchild = p2->lchild;
	root->lchild = p2->rchild;
	p2->lchild = p1;
	p2->rchild =root;
	root = p2;
}

void  lbanlance_avl_tree(avl_tree_node * root)
{
        avl_tree_node * lp_tree_node=root->left;
        avl_tree_node* temp;
        switch(lp_tree_node->bf)
        {
                case -1:
                {
                      temp=lp_tree_node->right;
                      switch(temp->bf)
                      {
                              case 1:
                                       {
                                               root->bf=-1;
                                               lp_tree_node->bf=0;
                                               break;
                                       }
                              case 0:
                                      {
                                              root->bf=0;
                                              lp_tree_node->bf=0;
                                              break;
                                      }
                              case -1:
                                      {
                                              root->bf=0;
                                              lp_tree_node->bf=1;
                                              break;
                                      }
                      }
                      lp_tree_node->bf=0;
                      trun_left_right(root);
                }
                case 0:
                {
                        root->bf=1;
                        lp_tree_node->bf=-1;
                        trun_left_left(root);
                        break;
                }
                case 1:
                {
                        root->bf=0;
                        lp_tree_node->bf=0;
                        trun_left_left(root);
                        break;
                }
        }
}

void  rbanlance_avl_tree(avl_tree_node * root)
{
        avl_tree_node * rc=root->left;
        avl_tree_node * lp_tree_node;
        switch(rc->bf)
        {
                case -1:
                {
                        root->bf=0;
                        rc->bf=0;
                        trun_right_right(root);
                        break;
                }
                case 0:
                {
                        root->bf=-1;
                        rc->bf=1;
                        trun_right_right(root);
                        break;
                }
                case 1:
                {
                        lp_tree_node=rc->left;
                        switch(lp_tree_node->bf)
                        {
                                case 1:
                                        root->bf=0;
                                        rc->bf=-1;
                                        break;
                                case 0:
                                        root->bf=0;
                                        rc->bf=0;
                                        break;
                                case -1:
                                        root->bf=1;
                                        rc->bf=0;
                                        break;
                        }
                        lp_tree_node->bf=0;
                        trun_right_left(root);
                        break;
                }
        }
}

int   insert_avl_tree(avl_tree_node* root,int  value,int *taller)
{
        avl_tree_node * new_node=(avl_tree_node*)malloc(1*sizeof(avl_tree_node));
        if(new_node==NULL)
        {
                print_error("insert_avl_tree","new_node malloc fail");
        }
        new_node->data=value;
        new_node->left=NULL;
        new_node->right=NULL;
        new_node->bf=0;
        if(root==NULL)
        {
                root=new_node;
                new_node=NULL;
                taller=1;
                return 1;
        }
        if(value==root->data)
        {
                taller=0;
                return 0;
        }
        if(value<root->data)
        {
                if(insert_avl_tree(root->left,value,taller)==0)
                {
                        print_error("insert_avl_tree","insert_avl_tree left child  fail ");
                        return 0;
                }
                if(*taller==1)
                {
                        switch(root->bf)
                        {
                                case -1:
                                        root->bf=0;
                                        *taller=0;
                                        break;
                                case 0:
                                        root->bf=1;
                                        *taller=1;
                                        break;
                                case 1:
                                        lbanlance_avl_tree(root);
                                        *taller=0;
                                        break;
                        }
                }
        }
        if(value>root->data)
        {
                if(insert_avl_tree(root->right,data,taller)==0)
                {
                        return 0;
                }
                if(*taller==1)
                {
                        switch(root->bf)
                        {
                                case 1:
                                        {
                                                root->bf=0;
                                                *taller=0;
                                                break;
                                        }
                                case 0:
                                        {
                                                root->bf=-1;
                                                *taller=1;
                                                break;
                                        }
                                case -1:
                                        {
                                                rbanlance_avl_tree(root);
                                                *taller=0;
                                                break;
                                        }
                        }
                }
        }
        return 1;
}

int   get_deepth(avl_tree_node * root)
{
        int max,hl,hr;
        if(root==NULL)
        {
                return 0;
        }
        else
        {
                hl=get_deepth(root->left);
                hr=get_deepth(root->right);
                return max=(hl>hr?hl:hr)+1;
        }
}
void  display_avl_tree(avl_tree_node* root,int deepth,char ch)
{
        int i;
        if(root)
        {
                for(i=0;i<deepth+1;i++)
                {
                        printf("----");
                }
                printf("+%d(%c)(%d)\n",root->data,ch,root->bf);
                display_avl_tree(root->left,--deepth,'L');
                display_avl_tree(root->right,deepth,'R');
        }
}

void   print_mid_tree(avl_tree_node* root)
{
        if(root)
        {
                print_mid_tree(root->left);
                printf("%d",root->data);
                print_mid_tree(root->right);
        }
}

avl_tree_node*  init_avl_tree()
{
        int value;
        char exit_ch;
        avl_tree_node* root=NULL;
        printf("please input one int data and one space,enter is over\n");
        while(1)
        {
                scanf("%d",&value);
                exit_ch=getchar();     
                if(exit_ch==10)
                {
                        break;
                }
        }
        return root;
}

int main(int argc ,const char * argv[])
{
        avl_tree_node *  root;
        int select;
        while(1)
        {
                printf("1.create tree\n2.insert node to tree\n3.delete node from tree\n");
                scanf("%d",&select);
                if(select==1)
                {

                }
                if(select==2)
                {

                }
                if(select==3)
                {

                }
        }
        return 0;
}
