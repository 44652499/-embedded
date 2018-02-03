#include <iostream>
using namespace std;
template<class T>
void defineswap(T &a,T &b)
{
	T  temp=a;
	a=b;
	b=temp;
}

template<class T>
void perm(T list[],int k,int m)
{
	int i;
	if(k==m)
	{
		for(i=0;i<=m;i++)
		{
			cout<<list[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(i=k;i<=m;i++)
		{
			defineswap(list[k],list[i]);
			perm(list,k+1,m);
			defineswap(list[k],list[i]);
		}
	}
}
int main(int argc, char const *argv[])
{
	int list[3];
	int i;
	for(i=0;i<3;i++)
	{
		list[i]=i+1;
	}
	perm(list,0,2);
	return 0;
}
