// ************************************* Best Time to Buy and Sell Stock *******************************************

// Know More :- https://drive.google.com/file/d/1P39bAP2VSr2aNGXdYMe29NLDjKm0a2tQ/view

// Compiler :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = prices[0];
        int profit = 0;
        
        for(int i=1; i<prices.size(); i++){
            
            int diff = prices[i] - mini;
            profit = max(profit, diff);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};