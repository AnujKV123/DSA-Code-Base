// *********************** Permutations ************************

/*  Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]

 

Constraints:

    1 <= nums.length <= 6
    -10 <= nums[i] <= 10
    All the integers of nums are unique.

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        void solve(vector<int> nums, int index, vector<vector<int>>& ans){

            if(index >= nums.size()){
                ans.push_back(nums);
                return;
            }

            for(int j = index; j<nums.size(); j++){

                swap(nums[index], nums[j]);
                solve(nums, index+1, ans);

                // backtracking
                swap(nums[index], nums[j]);

            }

        }
    public:
        vector<vector<int>> permutation(vector<int>& nums){
            int index = 0;
             vector<vector<int>> ans;

             solve(nums, index, ans);
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
    vector<vector<int>> result = obj.permutation(nums);
    
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
