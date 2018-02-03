#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#define  N 20
//员工结构
typedef  struct employ
{
        int emp_id;
        char emp_name[20];
        char  emp_sex;
        int emp_salary;
        int depart_id;
        struct employ  *  left;
        struct employ  *  right;
}employ;
9882

//部门结构
typedef struct department
{
        int depart_id;
        char depart_name[10];
}department;

//hash表中存储部门结构信息
typedef struct  depart_hash
{
         department  depart;
         employ  *  left;
         employ  *  right;
}depart_hash;

//定义部门hash表
depart_hash   g_depart_hash_table[N];
//
int   g_index=0;

//初始化每个部分信息
void  init_department_info(department * ptr_depart,int depart_id,char *  depart_name)
{
        ptr_depart->depart_id=depart_id;
        strcpy(ptr_depart->depart_name,depart_name);
}

//初始化部门数据信息
department*   init_department_data(int   size)
{
        department *  ptr_depart=(department*)malloc(size*sizeof(department));
        init_department_info(&ptr_depart[0],1,"departA");
        init_department_info(&ptr_depart[1],2,"departB");
        init_department_info(&ptr_depart[2],3,"departC");
        init_department_info(&ptr_depart[3],4,"departD");
        return  ptr_depart;
}
//初始化员工信息
void  init_employ_info(employ*  ptr_employ,int emp_id,char * emp_name,char emp_sex,int emp_salary,int emp_depart)
{
        ptr_employ->emp_id=emp_id;
        strcpy(ptr_employ->emp_name,"work1");
        ptr_employ->emp_sex=emp_sex;
        ptr_employ->emp_salary=emp_salary;
        ptr_employ->depart_id=emp_depart;
}
//初始化员工数据
employ*   init_employ_data(int size)
{
        employ * ptr_employ=(employ*)malloc(size*sizeof(employ));
        init_employ_info(&ptr_employ[0],1112,"work1",'f',5000,2);
        init_employ_info(&ptr_employ[1],1119,"work9",'m',5000,3);
        init_employ_info(&ptr_employ[2],1345,"work8",'f',4000,1);
        init_employ_info(&ptr_employ[3],2567,"work11",'m',3000,4);
        init_employ_info(&ptr_employ[4],3214,"work2",'f',2000,1);
        init_employ_info(&ptr_employ[5],4321,"work4",'m',3400,4);
        init_employ_info(&ptr_employ[6],9999,"work11",'f',7800,2);
        init_employ_info(&ptr_employ[7],1190,"work12",'m',5000,3);
        init_employ_info(&ptr_employ[8],4563,"work1",'f',1230,2);
        init_employ_info(&ptr_employ[9],2901,"work1",'f',6789,2);
        init_employ_info(&ptr_employ[10],3567,"work1",'f',5120,1);
        init_employ_info(&ptr_employ[11],6231,"work1",'m',9761,3);
        init_employ_info(&ptr_employ[12],7543,"work1",'f',3214,3);
        init_employ_info(&ptr_employ[13],1001,"work1",'m',3215,1);
        init_employ_info(&ptr_employ[14],2131,"work1",'m',6000,4);
        init_employ_info(&ptr_employ[15],3452,"a11",'m',1236,2);
        return  ptr_employ;
}
//hash函数
int   hash_key(int  depart_id)
{
        return depart_id;
}
//将部门信息存入hash表,以部门编号作为hash表的key
void   save_depart_hash_table(department  * ptr_depart)
{
        if(ptr_depart!=NULL)
        {
                int key=hash_key(ptr_depart->depart_id);
                depart_hash  de_hash;
                de_hash.depart=*ptr_depart;
                de_hash.left=NULL;
                de_hash.right=NULL;
                g_depart_hash_table[key]=de_hash;
                g_index++;
        }
}
//构建员工树
 void   init_employ_sub_tree(depart_hash* ptr_hash,employ * root,employ *ptr_employ)
 {
         if(root!=NULL)
         {
                 if(root->left==NULL &&  root->emp_id>ptr_employ->emp_id)
                 {
                         root->left=ptr_employ;
                 }
                 if(root->right==NULL && root->emp_id<ptr_employ->emp_id)
                 {
                         root->right=ptr_employ;
                 }
                 if(root->left!=NULL && root->emp_id>ptr_employ->emp_id)
                 {
                         init_employ_sub_tree(ptr_hash,root->left,ptr_employ);
                 }
                 if(root->right!=NULL && root->emp_id<ptr_employ->emp_id)
                 {
                        init_employ_sub_tree(ptr_hash,root->right,ptr_employ);
                 }
         }
         else
         {
                 root=ptr_employ;
                 ptr_hash->left=root;
                 ptr_hash->right=NULL;
         }
 }
 
 //判断员工子树是否只有左孩子
 int   is_all_left_child(employ * root)
 {
         int   is_all_left=1;
         while(root!=NULL)
         {
                 if(root->right!=NULL)
                 {
                         is_all_left=0;
                         break;
                 }
                 root=root->left;
         }
         return  is_all_left;
 }
//判断员工子树是否只有右孩子
int   is_all_right_child(employ * root)
 {
        int   is_all_right=1;
        while(root!=NULL)
        {
                if(root->left!=NULL)
                {
                        is_all_right=0;
                        break;
                }
                root=root->right;
        }
        return is_all_right;
 }
 //如果全是左孩子或是右孩子,计算出左孩子与右孩子的层次数,方便后序的旋转
 int   get_left_child_count(employ* root)
 {
         int  cnt=0;
         if(is_all_left_child(root))
         {
                 while(root!=NULL)
                 {
                         cnt++;
                         root=root->left;
                 }
         }
         return cnt;
 }
 //如果全是左孩子或是右孩子,计算出左孩子与右孩子的层次数,方便后序的旋转
 int   get_right_child_count(employ* root)
 {
         int  cnt=0;
         if(is_all_right_child(root))
         {
                 while(root!=NULL)
                 {
                         cnt++;
                         root=root->right;
                 }
         }
         return cnt;
 }
 //如果全是左孩子或是有孩子应该旋转成一颗有左右孩子的树,但不要求是平衡树
 void   rotate_tree(depart_hash * ptr_depart)
 {
         employ *  root=ptr_depart->left;
         int left_cnt=get_left_child_count(root);
         int right_cnt=get_right_child_count(root);
         //printf("left_cnt=%d\tright_cnt=%d\n",left_cnt,right_cnt);
         int mid_cnt=0;
         employ * temp=NULL;
         if(left_cnt>2)
         {
                 mid_cnt=0;
                 mid_cnt=left_cnt/2;
                 while(mid_cnt>=1)
                 {
                         temp=root;
                         root=root->left;
                         root->right=temp;
                         temp->left=NULL;
                         mid_cnt--;
                 }
                ptr_depart->left=root;
         }
         if(right_cnt>2)
         {
                mid_cnt=0;
                mid_cnt=right_cnt/2;
                while(mid_cnt>=1)
                {
                        temp=root;
                        root=root->right;
                        root->left=temp;
                        temp->right=NULL;
                        mid_cnt--;
                }  
                ptr_depart->left=root;
         }
 }
 //构建部门hash表域员工树
employ * insert_employ_hash_table(employ *ptr_employ)
 {
         employ * root;
         if(ptr_employ!=NULL)
         {
                 int key=hash_key(ptr_employ->depart_id);
                 root=g_depart_hash_table[key].left;
                 init_employ_sub_tree(&g_depart_hash_table[key],root,ptr_employ);      
                 rotate_tree(&g_depart_hash_table[key]);//修改之处,原因是旋转树之后并没有改变hash表中的存储树的根节点.感谢陈旺高同学的意见!!!!!                  
         }
         return root;
 }
 //输出员工信息
 void  print_employ_info(employ * root)
 {
         if(root!=NULL)
         {
                 //
                 printf("%d\t%s\t%c\t%d\t%d\n",root->emp_id,root->emp_name,root->emp_sex,root->emp_salary,root->depart_id);   
                 print_employ_info(root->left);            
                 print_employ_info(root->right);
         }
 }
 //输出部门与员工信息
 void  print_depart_info()
 {
         int i;
         for(i=1;i<=g_index;i++)
         {
                 printf("depart_id=%d\tdepart_name=%s\n",g_depart_hash_table[i].depart.depart_id,g_depart_hash_table[i].depart.depart_name);
                 if(g_depart_hash_table[i].left!=NULL)
                 {
                         print_employ_info(g_depart_hash_table[i].left);
                 }                 
         }
 }
 
int main(int argc,const char* argv[])
{
        department*  ptr_depart=init_department_data(4);
        int i;
        for(i=0;i<4;i++)
        {
                save_depart_hash_table(&ptr_depart[i]);
        }
        employ*   ptr_employ=init_employ_data(16);
        employ* root;
        for(i=0;i<16;i++)
        {
             root=insert_employ_hash_table(&ptr_employ[i]);
        }
        //rotate_tree(root);//旋转   之前的写法有一个严重的漏洞
        print_depart_info();
        return 0;
}
