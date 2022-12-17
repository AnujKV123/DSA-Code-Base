// ********************************* implementing topological sort by Using Kahn's Algorithm(BFS) **********************************

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

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    // first create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }

    // finding all integers
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    queue<int> q;
//     push element have 0 in degree
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
//     do bfs
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
//         store ans
        ans.push_back(front);
        
//       neoghbours indegree updated
        for(auto neoghbours:adj[front]){
            indegree[neoghbours]--;
            if(indegree[neoghbours] == 0)
                q.push(neoghbours);
        }
    }
    return ans;
}
