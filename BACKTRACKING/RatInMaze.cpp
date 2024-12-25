#include <bits/stdc++.h> 
using namespace std;

bool isSafe(vector < vector < int >> arr,vector < vector < int >> visited,int n,int i,int j){
    if(i>=0 && i<n && j>=0 && j<n && arr[i][j]==1 && visited[i][j]==0)
        return true;
    return false;
}
void ratInMaze(vector < vector < int >> arr,int n,vector < vector < int >> &visited,int i,int j,string path,vector<string> &ans){
     if (i == -1 || i == arr.size() || j == -1 || j == arr.size() || visited[i][j]==1 || arr[i][j] == 0) {
        return;
    }
        if(i==n-1 && j==n-1)
        {
            ans.push_back(path);
            return;
        }

        visited[i][j]=1;
        // Down
        if(isSafe(arr,visited,n,i+1,j)){
        // path.push_back('D');
        ratInMaze(arr,n,visited,i+1,j,path+'D',ans);
        // path.pop_back();
        }
        // Left
        if (isSafe(arr,visited, n, i, j-1)) {
        // path.push_back('L');
        ratInMaze(arr, n, visited, i, j - 1, path+'L', ans);
        // path.pop_back();
        }
        // Right
        if (isSafe(arr,visited, n, i, j+1)){
        // path.push_back('R');
        ratInMaze(arr, n, visited, i, j+1, path+'R', ans);
        // path.pop_back();
        }
        // Up
        if (isSafe(arr,visited, n, i-1, j)) {
        // path.push_back('U');
        ratInMaze(arr, n, visited, i-1, j, path+'U', ans);
        // path.pop_back();
        }

        visited[i][j]=0;
}
// Time Complexity: O(3^(n^2))
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    string path="";
    vector<string> ans;
    vector < vector < int >> visited(n, vector<int>(n, 0));
    ratInMaze(arr,n,visited,0,0,path,ans);
    return ans;

}