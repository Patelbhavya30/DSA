// Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

//Top down (recursion + momization)
int minCost(int n,vector<int>& cost,vector<int> &dp){
    if(n==0)
        return cost[0];
    if(n==1)
        return cost[1];
    
    if(dp[n]!=-1){
        return dp[n];
    }
    int mini=min(minCost(n-1,cost,dp),minCost(n-2,cost,dp));
    dp[n]=mini+cost[n];
    return dp[n];
}

// Tabulation
int bottomUp(int n,vector<int>& cost,vector<int> &dp){
    
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}

// Space Optimized
int spaceOp(int n,vector<int>& cost){
    
    int prev1=cost[0];
    int prev2=cost[1];
    for(int i=2;i<n;i++){
        int temp=cost[i]+min(prev1,prev2);
        prev1=prev2;
        prev2=temp;
    }
    return min(prev1,prev2);
}


    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        // dp[n]=0;
        // return min(minCost(n-1,cost,dp),minCost(n-2,cost,dp));
        // return bottomUp(n,cost,dp);
        return spaceOp(n,cost);
    }
};