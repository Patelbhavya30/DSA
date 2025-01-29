// 0 1 Knapsack
// https://www.naukri.com/code360/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
using namespace std;
int rec(vector<int>& weight, vector<int>& value,int index, int capacity){
		if(index==0){
			if(weight[0]<=capacity)
				return value[0];
			else
				return 0;
		}
		int include=0;
		if(weight[index]<=capacity)
			include=value[index]+rec(weight,value,index-1,capacity-weight[index]);
		
		int exclude=rec(weight,value,index-1,capacity);

		return max(include,exclude);
}
int recMem(vector<int>& weight, vector<int>& value,int index, int capacity,vector<vector<int>> &dp){
		if(index==0){
			if(weight[0]<=capacity)
				return value[0];
			else
				return 0;
		}
		if(dp[index][capacity]!=-1){
			return dp[index][capacity];
		}
		int include=0;
		if(weight[index]<=capacity)
			include=value[index]+recMem(weight,value,index-1,capacity-weight[index],dp);
		
		int exclude=recMem(weight,value,index-1,capacity,dp);

		dp[index][capacity]= max(include,exclude);
		return dp[index][capacity];
}
int tab(vector<int>& weight,int n, vector<int>& value, int capacity){
		vector<vector<int>> dp(n,vector<int>(capacity+1,0));

		for(int w=weight[0];w<=capacity;w++){
				if(weight[0]<=capacity)
					dp[0][w]=value[0];
				else
					dp[0][w]=0;		
		}

		for(int index=1;index<n;index++){
			for(int w=0;w<=capacity;w++){
				int include=0;
			if(weight[index]<=w)
				include=value[index]+dp[index-1][w-weight[index]];
		
			int exclude=dp[index-1][w];

			dp[index][w]= max(include,exclude);
			}
		}
		return dp[n-1][capacity];

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// return rec(weight,value,n-1,maxWeight);

	// vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	// return recMem(weight,value,n-1,maxWeight,dp);

	return tab(weight,n,value,maxWeight);

}