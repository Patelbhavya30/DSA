// Pizza With 3n Slices
// https://leetcode.com/problems/pizza-with-3n-slices/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int rec(int index,int endIndex,vector<int>& slices,int n){
        if(n==0 || index > endIndex)
            return 0;
        
        int take = slices[index] + rec(index+2,endIndex,slices,n-1);
        int nottake = 0 +  rec(index+1,endIndex,slices,n);
    
        return max(take,nottake);
    }
    int recMem(int index,int endIndex,vector<int>& slices,int n,vector<vector<int>> &dp){
        if(n==0 || index > endIndex)
            return 0;
        if(dp[n][index] != -1)
            return dp[n][index];
        int take = slices[index] + recMem(index+2,endIndex,slices,n-1,dp);
        int nottake = 0 +  recMem(index+1,endIndex,slices,n,dp);
    
        return dp[n][index]=max(take,nottake);
    }
        int maxSizeSlices(vector<int>& slices) {
            int k= slices.size();
            // int case1=rec(0,k-2,slices,k/3);
            // int case2=rec(1,k-1,slices,k/3);
            
            vector<vector<int>> dp1(k,vector<int>(k,-1));
            vector<vector<int>> dp2(k,vector<int>(k,-1));
            int case1=recMem(0,k-2,slices,k/3,dp1);
            int case2=recMem(1,k-1,slices,k/3,dp2);
    
    
            return max(case1,case2);
        }
    };