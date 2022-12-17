// ******************** House Robber II *********************************

//  compiler :- https://www.codingninjas.com/codestudio/problems/house-robber_839733?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include <bits/stdc++.h> 
using namespace std;

// ********************* Top-Down Approch - (recursion + memoization) ************************
// T.C = O(n)+O(n)+O(n) = O(n)
// S.C = O(n)+O(n)+O(n)+O(n) = O(n)

// long long int findMaxSum(vector<int> &nums, int n, vector<int> &dp){
//     if(n<0) return 0;
//     if(n==0) return nums[0];
    
//     if(dp[n] != -1) return dp[n];
    
//     dp[n] = max(findMaxSum(nums, n-2, dp)+nums[n], findMaxSum(nums, n-1, dp)+0);
//     return dp[n];
// }

// long long int houseRobber(vector<int>& valueInHouse)
// {
//     // Write your code here.
//     int n = valueInHouse.size();
    
//     if(n==1) return valueInHouse[0];

//     vector<int> dp(n, -1);
//     vector<int> first, second;
//     for(int i=0; i<n; i++){
//         if(i != 0) 
//             first.push_back(valueInHouse[i]);
//         if(i != n-1)
//             second.push_back(valueInHouse[i]);
//     }
//     long long int x = findMaxSum(first, n-2, dp);
//     long long int y = findMaxSum(second, n-2, dp);
//     return max(x, y);
    
// }


// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(n)+O(n)+O(n) = O(n)
// S.C = O(n)+O(n)+O(n) = O(n)

// long long int findMaxSum(vector<int> &nums, int n){
//     vector<int> dp(n, 0);
   
//     dp[0] = nums[0];
//     for(int i=1; i<n; i++){
//         long long int inc = dp[i-2] + nums[i];
//         long long int excl = dp[i-1] + 0;
//         dp[i] = max(inc, excl);
//     }
    
//     return dp[n-1];
// }

// long long int houseRobber(vector<int>& valueInHouse)
// {
//     // Write your code here.
//     int n = valueInHouse.size();
    
//     if(n==1) return valueInHouse[0];
    
//     vector<int> first, second;
//     for(int i=0; i<n; i++){
//         if(i != 0) 
//             first.push_back(valueInHouse[i]);
//         if(i != n-1)
//             second.push_back(valueInHouse[i]);
//     }
// //     long long int x = findMaxSum(first, n-1);
// //     long long int y = findMaxSum(second, n-1);
//     return max(findMaxSum(first, n-1), findMaxSum(second, n-1));
    
// }



// ****************** Approch3 - Space Optimization *****************
// T.C = O(n)+O(n)+O(n) = O(n)
// S.C = O(n)+O(n) = O(n)

long long int findMaxSum(vector<int> &nums, int n){
    
    long long int prev1 = 0;
    long long int prev2 = nums[0];
    for(int i=1; i<n; i++){
        long long int inc = prev1 + nums[i];
        long long int excl = prev2 + 0;
        long long int ans = max(inc, excl);
        prev1 = prev2;
        prev2 = ans;
    }
    
    return prev2;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    
    if(n==1) return valueInHouse[0];
    
    vector<int> first, second;
    for(int i=0; i<n; i++){
        if(i != 0) 
            first.push_back(valueInHouse[i]);
        if(i != n-1)
            second.push_back(valueInHouse[i]);
    }
//     long long int x = findMaxSum(first, n-1);
//     long long int y = findMaxSum(second, n-1);
    return max(findMaxSum(first, n-1), findMaxSum(second, n-1));
    
}