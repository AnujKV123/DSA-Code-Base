// ******************************* Longest Increasing Subsequence **************************************


// know more :- https://drive.google.com/file/d/1Q4wfSVWmdKCmg8ro7XLusR3DtCQSFSrQ/view

// compiler :- https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    // ********************************* recursion ***************************************
    
    // int solve(int n, int a[], int curr, int prev){
        
    //     if(curr == n) return 0;
        
    //     // include
    //     int take = 0;
    //     if(prev == -1 || a[curr] > a[prev]){
    //         take = 1 + solve(n, a, curr+1, curr);
    //     }
        
    //     // exclude
    //     int notTake = 0 + solve(n, a, curr+1, prev);
        
    //     return max(take, notTake);
        
    // }
    
    // //Function to find length of longest increasing subsequence.
    // int longestSubsequence(int n, int a[])
    // {
    //   // your code here
    //   return solve(n, a, 0, -1);
    // }
    
    
// ********************* Top-Down Approch - (recursion + memoization) ***********************
// T.C = O(n^2)
// S.C = O(n^2)

    
    // int solve(int n, int a[], int curr, int prev, vector<vector<int>> &dp){
        
    //     if(curr == n) return 0;
        
    //     if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        
    //     // include
    //     int take = 0;
    //     if(prev == -1 || a[curr] > a[prev]){
    //         take = 1 + solve(n, a, curr+1, curr, dp);
    //     }
        
    //     // exclude
    //     int notTake = 0 + solve(n, a, curr+1, prev, dp);
        
    //     dp[curr][prev+1] = max(take, notTake);
        
    //     return dp[curr][prev+1];
        
    // }
    
    // //Function to find length of longest increasing subsequence.
    // int longestSubsequence(int n, int a[])
    // {
    //   // your code here
    //   vector<vector<int>> dp(n, vector<int>(n+1, -1));
       
    //   return solve(n, a, 0, -1, dp);
    // }
    
    
    
    
    
// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(n^2)
// S.C = O(n^2)
    
    // int solve(int n, int a[]){
    //   vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
    //     for(int curr = n-1; curr>=0; curr--){
            
    //         for(int prev = curr-1; prev>=-1; prev--){
                
    //             // include
    //             int take = 0;
    //             if(prev == -1 || a[curr] > a[prev]){
    //                 take = 1 + dp[curr+1][curr+1];
    //             }
                
    //             // exclude
    //             int notTake = 0 + dp[curr+1][prev+1];
                
    //             dp[curr][prev+1] = max(take, notTake);
    //         }
    //     }
        
    //     return dp[0][0];
    // }
    
    // //Function to find length of longest increasing subsequence.
    // int longestSubsequence(int n, int a[])
    // {
    //   // your code here
       
    //   return solve(n, a);
    // }
    
    
    
    
    
    
// ****************** Approch3 - Space Optimization *****************
// T.C = O(n^2)
// S.C = O(n)
    
    // int solve(int n, int a[]){
    //   vector<int> currRow(n+1, 0);
    //   vector<int> nextRow(n+1, 0);
        
    //     for(int curr = n-1; curr>=0; curr--){
            
    //         for(int prev = curr-1; prev>=-1; prev--){
                
    //             // include
    //             int take = 0;
    //             if(prev == -1 || a[curr] > a[prev]){
    //                 take = 1 + currRow[curr+1];
    //             }
                
    //             // exclude
    //             int notTake = 0 + currRow[prev+1];
                
    //             currRow[prev+1] = max(take, notTake);
    //         }
    //         nextRow = currRow;
    //     }
        
    //     return nextRow[0];
    // }
    
    // //Function to find length of longest increasing subsequence.
    // int longestSubsequence(int n, int a[])
    // {
    //   // your code here
       
    //   return solve(n, a);
    // }
   
    
    
    
    
    
// ****************** Approch3 - Space Optimization++ by using dp with binary search *****************
// T.C = O(nlogn)
// S.C = O(n)
    
    int solve(int n, int a[]){
        
        if(n==0) return 0;
        
       vector<int> ans;
       ans.push_back(a[0]);
       
       
       for(int i = 1; i<n; i++){
           
           if(a[i] > ans.back())
                ans.push_back(a[i]);
            
            else{
                
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
       }
       return ans.size();
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       
       return solve(n, a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends