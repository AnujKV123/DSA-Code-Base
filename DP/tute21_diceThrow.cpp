// ********************************** Dice Throw *******************************************

// know more :- https://drive.google.com/file/d/1r2-AMJTgAoZJLNamQWtoXdUw1FIypBcf/view

// compiler :- https://practice.geeksforgeeks.org/problems/dice-throw5349/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   *********************************** recursion *****************************************
    // long long solve(int faces, int dice, int target){
        
    //     // base case
    //     if(target < 0) return 0;
        
    //     if(dice == 0 && target != 0) return 0;
        
    //     if(target == 0 && dice != 0) return 0;
        
    //     if(dice == 0 && target == 0) return 1;
        
    //     long long ans = 0;
        
    //     for(int i=1; i <= faces; i++){
    //         ans = ans + solve(faces, dice-1, target-i);
    //     }
        
    //     return ans;
    // }
    
    // long long noOfWays(int M , int N , int X) {
    //     // code here
    //     return solve(M, N, X);
    // }
    
    
    
// ********************* Top-Down Approch - (recursion + memoization) ***********************
// T.C = O(M*N*X)
// S.C = O(N*X)

    // long long solve(int faces, int dice, int target, vector<vector<long long>> &dp){
        
    //     // base case
    //     if(target < 0) return 0;
        
    //     if(dice == 0 && target != 0) return 0;
        
    //     if(target == 0 && dice != 0) return 0;
        
    //     if(dice == 0 && target == 0) return 1;
        
    //     if(dp[dice][target] != -1) return dp[dice][target];
        
    //     long long ans = 0;
        
    //     for(int i=1; i <= faces; i++){
    //         ans = ans + solve(faces, dice-1, target-i, dp);
    //     }
        
    //     return dp[dice][target] = ans;
    // }
    
    // long long noOfWays(int M , int N , int X) {
    //     // code here
    //     vector<vector<long long>> dp(N+1, vector<long long>(X+1, -1));
    //     return solve(M, N, X, dp);
    // }
    
    
    
    
// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(M*N*X)
// S.C = O(N*X)

    // long long solve(int f, int d, int t){
        
    //     vector<vector<long long>> dp(d+1, vector<long long>(t+1, 0));
        
    //     // base case
    //     dp[0][0] = 1;
        
    //     for(int dice = 1; dice <= d; dice++){
            
    //         for(int target = 1; target <= t; target++){
                
    //             long long ans = 0;
        
    //             for(int i=1; i <= f; i++){
                    
    //                 if(target - i >= 0)
    //                     ans = ans + dp[dice-1][target-i];
    //             }
                
    //             dp[dice][target] = ans;
    //         }
    //     }
        
    //     return dp[d][t];
    // }
    
    // long long noOfWays(int M , int N , int X) {
    //     // code here
    //     return solve(M, N, X);
    // }
    
    
    
    
// ****************** Approch3 - Space Optimization *****************
// T.C = O(M*N*X)
// S.C = O(X)

    long long solve(int f, int d, int t){
        
        vector<long long> prev(t+1, 0);
        vector<long long> curr(t+1, 0);
        
        // base case
        prev[0] = 1;
        
        for(int dice = 1; dice <= d; dice++){
            
            for(int target = 1; target <= t; target++){
                
                long long ans = 0;
        
                for(int i=1; i <= f; i++){
                    
                    if(target - i >= 0)
                        ans = ans + prev[target-i];
                }
                
                curr[target] = ans;
            }
            prev = curr;
        }
        
        return prev[t];
    }
    
    long long noOfWays(int M , int N , int X) {
        // code here
        return solve(M, N, X);
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends