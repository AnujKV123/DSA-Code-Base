// ************************************** Russian Doll Envelopes **************************************

// compiler :- https://leetcode.com/problems/russian-doll-envelopes/
// T.C = O(n)
// S.C = O(nlogn)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(vector<int> &v1,vector<int> &v2){
        if(v1[0]!=v2[0]) return v1[0]<v2[0];
        else return v1[1]>v2[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),comp);
        
        int n=envelopes.size();
        
        vector<int> dp;
        
        dp.push_back(envelopes[0][1]);
        
        for(int i=1;i<n;i++){
            
            if(envelopes[i][1]>dp.back()){
                
                dp.push_back(envelopes[i][1]);
            }else{
                
                int lb=lower_bound(dp.begin(),dp.end(),envelopes[i][1])-dp.begin();
                dp[lb]=envelopes[i][1];
            }
        }
        return dp.size();
    }
};