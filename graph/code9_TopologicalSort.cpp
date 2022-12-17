// ********************************* implementing topological sort by using DFS **********************************

/*  A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.

    Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex 'u' to vertex 'v', vertex 'u' 
    comes before 'v' in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

    Given a DAG consisting of 'V' vertices and 'E' edges, you need to find out any topological sorting of this DAG. Return an array of 
    size 'V' representing the topological sort of the vertices of the given DAG. 
*/ 



// TC = O(n + e) n = no. of nodes, e = no of edges
// SC = O(n + e) n = no. of nodes, e = no of edges


#include<bits/stdc++.h>
using namespace std;

void  TopologicalSort(int node, vector<bool> &visited, 
                     stack<int> &s, unordered_map<int, list<int>> &adj){
    
    visited[node] = true;
    
    for(auto neoghbours:adj[node]){
        if(!visited[neoghbours]){
            TopologicalSort(neoghbours, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    // first create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    vector<bool> visited(v);
    stack<int> s;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            TopologicalSort(i, visited, s, adj);
        }
    }
    
    vector<int> ans;
    while(!s.empty()){
        int top = s.top();
        ans.push_back(top);
        s.pop();
    }
    return ans;
}