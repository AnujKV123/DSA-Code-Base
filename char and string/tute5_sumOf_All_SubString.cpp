// *************************************** Sum of Beauty of All Substrings **********************************

// know more :- https://practice.geeksforgeeks.org/problems/sum-of-beauty-of-all-substrings-1662962118/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        
    // // **************************** Approch-1 ******************************
    //     // Your code goes here
        int ans=0;
        
        for(int i=0; i<s.length(); i++){
            unordered_map<char, int> mp;
            
            for(int j=i; j<s.length(); j++){
                int maxi=INT_MIN, mini=INT_MAX;
                mp[s[j]]++;
                
                for(auto it:mp){
                    if(mini>it.second) mini=it.second;
                    if(it.second>maxi) maxi=it.second;
                }
                
                int beauty = maxi-mini;
                ans = ans+beauty;
            }
        }
        return ans;
    
    // ******************************* Approch-2 ***********************************

        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends