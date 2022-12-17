// *********************************** Minimum Swaps To Make Sequences Increasing *******************************************

// know more :- https://drive.google.com/file/d/1hCY4YGNAml-EXU51-PQ0QGoxX3ojXFbL/view

// compiler :- https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // ********************************** recursion **********************************
    
//     int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){
        
//         if(index == nums1.size()) return 0;
        
//         int ans = INT_MAX;
//         int prev1 = nums1[index-1];
//         int prev2 = nums2[index-1];
        
//         // catch
//         if(swapped)
//             swap(prev1, prev2);
        
//         // no swap
//         if(nums1[index] > prev1 && nums2[index] > prev2)
//             ans = solve(nums1, nums2, index+1, 0);
        
//         // swap
//         if(nums1[index] > prev2 && nums2[index] > prev1)
//             ans = min(ans, 1 + solve(nums1, nums2, index+1, 1));
        
//         return ans;
            
//     }
//     int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
//         nums1.insert(nums1.begin(), -1);
//         nums2.insert(nums2.begin(), -1);
//         // it means that the previous indexs are swapped or not
//         bool swapped = 0;
        
//         return solve(nums1, nums2, 1, swapped);
//     }
    
    

// ********************* Top-Down Approch - (recursion + memoization) ************************
    // T.C = O(n)
    // S.C = O(n)
    
//     int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>> &dp){
        
//         if(index == nums1.size()) return 0;
        
//         if(dp[index][swapped] != -1) return dp[index][swapped];
        
//         int ans = INT_MAX;
//         int prev1 = nums1[index-1];
//         int prev2 = nums2[index-1];
        
//         // catch
//         if(swapped)
//             swap(prev1, prev2);
        
//         // no swap
//         if(nums1[index] > prev1 && nums2[index] > prev2)
//             ans = solve(nums1, nums2, index+1, 0, dp);
        
//         // swap
//         if(nums1[index] > prev2 && nums2[index] > prev1)
//             ans = min(ans, 1 + solve(nums1, nums2, index+1, 1, dp));
        
//         return dp[index][swapped] = ans;
            
//     }
//     int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
//         nums1.insert(nums1.begin(), -1);
//         nums2.insert(nums2.begin(), -1);
//         // it means that the previous indexs are swapped or not
//         bool swapped = 0;
//         int n = nums1.size();
//         vector<vector<int>> dp(n, vector<int>(2, -1));
        
//         return solve(nums1, nums2, 1, swapped, dp);
//     }
    
    
    

// ****************** Bottom-Up Approch - Tabulatopn Method *****************
    // T.C = O(n)
    // S.C = O(n)
    
//     int solve(vector<int>& nums1, vector<int>& nums2){
//         int n = nums1.size();
//         vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
//         for(int index = n-1; index>=1; index--){
            
//             for(int swapped = 1; swapped>=0; swapped--){
                
//                 int ans = INT_MAX;
//                 int prev1 = nums1[index-1];
//                 int prev2 = nums2[index-1];

//                 // catch
//                 if(swapped)
//                     swap(prev1, prev2);

//                 // no swap
//                 if(nums1[index] > prev1 && nums2[index] > prev2)
//                     ans = dp[index+1][0];

//                 // swap
//                 if(nums1[index] > prev2 && nums2[index] > prev1)
//                     ans = min(ans, 1 + dp[index+1][1]);

//                 dp[index][swapped] = ans;
//             }
//         }
//         return dp[1][0];  
//     }
//     int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
//         nums1.insert(nums1.begin(), -1);
//         nums2.insert(nums2.begin(), -1);
        
//         return solve(nums1, nums2);
//     }
    
    
// ****************** Approch3 - Space Optimization *****************
    // T.C = O(n)
    // S.C = O(1)
    
    int solve(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        
        int swap = 0;
        int noswap = 0;
        int currswap = 0;
        int currnoswap = 0;
        
        for(int index = n-1; index>=1; index--){
            
            for(int swapped = 1; swapped>=0; swapped--){
                
                int ans = INT_MAX;
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // catch
                if(swapped){
                    int temp = prev1;
                    prev1 = prev2;
                    prev2 = temp;
                }

                // no swap
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = noswap;

                // swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + swap);

                if(swapped)
                    currswap = ans;
                else
                    currnoswap = ans;
            }
            swap = currswap;
            noswap = currnoswap;
        }
        return min(currswap, currnoswap);  
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        return solve(nums1, nums2);
    }
};