// Minimum Cost of ropes
// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
        priority_queue <int, vector<int>, greater<int> > pq;
        for(auto i:arr)
            pq.push(i);
        
        int ans=0;
        while(pq.size()>1){
            int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        ans+=(first+second);
        pq.push(first+second);
        }
        return ans;
    }
};