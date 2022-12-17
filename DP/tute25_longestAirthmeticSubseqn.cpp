// **************************************  Longest Arithmetic Subsequence of Given Difference ************************************

// know more :- https://drive.google.com/file/d/1OttRTNraFwBEHFhePi5NLlD8GjaFaieT/view

// compiler :- https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int, int> dp;
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            
            int temp = arr[i] - difference;
            int tempAns = 0;
            
            // check answer already exists for temp or not
            if(dp.count(temp))
                tempAns = dp[temp];
            
            // update currAns
            dp[arr[i]] = 1 + tempAns;
            
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};