// Cut Into Segments
// https://www.naukri.com/code360/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
using namespace std;
int rec(int n, int x, int y, int z){
	if(n==0)
		return 0;
	if(n<0)
		return INT_MIN;

	int xpieces=rec(n-x,x,y,z);
	int ypieces=rec(n-y,x,y,z);
	int zpieces=rec(n-z,x,y,z);
	int max1=max(xpieces,ypieces);
	int max2=max(max1,zpieces);
	return max2==INT_MIN?INT_MIN: max2+1;
}
int recMez(int n, int x, int y, int z,vector<int> &dp){
	if(n==0)
		return 0;
	if(n<0)
		return INT_MIN;
	if(dp[n]!=-1)
		return dp[n];
	int xpieces=recMez(n-x,x,y,z,dp);
	int ypieces=recMez(n-y,x,y,z,dp);
	int zpieces=recMez(n-z,x,y,z,dp);
	int max1=max(xpieces,ypieces);
	int max2=max(max1,zpieces);
	dp[n]= max2==INT_MIN?INT_MIN: max2+1;
	return dp[n];
}
int tab(int n, int x, int y, int z){
	vector<int> dp(n+1,-1);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		if(i-x>=0 && dp[i-x]!=-1)
			dp[i]=max(dp[i],dp[i-x]+1);
		if(i-y>=0 && dp[i-y]!=-1)
			dp[i]=max(dp[i],dp[i-y]+1);
		if(i-z>=0 && dp[i-z]!=-1)
			dp[i]=max(dp[i],dp[i-z]+1);
   

	}
	if(dp[n]<0)
		return 0;
	else
		return dp[n];
	
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	// int ans=rec(n,x,y,z);
	// vector<int> dp(n+1,-1);
	// int ans=recMez(n,x,y,z,dp);
	// return ans==INT_MIN?0:ans;

	return tab(n,x,y,z);
}
