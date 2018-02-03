#include <iostream>
using namespace std;
/*
自定义学生类:
*/
class   Student
{
public:
	void study()
	{
		cout<<"study"<<endl;
	}
	void eat()
	{
		cout<<"eat"<<endl;
	}
private:
	int sid;
	char name[10];
	char sex;
	int age;
	char addr[20];
};
int main(int argc, char const *argv[])
{
	Student s1;
	s1.study();
	s1.eat();
	Student s2;
	s2.study();
	s2.eat();
	return 0;
}