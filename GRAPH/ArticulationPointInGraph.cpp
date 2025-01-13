//  In A GArticulation point in graph
// https://www.naukri.com/code360/library/articulation-points-in-a-graph
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,int &timer,vector<int> &disc,vector<int> &low,unordered_map<int,bool> &vis,vector<vector<int>> &adj,vector<int> &result){
    vis[node]=true;
    disc[node]=low[node]=timer++;
    int child=0;
    for(auto nbr:adj[node]){
        if(nbr==parent)
            continue;
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,vis,adj,result);                      
            low[node]=min(low[nbr],low[node]);
            if(low[nbr]>=disc[node] && parent!=-1){
                result.push_back(node);
            }
            child++;
                
            
        }
        else{
            low[node] = min(low[node],disc[nbr]);
        }
    }
    if(parent==-1 && child>1){
        result.push_back(node);
    }
}
int main() {
    int v=5;
    int e=5;
    // Write your code here
    vector<vector<int>> edges;
    edges.push_back({0,3});
    edges.push_back({3,4});
    edges.push_back({0,4});
    edges.push_back({0,1});
    edges.push_back({1,2});
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
    vector<int> result;
    for(int i=0;i<v;i++){
        dfs(i,parent,timer,disc,low,vis,adj,result);   
    }
    for(auto i:result){
        cout<<i<<" ";
    }
    

}