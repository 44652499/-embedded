#include <stdio.h>
#include <stdlib.h>
#define LX  1
#define EX  0
#define RX  -1
#define TRUE  1
#define FALSE  -1
typedef struct avl_tree_node
{
        int data;
        int bf;
        struct avl_tree_node * lchild;
        struct avl_tree_node * rchild;
}avl_tree_node;

void  print_error(char * title,char *msg)
{
        printf("%s:%s\n",title,msg);
        return;
}
void R_rotate(avl_tree_node * p)
{
        avl_tree_node * l;
        l=p->lchild;
        p->lchild=l->rchild;
        l-rchild=p;
        p=l;
}

void L_rotate(avl_tree_node * p)
{
        avl_tree_node *r;
        r=p->rchild;
        p->rchild=r->lchild;
        r-lchild=p;
        p=r;
}
void leftbanlance(avl_tree_node* root)
{
        avl_tree_node * lc,*lr;
        lc=root->lchild;

        switch(lc->bf)
        {
                case LX: 
                        {
                                root->bf=EX;
                                lc->bf=EX;
                                R_rotate(root);
                                break;
                        }
                case RX:
                        {
                                lr=lc->rchild;
                                switch(lr->bf)
                                {
                                        case LX:
                                                {
                                                        root->bf=RX;
                                                        lc->bf=EX;
                                                        break;
                                                }
                                        case EX:
                                                {
                                                        root->bf=EX;
                                                        lc->bf=LX;
                                                        break;
                                                }
                                        case RX:
                                                {
                                                        root->bf=EX;
                                                        lc->bf=LX;
                                                        break;
                                                }
                                        lr->bf=EX;
                                        L_rotate(root->lchild);
                                        //R_rotate(root);
                                }
                        }
        }
}

rightbalance(avl_tree_node* root)
{

}

int   insertAVL(avl_tree_node* root,int value,int *taller)
{
        if(root==NULL)
        {
                root=(avl_tree_node*)malloc(sizeof(avl_tree_node));
                root->data=value;
                root->lchild=NULL;
                root->rchild=NULL;
                root->bf=;
                *taller=TRUE;
        }
        else
        {
                if(value==root->data)
                {
                        *taller=FALSE;
                        return FALSE;
                }
                if(value<root->data)
                {
                        if(!insertAVL(root->lchild,value,taller))
                        {
                                return FALSE;
                        }
                        if(*taller)
                        {
                                switch(root->bf)
                                {
                                        case LX:
                                                {
                                                        leftbanlance(root);
                                                        *taller=FALSE;
                                                        break;
                                                }
                                        case RX:
                                                {
                                                        root->bf=EX;
                                                        *taller=false;
                                                        break;
                                                }
                                        case EX:
                                                {
                                                        root->bf=LX;
                                                        *taller=TRUE;
                                                        break;
                                                }
                                }
                        }
                }
                else
                {
                        if(!insertAVL(root->rchild,value,taller))
                        {
                                return FALSE;
                        }
                        if(*taller)
                        {
                                switch(root->bf)
                                {
                                        case LX:
                                                {
                                                        root->bf=EX;
                                                        *taller=FALSE;
                                                        break;
                                                }
                                        case RX:
                                                {
                                                        rightbalance(root);
                                                        *taller=FALSE;
                                                        break;
                                                }
                                        case EX:
                                                {
                                                        root->bf=RX;
                                                        *taller=TRUE;
                                                        break;
                                                }
                                }
                        }
                }
        }
}
int main(int argc ,const char * argv[])
{
        return 0;
}