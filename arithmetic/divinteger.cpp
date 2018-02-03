#include <iostream>
using namespace std;
int div_int(int n,int m)
{
	if(n<1 ||  m<1)
		return 0;
	if(n==1 || m==1)
		return 1;
	if(n<m)
	{
		return div_int(n,n);
	}
	if(n==m)
	{
		return div_int(n,m-1)+1;
	}
	else
		return div_int(n,m-1)+div_int(n-m,m);
}
int main(int argc, char const *argv[])
{
	cout<<div_int(6,6)<<endl;
	return 0;
}
