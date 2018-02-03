#include <iostream>
#include <map>
#include <utility> //可以不用重新声明 因为<map>中已经包含了<utility>的声明了
	//该程序抛出异常部分 未完善
	//一个map容器包括:关键字/值  pair类型
	//键值(key):可以是任意数据类型,只读,不重复,有序
	//值(value):任意数据类型
	//map必须有一个默认的构造
#include "d_rb_tree.h"

template <class T>
class rbtree;

template <class Key, class T>
class Map
{

public:
	typedef pair<Key, T> value_type;//Key 可以为 const Key 表示只读对Key

	typedef rbtree<value_type>::iterator iterator;
		//typedef rbtree<pair<Key, T> >::iterator it;//报错
		// 注意：内部类是一个编译时的概念，一旦编译成功，就会成为完全不同的两类。 
		// 对于一个名为outer的外部类和其内部定义的名为inner的内部类。编译完成后出现 
		// 	所以在一个类中调用另一个外部类的内部类就需要直接调用内部类 std::iterator<Key, T> 
		//而不是rbtree<pair<Key, T> >::iterator
	//typedef std::iterator<Key, T> iterator;
	
	
	// Map();
	// 	//定义map无参数构造

	// Map(value_type *first, value_type *last);
	// 	//一个pair类型的数组。其中的两个指针[first, last)

	// Map(const Map<Key, T>& obj);
	// 	//对象构造

	// ~Map();
	// 	//析构函数

	// iterator begin()
	// {
	// 	return t.begin();
	// }
	// 	//begin()函数返回一个迭代器指向map的首部。

 //  	iterator end()
 //  	{
 //  		return t.end();	
 //  	}
		//end()函数返回一个迭代器指向map的尾部。

	// void clear();
	// 	//
		
 //  	int count(const Key &key);
 //  		//count()函数返回map中键值等于key的元素的个数。
  
 //  	bool empty();
	// 	//empty()函数返回真(true)如果map为空，否则返回假(false)。

 //  	iterator equal_range(const Key &key);
	// 	//equal_range()函数返回两个迭代器——一个指向第一个键值为key的元素，另一个指向最后一个键值为key的元素。

 //  	void erase(iterator pos);
  	
 //  	void erase(iterator start, iterator end);
  	
 //  	int erase(const Key &key);

 //  	pair<iterator, iterator> find(const Key &key);
	// 	//find()函数返回一个迭代器指向键值为key的元素，如果没找到就返回指向map尾部的迭代器。

 // 	// iterator insert(iterator pos, const pair<Key, T> &val);
 // 	// void insert(iterator start, iterator end);  //无意义 插入后还要排序

 // 	pair<Map<Key, T>::iterator, bool> insert(const pair<Key, T> &val);

 	// iterator lower_bound(const Key &key);
		// //lower_bound()函数返回一个迭代器，指向map中键值>=key的第一个元素。

  // 	reverse_iterator rbegin();
		// //rbegin()函数返回一个指向map尾部的逆向迭代器。

  // 	reverse_iterator rend();
		// //rend()函数返回一个指向map头部的逆向迭代器。

  // 	int size();
		// //size()函数返回map中保存的元素个数。

  // 	void swap(Map &obj);
		// //swap()交换obj和现map中的元素。

  // 	iterator upper_bound(const Key &key);
		// //upper_bound()函数返回一个迭代器，指向map中键值>key的第一个元素。

private:
	rbtree<pair<Key, T> > t;
		//一个树对象
};

// template <class Key,class T>
// Map<Key, T>::Map():t()
// {}

// template <class Key,class T>
// Map<Key, T>::Map(value_type *first, value_type *last):t(first, last)
// {}

// template <class Key,class T>
// Map<Key, T>::Map(const Map<Key, T>& obj):t(obj.t)
// {}

// template <class Key,class T>
// Map<Key, T>::~Map()
// {}



// template <class Key,class T>
// void Map<Key, T>::clear()
// {
// 	t.clear();
// }
	
// template <class Key,class T>
// int Map<Key, T>::count(const Key &key)
// {
// 	return 1;
// }

// template <class Key,class T>
// bool Map<Key, T>::empty()
// {
// 	return t.empty();
// }

// template <class Key,class T>
// pair<iterator, iterator> Map<Key, T>::equal_range(const Key &key);
// {
// 	pair<iterator, iterator> p;
// 	p.first = t.find();
// 	p.second = t.find();
// 	return p;
// }

// template <class Key,class T>
// void Map<Key, T>::erase(iterator pos)
// {
// 	t.erase(pos);
// }
	
// template <class Key,class T>	
// void Map<Key, T>::erase(iterator start, iterator end)
// {
// 	erase(start, end);
// }

// template <class Key,class T>	
// int Map<Key, T>::erase(const Key &key)
// {
// 	return t.erase(key);
// }

// template <class Key,class T>
// iterator Map<Key, T>::find(const Key &key);
// {
// 	return t.find();
// }

// template <class Key,class T>
// pair<Map<Key, T>::iterator, bool> Map<Key, T>::insert(const pair<Key, T> &val)
// {
// 	return insert(val);
// }

// template <class Key,class T>
// iterator Map<Key, T>::lower_bound(const Key &key)
// {
// 	iterator curr = begin();
// 	while (curr != end())
// 	{
// 		if (*curr >= key)
// 		{
// 			return curr;
// 		}
// 	}
// 	return end();  //没有返回end()
// }

// 	// reverse_iterator rbegin();
// 	// //rbegin()函数返回一个指向map尾部的逆向迭代器。

// 	// reverse_iterator rend();
// 	// //rend()函数返回一个指向map头部的逆向迭代器。

// template <class Key,class T>
// int Map<Key, T>::size()
// {
// 	return t.size();
// }
	
// template <class Key,class T>	
// void Map<Key, T>::swap(Map<Key, T> &obj)
// {
// 	Map<Key, T> tmp(*this);
// 	t = obj.t;
// 	obj.t = tmp.t;
// }
// 	//swap()交换obj和现map中的元素。
// template <class Key,class T>
// iterator Map<Key, T>upper_bound(const Key &key)
// {
// 	iterator curr = begin();
// 	while (curr != end())
// 	{
// 		if (*curr > key)
// 		{
// 			return curr;
// 		}
// 	}
// 	return end();  //没有返回end()	
// }



int main(int argc, char const *argv[])
{
	//Map<string, int> m1;


	//Map<string, int> m2(m1);
	return 0;
}
