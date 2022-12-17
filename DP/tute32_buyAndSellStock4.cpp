// *********************************************** Best Time to Buy and Sell Stock IV **********************************************

// know more :- https://drive.google.com/file/d/1G0tsD7ubGz5HfWRdvDAlyFRUO8VUa_Aa/view

// compiler :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

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
//     int maxProfit(int k, vector<int>& prices) {
//         return solve(0, 1, prices, k);
//     }
    
    
    
// ********************* Top-Down Approch - (recursion + memoization) ***********************
    // T.C = O(n*k)
    // S.C = O(n*k)
    
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
//     int maxProfit(int k, vector<int>& prices) {
        
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
//         return solve(0, 1, prices, dp, k);
//     }
    
    
    
// ****************** Bottom-Up Approch - Tabulatopn Method ******************
//     T.C = O(n*k)
//     S.C = O(n*k)
    
//     int solve(int k, vector<int>& prices){
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
//         for(int index=n-1; index>=0; index--){
//             for(int buy=0; buy<=1; buy++){
//                 for(int limit=1; limit<=k; limit++){
                
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
//         return dp[0][1][k];
//     }
//     int maxProfit(int k, vector<int>& prices) {
        
//         return solve(k, prices);
//     }
    
    
    

// ****************** Approch 3: - space optimization ******************
//     T.C = O(n*k)
//     S.C = O(k)
    
//     int solve(int k, vector<int>& prices){
//         int n = prices.size();
//         vector<vector<int>> curr(2, vector<int>(k+1, 0));
//         vector<vector<int>> next(2, vector<int>(k+1, 0));
        
//             for(int index=n-1; index>=0; index--){
//                 for(int buy=0; buy<=1; buy++){
//                     for(int limit=1; limit<=k; limit++){

//                     int profit = 0;
//                     if(buy){
//                         int buyKaro = -prices[index] + next[0][limit];
//                         int skipKaro = 0 + next[1][limit];
//                         profit += max(buyKaro, skipKaro);
//                     }
//                     else{
//                         int sellKaro = prices[index] + next[1][limit-1];
//                         int skipKaro = 0 + next[0][limit];
//                         profit += max(sellKaro, skipKaro);
//                     }
//                     curr[buy][limit] = profit;
//                  }
//             }
//             next = curr;
//         }
//         return next[1][k];
//     }
//     int maxProfit(int k, vector<int>& prices) {
        
//         return solve(k, prices);
//     }
    
    
// ***************************************************** Method - 2 *****************************************************
    
// //     ************************************** recursion **********************************************
    
//     int solve(int index, int operationNo, vector<int>& prices, int k){
        
//         if(index == prices.size()) return 0;
        
//         if(operationNo == 2*k) return 0;
        
//         int profit = 0;
//         if(operationNo%2 == 0){
//             int buyKaro = -prices[index] + solve(index+1, operationNo+1, prices, k);
//             int skipKaro = 0 + solve(index+1, operationNo, prices, k);
//             profit += max(buyKaro, skipKaro);
//         }
//         else{
//             int sellKaro = prices[index] + solve(index+1, operationNo+1, prices, k);
//             int skipKaro = 0 + solve(index+1, operationNo, prices, k);
//             profit += max(sellKaro, skipKaro);
//         }
//         return profit;
//     }
//     int maxProfit(int k, vector<int>& prices) {
//         return solve(0, 0, prices, k);
//     }
    
    
    
    
// ********************* Top-Down Approch - (recursion + memoization) ***********************
    // T.C = O(n*k)
    // S.C = O(n*k)
    
//     int solve(int index, int operationNo, vector<int>& prices, vector<vector<int>> &dp, int k){
        
//         if(index == prices.size()) return 0;
    
//         if(operationNo == 2*k) return 0;
        
//         if(dp[index][operationNo] != -1) return dp[index][operationNo];
        
//         int profit = 0;
//         if(operationNo%2 == 0){
//             int buyKaro = -prices[index] + solve(index+1, operationNo+1, prices, dp, k);
//             int skipKaro = 0 + solve(index+1, operationNo, prices, dp, k);
//             profit += max(buyKaro, skipKaro);
//         }
//         else{
//             int sellKaro = prices[index] + solve(index+1, operationNo+1, prices, dp, k);
//             int skipKaro = 0 + solve(index+1, operationNo, prices, dp, k);
//             profit += max(sellKaro, skipKaro);
//         }
//         return dp[index][operationNo] = profit;
//     }
//     int maxProfit(int k, vector<int>& prices) {
        
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2*k, -1));
//         return solve(0, 0, prices, dp, k);
//     }  
    
    
    
    
// ****************** Bottom-Up Approch - Tabulatopn Method ******************
//     T.C = O(n*k)
//     S.C = O(n*k)
    
//     int solve(int k, vector<int>& prices){
//         int n = prices.size();
//         vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        
//         for(int index=n-1; index>=0; index--){
//             for(int operationNo=0; operationNo<2*k; operationNo++){

//                 int profit = 0;
//                 if(operationNo%2 == 0){
//                     int buyKaro = -prices[index] + dp[index+1][operationNo+1];
//                     int skipKaro = 0 + dp[index+1][operationNo];
//                     profit += max(buyKaro, skipKaro);
//                 }
//                 else{
//                     int sellKaro = prices[index] + dp[index+1][operationNo+1];
//                     int skipKaro = 0 + dp[index+1][operationNo];
//                     profit += max(sellKaro, skipKaro);
//                 }
//                 dp[index][operationNo] = profit;
//             }
//         }
//         return dp[0][0];
//     }
//     int maxProfit(int k, vector<int>& prices) {
        
//         return solve(k, prices);
//     }

    
    
    
    
    
// ****************** Bottom-Up Approch - Tabulatopn Method ******************
//     T.C = O(n*k)
//     S.C = O(k)
    
    int solve(int k, vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2*k+1, 0);
        vector<int> prev(2*k+1, 0);
        
        for(int index=n-1; index>=0; index--){
            for(int operationNo=0; operationNo<2*k; operationNo++){

                int profit = 0;
                if(operationNo%2 == 0){
                    int buyKaro = -prices[index] + prev[operationNo+1];
                    int skipKaro = 0 + prev[operationNo];
                    profit += max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[index] + prev[operationNo+1];
                    int skipKaro = 0 + prev[operationNo];
                    profit += max(sellKaro, skipKaro);
                }
                curr[operationNo] = profit;
            }
            prev = curr;
        }
        return prev[0];
    }
    int maxProfit(int k, vector<int>& prices) {
        
        return solve(k, prices);
    }
};