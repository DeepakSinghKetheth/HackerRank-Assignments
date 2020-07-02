/*
																	Longest Consecutive Subsequence

You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sub sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.

Best solution takes O(n) time.

If two arrays are of equal length return the array whose index of smallest element comes first.

Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 10^5

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 

Sample Output 1 :
8 
9 
10 
11 
12

Sample Input 2 :
7
15 13 23 21 19 11 16
Sample Output 2 :
15 
16

*/



//#include<bits/stdc++.h>
//using namespace std;


//   Solution Provided By TA

#include<bits/stdc++.h>
#define pb push_back

using namespace std;

vector<int> longestSubsequence(int *arr, int n){
	vector<int> output;
  	set<int> s;
  
  for(int i=0;i<n;i++){
    s.insert(arr[i]);
  }
  
  int maxlen=0,j=0;
  for(int i=0;i<n;i++){
    int len=0,key=arr[i];
    while(s.find(key)!=s.end()){
      len++;
      key++;
      if(len>maxlen){
        maxlen=len;
        j=i;
      }
    }
  }
	int key=arr[j];
  	output.pb(key);maxlen--;key++;
  while(maxlen>0){
    output.pb(key);
    key++;
    maxlen--;
  }
  return output;
}



		int main()
		{
			int n;
			
			int arr[n];
			for(int i=0;i<n;i++)
			{
				cin>>arr[i];
			}
			
			vector<int>final_array;
			vector<int>::iterator it;
			
			 final_array = longestSubsequence(arr,n);
			 
			 for(it=final_array.begin();it!=final_array.end();it++)
			 {
			 	cout<<*it<<endl;
			 }
			return 0;
		}





/* 		My solution but 2 test cases were not successful to run.

vector<int> longestSubsequence(int *arr, int n){
    
        unordered_map<int,bool>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]=true;    
        }
        
       		 unordered_map<int,bool>::iterator it;
        
        int final_length = 0;
        int length,start,value,value2,start1;
        
        for(int i=0;i<n;i++)
        {
            if(m[arr[i]] == true)
            {
                start=arr[i];
                length=1;
                value=arr[i]+1;
                m[arr[i]]=false;
                
                while(m.find(value)!=m.end())
                {
                    m[value]=false;
                    value++;
                    length++;
                }
                
                value2=arr[i]-1;
                
                while(m.find(value2)!=m.end())
                {
                    m[value2]=false;
                    length++;
                    start--;
                    value2--;
                }
                
                
                if(final_length < length)
                {
                    final_length = length;
                    start1 = start;
                }
                
            }    
        }

        vector<int>new_arr;
        
        for(int i=0;i<final_length;i++)
        {
            new_arr.push_back(start1);
            start1++;
        }
        
      return new_arr;  
        
        
    }


		int main()
		{
			int n;
			
			int arr[n];
			for(int i=0;i<n;i++)
			{
				cin>>arr[i];
			}
			
			vector<int>final_array;
			vector<int>::iterator it;
			
			 final_array = longestSubsequence(arr,n);
			 
			 for(it=final_array.begin();it!=final_array.end();it++)
			 {
			 	cout<<*it<<endl;
			 }
			return 0;
		}






*/




















/*						In this solution you will get TLE.

vector<int> longestSubsequence(int *arr, int n){
	cout<<"func called"<<endl;
int p,q,length_of_subsequence=-1 ,start_index , last_index;
    
    sort(arr,arr+n);
    
    cout<<"sorted array"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    
    int i=0;
	while(i<n)
    {
        p=i;
        if(i== n)
        {
        	start_index = last_index = i; 
		}
		else
		{
		
       		 while(arr[i+1] == (arr[i]+1))
        		{
            		i++;
       			 }
        		q=i;
        
        		cout<<"p="<<p<<"\t"<<"q="<<q<<endl;
        
       			 if(length_of_subsequence < (q-p))
        			{
        				start_index = p;
        				last_index = q;
        				length_of_subsequence = (q-p);
        			}
        
       			 i++;
    	}
    }
    cout<<endl;
    cout<<"start_index ="<<start_index<<" last_index ="<<last_index<<endl;
    cout<<"Length = "<<length_of_subsequence<<endl;
    vector<int>new_arr;
    for(int i=start_index;i<last_index+1;i++)
    {
        new_arr.push_back(arr[i]);    
    }
    
    return new_arr;
}



int main()
{
		int n;
		cin>>n;

		int arr[n];
		vector<int>new_arr;
		vector<int>::iterator it;
				
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

new_arr =  longestSubsequence(arr,n);

cout<<endl<<"Printing new array"<<endl;

for(it=new_arr.begin();it!=new_arr.end();it++)
{
	cout<<*it<<" ";
}


}

*/
