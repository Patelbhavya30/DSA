// Cycle Detection In Undirected Graph
// https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;

// using bfs
// string cycleDetection (vector<vector<int>>& edges, int n, int m)
// {
//     // Write your code here.
//     vector<vector<int>> adjList(n+1);
//     for(int i=0;i<m;i++){
//         adjList[edges[i][0]].push_back(edges[i][1]);
//         adjList[edges[i][1]].push_back(edges[i][0]);
//     }

//     unordered_map<int,bool> visited;
//     for(int i=1;i<=n;i++){
//         if(!visited[i]){
//         queue<int> q;
//         q.push(i);
//         unordered_map<int,int> nodeToParent;
//         nodeToParent[i]=-1;
//         bool cycle=false;
//             while(!q.empty()){
//                 int node=q.front();
//                 q.pop();
//                 if(visited[node] && node!=nodeToParent[node]){
//                     cycle=true;
//                     break;
//                 }
//                     visited[node]=true;
//                     for(int i=0;i<adjList[node].size();i++){   
//                 if(!visited[adjList[node][i]]){
//                         nodeToParent[adjList[node][i]]=node;
//                         q.push(adjList[node][i]);      
//                     }
//                 }
//             }
//         if(cycle){
//             return "Yes";
//         }
//         }
//     }
//     return "No";
    

// }



bool isCycle(int node, int parent, unordered_map<int, bool> &visited, vector<vector<int>> &adjList) {
    visited[node] = true;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (isCycle(neighbor, node, visited, adjList)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true; // Cycle detected
        }
    }
    return false;
}
// using dfs
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<m;i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    
    unordered_map<int,bool> visited;
    // unordered_map<int,int> parentToNode;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(isCycle(i,-1,visited,adjList)){
                return "Yes";
            }
        }
    }
    return "No";
    
}

