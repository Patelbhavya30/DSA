//  Creating and Printing
// https://www.naukri.com/code360/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<vector<int>> ans;
    // Time Complexity: O(n)
    for(int i=0;i<n;i++){
        vector<int> temp;
        temp.push_back(i);
        ans.push_back(temp);
    }
    // Time Complexity: O(m)
    for(auto i:edges){
        ans[i[0]].push_back(i[1]);
        ans[i[1]].push_back(i[0]);
    }

    // Time Complexity: O(n+m)
    return ans;
}