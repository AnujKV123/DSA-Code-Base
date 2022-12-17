// **************************************** Min Cost Climbing Stairs *******************************************

/* You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay 
the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 */ 

// code compiler :- https://leetcode.com/problems/min-cost-climbing-stairs/

// know more :- https://drive.google.com/file/d/1Lla9Dra26tRxzs73KMv1vMWS3U2kye7T/view
#include<bits/stdc++.h>
using namespace std;

// ********************* Top-Down Approch - (recursion + memoization) ************************
// T.C = O(n)
// S.C = O(n) + O(n) = O(n)

// class Solution {
// public:
//     int solve(int n, vector<int> &cost, vector<int> &dp){
        
// //         base case
//         if(n==0) return cost[0];
        
//         if(n==1) return cost[1];
        
// //         step3
//         if(dp[n] != -1) return dp[n];
        
//         dp[n] = cost[n] + min(solve(n-1, cost, dp), solve(n-2, cost, dp));
//         return dp[n];
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
        
//         int n = cost.size();
//         vector<int> dp(n+1, -1);
        
//         int ans = min(solve(n-1, cost, dp), solve(n-2, cost, dp));
        
//         return ans;
        
//     }
// };


// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(n)
// S.C = O(n)

// class Solution {
// public:
//     int solve(vector<int> &cost, int n){
//         vector<int> dp(n+1);

//         dp[0] = cost[0];
//         dp[1] = cost[1];
        
// //         step3
//         for(int i=2; i<n; i++){
//             dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
//         }
//         return min(dp[n-1], dp[n-2]);
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
        
//         int n = cost.size();
        
//         int ans = solve(cost, n);
        
//         return ans;
        
//     }
// };


// ****************** Approch3 - Space Optimization *****************
// T.C = O(n)
// S.C = O(1)

class Solution {
public:
    int solve(vector<int> &cost, int n){

        int prev1 = cost[0];
        int prev2 = cost[1];
        
//         step3
        for(int i=2; i<n; i++){
            int curr = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
            
        }
        return min(prev1, prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        int ans = solve(cost, n);
        
        return ans;
        
    }
};