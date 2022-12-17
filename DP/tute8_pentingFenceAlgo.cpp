// ****************************** Painting Fence Algorithm *******************************

// know more :- https://www.geeksforgeeks.org/painting-fence-algorithm/

// dlides :- https://drive.google.com/file/d/1thnHoMRdAucm9RM6FCbqvgnZAhcF3gTy/view

//  compiler :- https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//  main recursive relation is :- solve(n) = solve(n-2)*(k-1) + solve(n-1)*(k-1);


#include <bits/stdc++.h> 
#define MOD 1000000007

// ************************* recursion ***************************
// int add(int a, int b){
//     return (a%MOD + b%MOD)%MOD;
// }

// int mul(int a, int b){
//     return (a%MOD * 1LL * b%MOD)%MOD;
// }

// int solve(int n, int k){
//     if(n == 1) return k;
    
//     if(n == 2) return add(k, mul(k, k-1));
    
//     int ans = add(mul(solve(n-2, k), k-1), mul(solve(n-1, k), k-1));
//     return ans;
    
// }

// int numberOfWays(int n, int k) {
//     // Write your code here.
//     return solve(n, k);
// }


// ********************* Top-Down Approch - (recursion + memoization) ************************
// T.C = O(n)
// S.C = O(n)+O(n) = O(n)

// int add(int a, int b){
//     return (a%MOD + b%MOD)%MOD;
// }

// int mul(int a, int b){
//     return (a%MOD * 1LL * b%MOD)%MOD;
// }

// int solve(int n, int k, vector<int> &dp){
//     if(n == 1) return k;
    
//     if(n == 2) return add(k, mul(k, k-1));
    
//     if(dp[n] != -1) return dp[n];
    
//     dp[n] = add(mul(solve(n-2, k, dp), k-1), mul(solve(n-1, k, dp), k-1));
//     return dp[n];
    
// }

// int numberOfWays(int n, int k) {
//     // Write your code here.
//     vector<int> dp(n+1, -1);
//     return solve(n, k, dp);
// }



// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(n)
// S.C = O(n)

// int add(int a, int b){
//     return (a%MOD + b%MOD)%MOD;
// }

// int mul(int a, int b){
//     return (a%MOD * 1LL * b%MOD)%MOD;
// }

// int solve(int n, int k){
//      vector<int> dp(n+1, 0);
//     dp[1] = k;
//     dp[2] = add(k, mul(k, k-1));
    
//     for(int i=3; i<=n; i++){
//         dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
//     }
//     return dp[n];
    
// }

// int numberOfWays(int n, int k) {
//     // Write your code here.
//     return solve(n, k);
// }



// ****************** Approch3 - Space Optimization *****************
// T.C = O(n)
// S.C = O(1)
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return (a%MOD * 1LL * b%MOD)%MOD;
}

int solve(int n, int k){
    int prev1 = k;
    int prev2 = add(k, mul(k, k-1));
    
    for(int i=3; i<=n; i++){
        int ans = add(mul(prev1, k-1), mul(prev2, k-1));
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
    
}

int numberOfWays(int n, int k) {
    // Write your code here.
    return solve(n, k);
}
