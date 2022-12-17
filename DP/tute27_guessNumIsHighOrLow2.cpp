// *********************************** Guess Number Higher or Lower II **************************************

// know more :- https://drive.google.com/file/d/1kuL18qrgOfBFbDNR7AqGVDxx_eo1sics/view

// compiler :- https://leetcode.com/problems/guess-number-higher-or-lower-ii/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
//     ************************************* recursion *****************************
    
//     int solve(int start, int end){
        
//         if(start >= end) return 0;
        
//         int maxi = INT_MAX;
//         for(int i=start; i<=end; i++){
            
//             maxi = min(maxi, i + max(solve(start, i-1), solve(i+1, end)));
//         }
//         return maxi;
//     }
    
//     int getMoneyAmount(int n) {
        
//         return solve(1, n);
//     }
    
    
// ********************* Top-Down Approch - (recursion + memoization) ************************
    
//     int solve(int start, int end, vector<vector<int>> &dp){
        
//         if(start >= end) return 0;
        
//         if(dp[start][end] != -1) return dp[start][end];
        
//         int maxi = INT_MAX;
//         for(int i=start; i<=end; i++){
            
//             maxi = min(maxi, i + max(solve(start, i-1, dp), solve(i+1, end, dp)));
//         }
//         return dp[start][end] = maxi;
//     }
    
//     int getMoneyAmount(int n) {
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//         return solve(1, n, dp);
//     }
    
    
    
// ****************** Bottom-Up Approch - Tabulatopn Method *****************
    
    int solve(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int start=n; start>=1; start--){
            
            for(int end=start; end<=n; end++){
                if(start == end)
                    continue;
                else{
                    int maxi = INT_MAX;
                    for(int i=start; i<=end; i++){

                        maxi = min(maxi, i + max(dp[start][i-1], dp[i+1][end]));
                    }
                    dp[start][end] = maxi;
                }
            }
        }
        return dp[1][n];
    }
    
    int getMoneyAmount(int n) {
        
        return solve(n);
    }
};