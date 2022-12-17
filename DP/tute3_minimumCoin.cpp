//  ***************************** Minimum Elements *********************************

// code compiler :- https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// know more :- https://drive.google.com/file/d/1k0TSXWRA8ja4j3CILO8hxzum84FPN4B2/view


#include <bits/stdc++.h> 
using namespace std;

// ********************* Top-Down Approch - (recursion + memoization) ************************
// T.C = O(x*n), x = amount, n = no. of coin
// S.C = O(x) + O(x) = O(x)

// int solveRec(vector<int> &num, int x, vector<int> &dp){
//     if(x==0) return x;
//     if(x < 0) return INT_MAX;
    
//     if(dp[x] != -1) return dp[x];
    
//     int mini = INT_MAX;
//     for(int i=0; i<num.size(); i++){
//         int ans = solveRec(num, x-num[i], dp);
//         if(ans != INT_MAX)
//             mini = min(mini, 1+ans);
//     }
//     dp[x] = mini;
//     return mini;
// }

// int minimumElements(vector<int> &num, int x)
// {
//     // Write your code here.

//     vector<int> dp(x+1, -1);
//     int ans = solveRec(num, x, dp);
//     if(ans != INT_MAX)
//         return ans;
//     return -1;
// }


// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(x*n), x = amount, n = no. of coin
// S.C = O(x)

int solveRec(vector<int> &num, int x){
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    
    for(int i=1; i<=x; i++){
        for(int j=0; j<num.size(); j++){
            if(i-num[j]>=0 && dp[i-num[j]] != INT_MAX){
                dp[i] = min(dp[i], 1+dp[i-num[j]]);
            }
        }
    }
    if(dp[x] == INT_MAX) return -1;
    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.

    int ans = solveRec(num, x);
    return ans;
}
