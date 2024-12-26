// NQueens
// https://www.naukri.com/code360/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
using namespace std;
vector<int> addSolution(vector<vector<int>> board){
	vector<int> ans;
	for(auto i:board){
		for(auto j:i){
         ans.push_back(j);
		}
	}
	return ans;
}
 bool isSafe(int row,int col,vector<vector<int>> board,int n){
	 for(int i=0;i<col;i++){
		 if(board[row][i]==1)
		 	return false;
	 }
	 for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
          if(board[i][j]==1)
		 	return false;
	 }
	 for(int i=row+1,j=col-1;i<n&&j>=0;i++,j--){
          if(board[i][j]==1)
		 	return false;
	 }
	 return true;
 }
void solve(vector<vector<int>> &board,vector<vector<int>> &ans,int col,int n){
	if(col==n){
      ans.push_back(addSolution(board));
	  return;
	}
	for(int row=0;row<n;row++){
		if(isSafe(row,col,board,n)){
			board[row][col]=1;
			solve(board,ans,col+1,n);
			board[row][col]=0;
		}
	}
}

// Time complexity: O(n^n+1)
vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> ans;
	solve(board,ans,0,n);
	return ans;

	
}