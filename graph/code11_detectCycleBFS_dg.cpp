// ********************************* detect cycle in a directed graph by using BFS or Kahn's algorithm **********************************

// TC = O(n + e) n = no. of nodes, e = no of edges
// SC = O(n + e) n = no. of nodes, e = no of edges


#include<bits/stdc++.h>
using namespace std;



// method 2:- by using Kahn's algorithm or BFS *******************

int detectCycleInDirectedGraph(int n, vector< pair < int, int >> &edges) {
  // Write your code here.
    unordered_map<int, list<int>> adj;
    
//     create adj list
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        
        adj[u].push_back(v);
    }
    // finding all indegrees
    vector<int> indegree(n);
//     findIndegree(indegree, adj);

    for(auto i:adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    
    queue<int> q;
//     push element have 0 in degree
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
//     do bfs
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
//        increment count
        cnt++;
        
//       neoghbours indegree updated
        for(auto neoghbours:adj[front]){
            indegree[neoghbours]--;
            if(indegree[neoghbours] == 0)
                q.push(neoghbours);
        }
    }
    if(cnt == n)
        return false;
    else
        return true;
}