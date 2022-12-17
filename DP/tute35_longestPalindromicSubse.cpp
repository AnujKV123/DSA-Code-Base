// ************************************ Longest Palindromic Subsequence ************************************

// know more :- https://drive.google.com/file/d/1zNrexJBrLOEvtVqeBO6_SqP75yKSY8NG/view

// compiler :- https://leetcode.com/problems/longest-palindromic-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// ****************** Approch 3: - space optimization ******************
//     T.C = O(n*m)
//     S.C = O(m)
    
    int solve(string& text1, string& text2){
        
        int n = text1.length();
        int m = text2.length();
        
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        for(int i=n-1; i>=0; i--){
            
            for(int j=m-1; j>=0; j--){
                
                int ans = 0;
                if(text1[i] == text2[j])
                    ans = 1 + next[j+1];
                else
                    ans = max(next[j], curr[j+1]);

                curr[j] = ans;
            }
            next = curr;
        }
        
        return next[0];
    }
    
    int longestPalindromeSubseq(string s) {
        
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        
        return solve(s, revStr);
    }
};