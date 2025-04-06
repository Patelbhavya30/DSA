// Reducing Dishes
// https://leetcode.com/problems/reducing-dishes/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int rec(vector<int>& satisfaction,int n,int currElem,int currNum,vector<vector<int>> &dp){
            if(currElem==n)
                return 0;
    
            if(dp[currElem][currNum] != INT_MIN){
                return dp[currElem][currNum];
            }
            int ans=INT_MIN;
            if(satisfaction[currElem]<0){
            ans=max(ans,rec(satisfaction,n,currElem+1,currNum,dp));
            }
    
            ans=max(ans,satisfaction[currElem] * currNum + rec(satisfaction,n,currElem+1,currNum+1,dp));
    
            return dp[currElem][currNum]=ans;
            
    
        }
    
        int tab(vector<int>& satisfaction){
            int n=satisfaction.size();
            sort(satisfaction.begin(),satisfaction.end());
            vector<vector<int>> dp(n+1,vector<int>(n+2,0));
            // dp[n][1]=0;
            for(int currElem=n-1;currElem>=0;currElem--){
                for(int currNum=n;currNum>=1;currNum--){
                    int ans=INT_MIN;
                    if(satisfaction[currElem]<0)
                        ans=max(ans,dp[currElem+1][currNum]);
            
    
                    ans=max(ans,satisfaction[currElem] * currNum + dp[currElem 
                    +1][currNum+1]);
    
                    dp[currElem][currNum]=ans;
                }
            }
    
            return dp[0][1];
            
        }
        int spaceOp(vector<int>& satisfaction){
            int n=satisfaction.size();
            sort(satisfaction.begin(),satisfaction.end());
            int curr=0;
            int next=0;
            // dp[n][1]=0;
            for(int currElem=n-1;currElem>=0;currElem--){
                int temp;
                for(int currNum=n;currNum>=1;currNum--){
                    int ans=INT_MIN;
                    if(satisfaction[currElem]<0)
                        ans=max(ans,curr);
            
    
                    ans=max(ans,satisfaction[currElem] * currNum + next);
    
                    temp=ans;
                }
                curr=temp;
            }
    
            return curr;
            
        }
    
        int maxSatisfaction(vector<int>& satisfaction) {
            // int n=satisfaction.size();
            // sort(satisfaction.begin(),satisfaction.end());
            // vector<vector<int>> dp(n,vector<int>(n+1,INT_MIN));
            // return rec(satisfaction,n,0,1,dp);
    
            // return tab(satisfaction);
            return spaceOp(satisfaction);
        }
    };