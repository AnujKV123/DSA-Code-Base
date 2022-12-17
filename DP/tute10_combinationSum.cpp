// ***************************** Combination Sum ***********************************


// know more :- https://drive.google.com/file/d/1WBv76GVH0USFx0_n_KeTSBtViHo9Xx7U/view

// compiler :- https://www.codingninjas.com/codestudio/problems/number-of-ways_3755252?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include <bits/stdc++.h> 
using namespace std;

// ************************** recursion ****************************
// int solve(vector<int> &num, int tar){
//     if(tar<0) return 0;
    
//     if(tar == 0) return 1;
    
//     int ans = 0;
//     for(int i=0; i<num.size(); i++){
//         ans += solve(num, tar-num[i]);
//     }
//     return ans;
// }

// int findWays(vector<int> &num, int tar)
// {
//     // Write your code here.
//     return solve(num, tar);
// }


// ********************* Top-Down Approch - (recursion + memoization) ************************
// int solve(vector<int> &num, int tar, vector<int> &dp){
//     if(tar<0) return 0;
    
//     if(tar == 0) return 1;
    
//     if(dp[tar] != -1) return dp[tar];
    
//     int ans = 0;
//     for(int i=0; i<num.size(); i++){
//         ans += solve(num, tar-num[i], dp);
//     }
//     dp[tar] = ans;
//     return dp[tar];
// }

// int findWays(vector<int> &num, int tar)
// {
//     // Write your code here.
//     vector<int> dp(tar+1, -1);
//     return solve(num, tar, dp);
// }



// ****************** Bottom-Up Approch - Tabulatopn Method *****************
int solve(vector<int> &num, int tar){
    vector<int> dp(tar+1, 0);
    
    dp[0] = 1;
    
    int ans = 0;
    
//     traversing from target 1 to tar
    for(int i=1; i<=tar; i++){
//         traversing on num vector
        for(int j=0; j<num.size(); j++){
            if(i-num[j]>=0)
                dp[i] += dp[i-num[j]];
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    return solve(num, tar);
}