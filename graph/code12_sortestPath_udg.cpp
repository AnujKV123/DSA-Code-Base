// ********************************* find the sotest path in a graph by using BFS (in unweighted graph)**********************************

// TC = O(n + e) n = no. of nodes, e = no of edges
// SC = O(n + e) n = no. of nodes, e = no of edges

// know more :- https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// first create adj list
    unordered_map<int, list<int>> adj;
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto neighbours:adj[front]){
            if(!visited[neighbours]){
                visited[neighbours]=true;
                parent[neighbours] = front;
                q.push(neighbours);
            }
        }
    }
    vector<int> ans;
    int currNode = t;
    ans.push_back(currNode);
    while(currNode != s){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
