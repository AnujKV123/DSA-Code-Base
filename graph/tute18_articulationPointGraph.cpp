// *************************************** Articulation Points in a Graph *****************************************

// Articulation Points :- A node in a grapgh if you delete it graph is break into two  or more part

// know more :- https://www.codingninjas.com/codestudio/library/articulation-points-in-a-graph

// TC = O( n + e) n = no. of vertices, e = no of edges
// SC = O(n)  n = no. of vertices

#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, 
    vector<int> &articulationPoint, int &timer){

        vis[node] = true;
        disc[node] = low[node] = timer++;
        int child=0;

        for(auto nbr:adj[node]){
            if(nbr == parent) continue;

            if(!vis[nbr]){
                dfs(nbr, node, disc, low, vis, adj, articulationPoint, timer);
                low[node] = min(low[node], low[nbr]);

                // check articulation point or not
                if(low[nbr]>=disc[node] && parent != -1){
                    articulationPoint[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node], disc[nbr]);
            }
        }
        if(parent == -1 && child > 1){
            articulationPoint[node] = 1;
        }
    }

int main(){

    int n=5;
    int e=5;
    vector<pair<int, int>> edges;

    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({1, 2});

    // creating adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    int timer=0;
    vector<int> low(n);
    vector<int> disc(n);
    unordered_map<int, bool> vis;
    vector<int> articulationPoint(n, 0);

    for(int i=0; i<n; i++){
        disc[i] = -1;
        low[i] = -1;
    }

    // let's do the dfs
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, -1, disc, low, vis, adj, articulationPoint, timer);
        }
    }

    // print the articulation point
    for(int i=0; i<n; i++){
        if(articulationPoint[i] != 0){
            cout<<i<<" ";
        }cout<<endl;
    }

    return 0;
}