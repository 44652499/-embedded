#include <iostream>
#include <map>
#include <string.h>
using namespace std;
class Student
{
friend ostream&  operator <<(ostream& out,Student s);
friend bool  operator ==(const Student& s1,const Student& s2);
friend bool operator <(const Student& s1,const Student & s2);
friend bool  operator >(const Student& s1,const Student & s2);
public:
	Student(int _sid,const char* _sname)
	{
		sid=_sid;
		strcpy(sname,_sname);
	}
	//map容器的key必须有序,默认为升序
	// bool operator <(const Student& s)
	// {
	// 	return  this->sid<s.sid;
	// }
	// bool  operator >(const Student& s)
	// {
	// 	return this->sid>s.sid;
	// }
	// //map容器的key值必须唯一
	// bool  operator ==(const Student& s)
	// {
	// 	return this->sid==s.sid;
	// }
private:
	int sid;
	char sname[10];
};
bool operator <(const Student& s1,const Student & s2)
{
	return  s1.sid<s2.sid;
}
bool  operator >(const Student& s1,const Student & s2)
{
	return s1.sid>s2.sid;
}
	//map容器的key值必须唯一
bool  operator ==(const Student& s1,const Student& s2)
{
	return s1.sid==s2.sid;
}
ostream&  operator <<(ostream& out,Student s)
{
	out<<s.sid<<"\t"<<s.sname;
	return out;
}
template<class T>
struct CMP
{
	bool operator()(T  t1,T t2)
	{
		return  t1>t2;
	}
};
int main(int argc, char const *argv[])
{
	// map<Student,int> m1;
	// m1.insert(pair<Student,int>(Student(21,"s21"),100));
	// m1.insert(pair<Student,int>(Student(12,"s12"),200));
	// m1.insert(pair<Student,int>(Student(32,"s32"),300));
	// m1.insert(pair<Student,int>(Student(16,"s16"),400));
	// m1.insert(pair<Student,int>(Student(23,"s23"),500));
	// m1.insert(pair<Student,int>(Student(30,"s30"),600));
	// map<Student,int>::iterator it;

	map<Student,int,CMP<Student> > m1;
	m1.insert(pair<Student,int>(Student(21,"s21"),100));
	m1.insert(pair<Student,int>(Student(12,"s12"),200));
	m1.insert(pair<Student,int>(Student(32,"s32"),300));
	m1.insert(pair<Student,int>(Student(16,"s16"),400));
	m1.insert(pair<Student,int>(Student(23,"s23"),500));
	m1.insert(pair<Student,int>(Student(30,"s30"),600));
	map<Student,int,CMP<Student> >::iterator it;
	for(it=m1.begin();it!=m1.end();it++)
	{
		cout<<it->first<<"\t"<<it->second<<endl;
	}
	return 0;
}