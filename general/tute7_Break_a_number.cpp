// ********************************** Break a number *********************************

// know more :- https://practice.geeksforgeeks.org/problems/break-a-number5913/1


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
// #define mod 1000000007
class Solution{   
public:
    int waysToBreakNumber(int N){
        // code here 
        
        // ***************** Approch-1 ***************
        
        // int j=1;
        // int ans=1;
        
        // for(int i=1; i<=N; i++){
        //     ++j;
        //     ans += j;
        //     ans = ans%mod;
        // }
        
        // return ans%mod;
        
        // ***************** Approch-2 *****************
        
        long mod = 1000000007;
        int ans = ( (N+1)%mod * (N+2)%mod )%mod/2;
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.waysToBreakNumber(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends