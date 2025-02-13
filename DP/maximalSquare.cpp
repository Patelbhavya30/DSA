// Largest square formed in a matrix
// https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int rec(vector<vector<int>>& mat,int i,int j,int &maxi,vector<vector<int>>& dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        
        if(dp[i][j]!=-1)
          return dp[i][j];
        int right=rec(mat,i,j+1,maxi,dp);
        int diagonal=rec(mat,i+1,j+1,maxi,dp);
        int down=rec(mat,i+1,j,maxi,dp);
        
        if(mat[i][j]==1){
            dp[i][j]=1+min(right,min(diagonal,down));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
            
        }
        else{
            return dp[i][j]=0;
        }
    }
    
    int tab(vector<vector<int>>& mat,int& maxi){
          int n=mat.size();
          int m=mat[0].size();
          vector<vector<int>> dp(n+1,vector<int>(m+1,0));
          
          for(int i=n-1;i>=0;i--){
              for(int j=m-1;j>=0;j--){
                  
                  int right=dp[i][j+1];
                  int diagonal=dp[i+1][j+1];
                  int down=dp[i+1][j];
        
                  if(mat[i][j]==1){
                      dp[i][j]=1+min(right,min(diagonal,down));
                      maxi=max(maxi,dp[i][j]);
            
                  }
                  else{
                      dp[i][j]=0;
                  }
                  
              }
          }
        
    }
    int spaceOp(vector<vector<int>>& mat,int& maxi){
          int n=mat.size();
          int m=mat[0].size();
          vector<int> prev(m+1,0);
          vector<int> curr(m+1,0);
          vector<int> temp;
          for(int i=n-1;i>=0;i--){
              for(int j=m-1;j>=0;j--){
                  
                  int right=prev[j+1];
                  int diagonal=curr[j+1];
                  int down=curr[j];
                  temp=curr;
                  if(mat[i][j]==1){
                      curr[j]=1+min(right,min(diagonal,down));
                      maxi=max(maxi,curr[j]);
            
                  }
                  else{
                      curr[j]=0;
                  }
                  prev=temp;
                  
              }
          }
        
    }
    int spaceOp2(vector<vector<int>>& mat,int& maxi){
          int n=mat.size();
          int m=mat[0].size();
          int prev1,curr1,curr,temp=0;
          for(int i=n-1;i>=0;i--){
              for(int j=m-1;j>=0;j--){
                  
                  int right=prev1;
                  int diagonal=curr1;
                  int down=curr;
                  temp=curr;
                  if(mat[i][j]==1){
                      curr=1+min(right,min(diagonal,down));
                      maxi=max(maxi,curr);
            
                  }
                  else{
                      curr=0;
                  }
                  prev1=temp;
                  
              }
          }
        
    }
      int maxSquare(vector<vector<int>>& mat) {
          // code here
          // int n=mat.size();
          // int m=mat[0].size();
          // vector<vector<int>> dp(n,vector<int>(m,-1));
          // int maxi=0;
          // rec(mat,0,0,maxi,dp);
          // return maxi;
          
          // int maxi=0;
          // tab(mat,maxi);
          // return maxi;
          
          // int maxi=0;
          // spaceOp(mat,maxi);
          // return maxi;
          
          int maxi=0;
          spaceOp2(mat,maxi);
          return maxi;
      }
  };