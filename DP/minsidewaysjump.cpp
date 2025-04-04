// Min side ways jumps
// https://leetcode.com/problems/minimum-sideway-jumps/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int rec(vector<int>& obstacles,int n,int lane,int position){
            if(position+1 == n)
                return 0;
    
            // if(obstacles[position]-1 == lane)
            //     return -1;
    
    
            if(obstacles[position+1] != lane)
                return rec(obstacles,n,lane,position+1);
    
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(lane!=i && obstacles[position] != i){
                    ans=min(ans,rec(obstacles,n,i,position)+1);
    
                }
            }
            
            return ans;    
            
    
        }
        int recMem(vector<int>& obstacles,int n,int lane,int position,vector<vector<int>> &dp){
            if(position+1 == n)
                return 0;
    
            // if(obstacles[position]-1 == lane)
            //     return -1;
    
            if(dp[position][lane] != -1)
                return dp[position][lane];
    
            if(obstacles[position+1] != lane)
                return recMem(obstacles,n,lane,position+1,dp);
    
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(lane!=i && obstacles[position] != i){
                    ans=min(ans,recMem(obstacles,n,i,position,dp)+1);
    
                }
            }
            
            
            return dp[position][lane]=ans;
            
    
        }
    
        int recTab(vector<int>& obstacles){
    
            int n=obstacles.size();
    
            vector<vector<int>> dp(4,vector<int>(n+1,1e9));
    
            dp[0][n-1]=0;
            dp[1][n-1]=0;
            dp[2][n-1]=0;
            dp[3][n-1]=0;
            
            for(int position=n-2;position>=0;position--){
                
                for(int lane=1;lane<=3;lane++){
                    if(obstacles[position+1] != lane){
                        dp[lane][position]=dp[lane][position+1];
                    }
                    else{
                    int ans=1e9;
                    for(int i=1;i<=3;i++){
                        if(lane!=i && obstacles[position] != i)
                            ans=min(ans,dp[i][position+1]+1);
                    }
                    dp[lane][position]=ans;
                    }
                }
            }
            
            
            return min(dp[2][0],min(dp[1][0],dp[3][0])+1);
            
    
        }
    
        int spaceOptimized(vector<int>& obstacles){
    
            int n=obstacles.size();
    
            vector<int> next(4,0);
            vector<int> curr(4,INT_MAX);
    
            for(int position=n-2;position>=0;position--){
                
                for(int lane=1;lane<=3;lane++){
                    if(obstacles[position+1] != lane){
                        curr[lane]=next[lane];
                    }
                    else{
                    int ans=1e9;
                    for(int i=1;i<=3;i++){
                        if(lane!=i && obstacles[position] != i)
                            ans=min(ans,next[i]+1);
                    }
                    curr[lane]=ans;
                    }
                }
                next=curr;
            }
            
            
            return min(curr[2],min(curr[1],curr[3])+1);
            
    
        }
        int minSideJumps(vector<int>& obstacles) {
            // int n=obstacles.size();
            // return rec(obstacles,n,2,0);
    
            // vector<vector<int>> dp(n,vector<int>(4,-1));
            // return recMem(obstacles,n,2,0,dp);
    
            // return recTab(obstacles);
    
            return spaceOptimized(obstacles);
    
            
        }
    };