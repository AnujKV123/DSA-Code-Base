// ******************************************* Number Of Open Doors ***************************** V.V.I- must read full question

// know more :- https://practice.geeksforgeeks.org/problems/number-of-open-doors1552/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int noOfOpenDoors(long long N) {
        // code here
        // int ans=0;
        
        // vector<int> a(N+1,1);
        
        // for(long long i=2;i<N+1;i++){
            
        //     long long s=1;
            
        //     while((i*s)<N+1){
        //         if(a[i*s]){
        //             a[i*s]=0;
        //         }
        //         else{
        //             a[i*s]=1;
        //         }
        //         s++;
        //     }
        // }
        
        // for(long long i=1;i<N+1;i++){
        //     if(a[i]){
        //         ans++;
        //     }
        // }
        
        // return ans;
        
        return int(sqrt(N));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.noOfOpenDoors(N) << endl;
    }
    return 0;
}
// } Driver Code Ends