// ************************** Bellman Ford Algorithm **************************

// know more :- https://www.programiz.com/dsa/bellman-ford-algorithm

#include<bits/stdc++.h>
using namespace std;

// TC = O(n*m) n = no. of nodes, m = no of edges
// SC = O(n) n = no. of nodes

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    
//     n-1 items
    for(int i=1; i<=n; i++){
//         traverse on edge list
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])){
                dist[v] = dist[u] + wt;
            }
        }
    }

    
//     check for negative cycle is present or not
    bool flag=0;  
    for(int j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != 1e9 && ((dist[u]+wt) < dist[v])){
            flag = 1;
        }
    }
    
    if(flag == 0){
        return dist[dest];
    }
    return -1;
}