//  Detect Cycle In A Directed Graph
// https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
using namespace std;
bool isCycle(int node,vector<vector<int>> &adjList,unordered_map<int,bool> &visited,unordered_map<int,bool> &visitedDfs){
  
  visited[node]=true;
  visitedDfs[node]=true;
  for(int i=0;i<adjList[node].size();i++){
    if(!visited[adjList[node][i]]){
      if(isCycle(adjList[node][i],adjList,visited,visitedDfs)){
        return true;
      };
      
    }
    else if(visitedDfs[adjList[node][i]]){
      return true;
    }
  }
  visitedDfs[node]=false;
  return false;

}
// Time complexity: O(n+m)
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<vector<int>> adjList(n+1);
  for(int i=0;i<edges.size();i++){
    adjList[edges[i].first].push_back(edges[i].second);
  }
  unordered_map<int,bool> visited;
  unordered_map<int,bool> visitedDfs;
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      visitedDfs[i]=true;
      if(isCycle(i,adjList,visited,visitedDfs)){
        return 1;
      }
      visitedDfs[i]=false;

    }
  }
  return 0;

}