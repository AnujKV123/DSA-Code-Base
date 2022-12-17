// ********************************* detect cycle in an undirected graph by using DFS **********************************

// TC = O(n + e) n = no. of nodes, e = no of edges
// SC = O(n + e) n = no. of nodes, e = no of edges

#include<bits/stdc++.h>
using namespace std;


bool isCycleDFS(int node, int parent, unordered_map<int, list<int>> &adj, 
               unordered_map<int, bool> &visited){
    visited[node] = true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool DetectCycle = isCycleDFS(neighbour, node, adj, visited);
            if(DetectCycle){
                return true;
            }
        }
        else if(neighbour != parent){
//             cycle is present
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // first create AdjList
    unordered_map<int, list<int>> adj;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    
//     handle disconnected components
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool result = isCycleDFS(i, -1, adj, visited);
            if(result){
                return "Yes";
            }
        }
    }
    return "No";
}
