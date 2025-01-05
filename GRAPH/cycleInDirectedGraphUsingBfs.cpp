// Detect Cycle In A Directed Graph
// https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
using namespace std;
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<vector<int>> adj(n+1);
    vector<int> inDeg(n+1,0);
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first].push_back(edges[i].second);
        inDeg[edges[i].second]++;
    }


    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inDeg[i]==0)
            q.push(i);
    }
   int ans=0;
    while(!q.empty()){
       int node=q.front();
       q.pop();
       ans++;
       for(auto neighbour:adj[node]){
           inDeg[neighbour]--;
           if(inDeg[neighbour]==0)
            q.push(neighbour);
       }
    }
   if(ans==n)
    return 0;
  else
    return 1;
}