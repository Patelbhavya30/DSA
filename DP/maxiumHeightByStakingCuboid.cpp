//  Maximum Height by Stacking Cuboids 
// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool check(vector<int> &above, vector<int> &below) {
        return (above[0] <= below[0] && above[1] <= below[1] && above[2] <= below[2]);
    }
    int space(vector<vector<int>>& arr){
              int n=arr.size();
              
              vector<int> currRow(n+1,0);
              vector<int> nextRow(n+1,0);
              
              for(int curr=n-1;curr>=0;curr--){
                  
              for(int prev=curr-1;prev>=-1;prev--){
                  
              int incans=0,excans=0;
              
              
              excans=nextRow[prev+1];
              
              if(prev==-1 || check(arr[prev],arr[curr]))
              {
                  incans= arr[curr][2] + nextRow[curr+1];
              }
                  
              currRow[prev+1]=max(excans,incans);
              }
              nextRow=currRow;
              
              }
              
              return nextRow[0];
              
              
            
        }
            int maxHeight(vector<vector<int>>& cuboids) {
    
            for(auto &arr:cuboids){
                sort(arr.begin(),arr.end());
            }
            sort(cuboids.begin(),cuboids.end());
            
            return space(cuboids);
    
            
        }
    };