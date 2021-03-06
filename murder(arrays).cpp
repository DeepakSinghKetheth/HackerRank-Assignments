/*
Coding Ninjas
																	Murder

Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. 
He found it suspicious and decides to remember all the numbers that he has seen till now. 
While remembering the numbers he found that he can find some pattern in those numbers. 
So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. 
Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.

Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.

Output

For each test case output one line giving the final sum for each test case.

Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.

Sample Input:
1
5
1 5 3 6 4

Sample Output:
15

Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).

*/



#include<bits/stdc++.h>
using namespace std;

long long merge(int A[],int left,int mid,int right)
{
    
        int i=left;
        int j=mid;
        int k=0;
        int temp[right-left+1];
    
    
    long long sum=0;
    while(i<mid && j<=right)   
    {
        if(A[i]<A[j])
        {
            sum+=(right-j+1)*A[i];
            temp[k++] = A[i++];
        }
         else
        {
            temp[k++] = A[j++];
            
        }
    }
    
    while(i<mid)
    {
        temp[k++] = A[i++];
    }
    while(j<=right)
    {
        temp[k++] = A[j++];
    }
    
    for(int i=left,k=0;i<=right;i++,k++)
    {
         A[i]=temp[k];
    }
    
    return sum;
}

long long merge_sort(int A[],int left , int right){
    
    long long sum =0;
    
    if(right>left)
    {
        
        int mid = ( left + right )/2;
        
        long long Leftsum = merge_sort(A,left,mid);
        long long Rightsum = merge_sort(A,mid+1,right);
        long long mergesum = merge(A,left,mid+1,right);
        
        return Leftsum + Rightsum + mergesum; 
    }
    return sum;
}


long long solve(int A[], int n)
{
    long long sum = merge_sort(A,0,n-1);
    return sum;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	
	long long totalsum = solve(A,n);
	cout<<totalsum<<endl; 
    
    }
	return 0;
}
