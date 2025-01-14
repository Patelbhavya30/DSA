// Count Strongly Connected Components (Kosaraju’s Algorithm)
// https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
using namespace std;
void dfs(int i,unordered_map<int,bool> &vis,stack<int> &st,unordered_map<int,list<int>> &adj){
	vis[i]=true;
	for(auto nbr:adj[i]){
		if(!vis[nbr]){
			dfs(nbr,vis,st,adj);
		}
	}
	st.push(i);
}

void revDfs(int i,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj){
	vis[i]=true;
	for(auto nbr:adj[i]){
		if(!vis[nbr]){
			revDfs(nbr,vis,adj);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}

	stack<int> st;
	unordered_map<int,bool> vis;
	for(int i=0;i<v;i++){
		if(!vis[i]){
			dfs(i,vis,st,adj);
		}
	}

	unordered_map<int,list<int>> adjT;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];
		adjT[v].push_back(u);
	}


	int ans=0;
	unordered_map<int,bool> visited;

	while(!st.empty()){
		int node=st.top();
		st.pop();
		if(!visited[node]){
	    ans++;
		revDfs(node,visited,adjT);
		}
	}
	return ans;


}