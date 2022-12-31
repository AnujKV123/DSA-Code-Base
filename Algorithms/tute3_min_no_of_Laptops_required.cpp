// ******************************** Find minimum number of Laptops required ***************************************

// know more :- https://practice.geeksforgeeks.org/problems/af49b143a4ead583e943ca6176fbd7ea55b121ae/1


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        // Code here
        map<int,int>m;
        for(int i=0; i<N; i++){
            m[start[i]] += 1;
            m[end[i]] -= 1;
        }
        vector<pair<int,int>> vec;
        for(auto it: m) vec.push_back(it);
        int c=0,ans=0;
        for(pair<int,int> i:vec){
            c+=i.second;
            ans=max(ans,c);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends