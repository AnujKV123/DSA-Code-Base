// *********************************** Akku and Binary Numbers ************************************

// know more :- https://practice.geeksforgeeks.org/problems/akku-and-binary-numbers0902/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    vector<long long int> v;
    void precompute()
    {
        // Code Here
        for(int i=0; i<63; i++){
            for(int j=i+1; j<63; j++){
                for(int k=j+1; k<63; k++){
                    
                    long long int temp = pow(2, i) + pow(2, j) + pow(2, k);
                    v.push_back(temp);
                }
            }
        }
        sort(v.begin(), v.end());
    }
    
    long long solve(long long l, long long r){
        // Code Here
        return (upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l));
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends