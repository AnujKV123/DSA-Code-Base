// ************************************** Maximum sum of non-adjacent elements ***********************************************

// know more :- https://drive.google.com/file/d/1MeB8PnElHmfZ5Z1yKrwwXYoAZRK15BR6/view

// code compiler :- https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include <bits/stdc++.h> 
using namespace std;

// ************************** recursion ******************************
// int findMaxSum(vector<int> &nums, int n){
//     if(n<0) return 0;
//     if(n==0) return nums[0];
    
//     return max(findMaxSum(nums, n-2)+nums[n], findMaxSum(nums, n-1)+0);
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.
//     int n = nums.size();
    
//     int ans = findMaxSum(nums, n);
//     return ans;
// }


// ********************* Top-Down Approch - (recursion + memoization) ************************
// T.C = O(n)
// S.C = O(n)+O(n) = O(n)

// int findMaxSum(vector<int> &nums, int n, vector<int> &dp){
//     if(n<0) return 0;
//     if(n==0) return nums[0];
    
//     if(dp[n] != -1) return dp[n];
    
//     dp[n] = max(findMaxSum(nums, n-2, dp)+nums[n], findMaxSum(nums, n-1, dp)+0);
//     return dp[n];
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.
//     int n = nums.size();
//     vector<int> dp(n+1, -1);
//     int ans = findMaxSum(nums, n-1, dp);
//     return ans;
// }


// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(n)
// S.C = O(n)

// int findMaxSum(vector<int> &nums, int n){
//     vector<int> dp(n, 0);
   
//     dp[0] = nums[0];
//     for(int i=1; i<n; i++){
//         int inc = dp[i-2] + nums[i];
//         int excl = dp[i-1] + 0;
//         dp[i] = max(inc, excl);
//     }
    
//     return dp[n-1];
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.
//     int n = nums.size();
//     int ans = findMaxSum(nums, n);
//     return ans;
// }


// ****************** Approch3 - Space Optimization *****************
// T.C = O(n)
// S.C = O(1)

int findMaxSum(vector<int> &nums, int n){
    
    int prev1 = 0;
    int prev2 = nums[0];
    for(int i=1; i<n; i++){
        int inc = prev1 + nums[i];
        int excl = prev2 + 0;
        int ans = max(inc, excl);
        prev1 = prev2;
        prev2 = ans;
    }
    
    return prev2;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int ans = findMaxSum(nums, n);
    return ans;
}