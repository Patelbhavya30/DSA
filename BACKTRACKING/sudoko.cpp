#include <bits/stdc++.h> 
bool isPossible(int num,int row,int col,vector<vector<bool>> rowCheck,vector<vector<bool>> colCheck,vector<vector<bool>> boxCheck){
  return (!rowCheck[row][num] && !colCheck[col][num] && !boxCheck[(row/3)*3+(col/3)][num]);
}
bool solve(vector<vector<int>>& sudoku,vector<vector<bool>> &rowCheck,vector<vector<bool>> &colCheck,vector<vector<bool>> &boxCheck){
    
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if(sudoku[row][col]==0){
                for(int num=1;num<10;num++){
                    if(isPossible(num,row,col,rowCheck,colCheck,boxCheck)){
                        sudoku[row][col]=num;
                        rowCheck[row][num]=true;
                        colCheck[col][num]=true;
                        boxCheck[(row/3)*3+(col/3)][num]=true;
                        bool solution=solve(sudoku,rowCheck,colCheck,boxCheck);
                        if(solution){
                            return true;
                        }else{

                        sudoku[row][col]=0;
                        rowCheck[row][num]=false;
                        colCheck[col][num]=false;
                        boxCheck[(row/3)*3+(col/3)][num]=false;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    vector<vector<bool>> rowCheck(9, vector<bool>(10, false));
    vector<vector<bool>> colCheck(9, vector<bool>(10, false));
    vector<vector<bool>> boxCheck(9, vector<bool>(10, false));
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            int num=sudoku[row][col];
            if(num!=0){
                rowCheck[row][num]=true;
                colCheck[col][num]=true;
                boxCheck[(row/3)*3+(col/3)][num]=true;
            }
        }
    }
    solve(sudoku,rowCheck,colCheck,boxCheck);
}