// Dijkstra's shortest path
// https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h> 
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(vertices,INT_MAX);
    set<pair<int,int>> s;
    dist[source]=0;
    s.insert({0,source});

    while(!s.empty()){
        auto top=*(s.begin());
        int nodeD=top.first;
        int topNode=top.second;
        s.erase(s.begin());
        for(auto neighbour:adj[topNode]){
            if(nodeD+neighbour.second<dist[neighbour.first]){
                auto record=s.find({dist[neighbour.first],neighbour.first});
                if(record != s.end()){
                    s.erase(record);
                }

                dist[neighbour.first]=nodeD+neighbour.second;
                s.insert({dist[neighbour.first],neighbour.first});
            }
        }
    }

    return dist;


}
