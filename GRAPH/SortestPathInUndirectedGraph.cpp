// Shortest path in an unweighted graph
// https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	vector<vector<int>> adj(n+1);
	for(int i=0;i<m;i++){
		int u=edges[i].first;
		int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
	}

	queue<int> q;
	unordered_map<int,bool> visited;
	unordered_map<int,int> nodeToParent;
	q.push(s);
	nodeToParent[s]=-1;
	visited[s]=true;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto neighbour:adj[node]){
			if(!visited[neighbour]){
				visited[neighbour]=true;
				nodeToParent[neighbour]=node;
				q.push(neighbour);
			}
		}
	}
	vector<int> ans;
	int temp=t;
	while(nodeToParent[temp]){
		ans.push_back(temp);
		temp=nodeToParent[temp];
	}
	int i=0;
	int j=ans.size()-1;
	while(i<j){
		swap(ans[i++],ans[j--]);
	}
		
	return ans;

	
}
