// ********************************* detect cycle in an undirected graph by using BFS **********************************

// TC = O(n + e) n = no. of nodes, e = no of edges
// SC = O(n + e) n = no. of nodes, e = no of edges

#include<bits/stdc++.h>
using namespace std;


bool isCycleBFS(int node, unordered_map<int, list<int>> &adj, 
               unordered_map<int, bool> &visited){
    queue<int> q;
    unordered_map<int, int> parent;
    
    parent[node] = -1;
    visited[node] = 1;
    q.push(node);
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto neighbour:adj[front]){
            if(visited[neighbour] && neighbour != parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
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
            bool result = isCycleBFS(i, adj, visited);
            if(result){
                return "Yes";
            }
        }
    }
    return "No";
}
