//  Topological Sort using bfs kahn's algorithm
// https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SOLUTION
#include <bits/stdc++.h> 
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    vector<int> inDeg(v,0);
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        inDeg[edges[i][1]]++;
    }


    queue<int> q;
    for(int i=0;i<v;i++){
        if(inDeg[i]==0)
            q.push(i);
    }
   vector<int> ans;
    while(!q.empty()){
       int node=q.front();
       q.pop();
       ans.push_back(node);
       for(auto neighbour:adj[node]){
           inDeg[neighbour]--;
           if(inDeg[neighbour]==0)
            q.push(neighbour);
       }
    }

    return ans;
}