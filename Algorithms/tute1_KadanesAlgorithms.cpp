// ************************************* Kadane's Algorithm's ***************************************

// know more :- https://drive.google.com/file/d/1Gu02aK7qcEyJFyvoUdzeJ84k_ct7ZbwU/view

// related question :- https://leetcode.com/problems/maximum-subarray/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;
        int maxi = nums[0];
        
        for(int i=0; i<nums.size(); i++){
            
            sum += nums[i];
            
            maxi = max(maxi, sum);
            if(sum<0){
                sum = 0;
            }
        }
        return maxi;
    }
};