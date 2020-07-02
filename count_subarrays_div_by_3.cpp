/*

 C++ program which returns the Number of sub sequences 
 (or subsets) which are divisible by m. 

1)  Recursive Solution : 
	
#include<bits/stdc++.h>
using namespace std;

int div_by_3(int arr[],int sum,int n)
{
	
	if(n == 0 )
	{	
		if(sum%3==0 && sum!=0)
		{
			cout<<sum<<" ";	
			return 1;
		}		
		
		return 0;
	}
	
	//excluding current element
	int sum1 = div_by_3(arr+1,sum,n-1);
	
	//Including the current element
	int sum2 = div_by_3(arr+1,sum+arr[0],n-1);
	
	return sum1+sum2;
	
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int sum = 0;
	int count = div_by_3(arr,sum,n);
	cout<<"count = "<<count;
	
	
	
	return 0;
}


*/


// 2) Iterative Solution (Using DP) Similar approach as Subset sum iterative solution.

#include <bits/stdc++.h> 
using namespace std; 

// Use Dynamic Programming to find 
// sum of subsequences. 
int sumSubSequence(vector<int> arr, int len, int m) 
{ 
	// Find sum of array elements 
	int sum = 0; 
	for (auto x : arr) 
	sum += x; 

	// dp[i][j] would be > 0 if arr[0..i-1] has 
	// a subsequence with sum equal to j. 
	vector<vector<int> > dp(len + 1, vector<int>(sum + 1, 0)); 

	// There is always sum equals zero 
	for (int i = 0; i <= len; i++) 
		dp[i][0]++; 

	// Fill up the dp table 
	for (int i = 1; i <= len; i++) { 

		dp[i][arr[i - 1]]++; 
		for (int j = 1; j <= sum; j++) { 

			if (dp[i - 1][j] > 0) { 
				dp[i][j]++; 
				dp[i][j + arr[i - 1]]++; 
			} 
		} 
	} 

	// Initialize the counter 
	int count = 0; 
	for (int j = 1; j <= sum; j++) 

		// Check if the sum exists 
		if (dp[len][j] > 0) 

			// check sum is divisible by m 
			if (j % m == 0) 
				count += dp[len][j]; 

	return count; 
} 

// Driver Code 
int main() 
{ 
	vector<int> arr{ 1, 2, 3 }; 
	int m = 3; 
	int len = arr.size(); 
	cout << sumSubSequence(arr, len, m) << endl; 
	return 0; 
} 



*/


