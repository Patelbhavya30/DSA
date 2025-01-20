// Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int minCost(int n,vector<int>& cost,int last,unordered_map<int,int> &dp){
    if(n<=last){
        return cost[last];
    }
    auto it = dp.find(n);
if (it != dp.end()) {
    return dp[n];
} 
    if(dp[n]){
        return dp[n];
    }
    int mini=min(minCost(n-1,cost,last,dp),minCost(n-2,cost,last,dp));
    dp[n]=mini+cost[n];
    return dp[n];
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        unordered_map<int,int> dp0;
        unordered_map<int,int> dp1;
        return min(min(minCost(n-1,cost,0,dp0),minCost(n-2,cost,0,dp0)),min(minCost(n-1,cost,1,dp1),minCost (n-2,cost,1,dp1)));
    }
};