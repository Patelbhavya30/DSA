// Ninja And The Fence
// https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION 
#include <bits/stdc++.h> 
#define MOD 1000000007
using namespace std;

int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a,int b){
    return (a%MOD * 1ll * b%MOD)%MOD;
}
int rec(int n,int k){
    if(n==1)
        return k;
    if(n==2){
       return add(k,mul(k,k-1));
    }
    int ans= add(mul(rec(n-2,k),k-1),mul(rec(n-1,k),k-1));
    return ans;
}
int recMem(int n,int k,vector<int>& dp){
    if(n==1)
        return k;
    if(n==2){
       return add(k,mul(k,k-1));
    }
    if(dp[n]!=-1)
        return dp[n];

    dp[n]= add(mul(recMem(n-2,k,dp),k-1),mul(recMem(n-1,k,dp),k-1));
    return dp[n];
}
int tab(int n,int k){
    vector<int> dp(n+1,-1);

    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));
    
    for(int i=3;i<=n;i++){
    dp[i]= add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
}
int spaceOp(int n,int k){
    vector<int> dp(n+1,-1);

    int prev1=k;
    int prev2=add(k,mul(k,k-1));
    int temp;
    for(int i=3;i<=n;i++){
    temp=prev2;
    prev2= add(mul(prev1,k-1),mul(prev2,k-1));
    prev1=temp;
    }
    return prev2;
}
int numberOfWays(int n, int k) {
    // Write your code here.
    // return rec(n,k);
    //rec+mem
    // vector<int> dp(n+1,-1);
    // return recMem(n,k,dp);

    //tabulation
    // return tab(n,k);

    // space optimized
    return spaceOp(n,k);


    
}
