#include <iostream>
#define  N   50
using namespace std;
//实现一个hash表,拉链法解决冲突

class Node
{
friend class  HashTable;
public:
	Node(string _node_value)
	{
		node_value=_node_value;
		next=NULL;
	}
private:
	string node_value;
	Node * next;
};
//定义记录链表起始 终止节点地址结构
class Pair
{
public:
	Pair()
	{
		ptr_head=NULL;
		ptr_tail=NULL;
	}
	Node* ptr_head;
	Node* ptr_tail;
};

//定义存放查找结果类型
class ResultType
{
public:
	ResultType()
	{
		is_find=false;
		ptr_result_prenode=NULL;
		ptr_result_node=NULL;
	}
	bool  is_find;
	Node* ptr_result_prenode;
	Node* ptr_result_node;
};


class  HashTable
{
public:
	HashTable()
	{
		int i;
		for(i=0;i<N;i++)
		{
			hash_table[i]=NULL;
		}
	}
	int hash_fun(string  value)
	{
		int sum=0;
		int i;
		for(i=0;i<value.length();i++)
		{
			sum+=value[i];
		}
		return  sum%N;
	}

	void  hash_insert(string value)
	{
		int key=hash_fun(value);
		Node*  ptr_new=new Node(value);
		Pair*  ptr_pair=hash_table[key];
		if(ptr_pair==NULL)
		{
			Pair *  ptr_new_pair=new Pair;
			ptr_new_pair->ptr_head=ptr_new;
			ptr_new_pair->ptr_tail=ptr_new;
			hash_table[key]=ptr_new_pair;
		}
		else
		{		
			ptr_pair->ptr_tail->next=ptr_new;
			ptr_pair->ptr_tail=ptr_new;
		}
	}
	ResultType* hash_find(string dest_value)
	{
		ResultType* ptr_result=new  ResultType;
		int key=hash_fun(dest_value);
		Pair*  ptr_pair=hash_table[key];
		if(ptr_pair==NULL)
		{
			return ptr_result;
		}
		else
		{
			Node* ptr_move=ptr_pair->ptr_head;
			Node* ptr_tmp=NULL;
			while(ptr_move!=NULL)
			{
				if(ptr_move->node_value==dest_value)
				{
					if(ptr_move==ptr_pair->ptr_head)
					{
						ptr_result->is_find=true;
						ptr_result->ptr_result_node=ptr_move;
					}
					else
					{
						ptr_result->is_find=true;
						ptr_result->ptr_result_node=ptr_move;
						ptr_result->ptr_result_prenode=ptr_tmp;
						ptr_tmp=NULL;
					}
					break;
				}
				else
				{
					ptr_tmp=ptr_move;
				}
				ptr_move=ptr_move->next;
			}
			return ptr_result;
		}
	}

	void  hash_delete(string dest_value)
	{
		ResultType*  ptr_result=hash_find(dest_value);
		if(!ptr_result->is_find)
		{
			cout<<"not found"<<endl;
			return;
		}
		Pair* ptr_pair=hash_table[hash_fun(dest_value)];
		if(ptr_result->ptr_result_prenode==NULL)
		{
			if(ptr_result->ptr_result_node->next==NULL)
			{
				ptr_pair->ptr_tail=NULL;
				ptr_pair->ptr_head=NULL;
				hash_table[hash_fun(dest_value)]=NULL;	
				delete  ptr_pair;
				ptr_pair=NULL;			
			}
			else
			{
				ptr_pair->ptr_head=ptr_result->ptr_result_node->next;
				delete ptr_result->ptr_result_node;
				ptr_result->ptr_result_node=NULL;				
			}
			return;			
		}
		if(ptr_result->ptr_result_node->next==NULL)
		{
			ptr_pair->ptr_tail=ptr_result->ptr_result_prenode;
		}
		ptr_result->ptr_result_prenode->next=ptr_result->ptr_result_node->next;
		delete ptr_result->ptr_result_node;
		ptr_result->ptr_result_node=NULL;	
	}

	void  hash_print()
	{
		int i ;
		for(i=0;i<N;i++)
		{
			if(hash_table[i]!=NULL)
			{
				Pair * ptr_pair=hash_table[i];
				Node* ptr_move=ptr_pair->ptr_head;
				while(ptr_move!=NULL)
				{
					cout<<ptr_move->node_value<<"\t";
					ptr_move=ptr_move->next;
				}
				cout<<endl;
			}			
		}
	}
private:
	Pair*  hash_table[N];
};

int main(int argc, char const *argv[])
{
	HashTable  hashtable;
	hashtable.hash_insert("qwerqwewqe");
	hashtable.hash_insert("123123");
	hashtable.hash_insert("sdfsdf");
	hashtable.hash_insert("567657");
	hashtable.hash_insert("fghfgh");
	hashtable.hash_insert("789789");
	hashtable.hash_insert("zxcxzc");
	hashtable.hash_insert("534634");
	hashtable.hash_insert("sdf3e4w5r345");
	hashtable.hash_insert("ghjhgj");
	hashtable.hash_insert("bnmnbm");
	hashtable.hash_insert("56765765");
	hashtable.hash_insert("sdfdsf343");
	hashtable.hash_insert("888rfgfdg");
	hashtable.hash_insert("12321cdvfdg");
	hashtable.hash_insert("56765fddfdf32");
	hashtable.hash_insert("32423sdf4");
	hashtable.hash_insert("789789");
	hashtable.hash_print();

	// ResultType *  ptr_result=hashtable.hash_find("56765761");
	// if(ptr_result->is_find)
	// {
	// 	cout<<"find ok"<<endl;
	// }
	// else
	// {
	// 	cout<<"not find"<<endl;
	// }
	hashtable.hash_delete("sdf3e4w5r345");
    hashtable.hash_print();
	hashtable.hash_insert("sdf3e4w5r345");
    hashtable.hash_print();
	
	return 0;
}