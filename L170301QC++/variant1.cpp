#include  <iostream>
using namespace std;
int  g_int_data=300;
int main(int argc, char const *argv[])
{
	// int l_int_data=300;
	// cout<<l_int_data<<endl;
	// cout<<g_int_data<<endl;

	int g_int_data=500;
	//cout<<g_int_data<<endl;//优先访问同作用域
	cout<<::g_int_data<<endl;//访问全局变量
	return 0;
}