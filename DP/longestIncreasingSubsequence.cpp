// Longest Increasing Subsequence
// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int rec(vector<int>& arr,int n,int curr,int prev,vector<vector<int>>& dp){
          if(curr == n )
              return 0;
          
          int incans=0,excans=0;
          
          if(dp[curr][prev+1] != -1)
              return dp[curr][prev+1];
          
          excans=rec(arr,n,curr+1,prev,dp);
          
          if(prev==-1 || arr[prev] < arr[curr])
          {
              incans= 1 + rec(arr,n,curr+1,curr,dp);
          }
              
          return dp[curr][prev+1]=max(excans,incans);
          
          
        
    } 
      int lis(vector<int>& arr) {
          // code here
          int n=arr.size();
          vector<vector<int>> dp(n,vector<int>(n+1,-1));
          return rec(arr,n,0,-1,dp);
      }
  };
  