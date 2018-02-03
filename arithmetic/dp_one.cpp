#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[]={1,3,5};
	int sum=11;
	int cent=0;
	int dp[12];
	dp[0]=0;
	int i;
	for(i=1;i<=sum;i++)
	{
		dp[i]=i;
	}
	int j;
	for(i=1;i<=sum;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i>=a[j] && dp[i-a[j]]+1<dp[i])
			{
				dp[i]=dp[i-a[j]]+1;
			}
		}
	}
	cout<<dp[sum]<<endl;
	return 0;
}