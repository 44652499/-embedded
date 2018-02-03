#include  <iostream>
using namespace std;
/*
友元函数:一个函数可以访问类的私有成员
*/
class  A
{
friend  void function();//声明友元函数
friend int main(int argc, char const *argv[]);
public:
	A(int _data)
	{
		data=_data;
	}
private:
	int data;
};

void  function()
{
	A a1(100);
	cout<<a1.data<<endl;
}
int main(int argc, char const *argv[])
{
	//function();

	A a2(200);
	cout<<a2.data<<endl;
	return 0;
}
