// Combination Sum IV
// https://www.naukri.com/code360/problems/number-of-ways_3755252?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
using namespace std;
int rec(vector<int>& num,int tar){
    if(tar==0)
        return 1;
    
    if(tar<0)
        return 0;
    int ans=0;
    for(int index=0;index<num.size();index++){
        ans+=rec(num,tar-num[index]);
    }
    return ans;
    
}
int recMem(vector<int>& num,int tar,vector<int>& dp){
    if(tar==0)
        return 1;
    
    if(tar<0)
        return 0;
    if(dp[tar]!=-1)
        return dp[tar];
    int ans=0;
    for(int index=0;index<num.size();index++){
        ans+=recMem(num,tar-num[index],dp);
    }
    dp[tar]=ans;
    return dp[tar];
    
}
int tab(vector<int>& num,int tar){
    
    vector<int> dp(tar+1,0);
    dp[0]=1;
    for(int t=1;t<=tar;t++){
        for(int j=0;j<num.size();j++){
            if(t-num[j]>=0)
                dp[t]+=dp[t-num[j]];
        }
    }
    return dp[tar];
    
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    // return rec(num,tar);
    
    // vector<int> dp(tar+1,-1);
    // return recMem(num,tar,dp);

    return tab(num,tar);


}