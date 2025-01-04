// Topological Sort
// https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
using namespace std;
void topoSort(int i,stack<int> &s,unordered_map<int,bool> &visited,vector<vector<int>> &adj){
    visited[i]=true;
    for(auto neighbour:adj[i]){
        if(!visited[neighbour]){
            topoSort(neighbour,s,visited,adj);
        }
        
    }
    s.push(i);
}
// Time complexity: O(V+E)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    unordered_map<int,bool> visited;
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,st,visited,adj);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}