#include <iostream>
#include <list>
using namespace std;
/*
链表容器(列表容器):list
list容器:list将元素按顺序储存在双链表中,将非连续元素形成一种顺序结构.插入删除元素时效率较高,但随机访问时效率较低.
链表容器元素是由每个节点组成

list容器构造:
list<T>()
list<T>(n,value)
list<T>(cosnt list&)
list<T>(list::iterator begin,list::iterator end)
*/
//一般迭代器输出容器元素
void  print_elements(list<int> l)
{
	list<int>::iterator  it;
	for(it=l.begin();it!=l.end();it++)
	{
		cout<<*it<<'\t';
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	list<int> l1;
	list<int> l2(3,8);
	list<int> l3(l2);
	list<int> l4(l2.bgin(),l2.end());
	print_elements(l2);
	return 0;
}