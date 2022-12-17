// *************************************** Count derangements ***************************************

// know more :- https://drive.google.com/file/d/1FMPmsyZvVVd6MO_5P0bqXPYHWKcZL0dO/view

//  compiler :- https://www.codingninjas.com/codestudio/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar



#define MOD 1000000007
#include<iostream>
#include<vector>
using namespace std;

// ************************ recursion ***************************
// T.C = O(n^2)
// S.C = O(n^2)
// long long int countDerangements(int n) {
//     // Write your code here.
    
// //     base case
//     if(n == 1) return 0;
//     if(n == 2) return 1;
    
//     int ans = ((n-1)%MOD*((countDerangements(n-1)%MOD) + 
//                          (countDerangements(n-2)%MOD))%MOD);
    
//     return ans;
// }


// ********************* Top-Down Approch - (recursion + memoization) ************************
// T.C = O(n)
// S.C = O(n)+O(n) = O(n)

// long long int solve(int n, vector<long long int> &dp) {
//     // Write your code here.
    
// //     base case
//     if(n == 1) return 0;
//     if(n == 2) return 1;
    
//     if(dp[n] != -1) return dp[n];
    
//     dp[n] = ((n-1)%MOD*((solve(n-1, dp)%MOD) + 
//                          (solve(n-2, dp)%MOD))%MOD);
    
//     return dp[n];
// }

// long long int countDerangements(int n) {
//     // Write your code here.
//     vector<long long int> dp(n+1, -1);
    
//     return solve(n, dp);
// }


// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(n)
// S.C = O(n)

// long long int solve(int n) {
//     // Write your code here.
//     vector<long long int> dp(n+1, 0);
    
// //     base case
//     dp[1] = 0;
//     dp[2] = 1;
    
    
//     for(int i=3; i<=n; i++){
//         dp[i] = ((i-1)%MOD*((dp[i-1]%MOD) + (dp[i-2]%MOD))%MOD);
//     }
    
//     return dp[n];
// }

// long long int countDerangements(int n) {
//     // Write your code here.
//     return solve(n);
// }


// ****************** Approch3 - Space Optimization *****************
// T.C = O(n)
// S.C = O(1)

long long int solve(int n) {

    long long int prev1 = 0;
    long long int prev2 = 1;
    
    
    for(int i=3; i<=n; i++){
        long long int ans = ((i-1)%MOD*((prev1%MOD) + (prev2%MOD))%MOD);
        prev1 = prev2;
        prev2 = ans;
    }
    
    return prev2;
}

long long int countDerangements(int n) {
    // Write your code here.
    return solve(n);
}