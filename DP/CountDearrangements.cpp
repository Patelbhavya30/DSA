// Count derangements
// https://www.naukri.com/code360/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;
// long long int rec(int n,vector<long long int>& dp){
//     if(n==2)
//         return 1;
    
//     if(n==1)
//         return 0;

//     if(dp[n]!=-1)
//         return dp[n];
//     dp[n]= (((n-1)%MOD)*(rec(n-1,dp)%MOD+rec(n-2,dp)%MOD))%MOD;
//     return dp[n];
// }
// long long int tab(int n){
//     vector<long long int> dp(n+1,-1);
//     dp[1]=0;
//     dp[2]=1;
//     for(int i=3;i<=n;i++){
//      dp[i]= (((i-1)%MOD)*(rec(i-1,dp)%MOD+rec(i-2,dp)%MOD))%MOD;
//     }
//     return dp[n];
// }
long long int spaceOP(int n){
    long long int prev2=1;
    long long int prev1=0;
    long long int temp;
    for(int i=3;i<=n;i++){
     temp=prev2;
     prev2= (((i-1)%MOD)*(prev2%MOD+prev1%MOD))%MOD;
     prev1=temp;
    }
    return prev2;
}

long long int countDerangements(int n) {
    // Write your code here.
    // vector<long long int> dp(n+1,-1);
    // return rec(n,dp);

    // tab
    // return tab(n);

    // Space Optimized
    return spaceOP(n);
}