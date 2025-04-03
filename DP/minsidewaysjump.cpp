// Min side ways jumps
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int rec(vector<int>& obstacles,int n,int lane,int position){
            if(position+1 == n)
                return 0;
    
            // if(obstacles[position]-1 == lane)
            //     return -1;
    
    
            if(obstacles[position+1] != lane)
                return rec(obstacles,n,lane,position+1);
    
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(lane!=i && obstacles[position] != i){
                    ans=min(ans,rec(obstacles,n,i,position)+1);
    
                }
            }
            
            return ans;    
            
    
        }
        int minSideJumps(vector<int>& obstacles) {
            int n=obstacles.size();
            return rec(obstacles,n,2,0);
            
        }
    };