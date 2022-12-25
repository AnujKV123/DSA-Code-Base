// *********************************** Wine Buying and Selling ***********************************

// know more :- https://practice.geeksforgeeks.org/problems/wine-buying-and-selling/1



//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int> &arr,int size){
      
    //*********************** Approch-1***************************
    
        // long long ans=0;
        // int p=0,n=0;
        // while(1) {
        //     while(arr[p]<=0 && p<size) {
        //         p++;
        //     }
        //     while(arr[n]>=0 && n<size) {
        //         n++;
        //     }
        //     if(p==size || n==size) {
        //         break;
        //     }
        //     int x=min(arr[p],-arr[n]);
        //     arr[p]-=x;
        //     arr[n]+=x;
        //     ans+=x*abs(p-n);
        // }
        // return ans;
        
        // *********************** Approch-2 ******************************
        
        long long int sum=0, ans=0;
        
        for(int i=0; i<size; i++){
            sum += arr[i];
            ans += abs(sum);
        }
        return ans;
    }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends