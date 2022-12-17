// *********************************************** Best Time to Buy and Sell Stock III **********************************************

// know more :- https://drive.google.com/file/d/1QHHJOwADCIL1vGPlgyrit0jlmY_ZfSsK/view

// compiler :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// //     ************************************** recursion **********************************************
    
//     int solve(int index, int buy, vector<int>& prices, int limit){
        
//         if(index == prices.size()) return 0;
        
//         if(limit == 0) return 0;
        
//         int profit = 0;
//         if(buy){
//             int buyKaro = -prices[index] + solve(index+1, 0, prices, limit);
//             int skipKaro = 0 + solve(index+1, 1, prices, limit);
//             profit += max(buyKaro, skipKaro);
//         }
//         else{
//             int sellKaro = prices[index] + solve(index+1, 1, prices, limit-1);
//             int skipKaro = 0 + solve(index+1, 0, prices, limit);
//             profit += max(sellKaro, skipKaro);
//         }
//         return profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         return solve(0, 1, prices, 2);
//     }
    
    
    
// ********************* Top-Down Approch - (recursion + memoization) ***********************
    // T.C = O(n)
    // S.C = O(n)
    
//     int solve(int index, int buy, vector<int>& prices, vector<vector<vector<int>>> &dp, int limit){
        
//         if(index == prices.size()) return 0;
    
//         if(limit == 0) return 0;
        
//         if(dp[index][buy][limit] != -1) return dp[index][buy][limit];
        
//         int profit = 0;
//         if(buy){
//             int buyKaro = -prices[index] + solve(index+1, 0, prices, dp, limit);
//             int skipKaro = 0 + solve(index+1, 1, prices, dp, limit);
//             profit += max(buyKaro, skipKaro);
//         }
//         else{
//             int sellKaro = prices[index] + solve(index+1, 1, prices, dp, limit-1);
//             int skipKaro = 0 + solve(index+1, 0, prices, dp, limit);
//             profit += max(sellKaro, skipKaro);
//         }
//         return dp[index][buy][limit] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
        
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
//         return solve(0, 1, prices, dp, 2);
//     }
    
    
    
// ****************** Bottom-Up Approch - Tabulatopn Method ******************
//     T.C = O(n)
//     S.C = O(n)
    
//     int solve(vector<int>& prices){
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
//         for(int index=n-1; index>=0; index--){
//             for(int buy=0; buy<=1; buy++){
//                 for(int limit=1; limit<=2; limit++){
                
//                     int profit = 0;
//                     if(buy){
//                         int buyKaro = -prices[index] + dp[index+1][0][limit];
//                         int skipKaro = 0 + dp[index+1][1][limit];
//                         profit += max(buyKaro, skipKaro);
//                     }
//                     else{
//                         int sellKaro = prices[index] + dp[index+1][1][limit-1];
//                         int skipKaro = 0 + dp[index+1][0][limit];
//                         profit += max(sellKaro, skipKaro);
//                     }
//                     dp[index][buy][limit] = profit;
//                 }
//             }
//         }
//         return dp[0][1][2];
//     }
//     int maxProfit(vector<int>& prices) {
        
//         return solve(prices);
//     }
    
    
    

// ****************** Approch 3: - space optimization ******************
//     T.C = O(n)
//     S.C = O(1)
    
    int solve(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));
        
            for(int index=n-1; index>=0; index--){
                for(int buy=0; buy<=1; buy++){
                    for(int limit=1; limit<=2; limit++){

                    int profit = 0;
                    if(buy){
                        int buyKaro = -prices[index] + next[0][limit];
                        int skipKaro = 0 + next[1][limit];
                        profit += max(buyKaro, skipKaro);
                    }
                    else{
                        int sellKaro = prices[index] + next[1][limit-1];
                        int skipKaro = 0 + next[0][limit];
                        profit += max(sellKaro, skipKaro);
                    }
                    curr[buy][limit] = profit;
                 }
            }
            next = curr;
        }
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {
        
        return solve(prices);
    }
};