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
    int tab(vector<int>& slices){
        int k= slices.size();
            
        vector<vector<int>> dp1(k+2,vector<int>(k+2,0));
        vector<vector<int>> dp2(k+2,vector<int>(k+2,0));
    
        for(int index=k-2;index>=0;index--){
            for(int n=1;n<=k/3;n++){
                int take = slices[index] + dp1[index+2][n-1];
                int nottake = 0 +  dp1[index+1][n];
                dp1[index][n]=max(take,nottake);
            }     
        }
    
        for(int index=k-1;index>=1;index--){
            for(int n=1;n<=k/3;n++){
                int take = slices[index] + dp2[index+2][n-1];
                int nottake = 0 +  dp2[index+1][n];
                dp2[index][n]=max(take,nottake);
            }     
        }
    
        return max(dp1[0][k/3],dp2[1][k/3]);
    
    }
    int spaceOp(vector<int>& slices){
        int k= slices.size();
            
        vector<int> prev1(k+2,0);
        vector<int> curr1(k+2,0);
        vector<int> next1(k+2,0);
    
        vector<int> prev2(k+2,0);
        vector<int> curr2(k+2,0);
        vector<int> next2(k+2,0);
        
        
    
    
        for(int index=k-2;index>=0;index--){
            for(int n=1;n<=k/3;n++){
                int take = slices[index] + next1[n-1];
                int nottake = 0 +  curr1[n];
                prev1[n]=max(take,nottake);
            }
            next1=curr1;
            curr1=prev1;     
        }
    
        for(int index=k-1;index>=1;index--){
            for(int n=1;n<=k/3;n++){
                int take = slices[index] + next2[n-1];
                int nottake = 0 +  curr2[n];
                prev2[n]=max(take,nottake);
            }
            next2=curr2;
            curr2=prev2;     
        }
    
        return max(curr1[k/3],curr2[k/3]);
    
    }
        int maxSizeSlices(vector<int>& slices) {
            int k= slices.size();
            // int case1=rec(0,k-2,slices,k/3);
            // int case2=rec(1,k-1,slices,k/3);
            
            // vector<vector<int>> dp1(k,vector<int>(k,-1));
            // vector<vector<int>> dp2(k,vector<int>(k,-1));
            // int case1=recMem(0,k-2,slices,k/3,dp1);
            // int case2=recMem(1,k-1,slices,k/3,dp2);
    
            // return max(case1,case2);
    
            // return tab(slices);
            return spaceOp(slices);
        }
    };