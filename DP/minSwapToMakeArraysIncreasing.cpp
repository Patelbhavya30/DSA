#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    
    int rec(vector<int>& nums1, vector<int>& nums2,int index,int swapped){
        
        if(index == nums1.size())
            return 0;
        
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        int ans=INT_MAX;

        if(swapped)
        {
            swap(prev1,prev2);
        }

        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans=rec(nums1,nums2,index+1,0);
        }

        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+rec(nums1,nums2,index+1,1));
        }
        
        return ans;
    }
    int recMem(vector<int>& nums1, vector<int>& nums2,int index,int swapped,vector<vector<int>>& dp){
        
        if(index == nums1.size())
            return 0;
        
        if(dp[index][swapped] != -1)
            return dp[index][swapped];

        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        int ans=INT_MAX;

        if(swapped)
        {
            swap(prev1,prev2);
        }

        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans=recMem(nums1,nums2,index+1,0,dp);
        }

        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+recMem(nums1,nums2,index+1,1,dp));
        }
        
        return dp[index][swapped]=ans;
    }

    int tab(vector<int>& nums1, vector<int>& nums2){

        int n=nums1.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int index=n-1;index>=1;index--){
            for(int swapped=1;swapped>=0;swapped--){
                int prev1=nums1[index-1];
                int prev2=nums2[index-1];

                int ans=INT_MAX;

                if(swapped)
                {
                    swap(prev1,prev2);
                }

                if(nums1[index]>prev1 && nums2[index]>prev2){
                    ans=dp[index+1][0];
                }

                if(nums1[index]>prev2 && nums2[index]>prev1){
                    ans=min(ans,1+dp[index+1][1]);
                }
                
                dp[index][swapped]=ans;
            }
        }

        return dp[1][0];


    }
    int spaceOp(vector<int>& nums1, vector<int>& nums2){

        int n=nums1.size();
        int swapi=0,noswap=0,currentSwap=0,currentNoswap=0;
        for(int index=n-1;index>=1;index--){
            for(int swapped=1;swapped>=0;swapped--){
                int prev1=nums1[index-1];
                int prev2=nums2[index-1];

                int ans=INT_MAX;

                if(swapped)
                {
                    swap(prev1,prev2);
                }

                if(nums1[index]>prev1 && nums2[index]>prev2){
                    ans=noswap;
                }

                if(nums1[index]>prev2 && nums2[index]>prev1){
                    ans=min(ans,1+swapi);
                }
                
                if(swapped)
                    currentSwap=ans;
                else
                    currentNoswap=ans;
            }
            swapi=currentSwap;
            noswap=currentNoswap;
        }

        return min(swapi,noswap);


    }

    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        // vector<vector<int>> dp(nums1.size(),vector<int>(2,-1));
        // int ans= rec(nums1,nums2,1,0);
        // int ans= recMem(nums1,nums2,1,0,dp);
        // int ans= tab(nums1,nums2);
        int ans= spaceOp(nums1,nums2);

        if(ans != INT_MAX)
            return ans;
        else
            return 0;
        
    }
};