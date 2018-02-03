#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
/*
list:列表容器.将元素按顺序储存在双链表中. 与向量(vectors)相比, 它允许快速的插入和删除,但是随机访问却比较慢
*/
void   print_list(list<int> l)
{
	list<int>::iterator  it;
	for(it=l.begin();it!=l.end();it++)
	//for(it=l.begin();it<l.end();it++)
	{
		cout<<*it<<"\t";
	}
	cout<<endl;
}

//定义排序类型函数(排序谓词)
template<class T>
bool  compare(T a,T b)
{
	return a>b;
}


//定义删除的一元谓词
template<class T>
bool  delete_if(T  value)
{
  return value>20;
}
int main(int argc, char const *argv[])
{
	list<int> l1;
	list<int> l2(5,8);
	// int a[]={1,2,3,4,5};
	// list<int> l3(a+0,a+5);
	// list<int> l4(l3.begin(),l3.end());
	// //print_list(l2);
	// print_list(l4);

	l1.push_back(12);
	l1.push_back(23);
	l1.push_back(34);
	l1.push_front(4);
	l1.push_front(1);
	//l1.push_front(34);
	//print_list(l1);
    //l1.merge(l2);//两个有序的链表合并成一个有序链表
    //l1.merge(l2,compare<int>);//实现是改变默认做法
	//cout<<l1.size()<<endl;
	//l1.remove(23);
	//l1.remove_if(delete_if<int>);
	//l1.reverse();
	//l1.sort(compare<int>);//默认是升序,compare<int> 称为排序谓词,改变排序方向
	//l1.unique();//针对有序链表有效
	//print_list(l1);

	list<int>::iterator it_ret=find(l1.begin(),l1.end(),12);//自定义list容器实现find成员方法
	if(it_ret==l1.end())
	{
		cout<<"not found"<<endl;
	}
	//l1.erase(it_ret);
	list<int>::iterator it_ret_2=find(l1.begin(),l1.end(),34);
	if(it_ret_2==l1.end())
	{
		cout<<"not found"<<endl;
	}
	//l1.erase(it_ret,it_ret_2);
	//l1.erase(it_ret,it_ret+2);//系统不支持,可以自定实现此功能
	//l1.insert(it_ret,100);
	//l1.insert(it_ret,5,100);
	l1.insert(it_ret,l2.begin(),l2.end());
	print_list(l1);
	return 0;
}