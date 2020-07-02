#include<bits/stdc++.h>
using namespace std;


int kadane_sum(int* sum,int m)
{
	int best_so_far = INT_MIN,curr_max = 0;
	for(int i=0;i<m;i++)
	{
		curr_max+=sum[i];
		
			if(curr_max<0)
			curr_max = 0;
			
		if(best_so_far < curr_max)
			best_so_far = curr_max;
		
	
		
		
		
	}
	return best_so_far;
	
}
void max_sum(int arr[][100],int m,int n)
{
	int finalans = 0;
	int sum[m];
	int ans=0 ;
	for(int i=0;i<n;i++)
	{
			memset(sum,0,sizeof(sum));

		for(int j=i;j<n;j++)
		{
			
			for(int k=0;k<m;k++)
			{
				sum[k]+=arr[k][j];
			}
			
			ans = kadane_sum(sum,m);
			if(finalans < ans)
			finalans = ans;
			
		}
		}
	cout<<endl;
	cout<<"Maximum Sum Rectangle = "<<finalans;
	
}

int main()
{
	int n,m;
	cin>>m>>n;
	int arr[100][100];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	max_sum(arr,m,n);
	
	return 0;
	
}



/*
#include<bits/stdc++.h>
using namespace std;


int maxsubarray(int sum[], int k){
    int cur_max=0;
    int pre_max=INT_MIN;
   for(int i=0;i<k;i++) {
            cur_max=cur_max+sum[i];
            if(cur_max>pre_max) {
                pre_max=cur_max;
            }
            if(cur_max<0) {
                cur_max=0;
            }
        }
       // if(pre_max>0){
        return pre_max;
       // }else{
       //     return -1;
        //}
    //return max_sum;
   
}


void max_sum(int arr[][1000],int m,int n)
{
 	int maximum_sum = INT_MIN;
    int pre_max=0;
    int sum[m]; 
    
    for(int i=0;i<n;i++)
	{
       memset(sum,0,sizeof(sum));
		for(int j=i;j<n;j++)
		{
				//creating vertical sum of elements in sum array.			
				for(int k=0;k<m;k++)
				{
					sum[k]+=arr[k][j]; 
				}
				
				//Using kadane's Algorithm to find rows. 
				 pre_max = maxsubarray(sum,m);
                if(maximum_sum<pre_max) 
                 {
                    maximum_sum=pre_max;
                 } 
		}
	}
	cout<<maximum_sum<<endl;
	
	
}


int  main()
{
	int n,m;
	cin>>m>>n;
	int arr[1000][1000];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	max_sum(arr,m,n);
	
	return 0;
}
*/
