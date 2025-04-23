// Russian Doll Envelopes
// https://leetcode.com/problems/russian-doll-envelopes/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    static bool compare(vector<int> a,vector<int> b){
        if(a[0]==b[0])
           return a[1]>b[1]; 
        else 
            return a[0]<b[0];
        
    }
    int solveOptimal(int n,vector<int> a){
            if(n==0)
                return 0;
            
            vector<int> ans;
            ans.push_back(a[0]);
            
            for(int i=1;i<n;i++){
                if(a[i]>ans.back()){
                    ans.push_back(a[i]);
                }
                else{
                    int index= lower_bound(ans.begin(),ans.end(),a[i])- ans.begin();
                    ans[index]=a[i];
                }
                
            }
            
            return ans.size();
        }
    
        int maxEnvelopes(vector<vector<int>>& envelopes) {
    
            sort(envelopes.begin(),envelopes.end(),compare);
    
            // We are sorting asc in width so each envelope will small than next, if same width   then desc height so same width envelop cannot added.
            vector<int> heights;
            for( auto i: envelopes){
                    heights.push_back(i[1]);
            }
            int n=heights.size();
    
            return solveOptimal(n,heights);
            
        }
    };