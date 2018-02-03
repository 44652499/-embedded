#include <stdio.h>
#include <stdlib.h>
typedef struct tree_node
{
        int data;
        struct tree_node * left;
        struct tree_node* right;
}tree_node;

void  sort_array_data(int * array,int len)
{
        int i,j;
        for(i=0;i<len;i++)
        {
                for(j=0;j<len-i-1;j++)
                {
                        if(array[j]>array[j+1])
                        {
                                int temp=array[j];
                                array[j]=array[j+1];
                                array[j+1]=temp;
                        }
                }
        }
}

tree_node *  init_haffman_tree(int * array,int len)
{
        tree_node * root;
        tree_node ** ptr_arrray;
        ptr_arrray=(tree_node **)malloc(len*sizeof(tree_node*));
        if(ptr_arrray==NULL)
        {
                printf("malloc error\n");
                return;
        }
        int i;
        for(i=0;i<len;i++)
        {
                tree_node * new_tree_node=(tree_node*)malloc(1*sizeof(tree_node));
                if(new_tree_node==NULL)
                {
                        printf("malloc fail \n");
                        return;
                }
                new_tree_node->data=array[i];
                new_tree_node->right=NULL;
                new_tree_node->left=NULL;
                ptr_arrray[i]=new_tree_node;
        }
        int j=0;
        i=0;
        while(1)
        {
                root=(tree_node*)malloc(1*sizeof(tree_node));
                root->data=ptr_arrray[i]->data+ptr_arrray[i+1]->data;
                root->left=ptr_arrray[i];
                root->right=ptr_arrray[i+1];
                for(j=i+2;j<len;j++)
                {
                        if(ptr_arrray[j]->data<root->data)
                        {
                                 ptr_arrray[j-1]=ptr_arrray[j];
                        }
                        else
                        {
                                ptr_arrray[j]=root;
                        }
                }
                if(j==len)
                {
                        ptr_arrray[j-1]=root;
                }
                i++;
                if(i==len-1)
                {
                        break;
                }
        }
        if(ptr_arrray!=NULL)
        {
                free(ptr_arrray);
                ptr_arrray=NULL;
        }
        return root;
}

void get_haffman_code(tree_node* root,int len)
{
        static int haffman_code[10];
        if(root->left==NULL && root->right==NULL)
        {
                int i;
                for(i=0;i<len;i++)
                {
                        printf("node data:%d\thaffman code:%d\n",root->data,haffman_code[i]);
                }
                printf("\n");
        }
        else
        {
                haffman_code[len]=0;
                get_haffman_code(root->left,len+1);
                haffman_code[len]=1;
                get_haffman_code(root->right,len+1);
        }
}
int   get_haffman_weight(tree_node * root,int len)
{
        if(root==NULL)
                return ;
        if(root->left==NULL && root->right==NULL)
        {
                return root->data*len;
        }
        else
        {
                return get_haffman_weight(root->left,len+1)+get_haffman_weight(root->right,len+1);
        }
}
void  mid_output_tree(tree_node* root)
{
        if(root!=NULL)
        {
                mid_output_tree(root->left);
                printf("%d\t",root->data);
                mid_output_tree(root->right);
        }
}
int    main(int argv,const char* argc[])
{
        int  a[]={3,9,5,12,6,15};
        sort_array_data(a,6);
	tree_node * root=init_haffman_tree(a,6);
        mid_output_tree(root);
        printf("\n");
        get_haffman_code(root,0);
        printf("%d\n",get_haffman_weight(root,0));
        return 0;
}
