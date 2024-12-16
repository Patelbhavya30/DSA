#include<bits/stdc++.h>
using namespace std;
class node{
  public:
  int data;
  int i;
  int j;
  node(int data,int i,int j){
      this->data=data;
      this->i=i;
      this->j=j;
  }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};
// Time complexity: O((k⋅n)logk) Space Complexity: O(K)
int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    int maxi=INT_MIN;
    
    priority_queue<node*,vector<node*>,compare> minHeap;
    for(int i=0;i<k;i++){
        int element=a[i][0];
        minHeap.push(new node(element,i,0));
        maxi=max(maxi,element);
    }
    int minRange=INT_MAX;
    while(!minHeap.empty()){
        node* mini=minHeap.top();
        minHeap.pop();
        int range=maxi-mini->data+1;
        minRange=min(minRange,range);
        if(++mini->j<n){
            minHeap.push(new node(a[mini->i][mini->j],mini->i,mini->j));
            maxi=max(a[mini->i][mini->j],maxi);

        }else{
            break;
        }

    }
    return minRange==0?1:minRange;
    
}