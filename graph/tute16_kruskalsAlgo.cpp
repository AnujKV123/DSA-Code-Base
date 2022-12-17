// ***************************** finding Minimum Spanning Tree by using kruskal's Algorithm ********************************

#include<bits/stdc++.h>
using namespace std;

// TC = O(eloge) or O(vlogv) v = no. of vertices, e = no of edges
// SC = O(n)  n = no. of vertices

// creating a comparetor
bool cmp(vector<int> &a, vector<int> &b){
    return a[2]<b[2];
}

void markSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
    
    vector<int> parent(n);
    vector<int> rank(n);
    markSet(parent, rank, n);
    sort(edges.begin(), edges.end(), cmp);
    
    int minWeight = 0;
    
    for(int i=0; i<edges.size(); i++){
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        
        if(u != v){
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}