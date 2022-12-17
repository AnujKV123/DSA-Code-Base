// ********************************* Count Strongly Connected Components (Kosaraju’s Algorithm) **********************************

// know more :- https://www.programiz.com/dsa/strongly-connected-components

#include<bits/stdc++.h>
using namespace std;

// TC = O(v + e) v = no. of nodes, e = no of edges
// SC = O(v + e) v = no. of nodes, e = no of edges

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, 
        unordered_map<int, list<int>> &adj){
    
    vis[node] = true;
    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            dfs(nbr, vis, st, adj);
        }
    }
    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &vis, 
            unordered_map<int, list<int>> &transpose){
    
    vis[node] = true;
    for(auto nbr:transpose[node]){
        if(!vis[nbr]){
            revDfs(nbr, vis, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
//     topological sort
    unordered_map<int, bool> vis;
    stack<int> st;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, vis, st, adj);
        }
    }
    
//     create a transpose graph
    unordered_map<int, list<int>> transpose;
    for(int i=0; i<v; i++){
        vis[i] = 0;
        for(auto nbr:adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    
//     dfs calling using above ordering
    int count=0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]){
            count++;
            revDfs(top, vis, transpose);
        }
    }
    return count;
}
