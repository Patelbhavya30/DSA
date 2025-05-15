// Dice throw
// https://www.geeksforgeeks.org/problems/dice-throw5349/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void rec(int m,int n,int x,int sum,int& ans){
          if(n<=0){
              
              if(sum==x)
                  ans++;
                  
              return;
          }
          
          for(int i=1;i<=m;i++){
              rec(m,n-1,x,sum+i,ans);
          }
          
          // return ans;
      }
      int recMem(int m,int n,int x,vector<vector<int>>& dp){
          
          if(x<0)
              return 0;
          
          if(n==0 && x!=0)
              return 0;
          
          if(x==0 && n!=0)
              return 0;
          
          if(x==0 && n==0)
              return 1;
              
          if(dp[n][x] != -1)
              return dp[n][x];
          
          int ans=0;
          for(int i=1;i<=m;i++){
              ans = ans + recMem(m,n-1,x-i,dp);
          }
          
          return dp[n][x]=ans;
          
          // return ans;
      }
      int tab(int m,int n,int x){
          
          vector<vector<int>> dp(n+1,vector<int>(x+1,0));
          
          dp[0][0]=1;
          
          for(int dice=1;dice<=n;dice++){
              for(int target=1;target<=x;target++){
                  
                  int ans=0;
                  for(int i=1;i<=m;i++){
                      if(target-i>=0)
                          ans = ans + dp[dice-1][target-i];
                  }
          
              dp[dice][target]=ans;
              }
          }
          
          return dp[n][x];
          
          // return ans;
      }
      int spaceOp(int m,int n,int x){
          
          vector<int> prev(x+1,0);
          vector<int> curr(x+1,0);
          
          prev[0]=1;
          // curr[0]=1;
          
          for(int dice=1;dice<=n;dice++){
              for(int target=1;target<=x;target++){
                  
                  int ans=0;
                  for(int i=1;i<=m;i++){
                      if(target-i>=0)
                          ans = ans + prev[target-i];
                  }
          
              curr[target]=ans;
              }
              prev=curr;
          }
          
          return curr[x];
          
          // return ans;
      }
      int noOfWays(int m, int n, int x) {
          // code here
          // int ans=0;
          // rec(m,n,x,0,ans);
          
          // vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
          // return recMem(m,n,x,dp);
          
          // return tab(m,n,x);
          return spaceOp(m,n,x);
          
      }
  };
  