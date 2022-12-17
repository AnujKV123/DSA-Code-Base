// ******************************** Minimum Sideway Jumps ****************************************

// know more :- https://drive.google.com/file/d/1N-d4Z86Phh04HJkH1jNTAFEcYyOpf_AE/view

// compiler :- https://leetcode.com/problems/minimum-sideway-jumps/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
//     ********************************** recursion *****************************************
    
//     int solve(vector<int>& obstacles, int currLane, int currPos){
        
//         int n = obstacles.size()-1;
        
//         if(currPos == n) return 0;
        
//         if(obstacles[currPos+1] != currLane){
//             return solve(obstacles, currLane, currPos+1);
//         }
//         else{
            
// //             sideways jump
//             int ans = INT_MAX;
//             for(int i=1; i<=3; i++){
//                 if(currLane != i && obstacles[currPos] != i)
//                     ans = min(ans, 1 + solve(obstacles, i, currPos));
//             }
//             return ans;
//         }
//     }
//     int minSideJumps(vector<int>& obstacles) {
        
//         return solve(obstacles, 2, 0);
//     }
    

// ********************* Top-Down Approch - (recursion + memoization) ***********************
        // T.C = O(n)
        // S.C = O(n)
    
//     int solve(vector<int>& obstacles, int currLane, int currPos, vector<vector<int>> &dp){
        
//         int n = obstacles.size()-1;
        
//         if(currPos == n) return 0;
        
//         if(dp[currLane][currPos] != -1) return dp[currLane][currPos];
        
//         if(obstacles[currPos+1] != currLane){
//             return solve(obstacles, currLane, currPos+1, dp);
//         }
//         else{
            
// //             sideways jump
//             int ans = INT_MAX;
//             for(int i=1; i<=3; i++){
//                 if(currLane != i && obstacles[currPos] != i)
//                     ans = min(ans, 1 + solve(obstacles, i, currPos, dp));
//             }
//             dp[currLane][currPos] = ans;
//             return dp[currLane][currPos];
//         }
//     }
    
//     int minSideJumps(vector<int>& obstacles) {
//         vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
//         return solve(obstacles, 2, 0, dp);
//     }
    
    
    

// ****************** Bottom-Up Approch - Tabulatopn Method *****************
        // T.C = O(n)
        // S.C = O(n)
//     int solve(vector<int>& obstacles){
        
//         int n = obstacles.size()-1;
//         vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));
        
//         dp[0][n] = 0;
//         dp[1][n] = 0;
//         dp[2][n] = 0;
//         dp[3][n] = 0;
        
//         for(int currPos = n-1; currPos>=0; currPos--){
//             for(int currLane = 1; currLane<=3; currLane++){
                
//                 if(obstacles[currPos+1] != currLane){
//                     dp[currLane][currPos] = dp[currLane][currPos+1];
//                 }
//                 else{

//         //             sideways jump
//                     int ans = 1e9;
//                     for(int i=1; i<=3; i++){
//                         if(currLane != i && obstacles[currPos] != i)
//                             ans = min(ans, 1 + dp[i][currPos+1]);
//                     }
//                     dp[currLane][currPos] = ans;
//                 }
//             }
//         }
        
//         return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
//     }
    
//     int minSideJumps(vector<int>& obstacles) {
        
//         return solve(obstacles);
//     }
    
    
    

// ****************** Approch3 - Space Optimization *****************
    // T.C = O(n)
    // S.C = O(1)
    
    int solve(vector<int>& obstacles){
        
        int n = obstacles.size()-1;
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);
        
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;
        
        for(int currPos = n-1; currPos>=0; currPos--){
            for(int currLane = 1; currLane<=3; currLane++){
                
                if(obstacles[currPos+1] != currLane){
                    curr[currLane] = next[currLane];
                }
                else{

        //             sideways jump
                    int ans = 1e9;
                    for(int i=1; i<=3; i++){
                        if(currLane != i && obstacles[currPos] != i)
                            ans = min(ans, 1 + next[i]);
                    }
                    curr[currLane] = ans;
                }
            }
            next = curr;
        }
        
        return min(curr[2], min(1+curr[1], 1+curr[3]));
    }
    
    int minSideJumps(vector<int>& obstacles) {
        
        return solve(obstacles);
    }
    
};