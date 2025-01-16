// Bellman Ford
// https://www.naukri.com/code360/problems/bellmon-ford_2041977?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1,1e8);
    dist[src]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            if(dist[u]!=1e8 && ((dist[u]+w)<dist[v])){
                dist[v]=dist[u]+w; 
            }

        }
    }
    // vector<int> ans;
    // for(int i=1;i<dist.size();i++){
    //     ans.push_back(dist[i]);
    // }
    return dist;
// Check for cycle.Not needed for code as negative cycle is not there
    // bool f=0;
    // for(int j=0;j<m;j++){
    //         int u=edges[j][0];
    //         int v=edges[j][1];
    //         int w=edges[j][2];
    //         if(dist[u]!=INT_MAX && (dist[u]+w<dist[v])){
    //             f=1;
    //         }

    //     }
    // if(f==0){
    //     return dist;
    // }
    


}