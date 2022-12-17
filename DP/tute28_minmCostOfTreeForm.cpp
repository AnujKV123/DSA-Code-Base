// ******************************************** Minimum Cost Tree From Leaf Values **************************************************

// know more :- https://drive.google.com/file/d/1Q1VKUUCsyCrrJDlJmKr62IJ2O-mgOvX-/view

// compiler :- https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
//     *********************************************** recursion ******************************************************
    
//     int solve(vector<int>& arr, map<pair<int, int>, int> &maxi, int left, int right){
        
//         // leaf node
//         if(left == right) return 0;
        
//         int ans = INT_MAX;
//         for(int i=left; i<right; i++){
            
//             ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i+1, right));
//         }
//         return ans;
//     }
    
//     int mctFromLeafValues(vector<int>& arr) {
        
//         map<pair<int, int>, int> maxi;
        
//         for(int i=0; i<arr.size(); i++){
//             maxi[{i,i}] = arr[i];
            
//             for(int j=i+1; j<arr.size(); j++){
                
//                 maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
//             }
//         }
//         return solve(arr, maxi, 0, arr.size()-1);
//     }
    
    

// ********************* Top-Down Approch - (recursion + memoization) ************************
//     T.C = O(n^3)
//     S.C = O(n^2)
    
    int solve(vector<int>& arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp){
        
        // leaf node
        if(left == right) return 0;
        
        if(dp[right][left] != -1) return dp[right][left];
        
        int ans = INT_MAX;
        for(int i=left; i<right; i++){
            
            ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solve(arr, maxi, left, i, dp) + solve(arr, maxi, i+1, right, dp));
        }
        return dp[right][left] = ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        
        map<pair<int, int>, int> maxi;
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        for(int i=0; i<arr.size(); i++){
            maxi[{i,i}] = arr[i];
            
            for(int j=i+1; j<arr.size(); j++){
                
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        return solve(arr, maxi, 0, arr.size()-1, dp);
    }
    
    
    

// ****************** Bottom-Up Approch - Tabulatopn Method ******************
    

};