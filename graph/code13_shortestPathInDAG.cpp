// ********************************* find the Shortest path in a directed acyclic graph **********************************

// TC = O(n + e) n = no. of nodes, e = no of edges
// SC = O(n + e) n = no. of nodes, e = no of edges

// for detail explain :- https://www.codingninjas.com/codestudio/library/shortest-path-in-a-directed-acyclic-graph


#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight){
        pair<int, int> p = {v, weight};
        adj[u].push_back(p);
    }

    void printEdge(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<"{"<<j.first<<", "<<j.second<<"}, ";
            }cout<<endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo){

        visited[node] = true;

        for(auto neighbours:adj[node]){
            if(!visited[neighbours.first]){
                dfs(neighbours.first, visited, topo);
            }
        }
        topo.push(node);
    }

// **************************** important part *********************************
    void getShortestPath(int src, vector<int> &ans, stack<int> &topo){

        ans[src] = 0;

        while(!topo.empty()){

            int top = topo.top();
            topo.pop();
            
            if(ans[top] != INT_MAX){
                for(auto i:adj[top]){
                    if(ans[top] + i.second < ans[i.first]){

                        ans[i.first] = ans[top] + i.second;
                    }
                }
            }
        }
    }

};

int main(){

    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    // g.printEdge();

    unordered_map<int, bool> visited;
    stack<int> topo;
    int n=6;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.dfs(i, visited, topo);
        }
    }

    int src = 1;
    vector<int> ans(n);

    for(int i=0; i<n; i++){
        ans[i] = INT_MAX;
    }

    g.getShortestPath(src, ans, topo);

    cout<<"Ans is :"<<endl;
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}