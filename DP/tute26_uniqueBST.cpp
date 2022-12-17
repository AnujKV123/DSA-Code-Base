// ******************************** Unique Binary Search Trees ****************************************

// know more :- https://drive.google.com/file/d/1Bh1MPA4QZpvY4P5_VjcuedmdeyMfPwgg/view

// compiler :- https://leetcode.com/problems/unique-binary-search-trees/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// ********************************** recursion **********************************
//     int numTrees(int n) {
        
//         if(n <= 1) return 1;
//         int ans = 0;
        
//         // think i as root node
//         for(int i=1; i<=n; i++){
            
//             ans += numTrees(i-1) * numTrees(n-i);
//         }
//         return ans;
//     }
    
    
    
// ********************* Top-Down Approch - (recursion + memoization) ************************
// T.C = O(n^2)
// S.C = O(n^2)

//     int solve(int n, vector<int> &dp){
//         if(n <= 1) return 1;
        
//         if(dp[n] != -1) return dp[n];
        
//         int ans = 0;
//         // think i as root node
//         for(int i=1; i<=n; i++){
            
//             ans += solve(i-1, dp) * solve(n-i, dp);
//         }
//         return dp[n] = ans;
//     }
//     int numTrees(int n) {
        
//         vector<int> dp(n+1, -1);
//         return solve(n, dp);
//     }
    
    
    
    
// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(n^2)
// S.C = O(n^2)

    int solve(int n){
        vector<int> dp(n+1, 0);
        
        dp[0] = dp[1] = 1;
        
        int ans = 0;
        // i-> no. of nodes
        for(int i=2; i<=n; i++){
            // j-> root node
            for(int j=1; j<=i; j++){
                
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        
        return solve(n);
    }
};