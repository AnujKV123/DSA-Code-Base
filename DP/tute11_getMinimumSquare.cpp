// ********************************************** Get Minimum Squares *******************************************

// know more :- https://drive.google.com/file/d/1_bFL3tvqsfixpmYw0VCVqaWZOKtqPO0k/view

//  compiler :- https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
// 	****************************** Recursion ***************************
// 	int solve(int n){
// 	    if(n==0) return 0;
	    
// 	    int ans = n;
// 	    for(int i=1; i*i<n; i++){
// 	        int temp = i*i;
// 	        ans = min(ans, 1+solve(n - temp));
// 	    }
// 	    return ans;
// 	}
// 	int MinSquares(int n)
// 	{
// 	    // Code here
// 	    return solve(n);
// 	}


// ********************* Top-Down Approch - (recursion + memoization) ************************
// 	int solve(int n, vector<int> &dp){
// 	   // base case
// 	    if(n == 0) return 0;
	    
// 	    if(dp[n] != -1) return dp[n];
	    
// 	    int ans = n;
// 	    for(int i=1; i*i<=n; i++){
// 	        int temp = i*i;
// 	        ans = min(ans, 1+solve(n - temp, dp));
// 	    }
// 	    dp[n] = ans;
	    
// 	    return dp[n];
// 	}
	
// 	int MinSquares(int n)
// 	{
// 	    // Code here
// 	    vector<int> dp(n+1, -1);
// 	    return solve(n, dp);
// 	}
	


// ****************** Bottom-Up Approch - Tabulatopn Method *****************
	int solve(int n){
	   // base case
	   vector<int> dp(n+1, INT_MAX);
	   
	    dp[0] = 0;
	    
	    for(int i=0; i<=n; i++){
	        
    	    for(int j=1; j*j<=n; j++){
    	        
    	        int temp = j*j;
    	        
    	        if(i-temp >= 0)
    	        
    	            dp[i] = min(dp[i], 1 + dp[i - temp]);
    	    }
	    }
	    
	    return dp[n];
	}
	
	int MinSquares(int n)
	{
	    // Code here
	    return solve(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends