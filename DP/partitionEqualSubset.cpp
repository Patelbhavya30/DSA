// Partition Equal Subset Sum
// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool rec(vector<int>& arr,int index,int n,int sum,int target){
        if(index >= n)
            return false;
            
        if(sum == target)
            return true;
            
        if(sum > target)
            return false;
        
        bool include=rec(arr,index+1,n,sum+arr[index],target);
        bool exclude=rec(arr,index+1,n,sum,target);
        
        return include || exclude;
    }
    
    bool recMem(vector<int>& arr,int index,int n,int sum,int target,vector<vector<int>>& dp){
        if(index >= n)
            return false;
            
        if(sum == target)
            return true;
            
        if(sum > target)
            return false;
            
        if(dp[index][sum] != -1)
            return dp[index][sum];
        
        bool include=recMem(arr,index+1,n,sum+arr[index],target,dp);
        bool exclude=recMem(arr,index+1,n,sum,target,dp);
        
        return dp[index][sum]=include || exclude;
    }
    
    bool tab(vector<int>& arr,int sumValue){
        
        int n = arr.size();
            
        // int sumValue=accumulate(arr.begin(), arr.end(), 0);
        vector<vector<bool>> dp(n+1,vector<bool>(sumValue,false));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }
        
        for(int index=n-1;index>=0;index++){
            for(int sum=0;sum<=sumValue/2;sum++){
                bool include;
                if(sum-arr[index] >=0){
                    include=dp[index+1][sum-arr[index]];
                }
                bool exclude=dp[index+1][sum];
                dp[index][sum] = include || exclude;
            }
        }
        
        return dp[0][sumValue/2];
    }
    
    bool equalPartition(vector<int>& arr) {
        // code here
        // int n = arr.size();
        
        int sum=accumulate(arr.begin(), arr.end(), 0);
        
        // vector<vector<int>> dp(n,vector<int>(sum,-1));
        
        if(sum & 1)
            return false;
        else 
            return tab(arr,sum);
            // return recMem(arr,0,n,0,sum/2,dp);
            // return rec(arr,0,n,0,sum/2);
        
    }
};
