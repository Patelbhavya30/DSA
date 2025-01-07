// Shortest path in Directed Acyclic Graph
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/0
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  void topoSort(int node,stack<int> &s,unordered_map<int,bool> &visited,unordered_map<int,list<pair<int,int>>> &adj){
      visited[node]=true;
      for(auto neighbour:adj[node]){
          if(!visited[neighbour.first]){
              
          topoSort(neighbour.first,s,visited,adj);
          }
      }
      s.push(node);
  }
//   Time complexity: O(V+E)
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<E;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        stack<int> s;
        unordered_map<int,bool> visited;
        topoSort(0,s,visited,adj);
        vector<int> ans(V,-1);
        ans[0]=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            for(auto neighbour:adj[node]){
                int n=neighbour.first;
                int w=ans[node]+neighbour.second;
                if(ans[n]==-1){
                    ans[n]=w;
                }
                else if(ans[n]>w){
                    ans[n]=w;
                }
                
            }
            
        }
        return ans;
        
    }
};
