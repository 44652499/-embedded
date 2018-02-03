#include <iostream>
#include <map>
using namespace std;
/*map容器:容器是一个非连续的RBTREE(红黑树),树节点存在两个值(key-value),通过key找到value,提高查询效率
rbtree:5个判断条件,左旋转 右旋转
map容器对象定义:
map<key_type,value_type>
key_type:表示键值类型,可以是任意类型.要求键值必须唯一 有序  只读.要求实现自定义类型时必须重写 =  < 或  >
value_type:表示值类型,可以使任意数据类型.
*/
template<class T>
class  CMP
{
public:
	bool operator()(T v1,T v2)
	{
		return v1>v2;
	}
};
void  print_map(map<string,int,CMP<string> > m)
{
	map<string,int,CMP<string> >::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		cout<<it->first<<'\t'<<it->second<<endl;
	}
}

int main(int argc, char const *argv[])
{
	map<string,int,CMP<string> > m1;//CMP称为排序类型,指定元素排序方式.不写默认为升序
	//用"[]"插入元素
	m1["abcd1"]=100;
	m1["abcd4"]=100;
	m1["abcd3"]=100;
	m1["abcd2"]=100;
	m1["abcd1"]=100;
    print_map(m1);
	//调用insert
	// m1.insert(pair<string,int>("abcd1",1000));
	// m1.insert(pair<string,int>("abcd5",1000));
	// m1.insert(pair<string,int>("abcd2",1000));
	// pair<map<string,int,CMP<string> >::iterator,bool>ret=m1.insert(pair<string,int>("abcd4",1000));
	// if(!ret.second)
	// {
	// 	cout<<"insert fail"<<endl;
	// }
	// else
	// {
	// 	cout<<ret.first->first<<"\t"<<ret.first->second<<endl;
	// }
	// print_map(m1);
	return 0;
}