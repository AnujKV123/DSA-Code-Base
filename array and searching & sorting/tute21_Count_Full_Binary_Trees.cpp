// ********************************** Count the Number of Full Binary Trees *****************************************

// know more :- https://practice.geeksforgeeks.org/problems/count-the-number-of-full-binary-trees2525/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

# define mod 1000000007
class Solution{
public:
    
    long long int numoffbt(long long int arr[], int n){
        // Your code goes here
        // sort(arr, arr+n);
        
        // long long int max = arr[n-1];
        // vector<int> visited(max+1, 0);
        // vector<long long int> total(max+1, 0);
        
        // for(int i=0; i<n; i++){
        //     visited[arr[i]] = 1;
        //     total[arr[i]] = 1;
        // }
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(visited[arr[i]] && visited[arr[j]] && visited[arr[i]*arr[j]]){
        //             total[arr[i]*arr[j]] = (total[arr[i]*arr[j]]%mod + 1)%mod;
        //         }
        //         else if(arr[i]*arr[j]>max){
        //             break;
        //         }
        //     }
        // }
        // long long int ans = 0;
        // for(long long int i=0; i<total.size(); i++){
        //     ans = (ans%mod + total[i]%mod)%mod;
        // }
        
        // return ans;
        
        const long long int MOD = 1000000007;
        long long int mn = INT_MAX, mx = INT_MIN;
        for(int i = 0; i < n; i++){
            mn = (mn > arr[i]) ? arr[i] : mn;
            mx = (mx < arr[i]) ? arr[i] : mx;
        }
        long long int ans = 0;
        int pd;
        vector<bool> vis(mx+1, false);
        vector<long long int> sol(mx+1, 0);
        for(int i = 0; i < n; i++){
            vis[arr[i]] = 1;
            sol[arr[i]] = 1;
        }
        for(int i = mn; i <= mx; i++){
            if(!vis[i]){
                continue;
            }
            for(int j = 2; i*j <= mx && j <= i; j++){
                pd = i*j;
                if(!vis[pd]){
                    continue;
                }
                sol[pd] = (sol[pd] + (sol[i]*sol[j])%MOD)%MOD;
                if(i != j){
                    sol[pd] = ( sol[pd] + (sol[i]*sol[j])%MOD)%MOD;
                }
            }
            ans = (ans + sol[i])%MOD;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends