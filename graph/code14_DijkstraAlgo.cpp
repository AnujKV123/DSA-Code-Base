// ********************************* Dijkstra Algorithm **********************************

// Dijkstra algorithm is a single-source shortest path algorithm. Here, single-source means that only one source is 
// given, and we have to find the shortest path from the source to all the nodes.

// for detail explain :- https://www.programiz.com/dsa/dijkstra-algorithm
// for detail explain :- https://www.javatpoint.com/dijkstras-algorithm


#include<bits/stdc++.h>
using namespace std;
// TC = O(elogv) v = no. of vertices, e = no of edges
// SC = O(n + v) v = no. of vertices, e = no of edges

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // first create adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<vec.size(); i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
//     create a distance array with a infinite value
    vector<int> dist(vertices);
    for(int i=0; i<dist.size(); i++){
        dist[i] = INT_MAX;
    }
    
//     creation of node on basis (distance, node)
    set<pair<int, int>> st;
    
//     initialse distance and set with source node
    dist[source] = 0;
    st.insert(make_pair(0, source));
    
//     **************************** important part **********************
    while(!st.empty()){
        
//         fetch top record
        auto top = *(st.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;
        
//         remove top record now
        st.erase(st.begin());
        
//         traverse in neighbours
        for(auto neighbour:adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                
//                 if record found then erase it
                if(record != st.end()){
                    st.erase(record);
                }
                
//                 distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
//                 record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}
