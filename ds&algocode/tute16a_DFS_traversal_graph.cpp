// DFS traversal in graph c++
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    /*
    *Take action on vertex after entering the vertex
    */ 
   cout<<vertex<<endl;
//    if(vis[vertex])return;
   vis[vertex] = true;
    for(int child : g[vertex]){
        cout<<"parent "<<vertex<<", child "<<child<<endl;
        if(vis[child])continue;
        /*
        *Take action on child before entering the child node
        */ 
        dfs(child);
        /*
        *Take action on child after exiting the child node
        */ 
    }
    /*
    *Take action on child before exiting the vertex
    */ 
}
// time complexity of DFS is O(V+E)

int main(){
    int n, m, x;
    cin>>n>>m;
    for(int i=0; i<m;++i){
        int v1, v2;
        cin>>v1>>v2;

// Adjacency Matrix
// o(n+m) - space complexity
// N = 10^5, E<10^7
// taking input inside the graph by using Adjacency List representation with unweighted graph
        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }
    //  x is vertices where you start traversal
    cin>>x;
    dfs(x);
}