// ************************************** minimum cost for ticket *********************************************

// know more :- https://drive.google.com/file/d/14fYHgLIdg9XPrB6PAyr3qj89_dlkpAXF/view
    // ans , https://drive.google.com/file/d/10yambBpPfNa7QsLI5XWqk8nWNHGDOmQi/view

// compiler :- https://www.codingninjas.com/codestudio/problems/minimum-coins_2180776?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include<bits/stdc++.h>
using namespace std;

// ************************** recursion ******************************
// int solve(int n, vector<int> days, vector<int> cost, int index){
    
// //     base case
//     if(index >= n) return 0;
    
// //     1 day pass
//     int option1 = cost[0] + solve(n, days, cost, index+1);
    
//     int i;
// //     7 days pass
//     for(i=index; i<n && days[i]<days[index] + 7; i++);
//     int option2 = cost[1] + solve(n, days, cost, i);
    
// //     30 days pass
//     for(i=index; i<n && days[i]<days[index] + 30; i++);
//     int option3 = cost[2] + solve(n, days, cost, i);
    
//     return min(option1, min(option2, option3));
// }

// int minimumCoins(int n, vector<int> days, vector<int> cost)
// {
//     // Write your code here.
//     return solve(n, days, cost, 0);
// }


// ********************* Top-Down Approch - (recursion + memoization) ************************
// T.C = O(n)
// S.C = O(n)

// int solve(int n, vector<int> days, vector<int> cost, int index, vector<int> &dp){
    
// //     base case
//     if(index >= n) return 0;
    
//     if(dp[index] != -1) return dp[index];
    
// //     1 day pass
//     int option1 = cost[0] + solve(n, days, cost, index+1, dp);
    
//     int i;
// //     7 days pass
//     for(i=index; i<n && days[i]<days[index] + 7; i++);
//     int option2 = cost[1] + solve(n, days, cost, i, dp);
    
// //     30 days pass
//     for(i=index; i<n && days[i]<days[index] + 30; i++);
//     int option3 = cost[2] + solve(n, days, cost, i, dp);
    
//     dp[index] = min(option1, min(option2, option3));
//     return dp[index];
// }

// int minimumCoins(int n, vector<int> days, vector<int> cost)
// {
//     // Write your code here.
//     vector<int> dp(n+1, -1);
//     return solve(n, days, cost, 0, dp);
// }



// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(n)
// S.C = O(n)

// int solve(int n, vector<int> days, vector<int> cost){
//     vector<int> dp(n+1, INT_MAX);
// //     base case
//     dp[n] = 0;
    
//     for(int k=n-1; k>=0; k--){
//     //     1 day pass
//         int option1 = cost[0] + dp[k+1];

//         int i;
//     //     7 days pass
//         for(i=k; i<n && days[i]<days[k] + 7; i++);
//         int option2 = cost[1] + dp[i];

//     //     30 days pass
//         for(i=k; i<n && days[i]<days[k] + 30; i++);
//         int option3 = cost[2] + dp[i];

//         dp[k] = min(option1, min(option2, option3));
//     }
//     return dp[0];
// }

// int minimumCoins(int n, vector<int> days, vector<int> cost)
// {
//     // Write your code here.
//     return solve(n, days, cost);
// }



// ****************** Approch3 - Space Optimization *****************
// T.C = O(n)
// S.C = O(1)
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    int ans = 0;
    queue<pair<int, int>> month;
    queue<pair<int, int>> week;
    
    for(int day:days){
//         step1: remove expired days
        while(!month.empty() && month.front().first + 30 <= day)
            month.pop();
        
        while(!week.empty() && week.front().first + 7 <= day)
            week.pop();
        
//         step2: add cost for current days
        week.push(make_pair(day, ans+cost[1]));
        month.push(make_pair(day, ans+cost[2]));
        
        ans = min(ans+cost[0], min(week.front().second, month.front().second));
    }
    return ans;
}