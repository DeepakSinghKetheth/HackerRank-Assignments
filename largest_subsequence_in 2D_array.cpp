#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	int arr[n][m];
	int dp[n][m];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];	
			dp[i][j] = 0;		
			
		}	
	}	
	
	dp[n-1][m-1] = 1;
	
	for(int i=m-2;i>=0;i--)
	{
		if(arr[n-1][i+1] > arr[n-1][i])
			dp[n-1][i] = dp[n-1][i+1] + 1 ;
			
		else
			 dp[n-1][i] = 1;	 
	}
	
	for(int i=n-2;i>=0;i--)
	{
		if(arr[i+1][m-1] > arr[i][m-1])
			dp[i][m-1] = dp[i+1][m-1] + 1 ;
			
		else
			 dp[i][m-1] = 1;	 
	}
	
	
	
	
	for(int i = n-2 ; i>=0; i--)
	{
		for(int j=m-2;j>=0 ; j--)
		{
			int max = 1;
			
			if(arr[i][j+1] > arr[i][j] )
				{
					max+=dp[i][j+1];
				}
		
			if(arr[i+1][j] > arr[i][j] && max < (dp[i+1][j] +1))
			{
				max=dp[i+1][j] + 1 ;
				
			}
			
			
			dp[i][j] = max;
			
			
			
		}
	}
	
	
	cout<<endl;
	
		//Print DP array
	
	for(int i = 0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
	
	
	
	
	cout<<"ans = ";
	cout<<dp[0][0];	
}
