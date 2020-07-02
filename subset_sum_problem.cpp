#include<bits/stdc++.h>
using namespace std;
int main()
{
	int value[] = {18,23,17,29,1,6,7,30,7,6};
	int n = 10;
	int sum = 100;
	
	bool **dp = new bool*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i] = new bool[sum+1];
	}

		//If sum is to be made and we have no elements then we cannot have the sum.
		for(int i=1;i<=sum;i++)
		{
			dp[0][i] = false;
		}
		
		//If sum to be made is equal to 0 then there is always a possibility of an empty set.
		for(int i=0;i<=n;i++)
		{
			dp[i][0] = true;
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=sum;j++)
			{
				dp[i][j] = dp[i-1][j] ;
				
				if(j>=value[i-1])
					dp[i][j] = dp[i][j] || dp[i-1][j-value[i-1]];
			}
		}
		
		
		cout<<dp[n][sum];
		
		delete [] dp;
	return 0;
}

