#include <iostream>
#define  N   50
using namespace std;
/*
hash表:称为散列表,是一种线性结构,通过key-->value(键值)管理存储元素.访问时根据一个散列函数f(key,value),计算出值位置.
hash函数key  value 关系函数.存储 搜索时使用该函数计算位置
hash表一般用来查找,提高查找效率

hash表缺陷:
1.元素分配不均匀
2.浪费空间
3.容易出现冲突
hash函数算法有多种,选择时根据实际数据选一种尽量避免冲突发生
常用hash函数算法:
1.常数法
2.平方法
3.余数法
4.数字分析法
5.重叠法
6.随机法
设计hash表示必须要设计一个方法解决冲突:
1.多次hash
2.拉链法(链表)

*/
//使用简单hash表排序:
// void  hash_sort()
// {
// 	int a[]={1,45,7,9,21,32,15};
// 	int* ptr_table=new int[46];
// 	int i;
// 	for(i=0;i<7;i++)
// 	{
// 		ptr_table[a[i]]=a[i];
// 	}
// 	for(i=0;i<46;i++)
// 	{
// 		if(ptr_table[i]!=0)
// 		{
// 			cout<<ptr_table[i]<<endl;
// 		}
// 	}
//
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
		Node*  ptr_table=hash_table[key];
		if(ptr_table==NULL)
		{
			hash_table[key]=ptr_new;
		}
		else
		{
			//可以优化成不需要循环获取链表尾节点位置(张奇演示)
			Node* ptr_move=ptr_table;
			while(ptr_move->next!=NULL)
			{
				ptr_move=ptr_move->next;
			}
			ptr_move->next=ptr_new;
			ptr_move=ptr_new;
			ptr_new=NULL;
		}
	}

	void  hash_print()
	{
		int i ;
		for(i=0;i<N;i++)
		{
			if(hash_table[i]!=NULL)
			{
				Node * ptr_move=hash_table[i];
				while(ptr_move!=NULL)
				{
					cout<<ptr_move->node_value<<"\t";
					ptr_move=ptr_move->next;
				}
				cout<<endl;
			}			
		}
	}
	//作业实现hash查找 ,删除(陶杰成演示)
private:
	Node*  hash_table[N];
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
	return 0;
}