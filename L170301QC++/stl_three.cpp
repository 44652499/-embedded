#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	list<vector<int> > l1;
	vector<int> v1(2,3);
	vector<int> v2(4,8);
	vector<int> v3(5,6);
	l1.push_back(v1);
	l1.push_back(v2);
	l1.push_back(v3);
	list<vector<int> >::iterator it;
	for(it=l1.begin();it!=l1.end();it++)
	{
		 vector<int>::iterator v_it;
		 for(v_it=it->begin();v_it!=it->end();v_it++)
		 {
		 	cout<<*v_it<<"\t";
		 }
		 cout<<endl;
	}
	return 0;
}