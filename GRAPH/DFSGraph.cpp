//  DFS Traversal
// https://www.naukri.com/code360/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
using namespace std;
void getAdjList(vector<vector<int>> edges,vector<vector<int>> &adjList){

    for(auto i:edges){
        adjList[i[0]].push_back(i[1]);
        adjList[i[1]].push_back(i[0]);
    }

}
void solve(int node,unordered_map<int,bool> &visited,vector<vector<int>> adjList,vector<int> &connectedNodes){
     if(visited[node]){
         return;
     }
     connectedNodes.push_back(node);
     visited[node]=true;
     for(int i=0;i<adjList[node].size();i++){
         solve(adjList[node][i],visited,adjList,connectedNodes);
     }

}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> adjList(V);
    getAdjList(edges,adjList);
    unordered_map<int,bool> visited;
    vector<vector<int>> dfs;
    vector<int> connectedNodes;
    solve(0,visited,adjList,connectedNodes);
    dfs.push_back(connectedNodes);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            connectedNodes.clear();
            solve(i,visited,adjList,connectedNodes);
            dfs.push_back(connectedNodes);
        }

    }
    return dfs;
    
}