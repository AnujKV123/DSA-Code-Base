// *********************** Subsets ************************

/*  Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]  */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        void solve(vector<int> nums, int index, vector<int> output, vector<vector<int>>& ans){

            if(index >= nums.size()){
                ans.push_back(output);
                return;
            }

            // exclude
            solve(nums, index+1, output, ans);

            // include
            int element = nums[index];
            output.push_back(element);
            solve(nums, index+1, output, ans);

        }
    public:
        vector<vector<int>> subset(vector<int>& nums){
            int index = 0;
            vector<int> output;
             vector<vector<int>> ans;

             solve(nums, index, output, ans);
             return ans;
        }
};

int main(){
    vector<int> nums;
    int n;
    cout<<"Enter the aize of an Array:"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    Solution obj;
    vector<vector<int>> result = obj.subset(nums);
    
    cout<<"[";
    for(int i=0; i<result.size(); i++){

        if(i>0) cout<<", [";
        else cout<<"[";

        for(int j=0; j<result[i].size();j++){

            if(j>0)  cout<<", "<<result[i][j];
            else cout<<result[i][j];
        }
        cout<<"]";
    }
    cout<<"]";

    return 0;
}

