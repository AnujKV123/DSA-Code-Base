// ***************************************** Knapsack problem **************************************


// compiler :- https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// know more :- https://drive.google.com/file/d/1nJCTpP7gjkEuh7Vcr27OVFC7tjEBtCXn/view


#include <bits/stdc++.h>
using namespace std; 

// ******************************** recursion ************************************
// int solve(vector<int> &weight, vector<int> &value, int index, int capacity){
    
// //     base case
// //     if only 1 item to steal, then compare its weight weight with the Knapsack capacity
//     if(index == 0){
//         if(weight[0] <= capacity)
//             return value[0];
//         else
//             return 0;
//     }
//     int include = 0;
//     if(weight[index] <= capacity)
//         include = value[index] + solve(weight, value, index-1, capacity-weight[index]);
    
//     int exclude = 0 + solve(weight, value, index-1, capacity);
    
//     return max(include, exclude);
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	// Write your code here
//     return solve(weight, value, n-1, maxWeight);
// }


// ********************* Top-Down Approch - (recursion + memoization) ************************
// T.C = O(n*capacity)
// S.C = O(n*capacity)

// int solve(vector<int> &weight, vector<int> &value, int index, int capacity, 
//          vector<vector<int>> &dp){
    
// //     base case
// //     if only 1 item to steal, then compare its weight weight with the Knapsack capacity
//     if(index == 0){
//         if(weight[0] <= capacity)
//             return value[0];
//         else
//             return 0;
//     }
    
//     if(dp[index][capacity] != -1) return dp[index][capacity];
    
//     int include = 0;
//     if(weight[index] <= capacity)
//         include = value[index] + solve(weight, value, index-1, capacity-weight[index], dp);
    
//     int exclude = 0 + solve(weight, value, index-1, capacity, dp);
    
//     dp[index][capacity] = max(include, exclude);
//     return dp[index][capacity];
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
//     // Write your code here
//     vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
//     return solve(weight, value, n-1, maxWeight, dp);
// }


// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(n*capacity)
// S.C = O(n*capacity)

// int solve(vector<int> &weight, vector<int> &value, int n, int capacity){
//     vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
    
// //     analyse base case
//     for(int w = weight[0]; w<=capacity; w++){
//         if(weight[0] <= capacity)
//             dp[0][w] = value[0];
//         else
//             dp[0][w] = 0;
//     }
    
// //     take care of remaning recursive calls
//     for(int index = 1; index<n; index++){
//         for(int w=0; w<=capacity; w++){
//             int include = 0;
//             if(weight[index] <= w)
//                 include = value[index] + dp[index-1][w-weight[index]];

//             int exclude = 0 + dp[index-1][w];

//             dp[index][w] = max(include, exclude);
            
//         }
//     }
//     return dp[n-1][capacity];
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
//     // Write your code here
//     return solve(weight, value, n, maxWeight);
// }



// ****************** Approch3 - Space Optimization *****************
// T.C = O(n*capacity)
// S.C = O(2*capacity)

// int solve(vector<int> &weight, vector<int> &value, int n, int capacity){
//     vector<int> prev(capacity+1, 0);
//     vector<int> curr(capacity+1, 0);
    
// //     analyse base case
//     for(int w = weight[0]; w<=capacity; w++){
//         if(weight[0] <= capacity)
//             prev[w] = value[0];
//         else
//             prev[w] = 0;
//     }
    
// //     take care of remaning recursive calls
//     for(int index = 1; index<n; index++){
//         for(int w=0; w<=capacity; w++){
//             int include = 0;
//             if(weight[index] <= w)
//                 include = value[index] + prev[w-weight[index]];

//             int exclude = 0 + prev[w];

//             curr[w] = max(include, exclude);
            
//         }
//         prev = curr;
//     }
//     return prev[capacity];
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
//     // Write your code here
//     return solve(weight, value, n, maxWeight);
// }



// ****************** Approch3 - Space Optimization ++++(more optimized)++++ *****************
// T.C = O(n*capacity)
// S>C = O(capacity)

int solve(vector<int> &weight, vector<int> &value, int n, int capacity){
    vector<int> curr(capacity+1, 0);
    
//     analyse base case
    for(int w = weight[0]; w<=capacity; w++){
        if(weight[0] <= capacity)
           curr[w] = value[0];
        else
            curr[w] = 0;
    }
    
//     take care of remaning recursive calls
    for(int index = 1; index<n; index++){
        for(int w=capacity; w>=0; w--){
            int include = 0;
            if(weight[index] <= w)
                include = value[index] + curr[w-weight[index]];

            int exclude = 0 + curr[w];

            curr[w] = max(include, exclude);
            
        }
    }
    return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // Write your code here
    return solve(weight, value, n, maxWeight);
}