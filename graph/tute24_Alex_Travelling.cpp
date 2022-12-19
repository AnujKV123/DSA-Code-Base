// ****************************************** Alex Travelling **************************************************

// know more :- https://practice.geeksforgeeks.org/problems/alex-travelling/1


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        
        vector<vector<vector<int>>> graph(n+1);
        for(int i  = 0 ; i < flights.size(); ++i){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            graph[u].push_back({v,w});
        }
        
        vector<int> dist(n+1, -1);
        queue<pair<int,int>> q;
        dist[k] = 0;
        q.push({k,dist[k]});
        int ans = INT_MIN;
        while(!q.empty()) {
            int node = q.front().first;
            int cost = q.front().second;
            q.pop();
            for(auto x: graph[node]) {
                int node_x = x[0];
                int cost_x = x[1];
                if(dist[node_x] == -1) {
                    dist[node_x] = cost + cost_x;
                    q.push({node_x, dist[node_x]});
                }
                else if(dist[node_x] > cost + cost_x) {
                    dist[node_x] = cost + cost_x;
                    q.push({node_x, dist[node_x]});
                }
            }
        }
        
        for(int i = 1 ; i < dist.size(); ++i) {
            if(dist[i] != -1) {
                ans = max(ans, dist[i]);
            }
            else return -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends