// Bridges In A Graph
// https://www.naukri.com/code360/problems/bridges-in-graph_893026?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,int &timer,vector<int> &disc,vector<int> &low,unordered_map<int,bool> &vis,vector<vector<int>> &adj,vector<vector<int>> &result){
    vis[node]=true;
    disc[node]=low[node]=timer++;
    for(auto nbr:adj[node]){
        if(nbr==parent)
            continue;
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,vis,adj,result);
                       
         low[node]=min(low[nbr],low[node]);
            if(low[nbr]>disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
                
                }
            
            
        }
        else{
            low[node] = min(low[node],disc[nbr]);
        }
    }
    }
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    int timer=0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent=-1;
    unordered_map<int,bool> vis;
    for(int i=0;i<v;i++){
        disc[i]=-1;
        low[i]=-1;
      }  
    vector<vector<int>> result;
    for(int i=0;i<v;i++){
        dfs(i,parent,timer,disc,low,vis,adj,result);   
    }
        return result;
    

}