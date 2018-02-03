#include <iostream>
#include <vector>
using namespace std;
/*
STL:Standard Template Library标准模板库 是通用类模板和算法的集合
C++ STL 提供给程序员以下三类数据结构的实现:
1.顺序结构:vector,list,double_end queue
2.容器适配器 :stack  queue  
3.联合容器:bitset map  multimap  set  multiset
vector:
顺序向量容器,包含着一系列连续存储的元素,其行为和数组类似.
访问Vector中的任意元素或从末尾添加元素都可以在常量级时间复杂度内完成
查找特定值的元素所处的位置或是在Vector中插入元素则是线性时间复杂度
构造:
vector(); 空容器
vector( size_type num, const TYPE &val ); 构造一个num个元素容器,元素值默认是val
vector( const vector &from );
vector( input_iterator start, input_iterator end );

input_iterator输入迭代器(iterator)
迭代器可被用来访问一个容器类的所包函的全部元素，其行为像一个指针.每一个不同容器都存在一个对应的迭代器(不同容器其元素存储内存不结构不同)
input_iterator:读取容器元素值,支持++  *
output_iterator:改写容器元素值,支持++ *
const_iterator:只能读取容器的元素值,支持++  *
reverse_iterator:反向迭代器,反向访问容器元素
*/

//迭代器输出容器的元素值
void   print_vector(vector<int> v)
{
	//定义容器的迭代器
	vector<int>::iterator   it;
	for(it=v.begin();it<v.end();it++)
	{
		//*it=100;
		cout<<*it<<"\t";
	}
	cout<<endl;
}

void   print_vector_const(vector<int> v)
{
	//定义容器的迭代器
	vector<int>::const_iterator   it;
	for(it=v.begin();it<v.end();it++)
	{
		//*it=100;//错误
		cout<<*it<<"\t";
	}
	cout<<endl;
}

void   print_vector_reverse(vector<int> v)
{
	//定义容器的迭代器
	vector<int>::reverse_iterator   it;
	for(it=v.rbegin();it<v.rend();it++)
	{
		cout<<*it<<"\t";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	vector<int> v1;
	vector<int> v2(5,8);
	vector<int> v3(v2);
	int a[]={10,20,30,40,50};
	vector<int> v4(a,a+5);//[a,a+4)
	vector<int> v5(v4.begin(),v4.end());
	//print_vector(v2);
	//print_vector(v3);
	//print_vector(v4);

	//print_vector_const(v4);
	//print_vector_reverse(v4);

	//cout<<v4[10]<<endl;
	//cout<<v4.at(10)<<endl;//异常处理

	//v1.push_back(12);
	//print_vector(v1);
	v1.push_back(12);//resize:创建足够容量,复制以前的元素.
	v1.push_back(12);
	v1.push_back(12);
	cout<<v1.size()<<endl;//当前元素个数
	cout<<v1.capacity()<<endl;//容量
	//capacity(size)=2^size;

	//任务 ,体验标准库vector 剩余函数
	return 0;
}
//周末作业:
//1.实现一个符合中国身份证号码存储程序,用自己身份证号测试(吴与梁)
//2.自定义实现一个向量容器vector(参照c++库函数(中文).chm vector 成员函数 构造函数 符号重载  除开assign  get_allocator) ,自定义迭代器(王鑫)