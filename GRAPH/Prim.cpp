// Prim's MST
// https://www.naukri.com/code360/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> parent(n+1,-1);
    vector<int> mst(n+1);
    vector<int> key(n+1,INT_MAX);
    parent[1]=-1;
    key[1]=0;
    for(int i=1;i<=n;i++){
        int mini=INT_MAX;
        int u;
        for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini=key[v];
            }
        }
        mst[u]=true;
        for(auto neighbour:adj[u]){
            int n=neighbour.first;
            int w=neighbour.second;        
           if(mst[n]==false && key[n]>w){
               parent[n]=u;
               key[n]=w;
           }
        }
        
    }
   
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<parent.size();i++){
          ans.push_back({{parent[i],i},key[i]});
        
    }
    return ans;
}
