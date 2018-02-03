#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  N 20
typedef int (*HASH_FUN)(const char* ch);
//定义hash表存储元素类型(解决冲突链表节点)
typedef struct node
{
    char ch_value[100];
    struct node * next;
}node;
node **  init_hash_table()
{
    node ** hash_table=(node **)malloc(N*sizeof(node*));
  //node *  hash_table[N];
   int i;
   for(i=0;i<N;i++)
   {
       hash_table[i]=NULL;
   }
    return hash_table;
}

void  insert_hash_table(const char * ch,node** hash_table,HASH_FUN hash_fun)
{
    int key=hash_fun(ch);
    node*  ptr_new=(node*)malloc(1*sizeof(node));
    strcpy(ptr_new->ch_value,ch);
    ptr_new->next=NULL;

    node*  ptr_tmp=hash_table[key];
    if(ptr_tmp==NULL)
    {
        hash_table[key]=ptr_new;
    }
    else
    {
        //缺点:每次都要循环冲突链表,但是不能新的节点存放在前面(李熙博解决)
        while(ptr_tmp->next!=NULL)
        {
            ptr_tmp=ptr_tmp->next;
        }
        ptr_tmp->next=ptr_new;
    }
    ptr_tmp=NULL;
    ptr_new=NULL;
}

void  print_hash_table(node** hash_table)
{
    int i;
    for(i=0;i<N;i++)
    {
        node* ptr_tmp=hash_table[i];
        if(ptr_tmp!=NULL)
        {
            while(ptr_tmp!=NULL)
            {
                printf("%s\t",ptr_tmp->ch_value);
                ptr_tmp=ptr_tmp->next;
            }
        }
        printf("\n");
    }
}

//定义hash 函数
int  hash_fun(const char*  ch)
{
    int i;
    int sum=0;
    for(i=0;i<strlen(ch);i++)
    {
        sum+=ch[i];
    }
    return sum%N;
}
//实现查找函数
//实现删除函数(在删除函数中调用查找函数)

int main(int argc,const char* argv[])
{
    node** hash_table=init_hash_table();
    insert_hash_table("abcd",hash_table,hash_fun);
    insert_hash_table("234234",hash_table,hash_fun);
    insert_hash_table("adfdsfererwe",hash_table,hash_fun);
    insert_hash_table("sdfdf234324",hash_table,hash_fun);
    insert_hash_table("dsfds",hash_table,hash_fun);
    insert_hash_table("122423",hash_table,hash_fun);
    insert_hash_table("a3453428",hash_table,hash_fun);
    insert_hash_table("akljlkklj",hash_table,hash_fun);
    insert_hash_table("99999",hash_table,hash_fun);
    insert_hash_table("991919",hash_table,hash_fun);
    insert_hash_table("0000000",hash_table,hash_fun);
    insert_hash_table("11111p-00",hash_table,hash_fun);
    print_hash_table(hash_table);
    return 0;
}
//fopen  fwrite fread
//以上hash 表结构建好之后,把整个hash表存储到文件