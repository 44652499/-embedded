#include <iostream>
#include <string.h>
#define  private  public 
using namespace std;
/*
如何访问类的私有成员
*/
class   Student
{
public:	
	void setsid(int _sid)
	{
		sid=_sid;
	}
private:
	int sid;
	char name[10];
};
int main(int argc, char const *argv[])
{
	Student s1;    
    s1.setsid(1111);
    //访问sid 值
   // int *p=(int*)&s1;//s1存储结构获取sid 地址
    //cout<<*p<<endl;

    cout<<s1.sid<<endl;
	return 0;
}