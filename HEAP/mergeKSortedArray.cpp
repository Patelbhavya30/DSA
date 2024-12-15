// Merge K Sorted Arrays
// https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
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
// TIME COMPLEXITY: O((N * K) * log(K)) SPACE COMPLEXITY: O(N * K)
// Another merge all arrays and sort them. TIME COMPLEXITY: O(N * K * log(N * K)) SPACE COMPLEXITY: O(N * K)
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*,vector<node*>,compare> minHeap;
    vector<int> ans;
    for(int i=0;i<kArrays.size();i++){
        minHeap.push(new node(kArrays[i][0],i,0));
    }
    while(!minHeap.empty()){
      node* top=minHeap.top();
      ans.push_back(top->data);
      minHeap.pop();
    //   If there is next element in array as top element then push it in minHeap
      if( ++top->j < kArrays[top->i].size()){
           minHeap.push(new node(kArrays[top->i][top->j],top->i,top->j));
      }
    }

    return ans;

}
