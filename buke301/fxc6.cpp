#include <iostream>
#include <string.h>
using namespace std;

// class A
// {
// 	int  data;
// 	int  &ptr=data;//类成员引用变量当成指针
// };

class A
{
private:
	int data;
public:
	explicit A(int _data)
	{
		data=_data;
	}
};

int main(int argc, char const *argv[])
{
	//cout<<sizeof(A)<<endl;  //引用变量底层就是一个指针
	//A  a1(20);
	A  a2=400;//初始化  a2.data=400;
	return 0;
}