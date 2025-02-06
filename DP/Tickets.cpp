// Ninja's Trip
// https://www.naukri.com/code360/problems/minimum-coins_2180776?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;
int rec(int n, vector<int> days, vector<int> cost,int index,vector<int>& dp){
    if(index>=n)
        return 0;

    if(dp[index]!=-1)
        return dp[index];
    int oneDayPass=cost[0] + rec(n,days,cost,index+1,dp);

    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int sevenDayPass=cost[1] + rec(n,days,cost,i,dp);

    for(i=index;i<n && days[i]<days[index]+30;i++);
    int oneMonthPass=cost[2] + rec(n,days,cost,i,dp);

    dp[index] = min(min(oneDayPass,sevenDayPass),oneMonthPass);
    return dp[index];

}
int tab(int n, vector<int>& days, vector<int>& cost){

    vector<int> dp(n+1,-1);
    dp[n]=0;
    
    for(int k=n-1;k>=0;k--){
    int oneDayPass=cost[0] + dp[k+1];

    int i;
    for(i=k;i<n && days[i]<days[k]+7;i++);
    int sevenDayPass=cost[1] + dp[i];

    for(i=k;i<n && days[i]<days[k]+30;i++);
    int oneMonthPass=cost[2] + dp[i];



    dp[k] = min(min(oneDayPass,sevenDayPass),oneMonthPass);
    }
    return dp[0];

}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    // return rec(n,days,cost,0);

    // vector<int> dp(n+1,-1);
    // return rec(n,days,cost,0,dp);

    return tab(n,days,cost);
}