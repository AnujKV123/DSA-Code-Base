// ********************************* implementation of graph by using adjucency list **********************************

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename T>

class graph{
    public:
    unordered_map<T, list<T>> adj;

   void addEdge(T u, T v, bool direction){

    // direction = 0 -> undirected
    // direction = 1 -> directed graph

    // create an edge from u to v
    adj[u].push_back(v);
    if(direction == 0){
        adj[v].push_back(u);
    }
   } 

   void printAdjList(){

    for(auto i:adj){
        cout<< i.first<<"-> ";
        for(auto j: i.second){
            cout<<j<<", ";
        }
        cout<<endl;
    }
   }

};

int main(){
    int n;
    cout<<"Enter the number of nodes :"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edge :"<<endl;
    cin>>m;

    graph<int> g;

    for(int i=0; i<m; i++){
        int u, v;
        cin>> u >> v;
        g.addEdge(u, v, 0);
    }

    // printing graph
    g.printAdjList();
    
    return 0;
}
/* Enter the number of nodes :
5
Enter the number of edge :
6

0 1
1 2
2 3
3 1
3 4
0 4
 */ 