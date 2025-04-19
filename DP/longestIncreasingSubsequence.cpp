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
    
    int tab(vector<int>& arr){
          int n=arr.size();
          vector<vector<int>> dp(n+1,vector<int>(n+1,0));
          
          for(int curr=n-1;curr>=0;curr--){
              
          for(int prev=n-1;prev>=-1;prev--){
              
          int incans=0,excans=0;
          
          
          excans=dp[curr+1][prev+1];
          
          if(prev==-1 || arr[prev] < arr[curr])
          {
              incans= 1 + dp[curr+1][curr+1];
          }
              
          dp[curr][prev+1]=max(excans,incans);
          }
          
          }
          
          return dp[0][0];
          
          
        
    }
    int space(vector<int>& arr){
          int n=arr.size();
          
          vector<int> currRow(n+1,0);
          vector<int> nextRow(n+1,0);
          
          for(int curr=n-1;curr>=0;curr--){
              
          for(int prev=n-1;prev>=-1;prev--){
              
          int incans=0,excans=0;
          
          
          excans=nextRow[prev+1];
          
          if(prev==-1 || arr[prev] < arr[curr])
          {
              incans= 1 + nextRow[curr+1];
          }
              
          currRow[prev+1]=max(excans,incans);
          }
          nextRow=currRow;
          
          }
          
          return nextRow[0];
          
          
        
    }
    int solveOptimal(int n,vector<int> a){
        if(n==0)
            return 0;
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i=1;i<n;i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }
            else{
                int index= lower_bound(ans.begin(),ans.end(),a[i])- ans.begin();
                ans[index]=a[i];
            }
            
        }
        
        return ans.size();
    }
      int lis(vector<int>& arr) {
          // code here
          int n=arr.size();
        //   vector<vector<int>> dp(n,vector<int>(n+1,-1));
        //   return rec(arr,n,0,-1,dp);
        
        // return tab(arr);
        // return space(arr);
        
        return solveOptimal(n,arr);
          
          
      }
  };
