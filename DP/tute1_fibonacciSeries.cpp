// ************************* introduction to dp - fibonacci series *************************

// compiler :- https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_74156?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

//  know more :- https://drive.google.com/file/d/1TJoGLJGk04p9JTVF_m7FKgxGpvqY3xng/view

#include<bits/stdc++.h>
using namespace std;

// ********************* Top-Down Approch - (recursion + memoization) ************************
// T.C = O(n)
// S.C = O(n)+O(n) = O(n)

// int fibo(vector<int> &dp, int n){
// //     step1 :- base case
//     if(n==0 || n==1) return n;
    
// //     step3
//     if(dp[n] != -1) return dp[n];
    
// //     step2
//     dp[n] = fibo(dp, n-1) + fibo(dp, n-2);
//     return dp[n];
// }

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> dp(n+1);
//     for(int i=0; i<=n; i++)
//         dp[i] = -1;
//     cout<<fibo(dp, n)<<endl;
// }

// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// batter solution than approch 1
// T.C = O(n)
// S.C = O(n)

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> dp(n+1);
//     dp[0] = 0;
//     dp[1] = 1;
    
//     for(int i=2; i<=n; i++){
//         dp[i] = dp[i-1] + dp[i-2];
//     }
//     cout<<dp[n]<<endl;
// }

// ****************** Approch3 - Space Optimization *****************
// batter solution than approch 1
// T.C = O(n)
// S.C = O(1)

int main()
{
    int n;
    cin>>n;
    int prev1 = 0;
    int prev2 = 1;
    
    if(n==0) cout<<prev1;
    
    for(int i=2; i<=n; i++){
        int curr = prev1 + prev2;
//         shifting
        prev1 = prev2;
        prev2 = curr;
    }
    cout<<prev2<<endl;
    return 0;
}