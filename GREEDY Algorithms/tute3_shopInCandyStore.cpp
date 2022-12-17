// ******************************************** Shop in Candy Store *********************************************

// compiler :- https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies, candies+N);
        
        int maxi = 0;
        int mini = 0;
        
        
        int x=N;
        for(int i=0; i<x; i++){
            
            mini = mini + candies[i];
            x = x-K;
        }
        
        x=0;
        for(int i=N-1; i>=x; i--){
            
            maxi = maxi + candies[i];
            x = x + K;
        }
        
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends