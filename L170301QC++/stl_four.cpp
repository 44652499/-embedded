#include <iostream>
#include <list>
#include <string.h>
using namespace std;
/*list 容器存放自定义类型学生类*/
class  Student
{
friend ostream &  operator <<(ostream&  out,Student s);
public:
	Student(int _sid,const char*  _sname)
	{
		sid=_sid;
		strcpy(sname,_sname);
	}
	bool operator  <(Student s)
	{
		return this->sid<s.sid;
	}
	bool  operator ==(Student s)
	{
		return this->sid==s.sid;
	}
private:
	int sid;
	char sname[10];
};

bool  compare(Student s1,Student s2)
{
	return !(s1<s2);
}

ostream &  operator <<(ostream&  out,Student s)
{
	out<<s.sid<<"\t"<<s.sname;
	return out;
}
int main(int argc, char const *argv[])
{
	list<Student>  l1;
	l1.push_back(Student(111,"s111"));
	l1.push_back(Student(222,"s222"));
	l1.push_back(Student(444,"s444"));
	l1.push_back(Student(555,"s555"));
	l1.push_back(Student(333,"s333"));
	l1.push_back(Student(666,"s666"));
	l1.push_back(Student(555,"s5555"));
	//l1.sort();
	l1.sort(compare);
	l1.unique();
	list<Student>::iterator it;
	for(it=l1.begin();it!=l1.end();it++)
	{
		cout<<*it<<endl;
	}
 	return 0;
}