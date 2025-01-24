//  Maximum sum of non-adjacent elements
// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h> 
using namespace std;
int rec(vector<int> &nums,int index,vector<int>& dp){
    if(index>=nums.size()){
        return 0;
    }
    //exclude
    if(dp[index] != -1){
        return dp[index];
    }
    int exc=rec(nums,index+1,dp);

    //include
    int inc=nums[index]+rec(nums,index+2,dp);
    dp[index]=max(inc,exc);
    return dp[index];
}
int tab(vector<int> &nums,int n){
    vector<int> dp(n+1,0);
    dp[-1]=0;
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[n-1];


}
int spaceOp(vector<int> &nums,int n){
    int prev1=0;
    int prev2=nums[0];
    for(int i=1;i<n;i++){
        int temp=prev2;
        prev2=max(prev1+nums[i],prev2);
        prev1=temp;

    }
    return prev2;


}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    // vector<int> dp(n,-1);
    // return rec(nums,0,dp);
    // return tab(nums,n);
    return spaceOp(nums,n);
    

}