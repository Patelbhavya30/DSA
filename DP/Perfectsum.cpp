// Get Minimum Squares
// https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int rec(int n,vector<int> &dp){
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
        
    int ans=n;
    for(int i=1;i*i<=n;i++){
        ans=min(ans,1+rec(n-i*i,dp));
            
    }
    dp[n]=ans;
    return dp[n];
  }
  int tab(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int j=1;j<=n;j++){
    for(int i=1;i*i<=n;i++){
        if(j-i*i>=0)
        dp[j]=min(dp[j],1+dp[j-i*i]);
            
    }
    }
    return dp[n];
  }
    int MinSquares(int n) {
        // Code here
        // vector<int> dp(n+1,-1);
        // return rec(n,dp);
        
        return tab(n);
        
        
    }
};