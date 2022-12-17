// ******************************************* Longest Common Subsequence ******************************************

// know more :- https://drive.google.com/file/d/18JvJHsoCo6Dql5Y0TIFcnLWqC_DKD7a4/view

// compiler :- https://leetcode.com/problems/longest-common-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//     ***************************************** recursion *********************************************
//     int solve(string& text1, string& text2, int i, int j){
        
//         if(i == text1.length()) return 0;
        
//         if(j == text2.length()) return 0;
        
//         int ans = 0;
//         if(text1[i] == text2[j])
//             ans = 1 + solve(text1, text2, i+1, j+1);
//         else
//             ans = max(solve(text1, text2, i+1, j), solve(text1, text2, i, j+1));
        
//         return ans;
//     }
//     int longestCommonSubsequence(string text1, string text2) {
        
//         return solve(text1, text2, 0, 0);
//     }
 
    
    
// ********************* Top-Down Approch - (recursion + memoization) ***********************
//     T.C = O(n*m)
//     S.C = O(n*m)
    
//     int solve(string& text1, string& text2, int i, int j, vector<vector<int>>& dp){
        
//         if(i == text1.length()) return 0;
        
//         if(j == text2.length()) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int ans = 0;
//         if(text1[i] == text2[j])
//             ans = 1 + solve(text1, text2, i+1, j+1, dp);
//         else
//             ans = max(solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));
        
//         return dp[i][j] = ans;
//     }
//     int longestCommonSubsequence(string text1, string text2) {
        
//         int n = text1.length();
//         int m = text2.length();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return solve(text1, text2, 0, 0, dp);
//     }
    
 
    
    
// ****************** Bottom-Up Approch - Tabulatopn Method ******************
//     T.C = O(n*m)
//     S.C = O(n*m)
    
//     int solve(string& text1, string& text2){
        
//         int n = text1.length();
//         int m = text2.length();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
//         for(int i=n-1; i>=0; i--){
            
//             for(int j=m-1; j>=0; j--){
                
//                 int ans = 0;
//                 if(text1[i] == text2[j])
//                     ans = 1 + dp[i+1][j+1];
//                 else
//                     ans = max(dp[i+1][j], dp[i][j+1]);

//                 dp[i][j] = ans;
//             }
//         }
        
//         return dp[0][0];
//     }
//     int longestCommonSubsequence(string text1, string text2) {
        
//         return solve(text1, text2);
//     }
    
 
    
    
// ****************** Approch 3: - space optimization ******************
//     T.C = O(n*m)
//     S.C = O(m)
    
    int solve(string& text1, string& text2){
        
        int n = text1.length();
        int m = text2.length();
        
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        for(int i=n-1; i>=0; i--){
            
            for(int j=m-1; j>=0; j--){
                
                int ans = 0;
                if(text1[i] == text2[j])
                    ans = 1 + next[j+1];
                else
                    ans = max(next[j], curr[j+1]);

                curr[j] = ans;
            }
            next = curr;
        }
        
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        return solve(text1, text2);
    }
};