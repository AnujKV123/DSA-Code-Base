// ********************************** Container With Most Water ************************************

// know more :- https://practice.geeksforgeeks.org/problems/container-with-most-water0535/1


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here
    long long ans=0;
    int start=0, end=len-1;
    
    while(start<end){
        
        long long water = (end-start) * min(A[start], A[end]);
        ans = max(ans, water);
        
        if(A[start] < A[end]){
            start++;
        }
        else end--;
    }
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends