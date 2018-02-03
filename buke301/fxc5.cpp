#include <iostream>
#include <string.h>
using namespace std;
/*
析构函数:释放对象,系统自动调用,释放对象成员占用其它空间
*/
class  student
{
private:
	int sid;
	char sname[100];
	int *ptr;
public:
	student(int _sid,const char* _sname)
	{
		sid=_sid;
		strcpy(sname,_sname);
		ptr=new int(20);
	}
private:
	~student()
	{
		cout<<"disconstructor"<<endl;
		//释放ptr成员指向的堆空间
		if(ptr!=NULL)
		{
			delete ptr;
			ptr=NULL;
		}
	}
};
int main(int argc, char const *argv[])
{
	//student s(11,"s11");//局部对象自动释放,调用析构函数
	student * s2=new student(12,"s12");//对象在堆空间,没有释放
	delete s2;
	s2=NULL;
	return 0;
}