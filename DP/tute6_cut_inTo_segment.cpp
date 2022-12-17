// ******************************************* Cut Into Segments **************************************************

// compiler :- https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//  know more :- https://drive.google.com/file/d/1v2hPd76Yk8qkWGoSV8Q1pJ_b53rRcvMj/view

#include<bits/stdc++.h>
using namespace std;

// ********************* recursion **************************
// int solve(int n, int x, int y, int z){
    
// //     base case
//     if(n==0) return 0;
//     if(n<0) return INT_MIN;
    
//     int a = solve(n-x, x, y, z) + 1;
//     int b = solve(n-y, x, y, z) + 1;
//     int c = solve(n-z, x, y, z) + 1;
    
//     int ans = max(a, max(b, c));
//     return ans;
// }

// int cutSegments(int n, int x, int y, int z) {
// 	// Write your code here.
//     int ans = solve(n, x, y, z);
//     if(ans<0)
//         return 0;
//     else
//         return ans;
// }


// ********************* Top-Down Approch - (recursion + memoization) ************************
// T.C = O(n)
// S.C = O(n)+O(n) = O(n)

// int solve(int n, int x, int y, int z, vector<int> &dp){
    
// //     base case
//     if(n==0) return 0;
//     if(n<0) return INT_MIN;
    
//     if(dp[n] != -1) return dp[n];
    
//     int a = solve(n-x, x, y, z, dp) + 1;
//     int b = solve(n-y, x, y, z, dp) + 1;
//     int c = solve(n-z, x, y, z, dp) + 1;
    
//     dp[n] = max(a, max(b, c));
//     return dp[n];
// }

// int cutSegments(int n, int x, int y, int z) {
//     // Write your code here.
//     vector<int> dp(n+1, -1);
//     int ans = solve(n, x, y, z, dp);
//     if(ans<0)
//         return 0;
//     else
//         return ans;
// }


// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(n)
// S.C = O(n)

int solve(int n, int x, int y, int z){
    
    vector<int> dp(n+1, -1);
//     base case
    dp[0] = 0;
    
    for(int i=1; i<=n; i++){
        if(i-x >= 0 && dp[i-x] != -1)
            dp[i] = max(dp[i], dp[i-x] + 1);
        
        if(i-y >= 0 && dp[i-y] != -1)
            dp[i] = max(dp[i], dp[i-y] + 1);
        
        if(i-z >= 0 && dp[i-z] != -1)
            dp[i] = max(dp[i], dp[i-z] + 1);
    }
    if(dp[n] < 0)
        return 0;
    else
        return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
    // Write your code here.
    return solve(n, x, y, z);
}