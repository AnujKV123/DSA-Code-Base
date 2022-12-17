// how to take inpput in graph

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int graph[N][N];
int graph1[N][N];
vector<int> graph2[N];
vector<pair<int, int>> graph3[N];

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m;++i){
        int v1, v2, wt;
        cin>>v1>>v2>>wt;
// Adjacency Matrix
// o(N^2) - space complexity
// N != 10^5/N <= 10^3
// taking input inside the graph by using Adjacency matrix representation with unweighted graph
        graph[v1][v2]=1;
        graph[v2][v1]=1;
// taking input inside the graph by using Adjacency matrix representation with weighted graph
        graph1[v1][v2]=wt;
        graph1[v2][v1]=wt;

// Adjacency Matrix
// o(n+m) - space complexity
// N = 10^5, E<10^7
// taking input inside the graph by using Adjacency List representation with unweighted graph
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
// taking input inside the graph by using Adjacency List representation with weighted graph
        graph3[v1].push_back({v2, wt});
        graph3[v2].push_back({v1, wt});
    }
    return 0;
}