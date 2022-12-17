// ********************************* Prim's Algorithm **********************************

// for detail explain :- https://www.programiz.com/dsa/prim-algorithm
// for detail explain :- https://www.javatpoint.com/prim-algorithm


#include<bits/stdc++.h>
using namespace std;
// TC = O(n^2) v = no. of vertices, e = no of edges
// SC = O(n + v) v = no. of vertices, e = no of edges



vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // first create adjLiat
    unordered_map<int, list<pair<int, int>>> adj;
    
    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    
    for(int i=1; i<=n; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    
//     **************** let's start the algo ********************
    key[1] = 0;
    parent[1] = -1;
    
    for(int i=1; i<n; i++){
        int mini = INT_MAX;
        int u;
//         let's find the mini node
        for(int v=1; v<=n; v++){
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini = key[v];
            }
        }
//         mark min node as true
        mst[u] = true;
        
//         check it's adjacent node
        for(auto i:adj[u]){
            int v = i.first;
            int w = i.second;
            if(mst[v]==false && w<key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; i++){
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}

// ********************************** Another optinal Approch by using heap **************************************

// TC = O(nlog(n)) v = no. of vertices, e = no of edges
// SC = O(n + v) v = no. of vertices, e = no of edges


#include<bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // first create adjLiat
    unordered_map<int, list<pair<int, int>>> adj;
    
    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    
    for(int i=1; i<=n; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    
//     **************** let's start the algo ********************
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[1] = 0;
    parent[1] = -1;
    pq.push({0, 1});
    
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        mst[u] = true;
        
//         check it's adjacent node
        for(auto i:adj[u]){
            int v = i.first;
            int w = i.second;
            if(mst[v]==false && w<key[v]){
                parent[v] = u;
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; i++){
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}

