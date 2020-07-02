/*
Coding Ninjas
Lecture-17 Dynamic Prorgramming -1

														Maximum Square Matrix With All Zeros

Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1

*/


#include<bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    int** dp = new int*[row];
    for(int i=0;i<row;i++)
    {
        dp[i] = new int[col];
    }
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            dp[i][j] = 1 xor arr[i][j];
        }
    }
        
    for(int i=row-2;i>=0;i--)
    {
        for(int j=col-2;j>=0;j--)
        {
            if(dp[i][j] != 0)
            {
                if(dp[i][j+1]==0 || dp[i+1][j+1]==0 || dp[i+1][j]==0)
                {
                         //dp[i] remains as it is.       
                }
                else if(dp[i][j+1]!=0 && dp[i+1][j+1]!=0 && dp[i+1][j]!=0)
                {
                   int val= min(dp[i][j+1],min(dp[i+1][j+1],dp[i+1][j]));
                    dp[i][j]+=val;
                }
                
            }
        }
            
    }
    
    
    
    int  min=-1;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(min<dp[i][j])
                min = dp[i][j];
        }
    }
    
    return min;
}

