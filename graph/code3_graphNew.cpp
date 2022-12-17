// ********************************* Creating and Printing graph by using adjucency list **********************************


// T.C - > O(N+E) where N -> time taken to visiting nodes, E -> for travelling through adj nodes
// S.C -> O(N)


#include<bits/stdc++.h>
using namespace std;


vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
//     ans array will store all adjacent nodes corresponding on indexes.
    
    // **************************************!!!!!!!!!! please Attention !!!!!!!!!!!!**************************************
    /*Note : vector<int> v[N]; 

    It creates a static array of N vectors of the first type i.e. v[0] is now a whole new and different vector than v[1] which 
    is totally different than v[2] and so on. If you want to push a value into the 1st vector that is v[0], you will do it by 
    v[0].push_back(val). To access that element you will call it by v[0][0](kind of a 2d matrix, isn't it?!). So, basically it 
    is an array of initially empty vectors to which you can add elements. These are very useful while you want to implement 
    graphs where each node has it's own vector and the nodes to which it is joined are pushed into that particular node's vector.
    */
    
    vector<int> ans[n];
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    
    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){
        adj[i].push_back(i);
        
//         entering neighbours
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<", ";
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}