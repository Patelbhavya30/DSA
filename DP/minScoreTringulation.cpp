// Minimum Score Triangulation of Polygon
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    // recursion
        int solve(vector<int>& values,int i,int j){
    
            if(i+1==j) return 0;
    
            int ans=INT_MAX;
            for(int k=i+1;k<j;k++){
                ans=min(ans,values[i]*values[k]*values[j]+solve(values,i,k)+solve(values,k,j));
            }
    
            return ans;
        }
        int mem(vector<int>& values,int i,int j,vector<vector<int>>& dp){
    
            if(i+1==j)
                 return 0;
    
            if(dp[i][j]!=-1)
                 return dp[i][j];
    
            int ans=INT_MAX;
            for(int k=i+1;k<j;k++){
                ans=min(ans,values[i]*values[k]*values[j]+mem(values,i,k,dp)+mem(values,k,j,dp));
            }
    
            dp[i][j]=ans;
            return dp[i][j];
    
        }
        // Time complexity O(n3)
        int tab(vector<int>& v){
            int n=v.size();
    
            vector<vector<int>> dp(n,vector<int> (n,0));
    
            for(int i=n-1;i>=0;i--){
                for(int j=i+2;j<n;j++){
                    int ans=INT_MAX;
            for(int k=i+1;k<j;k++){
                ans=min(ans,v[i]*v[k]*v[j]+dp[i][k]+dp[k][j]);
            }
            dp[i][j]=ans;
                }
            }
            
            return dp[0][n-1];
    
        }
        int minScoreTriangulation(vector<int>& values) {
            // int n=values.size();
            // return solve(values,0,n-1);
    
            // vector<vector<int>> dp(n,vector<int> (n,-1));
            // return mem(values,0,n-1,dp);
    
            return tab(values);
        }
    };