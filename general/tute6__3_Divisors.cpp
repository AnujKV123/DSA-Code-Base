// **************************************** 3 Divisors *********************************************

// know more :- https://practice.geeksforgeeks.org/problems/3-divisors3942/1


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int solve(long long int  n){

        n=sqrt(n);
    
        bool prime[n+1];
    
        memset(prime,true,sizeof(prime));
    
        for(int i=2;i*i<=n;i++){
    
            if(prime[i]==true){
    
                for(int p=i*i;p<=n;p=p+i){
    
                    prime[p]=false;
    
                }
    
            }
    
        }
    
        int c=0;
    
        for(int i=2;i<=n;i++){
    
            if(prime[i])c++;
    
        }
    
        return c;
    
    }

    vector<int> threeDivisors(vector<long long> query, int q)
    {

        vector<int>ans;

       for(int i=0;i<query.size();i++){

           int z=solve(query[i]);

           ans.push_back(z);

       }

       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends