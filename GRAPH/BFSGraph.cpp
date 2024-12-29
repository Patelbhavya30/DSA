// BFS in graph
// https://www.naukri.com/code360/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
using namespace std;
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int> bfs;
    unordered_map<int,bool> visited;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(!visited[node]){

        bfs.push_back(node);
        visited[node]=true;
        vector<int> adjNodes=adj[node];
        for(int i=0;i<adjNodes.size();i++){   
                q.push(adjNodes[i]);      
        }
        }
    }
    return bfs;
}