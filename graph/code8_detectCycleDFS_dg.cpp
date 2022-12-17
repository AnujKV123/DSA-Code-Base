// ********************************* detect cycle in a directed graph by using DFS **********************************

// TC = O(n + e) n = no. of nodes, e = no of edges
// SC = O(n + e) n = no. of nodes, e = no of edges

#include<bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, 
                  unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj){
    
    visited[node] = true;
    dfsVisited[node] = true;
    
    for(auto neoghbours:adj[node]){
        if(!visited[neoghbours]){
            bool detected = checkCycleDFS(neoghbours, visited, dfsVisited, adj);
            if(detected){
                return true;
            }
        }
        else if(dfsVisited[neoghbours]){
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    unordered_map<int, list<int>> adj;
    
//     create adj list
    for(int i=0; i<=edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    
//     call dfs for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bool cycle = checkCycleDFS(i, visited, dfsVisited, adj);
            if(cycle){
                return true;
            }
        }
    }
    return false;
}